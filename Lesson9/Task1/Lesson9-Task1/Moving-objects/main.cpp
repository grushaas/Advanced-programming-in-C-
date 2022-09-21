#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

template <class T>
void Move_vectors(T& one, T& two)
{
	T tmp = one;
	one = std::move(two);
	for (int i = 0; i < tmp.size(); ++i)
	{
		two.push_back(tmp[i]);
	}
}

int main()
{
	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;

	Move_vectors(one, two);
}