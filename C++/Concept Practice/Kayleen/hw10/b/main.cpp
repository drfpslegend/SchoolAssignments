#include <iostream>
#include <vector>

using namespace std;

void insertValue(vector<int>&, int, int);
void removeValue(vector<int>&, int);
void displayVector(const vector<int>&);

int main()
{
	vector<int> values;
	
	values.push_back(1);
	values.push_back(2);
	values.push_back(4);
	values.push_back(9);
	values.push_back(5);
	displayVector(values);
	cout << endl << endl;
	
	insertValue(values, 0, 3);
	displayVector(values);
	cout << endl << endl;
	
	removeValue(values, 0);
	displayVector(values);
	cout << endl << endl;
	
	values.pop_back();
	displayVector(values);
	cout << endl << endl;
	
	cout << "There are " << values.size() << " values in the vector" << endl << endl;
	
	system("pause");
	return 0;
}

void insertValue(vector<int>& v, int index, int value)
{
	if (index == v.size())
	{
		v.push_back(value);
	}
	else
	{
		v.push_back(0);
		for (int i = v.size() - 2; i >= index; --i)
		{
			v[i+1] = v[i];
		}
		v[index] = value;
	}
}

void removeValue(vector<int>& v, int index)
{
	for (int i = index; i < v.size() - 1; ++i)
	{
		v[i] = v[i+1];
	}
	v.pop_back();
}

void displayVector(const vector<int>& v)
{
	cout << "Vector: ";
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
}