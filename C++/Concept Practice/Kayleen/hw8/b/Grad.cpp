#include "Grad.h"

#include <string>
#include <iostream>

Grad::Grad(int id, std::string name, int units, std::string degree) : Student(id, name, units)
{
	this->degree = degree;
}

Grad::~Grad()
{
	
}

void Grad::displayRecord()
{
	std::cout << "ID:\t" << id << std::endl;
	std::cout << "Name:\t" << name << std::endl;
	std::cout << "Units:\t" << units << std::endl;
	std::cout << "Degree:\t" << degree << std::endl;
}