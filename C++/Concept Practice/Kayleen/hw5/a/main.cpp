#include <iostream>

void decToBinary (int &);

int main()
{
	int userNum;
	
	std::cout << "Enter a non-negative integer value: ";
	std::cin >> userNum;
	
	std::cout << "Decimal " << userNum << " = ";
	decToBinary(userNum);
	std::cout << " binary.";
	std::cout << std::endl << std::endl;
	
	system("pause");
	return 0;
}

void decToBinary (int &decNum)
{
	if (decNum < 0)
	{
		std::cout << "Invalid Entry";
		return;
	}
	
	int remainder = decNum % 2;
	decNum = decNum / 2;
	
	if (decNum != 0)
	{
		decToBinary(decNum);
	}
	
	std::cout << remainder;
	
	return;
}