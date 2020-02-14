#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
	private:
		int seconds;
		int minutes;
		int hours;
	public:
		Clock();
		Clock(int, int, int);
		~Clock();
		void setTime(int, int, int);
		void getTime(int &, int &, int &);
		void incrementSeconds();
		void incrementMinutes();
		void incrementHours();
		void printTime();
		bool areTimesEqual(Clock);
};

#endif