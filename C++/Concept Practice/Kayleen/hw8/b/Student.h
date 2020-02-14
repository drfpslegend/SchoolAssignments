#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student
{
	protected:
		int id;
		std::string name;
		int units;
	public:
		Student();
		Student(int, std::string, int);
		virtual ~Student();
		void setID(int);
		int getID();
		void setName(std::string);
		std::string getName();
		void setUnits(int);
		int getUnits();
		virtual void displayRecord() = 0;
};

#endif