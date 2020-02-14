#include <iostream>

using namespace std;

class LinkedList
{
	private:
		struct Node
		{
			int data;
			Node * next;
		};
		Node * head;
		Node * tail;
	public:
		LinkedList();
		void addNode(int);
		void printList();
};

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void LinkedList::addNode(int n)
{
	if (head == nullptr || tail == nullptr)
	{
		Node * temp = new Node;
		temp->data = n;
		temp->next = nullptr;
		head = temp;
		tail = temp;
	}
	else
	{
		Node * temp = new Node;
		temp->data = n;
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
	}
}

void LinkedList::printList()
{
	Node * temp = head;
	while (temp != nullptr)
	{
		if (temp->next != nullptr)
		{
			cout << temp->data << ", ";
		}
		else
		{
			cout << temp->data;
		}
		temp = temp->next;
	}
}

int main()
{
	LinkedList myList;
	
	cout << "Adding the numbers 1 - 20 into the list ..." << endl << endl;
	
	for (int i = 1; i <= 20; ++i)
	{
		cout << "Adding the integer " << i << " to the list ..." << endl;
		myList.addNode(i);
		cout << "Here is the current list:" << endl;
		myList.printList();
		cout << endl << endl;
	}
	
	system("pause");
	return 0;
}