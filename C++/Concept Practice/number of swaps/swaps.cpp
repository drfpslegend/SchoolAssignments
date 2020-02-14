#include <iostream>

using namespace std;

int main()
{
	while (true)
	{
		int n;
		cout << "Enter the size of your array: ";
		cin >> n;
		int array[n];
		cout << "Enter your values in ascending order:\n";
		for (int i = 0; i < n; ++i)
		{
			cout << i + 1 << ") ";
			cin >> array[i];
		}
		
		for (int i = 0; i < n - 1; ++i)
		{
			cout << "Swaps:";
			cout << " " << (n - i - 1) << endl;
		}
	}
	return 0;
}