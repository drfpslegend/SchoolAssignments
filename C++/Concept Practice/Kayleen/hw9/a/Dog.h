#ifndef DOG_H
#define DOG_H

#include <string>
#include <iostream>

class Dog;

std::ostream& operator<< (std::ostream&, const Dog&);

class Dog
{
	private:
		std::string name;
		float weight;
		int age;
	public:
		Dog(std::string, float, int);
		~Dog();
		void displayDog();
		bool operator>= (const int&);
		bool operator< (const Dog&);
		bool operator== (const Dog&);
		friend std::ostream& operator<< (std::ostream&, const Dog&);
};

Dog::Dog(std::string n, float w, int a)
{
	name = n;
	weight = w;
	age = a;
}

Dog::~Dog()
{
	
}

void Dog::displayDog()
{
	std::cout << "NAME: " << name << std::endl;
	std::cout << "WEIGHT: " << weight << std::endl;
	std::cout << "AGE: " << age << std::endl;
}

bool Dog::operator>= (const int& rhs)
{
	if (age >= rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dog::operator< (const Dog& rhs)
{
	if (weight < rhs.weight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dog::operator== (const Dog& rhs)
{
	if (name == rhs.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<< (std::ostream& s, const Dog& rhs)
{
	s << "NAME: " << rhs.name << std::endl << "WEIGHT: " << rhs.weight << " pounds" << std::endl << "AGE: " << rhs.age << " years old";
	
	return s;
}

#endif