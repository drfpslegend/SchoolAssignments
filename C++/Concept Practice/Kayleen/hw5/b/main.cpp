#include <iostream>
#include <vector>
#include <iomanip>

void showEvens (const int [], const int, int &, std::vector<int> &);

int main()
{
	const int SIZE = 10;
	int index = 0;
	int values[SIZE] = {2, 5, 7, 8, 11, 14, 17, 18, 22, 23};
	std::vector<int> evens(0);
	
	showEvens(values, SIZE, index, evens);
	
	std::cout << "Here are the " << evens.size() << " even numbers:\n";
	for (int i = 0; i < evens.size(); ++i)
	{
		std::cout << std::setw(4) << std::left << evens.at(i);
	}
	std::cout << std::endl << std::endl;
	
	system("pause");
	return 0;
}

void showEvens (const int array[], const int size, int &i, std::vector<int> &evens)
{
	if ((i < size) && (array[i] % 2 == 0))
	{
		evens.push_back(array[i]);
		++i;
		showEvens(array, size, i, evens);
	}
	else if (i < size)
	{
		showEvens(array, size, ++i, evens);
	}
	else
	{
		return;
	}
	
	return;
}