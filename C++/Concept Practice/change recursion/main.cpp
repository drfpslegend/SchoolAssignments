#include <iostream>

using namespace std;

void makeChange(int, const int, int,  int [], int []);

int main()
{
	int userAmount;
	const int NUM_COINS = 6;
	int coinIndex = 0;
	int baseCoinValues[NUM_COINS] = {100, 50, 25, 10, 5, 1};
	int returnCoinValues[NUM_COINS] = {0, 0, 0, 0, 0, 0};
	
	cout << "Enter an amount for which to make change: ";
	cin >> userAmount;
	cout << endl << "Making change..." << endl;
	
	makeChange(userAmount, NUM_COINS, coinIndex, baseCoinValues, returnCoinValues);
	
	cout << endl;
	cout << returnCoinValues[0] << " Dollars, " << returnCoinValues[1] << " Half-Dollars, " << returnCoinValues[2] << " Quarters, " << returnCoinValues[3] << " Dimes, " << returnCoinValues[4] << " Nickels, " << returnCoinValues[5] << " Pennies" << endl;
	cout << endl;
	
	system("pause");
	return 0;
}

void makeChange(int userAmount, const int NUM_COINS, int coinIndex, int baseCoinValues[], int returnCoinValues[])
{
	if (userAmount == 0)
	{
		return;
	}
	else if (userAmount >= baseCoinValues[coinIndex])
	{
		++returnCoinValues[coinIndex];
		userAmount = userAmount - baseCoinValues[coinIndex];
	}
	else if (userAmount < baseCoinValues[coinIndex])
	{
		++coinIndex;
	}
	
	makeChange(userAmount, NUM_COINS, coinIndex, baseCoinValues, returnCoinValues);
}