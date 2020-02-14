#include <iostream>

using namespace std;

void getTemps(double temps[], const int sizeOfArray);
double calcAvg(double temps[], const int sizeOfArray);
void displayAvg(double average);

int main()
{
	char cont = 'y';
	while (cont == 'y' || cont == 'Y')
	{
		const int sizeOfArray = 3;
		double temps [sizeOfArray];
		
		getTemps(temps, sizeOfArray);
		displayAvg(calcAvg(temps, sizeOfArray));
		
		cout << endl << "Run again? (Y/N): "; cin >> cont; cout << endl;
	}
	
	return 0;
}

void getTemps(double temps[], const int sizeOfArray)
{
	cout << "Enter temperature of " << sizeOfArray << " cities:" << endl << endl;
	for (int i = 0; i < sizeOfArray; ++i)
	{
		cout << "#" << i + 1 << ":     "; cin >> temps [i]; cout << endl;
	}
	
	return;
}

double calcAvg(double temps[], const int sizeOfArray)
{
	double sumOfTemps = 0.0;
	for (int i = 0; i < sizeOfArray; ++i)
	{
		sumOfTemps = sumOfTemps + temps[i];
	}
	
	return sumOfTemps / sizeOfArray;
}

void displayAvg(double average)
{
	cout << "The average temperature is " << average << " degrees." << endl;
}