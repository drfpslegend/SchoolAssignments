#include <iostream>

unsigned long long int fibonacci(int);

int main()
{
	int input = 1;
	while(input >= 1)
	{
		std::cout << "Fibonacci of " << input << ": " << fibonacci(input) << std::endl;
		std::cout << std::endl;
		
		std::cout << "Next input: "; std::cin >> input;
	}
	
	system("pause");
	return 0;
}

unsigned long long int fibonacci(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}