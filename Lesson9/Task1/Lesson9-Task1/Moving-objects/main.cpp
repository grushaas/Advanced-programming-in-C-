#include <vector>
#include <string>
#include <iostream>

template <class T>
void Move_vectors(T& one, T& two)
{
	T tmp = std::move(two);
	one = std::move(two);
	two = std::move(tmp);
}

int main()
{
	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;

	Move_vectors(one, two);
}