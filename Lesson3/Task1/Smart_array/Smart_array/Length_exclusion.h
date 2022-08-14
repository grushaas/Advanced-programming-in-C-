#pragma once
#include <stdexcept>
#include <string>

class Except_length : public std::length_error
{
public:
	Except_length(const char* message);
};