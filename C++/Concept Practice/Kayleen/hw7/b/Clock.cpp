#include <iostream>
#include <iomanip>
#include "Clock.h"

Clock::Clock()
{
	this->seconds = 0;
	this->minutes = 0;
	this->hours = 0;
}

Clock::Clock(int Seconds, int Minutes, int Hours)
{
	this->seconds = Seconds;
	this->minutes = Minutes;
	this->hours = Hours;
}

Clock::~Clock()
{
	
}

void Clock::setTime(int Seconds, int Minutes, int Hours)
{
	this->seconds = Seconds;
	this->minutes = Minutes;
	this->hours = Hours;
}

void Clock::getTime(int &seconds, int &minutes, int &hours)
{
	seconds = this->seconds;
	minutes = this->minutes;
	hours = this->hours;
}

void Clock::incrementSeconds()
{
	int maxSeconds = 59;
	int maxMinutes = 59;
	int maxHours = 23;
	
	++seconds;
	if (seconds > maxSeconds)
	{
		seconds = 0;
		++minutes;
		if (minutes > maxMinutes)
		{
			minutes = 0;
			++hours;
			if (hours > maxHours)
			{
				hours = 0;
			}
		}
	}
}

void Clock::incrementMinutes()
{
	int maxMinutes = 59;
	int maxHours = 23;
	
	++minutes;
	if (minutes > maxMinutes)
	{
		minutes = 0;
		++hours;
		if (hours > maxHours)
		{
			hours = 0;
		}
	}
}

void Clock::incrementHours()
{
	int maxHours = 23;
	
	++hours;
	if (hours > maxHours)
	{
		hours = 0;
	}
}

void Clock::printTime()
{
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << hours;
	
	std::cout.width(0);
	std::cout << ":";
	
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << minutes;
	
	std::cout.width(0);
	std::cout << ":";
	
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << seconds;
}

bool Clock::areTimesEqual(Clock otherClock)
{
	int numSeconds, numMinutes, numHours;
	
	otherClock.getTime(numSeconds, numMinutes, numHours);
	if ((seconds == numSeconds) && (minutes == numMinutes) && (hours == numHours))
	{
		return true;
	}
	else
	{
		return false;
	}
}