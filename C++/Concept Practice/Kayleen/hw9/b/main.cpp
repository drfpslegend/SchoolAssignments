#include <iostream>
#include <string>

#include "Car.h"

int Car::carCount = 0;

int main()
{
	Car myCar;
	Car yourCar("Toyota", 2017);
	
	std::cout << "My car: " << std::endl;
	myCar.displayCar();
	std::cout << std::endl << std::endl;
	std::cout << "Your car: " << std::endl;
	yourCar.displayCar();
	std::cout << std::endl << std::endl;
	
	myCar.setCar("Ford", 2012);
	
	std::cout << "My car: " << std::endl;
	myCar.displayCar();
	std::cout << std::endl << std::endl;
	
	if (myCar.areSame(yourCar))
	{
		std::cout << "The two cars are the same model and year" << std::endl << std::endl;
	}
	else
	{
		std::cout << "The two cars are not the same model and year" << std::endl << std::endl;
	}
	
	std::cout << myCar.getCount() << " cars have been made" << std::endl << std::endl;
	
	system("pause");
	return 0;
}