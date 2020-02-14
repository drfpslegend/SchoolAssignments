#include <iostream>
#include <fstream>
#include <iomanip>

const int SIZE = 51;
struct Cat
{
	char name[SIZE];
	int age;
};

int main()
{
	int numCats = 3;
	std::fstream file("critters.bin", std::ios::binary | std::ios::out);
	std::cout << "Enter " << numCats << " cat records:" << std::endl;
	for (int i = 0; i < numCats; ++i)
	{
		Cat kitty;
		std::cout << "Enter information about a cat:" << std::endl;
		std::cout << "Name: ";
		std::cin.getline(kitty.name, SIZE);
		std::cout << "Age: ";
		std::cin >> kitty.age;
		std::cin.ignore();
		file.write(reinterpret_cast<char *>(&kitty), sizeof(kitty));
	}
	std::cout << "Records written to file." << std::endl;
	file.close();
	
	std::cout << std::endl;
	
	file.open("critters.bin", std::ios::binary | std::ios::out | std::ios::app);
	Cat kitty;
	std::cout << "Enter one more cat:" << std::endl;
	std::cout << "Name: ";
	std::cin.getline(kitty.name, SIZE);
	std::cout << "Age: ";
	std::cin >> kitty.age;
	std::cin.ignore();
	file.write(reinterpret_cast<char *>(&kitty), sizeof(kitty));
	file.close();
	
	std::cout << std::endl;
	
	file.open("critters.bin", std::ios::binary | std::ios::in);
	std::cout << "Here is a list of all cats: " << std::endl;
	file.read(reinterpret_cast<char *>(&kitty), sizeof(kitty));
	while (!file.eof())
	{
		std::cout << std::setw(20) << std::left << kitty.name;
		std::cout << std::setw(20) << std::left << kitty.age;
		std::cout << std::endl;
		file.read(reinterpret_cast<char *>(&kitty), sizeof(kitty));
	}
	std::cout << std::endl;
	file.close();
	
	system("pause");
	return 0;
}