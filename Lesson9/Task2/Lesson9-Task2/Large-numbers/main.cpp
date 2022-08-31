#include <iostream>
#include <string>

class Big_integer
{
private:
	std::string num;
	long long numb;

public:
	Big_integer(std::string value) : num(value) 
	{
		numb = std::stoll(num);
	}

	Big_integer(Big_integer&& other) noexcept : numb(std::exchange(other.numb, numb)) {}

	Big_integer& operator=(Big_integer&& other) noexcept
	{
		std::swap(numb, other.numb);
		return *this;
	}

	long long operator+(Big_integer& other)
	{
		long long result = numb + other.numb;
		return result;
	}

	long long operator*(Big_integer& other)
	{
		long long result = numb * other.numb;
		return result;
	}
};

int main()
{
	auto number1 = Big_integer("114575");
	auto number2 = Big_integer("78524");
	auto result = number1 + number2;
	std::cout << result;
}