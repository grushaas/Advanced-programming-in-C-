#include "Ini_parser.h"
#include <iostream>
#include <string>


int main()
{
	std::string sectionAndValue = "Section1.var1";
	IniParser parser("file.ini");
	parser.GetValue<int>("Section1", "var1");
	parser.GetValue<std::string>("Section1", "var2");
}