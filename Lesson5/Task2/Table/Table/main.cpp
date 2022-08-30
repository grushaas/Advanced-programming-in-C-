#include <iostream>
#include <string>
#include <vector>

template<class T>
class Table
{
private:
	int const rows = 0;
	int const cols = 0;
	int size = 0;
	T** arr = nullptr;

public:
	Table(int r, int c) : rows(r), cols(c)
	{
		if (rows <= 0 || cols <= 0) throw std::runtime_error("The size of the row or column must be greater than or equal to zero");
		arr = new T* [rows];
		for (int i = 0; i < rows; ++i)
		{
			arr[i] = new T[cols];
		}
		size = rows * cols;
	}

	~Table()
	{
		for (int i = 0; i < rows; ++i)
		{
			delete arr[i];
		}

		delete[] arr;
		
	}

	int Size() const
	{
		return size;
	}

	T* operator[](const int i) const
	{
		return arr[i];
	}

	T* operator[](int i)
	{
		return arr[i];
	}
};

int main()
{
	const Table<bool> table = Table<bool>(3, 5);
	table[0][0] = false;
	std::cout << table[0][0] << std::endl;

	table.Size();
}