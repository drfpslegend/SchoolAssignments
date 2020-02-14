#include <iostream>
#include <iomanip>

struct Box
{
	int idNumber;
	double length;
	double width;
	double height;
	Box * next;
};

void getBoxes(Box * &);
void displayBoxes(Box * &);
void deleteBox(Box * &);

int main()
{
	Box * listStart = new Box;
	listStart->next = nullptr;
	
	getBoxes(listStart);
	displayBoxes(listStart);
	std::cout << std::endl;
	
	deleteBox(listStart);
	displayBoxes(listStart);
	std::cout << std::endl;
	
	system("pause");
	system("cls");
	return 0;
}

void getBoxes(Box * &listStart)
{
	Box * currentBox = listStart;
	char cont = 'y';
	
	while(std::tolower(cont) == 'y')
	{
		std::cout << "Enter the dimensions of the box...";
		std::cout << std::endl;
		std::cout << "ID Number: ";
		std::cin >> currentBox->idNumber;
		std::cout << "Length: ";
		std::cin >> currentBox->length;
		std::cout << "Width: ";
		std::cin >> currentBox->width;
		std::cout << "Height: ";
		std::cin >> currentBox->height;
		
		std::cout << std::endl;
		std::cout << "Enter another box? (y/n): ";
		std::cin >> cont;
		std::cout << std::endl;
		
		if(std::tolower(cont) == 'y')
		{
			currentBox->next = new Box;
			currentBox = currentBox->next;
			currentBox->next = nullptr;
		}
	}
	
	return;
}

void displayBoxes(Box * &listStart)
{
	Box * currentBox = listStart;
	int width = 10;
	
	system("cls");
	
	std::cout << "Here are your boxes:" << std::endl << std::endl;
	std::cout << std::setw(width) << std::left << "ID";
	std::cout << std::setw(width) << std::left << "Length";
	std::cout << std::setw(width) << std::left << "Width";
	std::cout << std::setw(width) << std::left << "Height";
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	
	while (true)
	{
		std::cout << std::setw(width) << std::left << currentBox->idNumber;
		std::cout << std::setw(width) << std::left << currentBox->length;
		std::cout << std::setw(width) << std::left << currentBox->width;
		std::cout << std::setw(width) << std::left << currentBox->height;
		std::cout << std::endl;
		
		if (currentBox->next == nullptr)
		{
			break;
		}
		currentBox = currentBox->next;
	}
	
	return;
}

void deleteBox(Box * &listStart)
{
	Box * previousBox;
	Box * currentBox = listStart;
	Box * nextBox = currentBox->next;
	int boxID;
	
	std::cout << "Enter the ID number for the box that you want to delete: ";
	std::cin >> boxID;
	
	while (boxID != currentBox->idNumber)
	{
		previousBox = currentBox;
		currentBox = nextBox;
		nextBox = currentBox->next;
	}
	
	if (currentBox == listStart)
	{
		Box * temp = currentBox;
		listStart = currentBox->next;
		delete temp;
	}
	else
	{
		Box * temp = currentBox;
		previousBox->next = nextBox;
		delete temp;
	}
	
	return;
}