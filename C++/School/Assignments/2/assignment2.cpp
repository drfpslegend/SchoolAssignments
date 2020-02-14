// Kevin Holst, kevin_holst1@my.vcccd.edu

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CashRegister
{
	private:
		double cashOnHand;
	public:
		CashRegister();
		CashRegister(double);
		~CashRegister();
		double getBalance();
		void adjustBalance(double);
};

CashRegister::CashRegister()
{
	cashOnHand = 100;
}

CashRegister::CashRegister(double c)
{
	cashOnHand = c;
}

CashRegister::~CashRegister()
{
	
}

double CashRegister::getBalance()
{
	return cashOnHand;
}

void CashRegister::adjustBalance(double delta)
{
	cashOnHand += delta;
}

class Dispenser
{
	private:
		string productName;
		int numItems;
		double pricePerItem;
	public:
		Dispenser();
		Dispenser(string, int, double);
		~Dispenser();
		string getProductName();
		int getNumItems();
		double getPricePerItem();
		void makeSale(CashRegister &, double);
};

Dispenser::Dispenser()
{
	productName = "Product";
	numItems = 50;
	pricePerItem = 2.00;
}

Dispenser::Dispenser(string n, int i, double p)
{
	productName = n;
	numItems = i;
	pricePerItem = p;
}

Dispenser::~Dispenser()
{
	
}

string Dispenser::getProductName()
{
	return productName;
}

int Dispenser::getNumItems()
{
	return numItems;
}

double Dispenser::getPricePerItem()
{
	return pricePerItem;
}

void Dispenser::makeSale(CashRegister & moneyBag, double payment)
{
	if (numItems <= 0)
	{
		cout << "Payment returned: $" << payment << endl;
		cout << "This item is sold out.  Please choose another item." << endl << endl;
	}
	else if (payment < pricePerItem)
	{
		cout << "Payment returned: $" << payment << endl;
		cout << "Please choose another item or purchase your selection with the full ammount." << endl << endl;
	}
	else
	{
		cout << "Dispensing item ..." << endl;
		--numItems;
		moneyBag.adjustBalance(payment);
		cout << "Thank you for your purchase." << endl;
		double change = payment - pricePerItem;
		moneyBag.adjustBalance(-1.0 * change);
		cout << "Change returned: $" << change << endl << endl;
	}
	system("pause");
}

void showSelection(vector<Dispenser *> d)
{
	for (int i = 0; i < d.size(); ++i)
	{
		cout << "(" << i + 1 << ") " << d[i]->getProductName() << " [" << d[i]->getNumItems() << " left] : \t\t$" << d[i]->getPricePerItem() << endl;
	}
	cout << "(0) Quit" << endl;
}

int main()
{
	CashRegister machineRegister(500);
	vector<Dispenser *> vendingMachine;
	Dispenser * d;
	int selection;
	double payment;
	
	d = new Dispenser("Twix Bar", 30, 3.00);
	vendingMachine.push_back(d);
	
	d = new Dispenser("Baby Ruth Bar", 25, 2.50);
	vendingMachine.push_back(d);
	
	d = new Dispenser("Crunch Bar", 20, 2.00);
	vendingMachine.push_back(d);
	
	d = new Dispenser("Kit Kat Bar", 35, 3.50);
	vendingMachine.push_back(d);
	
	d = new Dispenser("Hershey's Bar", 10, 1.00);
	vendingMachine.push_back(d);
	
	d = nullptr;
	
	while(true)
	{
		cout << "Vending machine balance: $" << machineRegister.getBalance() << endl;
		showSelection(vendingMachine);
		cout << endl;
		cout << "Please select an item to purchase: ";
		cin >> selection;
		if (selection == 0)
		{
			break;
		}
		while(selection < 0 || selection > vendingMachine.size())
		{
			cout << "Please enter a number corresponding to an available item: ";
			cin >> selection;
		}
		
		system("cls");
		
		cout << "(" << selection << ") " << vendingMachine[selection - 1]->getProductName() << " [" << vendingMachine[selection - 1]->getNumItems() << " left] : \t\t$" << vendingMachine[selection - 1]->getPricePerItem() << endl << endl;
		cout << "Please enter your payment: ";
		cin >> payment;
		
		system("cls");
		vendingMachine[selection - 1]->makeSale(machineRegister, payment);
		
		system("cls");
	}
	
	for (int i = 0; i < vendingMachine.size(); ++i)
	{
		delete vendingMachine[i];
		vendingMachine[i] = nullptr;
	}
	
	system("cls");
	cout << "Thank you for using Kevin's vending machine :)" << endl << endl;
	system("pause");
	
	return 0;
}