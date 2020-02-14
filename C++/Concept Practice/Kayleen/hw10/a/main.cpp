#include <iostream>
#include <string>

using namespace std;

template <class T>
T aMax(T a, T b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a = 6;
	int b = 9;
	double c = 2.72;
	double d = 3.14;
	char e = 'k';
	char f = 'h';
	string g = "Fate";
	string h = "Fatal";
	
	cout << "Max of " << a << " and " << b << ": " << aMax(a, b) << endl;
	cout << "Max of " << c << " and " << d << ": " << aMax(c, d) << endl;
	cout << "Max of " << e << " and " << f << ": " << aMax(e, f) << endl;
	cout << "Max of " << g << " and " << h << ": " << aMax(g, h) << endl;
	
	system("pause");
	return 0;
}