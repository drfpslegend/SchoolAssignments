#include <iostream>
#include <string>

#include "Dog.h"

int main()
{
	Dog myDog("Spot", 5.5, 3);
	Dog yourDog("Jack", 4.5, 3);
	
	if (myDog >= 2)
	{
		std::cout << "The dog is at least 2 years old" << std::endl << std::endl;
	}
	else
	{
		std::cout << "The dog is less than 2 years old" << std::endl << std::endl;
	}
	
	if (yourDog < myDog)
	{
		std::cout << "Your dog weighs less than my dog" << std::endl << std::endl;
	}
	else
	{
		std::cout << "Your dog does not weigh less than my dog" << std::endl << std::endl;
	}
	
	if (myDog == yourDog)
	{
		std::cout << "Our dogs have the same name" << std::endl << std::endl;
	}
	else
	{
		std::cout << "Our dogs have different names" << std::endl << std::endl;
	}
	
	std::cout << yourDog << std::endl << std::endl;
	
	system("pause");
	return 0;
}