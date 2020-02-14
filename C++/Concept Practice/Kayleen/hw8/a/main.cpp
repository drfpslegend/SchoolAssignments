#include <iostream>
#include <string>
#include "Student.h"

int main()
{
	Student s1;
	Student s2(100, "Tom P. Lee", 12);
	
	std::cout << "Student 1:\n";
	s1.displayRecord();
	std::cout << std::endl;
	std::cout << "Student 2:\n";
	s2.displayRecord();
	std::cout << std::endl;
	
	std::cout << "Setting new student information...\n\n";
	s1.setID(101);
	s1.setName("John Lee Hooker");
	s1.setUnits(15);
	
	std::cout << "Student 1:\n";
	s1.displayRecord();
	std::cout << std::endl;
	
	system("pause");
	return 0;
}