/*

Yuyue's Classes Library For Microsoft Visual C++

Copyright @2016 CDU INnoVation Studio
All rights reserved.

�ļ����ƣ�ASetting.h
ժҪ��
1.���ļ�����ini��д���������ʵ����ASetting.cpp�С�
2.ini��д����ʵ��ͨ������ֵ����дini�ļ��е����ݡ�
3.���й��ܵ�ʵ�־���������Windows API�����������Ͻ����ļ�����ʵ�ֿ�ƽ̨��
4.ini�ļ�һ�����ֻ����1024���ַ����������ִ���
5.֧��ANSI��ʽ��UTF-8��֧����BOM��ʽ��

��ǰ�汾��V1.1
���ߣ�����
e-mail��1397011447@qq.com
�������ڣ�2016��11��25��
�������ڣ�2016��12��02��

������־��
v1.1�������ײ����ݱ�ʾ��һ���߼�����

*/

#pragma once

#include <string>
#include <memory>
#include "ACore.h"

struct ASettingData;

ATHENA_BEGIN

class ASetting final
{
public:
	ASetting();
	ASetting(const ASetting &);
	ASetting(ASetting &&);
	explicit ASetting(const char *);
	explicit ASetting(const std::string &);
	const std::string &getValue(const std::string&, const std::string &) const;
	bool setValue(const std::string&, const std::string &, const std::string&);
	bool saveToFile();
	~ASetting();
private:
	void readFromFile();
private:	
	std::unique_ptr<ASettingData> data;
};

ATHENA_END
