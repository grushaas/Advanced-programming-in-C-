#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//template<class T>
class Ini_parser
{
private:
	std::string fileName;

	void tokenize(std::string const& str, const char symbol, std::vector<std::string>& out)
	{
		std::stringstream ss(str);

		std::string s;
		while (std::getline(ss, s, symbol))
		{
			out.push_back(s);
		}
	}

public:
	Ini_parser(std::string fileName) : fileName(fileName) {}
	
	template<class T>
	T getValue(std::string sectionAndValue)
	{
		std::string sectionIniFile;
		std::string variable;
		char symbol = ".";
		std::vector<std::string> out;
		std::vector<std::string> resultVector;
		T result
			std::ifstream iniFile(fileName);

		tokenize(sectionAndValue, symbol, out);

		if (iniFile.is_open())
		{
			continue;
		}
		else
		{
			return 1;
		}

		do
		{
			iniFile >> sectionIniFile;

		} while (out[0] != sectionIniFile);

		do
		{
			iniFile >> variable;

		} while (out[1] != variable);

		symbol = "=";

		tokenize(variable, symbol, resultVector);

		result = std::stoi(resultVector[2]);

		return result;
	}
};

int main()
{
	Ini_parser parser("file.ini");
}