#include <iostream>
#include <algorithm>
#include <string>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

void Getting_the_result()
{
	auto value = get_variant();

	if (std::holds_alternative<int>(value))
	{
		int num = std::get<int>(value) * 2;
		std::cout << num << std::endl;
	}
	else if (std::holds_alternative<std::string>(value))
	{
		std::string string = std::get<std::string>(value);
		std::cout << string << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(value))
	{
		std::vector<int> vec = std::get<std::vector<int>>(value);
		std::for_each(vec.cbegin(), vec.cend(), [](int n)
			{
				std::cout << n << " ";
			});
	}
}

int main()
{
	Getting_the_result();
}