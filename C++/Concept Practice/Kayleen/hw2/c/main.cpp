#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream studentGrades("grades.dat");
	char gradesArray[5][3];
	
	if (!studentGrades.is_open())
	{
		std::cout << "Error opening data file" << std::endl;
		
		system("PAUSE");
		return 0;
	}
	
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			studentGrades >> gradesArray[i][j];
		}
	}
	
	int width = 10;
	std::cout << "All Grades" << std::endl;
	std::cout << std::setw(width) << std::left << "Student";
	std::cout << std::setw(width) << std::left << "English";
	std::cout << std::setw(width) << std::left << "History";
	std::cout << std::setw(width) << std::left << "Math";
	std::cout << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << std::left << "#" << std::setw(width - 1) << std::left << i + 1;
		for (int j = 0; j < 3; ++j)
		{
			std::cout << std::setw(width) << std::left << gradesArray[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Student GPAs:" << std::endl;
	std::cout << "Student" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << std::setw(width) << std::left << i + 1;
		double sum = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (gradesArray[i][j] == 'A')
			{
				sum = sum + 4;
			}
			else if (gradesArray[i][j] == 'B')
			{
				sum = sum + 3;
			}
			else if (gradesArray[i][j] == 'C')
			{
				sum = sum + 2;
			}
			else if (gradesArray[i][j] == 'D')
			{
				sum = sum + 1;
			}
			else
			{
				sum = sum + 0;
			}
		}
		std::cout << std::setw(width) << std::left << std::showpoint << std::fixed << std::setprecision(2) << sum / 3 << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Average GPA by Subject:" << std::endl;
	std::cout << std::setw(width) << std::left << "English";
	std::cout << std::setw(width) << std::left << "History";
	std::cout << std::setw(width) << std::left << "Math";
	std::cout << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		double sum = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (gradesArray[j][i] == 'A')
			{
				sum = sum + 4;
			}
			else if (gradesArray[j][i] == 'B')
			{
				sum = sum + 3;
			}
			else if (gradesArray[j][i] == 'C')
			{
				sum = sum + 2;
			}
			else if (gradesArray[j][i] == 'D')
			{
				sum = sum + 1;
			}
			else
			{
				sum = sum + 0;
			}
		}
		std::cout << std::setw(width) << std::left << std::showpoint << std::fixed << std::setprecision(2) << sum / 5;
	}
	std::cout << std::endl << std::endl;
	
	system("PAUSE");
	return 0;
}