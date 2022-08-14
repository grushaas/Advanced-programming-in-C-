#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> nums = { 4, 7, 9, 14, 12 };
	auto print = [](int n)
	{
		std::cout << n << " ";
	};

	std::cout << "Input data: ";
	std::for_each(nums.cbegin(), nums.cend(), print);
	
	std::cout << std::endl;

	std::for_each(nums.begin(), nums.end(), [](int &n) {
		if (n % 2 != 0)
		{
			n *= 3;
		}
		});

	std::cout << "Output data: ";
	std::for_each(nums.cbegin(), nums.cend(), print);
}