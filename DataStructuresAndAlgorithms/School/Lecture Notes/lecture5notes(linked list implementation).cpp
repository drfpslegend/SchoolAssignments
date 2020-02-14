// singly linked list: 1 data, 1 pointer to the next node.

struct Node
{
	int data;
	Node * next;
}

// doubly linked list: 1 data, 1 pointer to the next node, 1 pointer to the previous node.

struct Node
{
	int data;
	Node * next;
	Node * prev;
}

// circular singly linked list: same as singly linked list but with the last node pointing to the first node instead of a null pointer.
// circular doubly linked list: same as doubly linked list but with the last node pointing to the first node instead of a null pointer, and the previous pointer of the first node pointing to the last node.

// implementation of a linked list.

struct Node
{
	int data;
	Node * next;
}

int main()
{
	Node * head;
	Node * current;
	Node * temp; // node pointer which points a new node.
	
	temp = new Node;
	temp->data = 2;
	temp->next = nullptr;
	current = temp;
	head = temp; // head and current are pointing to whatever temp is pointing to.
	
	temp = new Node;
	temp->data = 4;
	temp->next = nullptr;
	curernt->next = temp;
	current = temp;
	
	temp = new Node;
	temp->data = 8;
	temp->next = nullptr;
	current->next = temp;
	current = temp;
	
	return 0;
}

// linked list implementation using a class.
#include <cstdlib>
#include <iostream>

using namespace std;

class List
{
	private:
		struct Node
		{
			int data;
			Node * next;
		};
		Node * head;
		Node * tail;
		int size;
	public:
		List();
		void addNodeHead(int);
		void addNodeTail(int);
		void insertNode(int, int);
		int countNodes();
		int countValues(int);
		void deleteNode(int);
		void deleteValue(int);
		void displayList();
};

List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

void List::addNodeHead(int val)
{
	Node * temp = new Node;
	temp->data = val;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		++size;
	}
	else
	{
		temp->next = head;
		head = temp;
		++size;
	}
}

void List::addNodeTail(int val)
{
	Node * temp = new Node;
	temp->data = val;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		++size;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		++size;
	}
}

void List::insertNode(int pos, int val)
{
	if (0 <= pos && pos <= size)
	{
		if (pos == 0)
		{
			addNodeHead(val);
		}
		else if (pos == size)
		{
			addNodeTail(val);
		}
		else
		{
			Node * temp = new Node;
			temp->data = val;
			temp->next = nullptr;
			Node * prev = head;
			for (int i = 0; i < pos - 1; ++i)
			{
				prev = prev->next;
			}
			temp->next = prev->next;
			prev->next = temp;
			++size;
		}
	}
	else
	{
		cout << "Out of bounds!" << endl;
	}
}

void List::deleteNode(int pos)
{
	Node * temp = head;
	Node * prev = nullptr;
	for(int i = 0; i < pos; ++i)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	delete temp;
}

void List::deleteValue(int val)
{
	Node * temp = head;
	int i = 0;
	while (temp != nullptr)
	{
		if (temp->data == val)
		{
			deleteNode(i);
		}
		temp = temp->next;
		++i;
	}
}

void List::displayList()
{
	Node * current = head;
	while(current != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

int List::countNodes()
{
	Node * nodeCounter = head;
	int counter = 0;
	while (nodeCounter != nullptr)
	{
		++counter;
		nodeCounter = nodeCounter->next;
	}
	return counter;
}

int List::countValues(int val)
{
	Node * nodeCounter = head;
	int counter = 0;
	while (nodeCounter != nullptr)
	{
		if (nodeCounter->data == val)
		{
			++counter;
		}
		nodeCounter = nodeCounter->next;
	}
	return counter;
}

int main()
{
    List myInts;
    myInts.addNodeHead(2);
    myInts.addNodeHead(1);
    myInts.addNodeTail(4);
    myInts.insertNode(2, 3);
    myInts.addNodeTail(1);
    
    myInts.displayList();
    cout << "-----" << endl;
    myInts.deleteNode(4);
    myInts.displayList();
    cout << "-----" << endl;
    myInts.deleteNode(1);
    myInts.displayList();
    cout << "-----" << endl;
	myInts.deleteValue(4);
	myInts.displayList();
    
    return 0;
}