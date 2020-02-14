#include <iostream>
#include <fstream>

int main()
{
	std::fstream file;
	file.open("data.txt", std::ios::in | std::ios::binary);
	
	if (file.is_open())
	{
		std::cout << "Here are the numbers in the file:\n";
		while (!file.eof())
		{
			int num;
			file >> num;
			std::cout << "\t" << num << std::endl;
		}
	}
	else
	{
		std::cout << "Error opening file!\n";
		file.close();
		std::exit;
	}
	
	system("pause");
	return 0;
}