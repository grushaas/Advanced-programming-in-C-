#include <iostream>
#include <vector>

template<class T>
class Table
{
private:
	T rows = 0;
	T cols = 0;
	T** arr = nullptr;

public:
	Table(T r, T c) : rows(r), cols(c)
	{
		if (rows <= 0 || cols <= 0) throw std::runtime_error("The size of the row or column must be greater than or equal to zero");
		arr = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			arr[i] = new int[cols];
		}
	}

	~Table()
	{
		for (int i = 0; i < rows; ++i)
		{
			delete arr[i];
		}

		delete[] arr;
		
	}

	T const Size()
	{
		return rows * cols;
	}

	T* operator[](const T i) const
	{
		return arr[i];
	}

	T* operator[](T i)
	{
		return arr[i];
	}
};

int main()
{
	auto table = Table<int>(2, 3);
	table[0][0] = 4;
	std::cout << table[0][0] << std::endl;

	std::cout << "Array size: " << table.Size() << std::endl;
}