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
5.��֧��ANSI��ʽ��UTF-8��BOM��ʽ��

��ǰ�汾��V1.0
���ߣ�����
e-mail��1397011447@qq.com
�������ڣ�2016��11��25��
�������ڣ�2016��11��25��

������־��

*/

#pragma once

#include <string>
#include <map>
#include <memory>

struct ASettingData;

class ASetting final
{
public:
	ASetting();
	ASetting(const ASetting &);
	ASetting(ASetting &&);
	explicit ASetting(const char *);
	explicit ASetting(const std::string &);
	const std::string &getValue(const std::string&, const std::string &) const;
	void saveToFile();
	~ASetting();
private:
	void readFromFile();
private:	
	std::unique_ptr<ASettingData> data;
};

