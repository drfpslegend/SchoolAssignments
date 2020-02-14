#include <iostream>
#include <iomanip>

int main()
{
	int maxNum = 0;
	
	std::cout << "Enter the maximum number to print out: ";
	std::cin >> maxNum;
	
	for (int i = 1; i <= maxNum; ++i)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			std::cout << std::setw(10) << std::left << "fizzbuzz";
		}
		else if (i % 3 == 0)
		{
			std::cout << std::setw(10) << std::left << "fizz";
		}
		else if (i % 5 == 0)
		{
			std::cout << std::setw(10) << std::left << "buzz";
		}
		else
		{
			std::cout << std::setw(10) << std::left << i;
		}
		
		if (i % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
	
	return 0;
}