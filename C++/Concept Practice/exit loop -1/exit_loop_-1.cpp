#include <iostream>
#include <string>

int main()
{
	struct Box
	{
		int userID;
		int length;
		int width;
		int height;
	};
	
	Box box;
	std::string answer = "";
	
	while (answer != "-1")
	{
		std::cout << "Enter user id: ";
		std::cin >> box.userID;
		std::cout << "Enter length: ";
		std::cin >> box.length;
		std::cout << "Enter width: ";
		std::cin >> box.width;
		std::cout << "Enter height: ";
		std::cin >> box.height;
		
		std::cin.ignore();
		std::getline(std::cin, answer);
	}
	
	system("pause");
	return 0;
}