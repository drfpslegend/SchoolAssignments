#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
	private:
		int id;
		std::string name;
		int units;
	public:
		Student();
		Student(int, std::string, int);
		~Student();
		void setID(int);
		void setName(std::string);
		void setUnits(int);
		void displayRecord();
};

#endif