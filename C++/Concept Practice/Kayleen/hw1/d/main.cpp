#include <iostream>

using namespace std;

int main()
{
	int arraySize = 5;
	int idNumbers[arraySize] = {56789, 98765, 54321, 12345, 13579};
	int userid = 0;
	
	char cont = 'y';
	while (cont == 'y' || cont == 'Y')
	{
		cout << "Querry the array for an ID number: "; cin >> userid;
		for (int i = 0; i < arraySize; ++i)
		{
			if (userid == idNumbers[i])
			{
				cout << "Position " << i << " in the array." << endl;
				break;
			}
			else if (i == arraySize - 1)
			{
				cout << "ID number not in the array." << endl;
			}
		}
		
		cout << "Run again (Y/N): "; cin >> cont; cout << endl;
	}
	
	return 0;
}