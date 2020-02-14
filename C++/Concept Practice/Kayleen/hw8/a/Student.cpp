#include "Student.h"
#include <string>
#include <iostream>

Student::Student()
{
	id = 0;
	name = "";
	units = 0;
}

Student::Student(int id, std::string name, int units)
{
	this->id = id;
	this->name = name;
	this->units = units;
}

Student::~Student()
{
	
}

void Student::setID(int id)
{
	this->id = id;
}

void Student::setName(std::string name)
{
	this->name = name;
}

void Student::setUnits(int units)
{
	this->units = units;
}

void Student::displayRecord()
{
	std::cout << "ID:\t" << id << std::endl;
	std::cout << "Name:\t" << name << std::endl;
	std::cout << "Units:\t" << units << std::endl;
}