#include <iostream>
#include <exception>
#include "Length_exclusion.h"

class Smart_Array
{
private:
	int amount = 0;
	int logical_size = 0;
	int* smart_array;
	
public:
	Smart_Array(int sum) : amount(sum)
	{
		smart_array = new int[amount];
	}

	void add_element(int element)
	{
		if (logical_size >= amount) throw Except_length("The logical size exceeds the size of the entire array");
		smart_array[logical_size] = element;
		logical_size += 1;
	}

	int get_element(int index)
	{
		if (index >= amount) throw Except_length("There are no elements for a given index");
		int element = smart_array[index];
		return element;
	}

	~Smart_Array()
	{
		delete[] smart_array;
	}

};

int main()
{
	try
	{
		Smart_Array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//arr.add_element(100);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const Except_length& el)
	{
		std::cout << el.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}
}
