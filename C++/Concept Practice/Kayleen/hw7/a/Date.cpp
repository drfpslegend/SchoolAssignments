#include <iostream>
#include "Date.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
	
}

void Date::setDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::displayDate()
{
	std::cout << month << '/' << day << '/' << year;
}

void Date::addDays(int moreDays)
{
	for (int i = 0; i < moreDays; ++i)
	{
		++day;
		if (month == 2 && day > 28) // except for february
		{
			if (((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) || (day > 29)) // not a leap year or already counted extra day
			{
				++ month;
				day = 1;
			}
		}
		else if ((month == 9 || month == 4 || month == 6 || month == 11) && (day > 30)) // september, april, june, november
		{
			++month;
			day = 1;
		}
		else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && (day > 31)) // all the rest
		{
			++month;
			day = 1;
		}
		else if (month == 12 && day > 31)
		{
			++year;
			month = 1;
			day = 1;
		}
	}
}