#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

//template<class T>
class Ini_parser
{
private:
	std::string fileName;

public:
	Ini_parser(std::string fileName) : fileName(fileName) {}
	
	template<class T>
	T getValue(std::string value_section, std::string value_var)
	{
		T result;
		std::ifstream ini(fileName);

		std::regex section(value_section);
		std::regex var(value_var);
		while (!ini.eof())
		{
			std::string string;
			ini >> string;
			if (std::regex_search(string, section))
			{
				//std::cout << string << std::endl;
				ini >> string;
				if (std::regex_search(string, var))
				{
					std::smatch matched;
					if (std::regex_search(string, matched, std::regex("=(\d+)")))
					{
						std::cout << matched[0] << std::endl;
					}
					
				}
			}
		}
		return 0;
	}
};

int main()
{
	std::string sectionAndValue = "Section1.var1";
	Ini_parser parser("file.ini");
	parser.getValue<int>("Section1", "var1");
	parser.getValue<std::string>("Section1", "var2");
}