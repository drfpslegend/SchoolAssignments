#include "Undergrad.h"

#include <string>
#include <iostream>

Undergrad::Undergrad(int id, std::string name, int units, std::string level) : Student(id, name, units)
{
	this->level = level;
}

Undergrad::~Undergrad()
{
	
}

void Undergrad::displayRecord()
{
	std::cout << "ID:\t" << id << std::endl;
	std::cout << "Name:\t" << name << std::endl;
	std::cout << "Units:\t" << units << std::endl;
	std::cout << "Level:\t" << level << std::endl;
}