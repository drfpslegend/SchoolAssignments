#include <iostream>
#include <vector>

unsigned long long int fib(std::vector<unsigned long long int> &, int);
void printList(std::vector<unsigned long long int>, bool &);
bool checkOverflow(std::vector<unsigned long long int>, int, bool);

int main()
{
	int n = 0;
	while (n >= 0)
	{
		std::vector<unsigned long long int> fibvals;
		unsigned long long int result;
		bool overflow = false;
		
		result = fib(fibvals, n);
		printList(fibvals, overflow);
		std::cout << std::endl;
		std::cout << "Fibonacci of " << n << ": " << result;
		if (overflow)
		{
			std::cout << " (OVERFLOW!)";
		}
		std::cout << std::endl;
		
		std::cout << std::endl;
		std::cout << "Next fibonacci number: ";
		std::cin >> n;
		
		system("cls");
	}
	
	return 0;
}

unsigned long long int fib(std::vector<unsigned long long int> &fibvals, int n)
{
	for (int i = 0; i <= n; ++i)
	{
		if (i == 0)
		{
			fibvals.push_back(0);
		}
		else if (i == 1)
		{
			fibvals.push_back(1);
		}
		else
		{
			fibvals.push_back(fibvals.at(i - 1) + fibvals.at(i - 2));
		}
	}
	
	return fibvals.at(n);
}

void printList(std::vector<unsigned long long int> list, bool &overflow)
{
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << i << ": " << list.at(i);
		if (!overflow)
		{
			overflow = checkOverflow(list, i, overflow);
		}
		if (overflow)
		{
			std::cout << " (OVERFLOW!)";
		}
		std::cout << std::endl;
	}
}

bool checkOverflow(std::vector<unsigned long long int> fibvals, int index, bool overflow)
{
	if (index == 0)
	{
		return false;
	}
	else if ((fibvals.at(index) < fibvals.at(index - 1)) || overflow == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}