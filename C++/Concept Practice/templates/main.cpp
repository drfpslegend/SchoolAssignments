#include <iostream>

#include "vector.h"

using namespace std;

int main()
{
	vector<int> v1(10);
	vector<int> v2(20);
	
	for (int i = 0; i < v1.size(); ++i)
	{
		v1[i] = i + 1;
	}
	for (int i = 0; i < v2.size(); ++i)
	{
		v2[i] = i + 1;
	}
	
	cout << "v1:" << endl;
	for (int i = 0; i < v1.size(); ++i)
	{
		cout << v1.at(i) << ", ";
	}
	cout << endl << endl;
	
	cout << "v2:" << endl;
	for (int i = 0; i < v2.size(); ++i)
	{
		cout << v2.at(i) << ", ";
	}
	cout << endl << endl;
	
	v1 = v2;
	
	cout << "v1:" << endl;
	for (int i = 0; i < v1.size(); ++i)
	{
		cout << v1.at(i) << ", ";
	}
	cout << endl << endl;
	
	system("pause");
	return 0;
}