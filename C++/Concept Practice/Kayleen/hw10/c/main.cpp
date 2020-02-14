#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	const int NUM_EMPLOYEES = 5;
	vector<int> hours (NUM_EMPLOYEES);
	vector<double> wage (NUM_EMPLOYEES);
	
	for (int i = 0; i < NUM_EMPLOYEES; ++i)
	{
		cout << "Hours for employee #" << i + 1 << ": ";
		cin >> hours[i];
		cout << "Wage for employee #" << i + 1 << ": ";
		cin >> wage[i];
	}
	system("cls");
	
	cout << "Gross pay for each employee:" << endl << endl;
	for (int i = 0; i < NUM_EMPLOYEES; ++i)
	{
		cout << "Employee #" << i + 1 << "\t$ " << wage[i] * hours[i] << endl;
	}
	cout << endl;
	
	cout << "Employee #1 hours = " << hours.front() << endl;
	cout << "Employee #5 hours = " << hours.back() << endl;
	cout << endl;
	
	system("pause");
	return 0;
}