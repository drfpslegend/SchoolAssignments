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
		
		std::ofstream outFile;
		outFile.open("results.txt", std::ios::binary | std::ios::out);  // opens results file in output mode
		for (int i = 0; i < fileData.size(); ++i)
		{
			outFile << fileData.at(i) << "\n";  // stores latest value from vector in results file
		}
		std::cout << "The data has been written to the file.\n";
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