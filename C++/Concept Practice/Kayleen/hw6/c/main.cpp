#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::fstream file;
	file.open("data.txt", std::ios::binary | std::ios::in);  // opens file in input mode
	std::vector<int> fileData;  // vector to store data from file
	
	if (file.is_open())
	{
		std::cout << "Here are the numbers in the file:\n";
		while (!file.eof())
		{
			int num;
			file >> num;
			fileData.push_back(num);
			std::cout << "\t" << fileData.at(fileData.size() - 1) << std::endl;  // outputs latest value stored in vector to screen
		}
		file.close();
		
		file.open("results.txt", std::ios::binary | std::ios::out);  // opens results file in output mode
		for (int i = 0; i < fileData.size(); ++i)
		{
			file << fileData.at(i) << "\n";  // stores latest value from vector in results file
		}
		file.close();
		
		file.open("results.txt", std::ios::binary | std::ios::out | std::ios::app);  // opens results file in output mode and append mode
		int moreNumbers = 3;
		std::cout << "Enter " << moreNumbers << " more numbers:\n";
		for (int i = 0; i < moreNumbers; ++i)
		{
			int num;
			std::cin >> num;
			file << num << "\n";  // stores new numbers to the end of the file
		}
		std::cout << "All numbers have been written or appended to the results file.\n";
		file.close();
	}
	else
	{
		std::cout << "Error opening file!\n";  // outputs error message to screen if file did not open successfully
		file.close();
		std::exit;  // closes program
	}
	
	system("pause");
	return 0;
}