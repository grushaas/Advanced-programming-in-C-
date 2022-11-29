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

    std::map<std::string, std::string> tokenize(std::string const& str, const char delim, std::map<std::string, std::string> map);

    // template <>
    // int Converter<std::string>(std::string& str);

public:
    IniParser(std::string filename);

    template <class T>
    T GetValue(std::string valueSection, std::string valueVar)
    {
        std::string str;
        for (const auto& [key, value] : sections)
        {
            if (valueSection == key)
            {
                for (const auto& [key2, value2] : values)
                {
                    if (key2 == valueVar)
                    {
                        str = value2;
                        break;
                    }
                }
            }
        }
        //T result = Converter(str);

        //std::cout << result << std::endl;
        return 0;
    }
};
