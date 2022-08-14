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

	~Smart_Array()
	{
		delete[] smart_array;
	}

};

int main()
{
	Smart_Array arr(5);
	{
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
	}
	
	Smart_Array newArr(2);
	newArr.add_element(44);
	newArr.add_element(34);

	arr = newArr;

	std::cout << arr.get_element(3);
}