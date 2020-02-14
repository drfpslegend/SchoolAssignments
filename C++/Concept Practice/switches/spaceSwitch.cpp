#include <iostream>

int main()
{
	double earthWeight = 0.0;
	int planetNumber = 0;

	while (true)
	{
		std::cout << "Enter your weight on Earth: ";
		std::cin >> earthWeight;
		std::cout << "Enter the planet number: ";
		std::cin >> planetNumber;

		switch (planetNumber)
		{
			case 0:
			  std::cout << "You are dead, the sun is not a planet." << std::endl;
			  break;
			case 1:
			  std::cout << "Mercury is a curious one indeed." << std::endl;
			  break;
			case 2:
			  std::cout << "Weight on Venus is " << earthWeight * 0.78 << std::endl;
			  break;
			case 4:
			  std::cout << "Weight on Mars is " << earthWeight * 0.39 << std::endl;
			  break;
			case 5:
			  std::cout << "Weight on Jupiter is " << earthWeight * 2.65 << std::endl;
			  break;
			case 6:
			  std::cout << "Weight on Saturn is " << earthWeight * 1.17 << std::endl;
			  break;
			case 7:
			  std::cout << "Weight on Uranus is " << earthWeight * 1.05 << std::endl;
			  break;
			case 8:
			  std::cout << "Weight on Neptune is " << earthWeight * 1.23 << std::endl;
			  break;
			default:
			  std::cout << "Too far away, haven't traveled there yet." << std::endl;
			  break;
		}

		std::cout << std::endl;
	}

	return 0;
}