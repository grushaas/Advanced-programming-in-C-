#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

class IniParser
{
private:
	std::ifstream iniFile;
	std::map<std::string, std::string> values;
	std::map<std::string, std::map<std::string, std::string>> sections;

	std::map<std::string, std::string> tokenize(std::string const& str, const char delim, std::map<std::string, std::string> map); // Делитель строки на две части по ключевому символу

public:
	IniParser(std::string fileName);

	template<class T>
	T GetValue(std::string valueSection, std::string valueVar)
	{
		// Тут остановился
		// На данный момент, метод под именем tokenize завершен
		return 0;
	}
};