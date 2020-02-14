#include <iostream>

void showInUpper (const char [], const int, int);

int main()
{
	const int size = 27;
	char alphabet[size] = "abcdefghijklmnopqrstuvwxyz";
	int index = 0;
	
	showInUpper(alphabet, size, index);
	std::cout << std::endl << std::endl;
	
	system("pause");
	return 0;
}

void showInUpper (const char alphabet[], const int size, int index)
{
	if (index >= size - 1)
	{
		return;
	}
	else
	{
		std::cout << static_cast<char>(std::toupper(alphabet[index]));
		showInUpper(alphabet, size, ++index);
		return;
	}
}