#include <iostream>
#include <iomanip>

using namespace std;

double getSalesAmt();
double calcCommission(double);
double calcPay(double, double);
void displayPay(double, double, double, double);

int main()
{
	char cont = 'y';
	double basePay = 2500.0;
	
	while (cont == 'y' || cont == 'Y')
	{
		double sales = getSalesAmt();

		double commission = calcCommission(sales);
		
		double pay = calcPay(basePay, commission);
		
		displayPay(sales, commission, basePay, pay);
		
		cout << "Do it again? (Y/N): ";
		cin >> cont;
		cout << endl;
	}

	return 0;
}

 double getSalesAmt()
 {
	 double sales = 0.0;
	 
	 cout << "Enter monthly sales amount: ";
	 cin >> sales;

	 return sales;
 }

 double calcCommission(double sales)
 {
	 double commission = 0.0;
	 
	 if (sales > 50000)
	 {
		 commission = 0.02 * sales;
	 }
	 else if (sales >= 25000 && sales <= 50000)
	 {
		 commission = 0.015 * sales;
	 }
	 else
	 {
		 commission = 0.0;
	 }
	 
	 return commission;
 }
 
 double calcPay(double basePay, double commission)
 {
	 double pay = basePay + commission;
	 
	 return pay;
 }
 
 void displayPay(double sales, double commission, double basePay, double pay)
 {
	 int width = 10;
	 int number = 0;
	 
	 number = 0;
	 for (double i = sales; i > 1; i = i / 10)
	 {
		 ++number;
	 }
	 cout << "Monthly Sales:     $" << setw(width) << setprecision(number + 2) << sales << endl;
	 
	 number = 0;
	 for (double i = commission; i > 1; i = i / 10)
	 {
		 ++number;
	 }
	 cout << "Commission:        $" << setw(width) << setprecision(number + 2) << commission << endl;
	 
	 number = 0;
	 for (double i = basePay; i > 1; i = i / 10)
	 {
		 ++number;
	 }
	 cout << "Base Pay:          $" << setw(width) << setprecision(number + 2) << basePay << endl;
	 
	 number = 0;
	 for (double i = pay; i > 1; i = i / 10)
	 {
		 ++number;
	 }
	 cout << "Total Pay:         $" << setw(width) << setprecision(number + 2) << pay << endl;
	  
	 return;
 }