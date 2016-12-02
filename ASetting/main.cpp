#include "ASetting.h"

#include <iostream>

int main()
{
	ASetting as("e:/a.ini");
	as.setValue("Test", "FontName", "233");
	as.setValue("Test2", "Name", "555");

	std::cin.get();
	return 0;
}