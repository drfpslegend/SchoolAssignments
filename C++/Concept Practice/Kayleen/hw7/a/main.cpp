#include <iostream>
#include "Date.h"

int main()
{
	char again = 'y';
	while (std::tolower(again) == 'y')
	{
		Date today(25, 10, 2019);
		Date payday;
		int aday, amonth, ayear;
		
		std::cout << "Enter the day for pay day: " << std::endl;
		std::cout << "Day: "; std::cin >> aday;
		std::cout << "Month: "; std::cin >> amonth;
		std::cout << "Year: "; std::cin >> ayear;
		
		payday.setDate(aday, amonth, ayear);
		
		std::cout << "Today's date is on "; today.displayDate(); std::cout << std::endl;
		std::cout << "Upcoming pay day is on "; payday.displayDate(); std::cout << std::endl;
		
		payday.addDays(14);
		std::cout << "Next upcoming pay day is on "; payday.displayDate(); std::cout << std::endl;
		
		std::cout << "Run again? (y/n): ";
		std::cin >> again;
		system("cls");
	}
	
	return 0;
}