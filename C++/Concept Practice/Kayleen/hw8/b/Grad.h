#ifndef GRAD_H
#define GRAD_H

#include "Student.h"

#include <string>
#include <iostream>

class Grad : public Student
{
	protected:
		std::string degree;
	public:
		Grad(int, std::string, int, std::string);
		virtual ~Grad();
		virtual void displayRecord();
};

#endif