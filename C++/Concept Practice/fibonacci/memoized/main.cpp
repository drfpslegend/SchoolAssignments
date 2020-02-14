#include <iostream>
#include <vector>

// function declarations
unsigned long long int fib(std::vector<unsigned long long int> &, int);
void printList(std::vector<unsigned long long int>);

int main()
{
	int input = 0;
	while(input >= 0)
	{
		// ordered list of fibonacci numbers from 0 to n
		std::vector<unsigned long long int> fibvals;
		// result for nth fibonacci number
		unsigned long long int result;
		// result for n-1th fibonacci number
		unsigned long long int result1;
		
		// compute nth fibonacci number and update list accordingly
		
		// first 5 values do not update list correctly
		if (input <= 4)
		{
			switch(input)
			{
				case 0:
					fibvals.push_back(0);
					result = 0;
					break;
				case 1:
					fibvals.push_back(0);
					fibvals.push_back(1);
					result = 1;
					break;
				case 2:
					fibvals.push_back(0);
					fibvals.push_back(1);
					fibvals.push_back(1);
					result = 1;
					break;
				case 3:
					fibvals.push_back(0);
					fibvals.push_back(1);
					fibvals.push_back(1);
					fibvals.push_back(2);
					result = 2;
					break;
				case 4:
					fibvals.push_back(0);
					fibvals.push_back(1);
					fibvals.push_back(1);
					fibvals.push_back(2);
					fibvals.push_back(3);
					result = 3;
					break;
			}
		}
		else
		{
			result1 = fib(fibvals, input - 1); // to get the n-1 term that is missing in the final list
			fibvals = {}; // resets list to have 0 values
			result = fib(fibvals, input); // final result with a correct list up to n-2 term
			fibvals.push_back(result1); // update the list with n-1 term
			fibvals.push_back(result); // update the list with nth term
		}
		
		// print values
		bool overflow = false;
		for (int i = 0; i < fibvals.size(); ++i)
		{
			// case for n = 0, only print the first value
			if (input == 0)
			{
				std::cout << 0 << ": " << fibvals.at(0) << std::endl;
				break;
			}
			else
			{
				// print value
				std::cout << i << ": " << fibvals.at(i);
				// check for overflow
				if ((i >= 1) && ((fibvals.at(i) < fibvals.at(i - 1)) || overflow))
				{
					std::cout << " (OVERFLOW!)";
					overflow = true;
				}
				std::cout << std::endl;
			}
		}
		
		std::cout << std::endl;
		
		// print final result
		std::cout << "Fibonacci of " << input << ": " << result;
		if (overflow)
		{
			std::cout << " (OVERFLOW!)";
		}
		std::cout << std::endl;
		
		std::cout << std::endl;
		
		// request new fibonacci number
		std::cout << "Next input: "; std::cin >> input;
		// clear screen
		system("cls");
	}
	
	system("pause");
	return 0;
}

// function implementations
unsigned long long int fib(std::vector<unsigned long long int> &fibvals, int n)
{
	// pushes 0 and 1 to first two entries
	if (fibvals.size() < 2)
	{
		if (fibvals.size() == 0)
		{
			fibvals.push_back(0);
			fibvals.push_back(1);
		}
		else if (fibvals.size() == 1)
		{
			fibvals.push_back(1);
		}
	}
	
	// if the fibonacci number being requested already has an entry in the dictionary, use it instead of computing it
	if (n < fibvals.size())
	{
		return fibvals.at(n);
	}
	// else if the fibonacci number being requested is the next one to be entered into the dictionary, compute it and use it.
	else if (n == fibvals.size())
	{
		fibvals.push_back(fibvals.at(n - 2) + fibvals.at(n - 1));
		return fibvals.at(n);
	}
	// else compute the sequence
	else
	{
		return fib(fibvals, n - 2) + fib(fibvals, n - 1);
	}
}