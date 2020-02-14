#ifndef UNDERGRAD_H
#define UNDERGRAD_H

#include "Student.h"

#include <string>
#include <iostream>

class Undergrad : public Student
{
	protected:
		std::string level;
	public:
		Undergrad(int, std::string, int, std::string);
		virtual ~Undergrad();
		virtual void displayRecord();
};

#endif