#include <iostream>

int main() {
	while (true)
	{
		int userNum;
		std::cout << "Enter an integer number: ";
		std::cin >> userNum;
		
		switch (userNum)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				std::cout << "0 <= " << userNum << " <= 5\n\n";
				break;
			case 100:
				std::cout << userNum << " is max\n\n";
				break;
			default:
				if (userNum < 0)
				{
					std::cout << userNum << " is negative\n\n";
				}
				else if ((userNum > 5) && (userNum < 100))
				{
					std::cout << "5 < " << userNum << " < 100\n\n";
				}
				else
				{
					std::cout << "100 < " << userNum << " infinity\n\n";
				}
				break;
		}
	}
	
	return 0;
}