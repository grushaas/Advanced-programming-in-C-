#include "IniParser.h"
#include <string>
#include <iostream>

int main()
{
    std::string sectionAndValue = "Section1.var1";
    IniParser parser("../file.ini");
    parser.GetValue<double>("[Section1]", "var1");
    //parser.GetValue<std::string>("Section1", "var2");
}