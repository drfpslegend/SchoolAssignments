#include <iostream>
#include "Clock.h"

int main()
{
	Clock myClock(0, 30, 3);
	std::cout << "The time on my clock is "; myClock.printTime(); std::cout << std::endl;
	
	Clock yourClock(15, 0, 10);
	std::cout << "The time on your clock is "; yourClock.printTime(); std::cout << std::endl;
	
	if (myClock.areTimesEqual(yourClock))
	{
		std::cout << "The times of my clock and your clock are equal." << std::endl;
	}
	else
	{
		std::cout << "The times of my clock and your clock are not equal." << std::endl;
	}
	
	Clock myOtherClock;
	std::cout << "The time on my other clock is "; myOtherClock.printTime(); std::cout << std::endl;
	
	std::cout << "I am going to add 1 minute and 1 second to my other clock." << std::endl;
	myOtherClock.incrementMinutes();
	myOtherClock.incrementSeconds();
	std::cout << "The time on my other clock is "; myOtherClock.printTime(); std::cout << std::endl;
	
	system("pause");
	return 0;
}