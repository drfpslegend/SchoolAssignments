// Kevin Holst, kevin_holst1@my.vcccd.edu

#include <iostream>

using namespace std;

int * allocateCubeArray(int);

int main()
{
	int size;
	
	cout << "Enter the size of the array you want (integer value): ";
	cin >> size;
	
	int * cubeArrayPtr = allocateCubeArray(size);
	
	cout << "Here are the values of your array:" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << "^3 = " << *(cubeArrayPtr + i) << endl;
	}
	cout << endl;
	
	system("pause");
	return 0;
}

int * allocateCubeArray(int n)
{
	int * intPtr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		*(intPtr + i) = (i+1) * (i+1) * (i+1);
	}
	
	return intPtr;
}