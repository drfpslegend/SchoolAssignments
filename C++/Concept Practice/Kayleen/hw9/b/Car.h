#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
	private:
		std::string model;
		int year;
		static int carCount;
	public:
		Car();
		Car(std::string, int);
		~Car();
		void setCar(std::string, int);
		int getCount();
		void displayCar();
		bool areSame(const Car&);
};

#endif