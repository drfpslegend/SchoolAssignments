#include <iostream>
#include <fstream>
#include <string>

bool openFileIn(std::fstream &file, std::string name);                       // passes a file stream object to a function, plus the name of the file to open

int main()
{
	std::fstream file;
	
	file.open("data1.txt", std::ios::out);                 // opens file in out and binary modes
	file << "Some\n";
	file << "Data\n";
	file << "For\n";                                                         // simple output to a file using constant c strings
	file << "The\n";
	file << "File.\n";
	
	file.close();
	
	file.open("data1.txt", std::ios::out | std::ios::app); // opens file in out, binary, and append modes
	file << "More\n";
	file << "Information.\n";                                                 // appends new data to end of file
	
	file.close();
	
	bool checkFileOpenStatus = openFileIn(file, "data1.txt");
	if(checkFileOpenStatus)
	{
		file.close();
	}
	else
	{
		std::cout << "Error opening file!\n";
	}
	
	file.open("data2.txt", std::ios::out);
	std::string sentence;
	file << "This is a sentence with spaces.\n";
	file.close();
	file.open("data2.txt", std::ios::in);
	std::getline(file, sentence, '\n');                           // reads from the file until \n is encountered
	
	file.close();
	
	const int SIZE = 51;
	struct Human
	{
		char name[SIZE];
		int age;
		double salary;
		char dreamJob[SIZE];
		int yearsWorked;
	};
	
	file.open("data3.txt", std::ios::out | std::ios::binary);
	if(file.fail())
	{
		std::cout << "Error opening file for output";
		return 0;
	}
	else
	{
		char again = 'y';
		while(std::tolower(again) == 'y')
		{
			Human person;
			std::cout << "Enter your name: ";
			std::cin.getline(person.name, SIZE);
			std::cout << "Enter your age: ";
			std::cin >> person.age;
			std::cout << "Enter your salary: ";                        // stores information from the user into the Human object
			std::cin >> person.salary;
			std::cin.ignore();
			std::cout << "Enter your dream job: ";
			std::cin.getline(person.dreamJob, SIZE);
			std::cout << "Enter total career time in years: ";
			std::cin >> person.yearsWorked;
			std::cin.ignore();
			
			file.write(reinterpret_cast<char *>(&person), sizeof(person));      // saves object to the file (casts address to char pointer first)
			
			std::cout << std::endl << "Store another person's info? (y/n): ";
			std::cin >> again;
			std::cout << std::endl;
			std::cin.ignore();
		}
		file.close();
	}
	
	file.open("data3.txt", std::ios::in | std::ios::binary);
	if(file.fail())
	{
		std::cout << "Error opening file for input";
		return 0;
	}
	else
	{
		std::cout << "This is what you entered:" << std::endl << std::endl;
		Human person;
		file.read(reinterpret_cast<char *>(&person), sizeof(person));
		while(!file.eof())
		{
			std::cout << "Name: " << person.name << std::endl;
			std::cout << "Age: " << person.age << std::endl;
			std::cout << "Salary: " << person.salary << std::endl;
			std::cout << "Dream Job: " << person.dreamJob << std::endl;
			std::cout << "Total Years Worked: " << person.yearsWorked << std::endl;
			
			std::cout << std::endl << "Press enter to see the next person: ";
			char ch;
			std::cin.get(ch);
			std::cout << std::endl;
			
			file.read(reinterpret_cast<char *>(&person), sizeof(person));
		}
		std::cout << "Nothing left to display..." << std::endl << std::endl;
		file.close();
	}
	
	file.open("data3.txt", std::ios::in | std::ios::binary);              // opens in read mode
	
	Human person;
	const int POS = 3;
	long int position[POS] = {2, 0, 1};                                   // order to read objects in
	
	for(int i = 0; i < POS; ++i)
	{
		file.seekg(sizeof(person) * position[i], std::ios::beg);          // sets file position to proper byte location
		file.read(reinterpret_cast<char *>(&person), sizeof(person));     // reads starting from properly set byte
		
		std::cout << "Here is the information of person " << position[i] + 1 << ":" << std::endl;
		std::cout << "Name: " << person.name << std::endl;
		std::cout << "Age: " << person.age << std::endl;
		std::cout << "Salary: " << person.salary << std::endl;
		std::cout << "Dream Job: " << person.dreamJob << std::endl;
		std::cout << "Total Years Worked: " << person.yearsWorked << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "The current byte number being read is: byte " << file.tellg() << std::endl;
	file.seekg(0L, std::ios::end);
	std::cout << "The total number of bytes in the file is: " << file.tellg() << std::endl << std::endl;
	
	file.close();
	
	file.open("data3.txt", std::ios::in | std::ios::out | std::ios::binary);
	int userNum;
	
	std::cout << "Which record would you like to change: ";
	std::cin >> userNum;
	std::cout << std::endl;
	
	file.seekg(sizeof(person) * (userNum - 1), std::ios::beg);
	file.read(reinterpret_cast<char *>(&person), sizeof(person));
	
	std::cout << "Here is the information of person " << userNum << ":" << std::endl;
	std::cout << "Name: " << person.name << std::endl;
	std::cout << "Age: " << person.age << std::endl;
	std::cout << "Salary: " << person.salary << std::endl;
	std::cout << "Dream Job: " << person.dreamJob << std::endl;
	std::cout << "Total Years Worked: " << person.yearsWorked << std::endl;
	std::cout << std::endl;
	
	std::cout << "Enter the new information:" << std::endl;
	std::cout << "Name: ";
	std::cin.ignore();
	std::cin.getline(person.name, SIZE);
	std::cout << "Age: ";
	std::cin >> person.age;
	std::cout << "Salary: ";
	std::cin >> person.salary;
	std::cout << "Dream Job: ";
	std::cin.ignore();
	std::cin.getline(person.dreamJob, SIZE);
	std::cout << "Total years worked: ";
	std::cin >> person.yearsWorked;
	
	file.seekg(sizeof(person) * (userNum - 1), std::ios::beg);
	file.write(reinterpret_cast<char *>(&person), sizeof(person));
	
	system("pause");
	return 0;
}

bool openFileIn(std::fstream &file, std::string name)
{
	file.open(name, std::ios::in);
	
	if(file.fail())
	{
		return false;
	}
	else
	{
		return true;
	}
}