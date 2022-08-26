#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <map>
#include <string>

template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B>& p)
{
	return std::pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B, A> flip_map(const std::map<A, B>& src)
{
	std::multimap<B, A> dst;
	std::transform(src.rbegin(), src.rend(), std::inserter(dst, dst.begin()),
		flip_pair<A, B>);
	return dst;
}

int main()
{
	const char* str = "Hello world!!";
	std::map<char, int> frequency;

	for (int i = 0; i < strlen(str); i++)
	{
		const char value = str[i];
		int count = 0;
		for (int j = 0; j < strlen(str); j++)
		{
			if (value == str[j])
			{
				count += 1;
			}
		}
		frequency[value] = count;
	}
	std::multimap<int, char> dst = flip_map(frequency);
	for (auto& i : dst)
	{
		std::cout << i.first << ": " << i.second << std::endl;
	}
}