#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			for (int k = 1; k <= 6; ++k)
			{
				if (i*j*k == 72)
				{
					cout << i << ", " << j << ", " << k << endl;
				}
			}
		}
	}
	
	system("pause");
	return 0;
}