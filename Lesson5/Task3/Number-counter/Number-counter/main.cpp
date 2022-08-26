#include <iostream>
#include <algorithm>
#include <vector>

class Functor
{
private:
	int count = 0;
	int sum = 0;

public:
	int Get_sum() const
	{
		return sum;
	}

	int Get_count() const
	{
		return count;
	}

	void operator()()
	{
		int n;
		if (!(n % 3))
		{
			sum += n;
			++count;
		}
	}
};

int main()
{
	std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
	Functor func;
	std::for_each(numbers.begin(), numbers.end(), func);
	std::cout << func.Get_sum() << std::endl;
	std::cout << func.Get_count() << std::endl;
}