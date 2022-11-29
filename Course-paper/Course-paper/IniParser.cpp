#include "IniParser.h"

IniParser::IniParser(std::string fileName)
{
	iniFile.open(fileName);
	std::string str;
	std::string section;

	while (std::getline(iniFile, str))
	{
		if (str.find(';') == 0)
		{
			continue;
		}
		else if (str.find('=') != std::string::npos)
		{
			values = tokenize(str, '=', values);
		}
		else if (str.find('[') == 0)
		{
			if (section == "")
			{
				section = str;
			}
			else
			{
				sections[section] = values;
				values.clear();
				section = str;
			}
		}
	}
}

std::map<std::string, std::string> IniParser::tokenize(std::string const& str, const char delim, std::map<std::string, std::string> map)
{
	std::stringstream ss(str);

	std::string var1;
	std::string var2;
	while (std::getline(ss, var1, delim))
	{
		while (std::getline(ss, var2, delim))
		{
			map[var1] = var2;
		}
	}

	return map;
}
