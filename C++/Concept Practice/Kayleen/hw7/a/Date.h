#ifndef DATE_H
#define DATE_H

class Date
{
	private:
		int day;
		int month;
		int year;
	public:
		Date();
		Date(int, int, int);
		~Date();
		void setDate(int, int, int);
		void displayDate();
		void addDays(int);
};

#endif