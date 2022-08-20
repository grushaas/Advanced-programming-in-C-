#include <iostream>

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

	Smart_Array(const Smart_Array& other)
	{
		smart_array = other.smart_array;
	}

	~Smart_Array()
	{
		delete[] smart_array;
	}

	void add_element(int element)
	{
		smart_array[logical_size] = element;
		logical_size += 1;
	}

	int get_element(int index)
	{
		int element = smart_array[index];
		return element;
	}

	Smart_Array operator=(const Smart_Array& other)
	{
		for (int i = logical_size; i < amount; ++i)
		{
			for (int j = other.logical_size; j < other.amount; ++j)
			{
				smart_array[i] = other.smart_array[j];
			}
		}

		return *this;
	}

};

int main()
{
	Smart_Array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	
	Smart_Array newArr(2);
	newArr.add_element(44);
	newArr.add_element(34);

	arr = newArr;

	std::cout << arr.get_element(4);
}