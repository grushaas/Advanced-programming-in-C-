#include <iostream>
#include <vector>
#include <algorithm>

void Removing_duplicates(std::vector<int>& vector)
{
	std::sort(vector.begin(), vector.end());
	auto last = std::unique(vector.begin(), vector.end());
	vector.erase(last, vector.end());
}

int main()
{
	int size = 0;
	std::cout << "[IN]: " << std::endl;
	std::cin >> size;
	std::vector<int> vector;

	while (size != 0)
	{
		int value;
		std::cin >> value;
		vector.push_back(value);
		size -= 1;
	}

	Removing_duplicates(vector);

	std::cout << "[OUT]: " << std::endl;
	auto print = [](int n)
	{
		std::cout << n << std::endl;
	};

	std::for_each(vector.rbegin(), vector.rend(), print);
}