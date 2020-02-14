#include <iostream>
#include <cstdlib>

void getScores(double array[], const int size);
void showMenu();
char getChoice();
void displayResult(double array[], const int size, char choice);

int main()
{
	const int SIZE = 5;
	double testScores[SIZE];
	
	getScores(testScores, SIZE);
	
	system("CLS");
	
	showMenu();
	char choice = getChoice();
	
	system("CLS");
	
	displayResult(testScores, SIZE, choice);
	
	system("PAUSE");
	return 0;
}

void getScores(double array[], const int size)
{
	std::cout << "Enter 5 test scores:" << std::endl;
	
	for (int i = 0; i < size; ++i)
	{
		std::cin >> array[i];
	}
	
	return;
}

void showMenu()
{
	std::cout << "A) Calculate the average of the test scores" << std::endl;
	std::cout << "B) Display all test scores" << std::endl;
	
	return;
}

char getChoice()
{
	std::cout << "Enter your choice: ";
	char c;
	std::cin >> c;
	
	return c;
}

void displayResult(double array[], const int size, char choice)
{
	if (std::toupper(choice) == 'A')
	{
		double sum = 0.0;
		for (int i = 0; i < size; ++i)
		{
			sum = sum + array[i];
		}
		
		std::cout << "The average is " << sum / size << std::endl;
	}
	else if (std::toupper(choice) == 'B')
	{
		std::cout << "The scores are: " << std::endl;
		for (int i = 0; i < size; ++i)
		{
			std::cout << array[i] << std::endl;
		}
	}
	
	return;
}