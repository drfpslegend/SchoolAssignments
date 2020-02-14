#include <iostream>

using namespace std;

void getTemps(double&, double&, double&);
double calcAvg(double, double, double);
void displayAvg(double);

int main()
{
	char cont = 'y';
	while (cont == 'y' || cont == 'Y')
	{
		double temp1 = 0.0, temp2 = 0.0, temp3 = 0.0;
		
		getTemps(temp1, temp2, temp3);
		displayAvg(calcAvg(temp1, temp2, temp3));
		cout << endl << "Run again? (Y/N): "; cin >> cont; cout << endl;
	}
	
	return 0;
}

void getTemps(double &temp1, double &temp2, double &temp3)
{
	cout << "Enter temperature of 3 cities:" << endl << endl;
	cout << "#1:     "; cin >> temp1; cout << endl;
	cout << "#2:     "; cin >> temp2; cout << endl;
	cout << "#3:     "; cin >> temp3; cout << endl;
	
	return;
}

double calcAvg(double temp1, double temp2, double temp3)
{
	return (temp1 + temp2 + temp3) / 3;
}

void displayAvg(double average)
{
	cout << "The average temperature is " << average << " degrees." << endl;
	
	return;
}