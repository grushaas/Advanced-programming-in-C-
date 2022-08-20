#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
T squaring(T a)
{
	return a * a;
}

template <class T>
void squaring(std::vector<T>& xs)
{
	for (int i = 0; i < xs.size(); ++i)
	{
		xs[i] *= xs[i];
	}
}

int main()
{
	int num = 10;
	std::vector<int> nums = { -1, 4, 8 };
	auto print = [](int n)
	{
		std::cout << n << " ";
	};

	std::cout << "[IN]: " << num << std::endl;
	std::cout << "[OUT]: " << squaring(num) << std::endl;
	std::cout << "[IN]: ";
	std::for_each(nums.cbegin(), nums.cend(), print);

	std::cout << std::endl;

	std::cout << "[OUT]: ";
	squaring(nums);
	std::for_each(nums.cbegin(), nums.cend(), print);
}