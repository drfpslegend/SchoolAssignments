// Kevin Holst, kevin_holst1@my.vcccd.edu

#include <iostream>
#include <string>

using namespace std;

class Student
{
	private:
		int adminNumber;
		string studentName;
		double english;
		double math;
		double science;
		double total;
		double calcTotal();
	public:
		Student();
		Student(int, string, double, double, double);
		~Student();
		void takeData();
		void showData();
};

Student::Student()
{
	adminNumber = 0;
	studentName = "Student";
	english = 0.0;
	math = 0.0;
	science = 0.0;
	total = 0;
}

Student::Student(int a, string n, double e, double m, double s)
{
	adminNumber = a;
	studentName = n;
	english = e;
	math = m;
	science = s;
	total = calcTotal();
}

Student::~Student() 
{
	
}

double Student::calcTotal()
{
	return english + math + science;
}

void Student::takeData()
{
	cout << "Admin number: ";
	cin >> adminNumber;
	cout << "Student name: ";
	cin.ignore();
	getline(cin, studentName);
	cout << "English score: ";
	cin >> english;
	cout << "Math score: ";
	cin >> math;
	cout << "Science score: ";
	cin >> science;
	total = calcTotal();
	cout << "Total: " << total << endl;
}

void Student::showData()
{
	cout << "Admin number: " << adminNumber << endl;
	cout << "Student name: " << studentName << endl;
	cout << "English score: " << english << endl;
	cout << "Math score: " << math << endl;
	cout << "Science score: " << science << endl;
	cout << "Total: " << total << endl;
}

class Batsman
{
	private:
		int batterCode;
		string batterName;
		int innings;
		int runs;
		int notout;
		double battingAvg;
		double calcAvg();
	public:
		Batsman();
		Batsman(int, string, int, int, int);
		~Batsman();
		void readData();
		void displayData();
};

Batsman::Batsman()
{
	batterCode = 0;
	batterName = "Batsman";
	innings = 0;
	runs = 0;
	notout = 0;
	battingAvg = 0;
}

Batsman::Batsman(int c, string n, int i, int r, int o)
{
	batterCode = c;
	batterName = n;
	innings = i;
	runs = r;
	notout = o;
	battingAvg = calcAvg();
}

Batsman::~Batsman()
{
	
}

double Batsman::calcAvg()
{
	return static_cast<double>(runs)/(innings-notout);
}

void Batsman::readData()
{
	cout << "Batter code: ";
	cin >> batterCode;
	cout << "Batter name: ";
	cin.ignore();
	getline(cin, batterName);
	cout << "Innings: ";
	cin >> innings;
	cout << "Runs: ";
	cin >> runs;
	cout << "Notout: ";
	cin >> notout;
	battingAvg = calcAvg();
	cout << "Batting average: " << battingAvg << endl;
}

void Batsman::displayData()
{
	cout << "Batter code: " << batterCode << endl;
	cout << "Batter name: " << batterName << endl;
	cout << "Innings: " << innings << endl;
	cout << "Runs: " << runs << endl;
	cout << "Notout: " << notout << endl;
	cout << "Batting average: " << battingAvg << endl;
}

int main()
{
	Student s1;
	Student s2(2, "Catra", 3.5, 2.4, 3.1);
	Student s3(1, "Adora", 3.5, 3.0, 2.8);
	
	s1.takeData();
	cout << endl;
	
	system("cls");
	
	s1.showData();
	cout << endl;
	s2.showData();
	cout << endl;
	s3.showData();
	cout << endl;
	
	system("pause");
	system("cls");
	
	Batsman b1;
	Batsman b2(1, "Babe Ruth", 9, 3, 3);
	Batsman b3(2, "Jackie Robinson", 9, 5, 1);
	
	b1.readData();
	cout << endl;
	
	system("cls");
	
	b1.displayData();
	cout << endl;
	b2.displayData();
	cout << endl;
	b3.displayData();
	cout << endl;
	
	system("pause");
	return 0;
}