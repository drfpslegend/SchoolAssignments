#include <iostream>
#include <iomanip>

void getData(int array[3][4], int rows, int columns);
void displayArray(int array[3][4], int rows, int columns);

int main()
{
	int rows = 3, columns = 4;
	int numArray[3][4];
	
	getData(numArray, rows, columns);
	system("CLS");
	displayArray(numArray, rows, columns);
	std::cout << std::endl;
	
	system("PAUSE");
	return 0;
}

void getData(int array[3][4], int rows, int columns)
{
	std::cout << "Enter integers into the 2-dimensional array: " << std::endl << std::endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout << "Enter a number: ";
			std::cin >> array[i][j];
		}
	}
	
	return;
}

void displayArray(int array[3][4], int rows, int columns)
{
	std::cout << "Here is the data in the 2-dimensional array: " << std::endl << std::endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout << std::setw(5) << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return;
}