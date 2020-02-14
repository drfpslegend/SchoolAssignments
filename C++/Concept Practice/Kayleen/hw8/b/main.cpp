#include <iostream>
#include <string>

#include "Student.h"
#include "Undergrad.h"
#include "Grad.h"

int main()
{
	Undergrad undergrad(100, "Tom Lee", 9, "Freshman");
	Grad grad(101, "Jim Jones", 12, "PHD");
	
	std::cout << "Student 1:\n";
	undergrad.displayRecord();
	std::cout << std::endl;
	
	std::cout << "Student 2:\n";
	grad.displayRecord();
	std::cout << std::endl;
	
	std::cout << "Updating units...\n\n";
	grad.setUnits(15);
	
	std::cout << "Student 2:\n";
	grad.displayRecord();
	std::cout << std::endl;
	
	system("pause");
	return 0;
}