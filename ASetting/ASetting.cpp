#include "ASetting.h"
#include <fstream>

using keyValue=std::map<std::string, std::string>;
using iniValue= std::map<std::string, std::map<std::string, std::string>>;

struct ASettingData
{
	void operator=(const ASettingData& asd)
	{
		isOk = asd.isOk;
		fileName = asd.fileName;
		values = asd.values;
	}
	bool isOk;
	std::string fileName;
	std::string emptyValue;
	iniValue values;
};

ASetting::ASetting()
{
	data = std::make_unique<ASettingData>();
}

ASetting::~ASetting()
{
}

ASetting::ASetting(const ASetting &as)
{
	data = std::make_unique<ASettingData>();
	*data = *as.data;
}

ASetting::ASetting(ASetting &&as)
{
	as.data.swap(data);
}

void ASetting::readFromFile()
{
	if (data->fileName.empty())
	{
		data->isOk = false;
		return;
	}

	std::ifstream inputFile(data->fileName);
	if (!inputFile.is_open())
	{
		data->isOk = false;
		return;
	}

	char buffer[1024];
	std::string currentSection;
	data->values.insert(std::pair<std::string, keyValue>(currentSection, keyValue()));

	for (;!inputFile.eof();)
	{
		int equalIndex=-1,len;
		inputFile.getline(buffer, sizeof(buffer));

		if (buffer[0] == ';')
		{
			continue;
		}

		for (len= 0;buffer[len]!=0; len++)
		{
			if (buffer[len] == '='&&equalIndex==-1)
			{
				equalIndex = len;
			}
		}

		if (buffer[0] == '['&&buffer[len - 1] == ']')
		{
			buffer[len - 1] = 0;
			currentSection=buffer + 1;
			if (data->values.find(currentSection) == data->values.end())
			{
				data->values.insert(std::pair<std::string,keyValue>(currentSection,keyValue()));
			}
			continue;
		}

		if (equalIndex == -1)
		{
			continue;
		}

		std::string value(buffer + equalIndex+1);
		buffer[equalIndex] = 0;
		std::string key(buffer);
		
		auto target = data->values.find(currentSection);
		target->second[key] = std::move(value);
	}

	data->isOk = true;
}

ASetting::ASetting(const char *file)
{
	data = std::make_unique<ASettingData>();
	data->fileName = file;
	readFromFile();
}

ASetting::ASetting(const std::string &file):ASetting(file.c_str())
{

}

const std::string & ASetting::getValue(const std::string &section, const std::string &key) const
{
	auto it = data->values.find(section);
	if (it == data->values.end())
	{
		return data->emptyValue;
	}

	auto result = it->second.find(key);
	if (result == it->second.end())
	{
		return data->emptyValue;
	}

	return result->second;
}

void ASetting::saveToFile()
{

}
