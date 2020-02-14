#include <iostream>

#include "Car.h"

Car::Car()
{
	model = "";
	year = 0;
	++carCount;
}

Car::Car(std::string m, int y)
{
	model = m;
	year = y;
	++carCount;
}

Car::~Car()
{
	
}

void Car::setCar(std::string m, int y)
{
	model = m;
	year = y;
}

int Car::getCount()
{
	return carCount;
}

void Car::displayCar()
{
	std::cout << "Model: " << model << std::endl;
	std::cout << "Year: " << year;
}

bool Car::areSame(const Car& c)
{
	if ((this->model == c.model) && (this->year == c.year))
	{
		return true;
	}
	else
	{
		return false;
	}
}