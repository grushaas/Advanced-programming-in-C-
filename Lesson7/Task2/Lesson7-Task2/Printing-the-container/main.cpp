#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <list>

template <class T>
void Print_container(T cont)
{
	auto it = cont.cbegin();

	while (it != cont.cend())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::cout << "Container 'std::set'" << std::endl;
	Print_container(test_set);

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::cout << "Container 'std::list'" << std::endl;
	Print_container(test_list);

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	std::cout << "Container 'std::vector'" << std::endl;
	Print_container(test_vector);
}