#include <iostream>
#include <iomanip>

struct Time
{
	int hours;
	int minutes;
	int seconds;
};

void getTime(Time &);
bool isTimeValid(Time &);
void addOneSecond(Time &);
void displayTime(const Time &);

const int MAX_HOURS = 23;
const int MAX_MINUTES = 59;
const int MAX_SECONDS = 59;

int main()
{
	char repeat = 'y';
	while(std::tolower(repeat) == 'y')
	{
		Time time;
		
		getTime(time);
		addOneSecond(time);
		
		std::cout << std::endl;
		
		displayTime(time);
		
		std::cout << std::endl << std::endl << "Do it again? (Y/N): ";
		std::cin >> repeat;
		
		system("cls");
	}
	
	return 0;
}

void getTime(Time &t)
{
	bool done = false;
	do
	{
		std::cout << "Enter the time in \"Military Time\", (24-hour format), in the following order: HH:MM:SS (Hours, Minutes, Seconds).";
		std::cout << std::endl << std::endl;
		std::cout << "Hours: ";
		std::cin >> t.hours;
		std::cout << "Minutes: ";
		std::cin >> t.minutes;
		std::cout << "Seconds: ";
		std::cin >> t.seconds;
		
		done = isTimeValid(t);
		if(!done)
		{
			std::cout << std::endl << "Invalid time" << std::endl << std::endl;
		}
	} while(!done);
	
	return;
}

bool isTimeValid(Time &t)
{
	if((t.hours >= 0) && (t.hours <= MAX_HOURS) && (t.minutes >= 0) && (t.minutes <= MAX_MINUTES) && (t.seconds >= 0) && (t.seconds <= MAX_SECONDS))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void addOneSecond(Time &t)
{
	++t.seconds;
	if(t.seconds > MAX_SECONDS)
	{
		t.seconds = 0;
		++t.minutes;
		
		if(t.minutes > MAX_MINUTES)
		{
			t.minutes = 0;
			++t.hours;
			
			if(t.hours > MAX_HOURS)
			{
				t.hours = 0;
			}
		}
	}
	
	return;
}

void displayTime(const Time &t)
{
	std::cout << "After adding one second, the time is ";
	std::cout.fill('0');
	std::cout << std::setw(2) << t.hours;
	std::cout << ':';
	std::cout << std::setw(2) << t.minutes;
	std::cout << ':';
	std::cout << std::setw(2) << t.seconds;
	
	return;
}