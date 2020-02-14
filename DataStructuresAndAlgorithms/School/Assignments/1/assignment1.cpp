#include <iostream>
#include <string>

using namespace std;

class Employee // employee class
{
	protected:
		string name;
		int id;
		int hireDate;
	public:
		Employee() // default constructor
		{
			name = "Employee";
			id = 0;
			hireDate = 112000;
		}
		Employee(string n, int e, int h) // overloaded constructor
		{
			name = n;
			id = e;
			hireDate = h;
		}
		void setName(string n) // name mutator
		{
			name = n;
		}
		string getName() // name accessor
		{
			return name;
		}
		void setID(int i) // id mutator
		{
			id = i;
		}
		int getID() // id accessor
		{
			return id;
		}
		void setHireDate(int h) // hire date mutator
		{
			hireDate = h;
		}
		int getHireDate() // hire date accessor
		{
			return hireDate;
		}
};

class ProductionWorker : public Employee
{
	protected:
		int shift;
		double hourlyPay;
	public:
		ProductionWorker() : Employee() // default constructor which calls the employee default constructor
		{
			shift = 1;
			hourlyPay = 15.0;
		}
		ProductionWorker(string n, int i, int h, int s, double p) : Employee(n, i, h) // overloaded constructor which calls the employee overloaded constructor
		{
			shift = s;
			hourlyPay = p;
		}
		void setShift(int s) // shift mutator
		{
			shift = s;
		}
		int getShift() // shift accessor
		{
			return shift;
		}
		void setHourlyPay(double p) // hourly pay mutator
		{
			hourlyPay = p;
		}
		double getHourlyPay() // hourly pay accessor
		{
			return hourlyPay;
		}
};

int main()
{
	Employee employeeOfTheMonth;
	ProductionWorker worker1("Christina", 95230, 451996, 2, 40.0); // declares one employee object and two production worker objects
	ProductionWorker worker2;
	
	worker2 = worker1;
	worker2.setName("Zasha");
	worker2.setID(85825);
	worker2.setHireDate(8171999); // assigns the contents of worker 1 to worker 2, and uses the mutators to change worker 2's data
	worker2.setShift(1);
	worker2.setHourlyPay(37.5);
	
	cout << "Worker 1:" << endl;
	cout << "Name: " << worker1.getName() << endl;
	cout << "ID: " << worker1.getID() << endl;
	cout << "Hire Date: " << worker1.getHireDate() << endl; // displays worker 1's data
	cout << "Shift: " << worker1.getShift() << endl;
	cout << "Hourly Pay: " << worker1.getHourlyPay() << endl << endl;
	
	cout << "Worker 2:" << endl;
	cout << "Name: " << worker2.getName() << endl;
	cout << "ID: " << worker2.getID() << endl;
	cout << "Hire Date: " << worker2.getHireDate() << endl; // displays worker 2's data
	cout << "Shift: " << worker2.getShift() << endl;
	cout << "Hourly Pay: " << worker2.getHourlyPay() << endl << endl;
	
	employeeOfTheMonth = worker1; // demonstrates the "is a" functionality by assigning a production worker object to an employee object
	cout << "The employee of the month this month is " << employeeOfTheMonth.getName() << "!" << endl << endl; // calls a function that is common to both classes
	
	system("pause");
	return 0;
}