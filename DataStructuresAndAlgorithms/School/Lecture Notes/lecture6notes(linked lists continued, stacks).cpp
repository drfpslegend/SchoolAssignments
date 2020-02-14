// linked lists continued

// linked list functions include:
// 	adding data at the end of the list
// 	adding data at the beginning of the list
// 	adding data at a position within the list
// 	adding data into a sorted list
// 	sorting a list
// 	deleting data from the end of the list
// 	deleting data from the beginning of the list
// 	deleting data from a position within the list
// 	deleting all instances of a value from the list
// these all have fairly straight forward implentations, which can be written with or without a tail data member

// linked list implementation using only classes

#include <iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node * next;
};

class LinkedList
{
	private:
		Node * head;
	public:
		LinkedList();
		~LinkedList();
		void addNode(int);
		void display();
};

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList();
{
	
}

void LinkedList;addNode(int n)
{
	Node * temp = new Node;
	temp->data = n;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		Node * current = head;
		while (current->next != hull)
		{
			current = current->next;
		}
		current->next = temp;
	}
}

void LinkedList::display()
{
	if (head == nullptr)
	{
		cout << "List is empty." << endl;
	}
	else
	{
		Node * current = head;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
}

int main()
{
	LinkedList * list1 = new LinkedList;
	list1->addNode(100);
	list1->addNode(200);
	list1->addNode(300);
	list1->addNode(400);
	list1->display();
	delete list1;
	
	return 0;
}

// stacks

// memory to be allocated to a program is broken into 5 parts: heap, stack, main, static/global variables/functions, program instructions
// the heap is for dynamic memory allocation
// the stack is where all the global variables and all the information about function calls and local variables are located
// the main is for when we call a function in main, we call the stack frame of that function

// a stack is an abstract data type that stores and retrieves items in a last-in-first-out manner
// like arrays and linked lists, stacks hold a sequence of elements
// unlike arrays and linked lists, stacks are last-in-first-out structures
// examples: a stack of plates or books, when a function is called it saves the return address in the program on the stack, functions create local variables on the stack
// some calculators use stacks for mathematical operations
// 2 types of stacks: static and dynamic stacks.
// static stacks are implemented with arrays, and dynamic stacks are implemented with linked lists

// stack operations:
// push - data is added to the top of the stack
// pop - data is removed from the top of the stack
// isEmpty - checks if the stack is empty
// isFull - checks if the stack is full

// static class implementation

class IntStack
{
	private:
		int * stackArray;
		int size;
		int top; // index for top of stack
	public:
		IntStack(int);
		IntStack(const IntStack &);
		~IntStack();
		void push(int);
		void pop(int &);
		bool isFull();
		bool isEmpty();
		void display();
};

IntStack::IntStack(int s)
{
	stackArray = new int [s];
	size = s;
	top = -1;
}

IntStack::IntStack(const IntStack & stackObj)
{
	
}

IntStack::~IntStack()
{
	delete [] stackArray;
}

void IntStack::push(int n)
{
	if (isFull())
	{
		cout << "The stack is full." << endl;
	}
	else
	{
		++top;
		stackArray[top] = n;
	}
}

void IntStack::pop(int & ret)
{
	if (isEmpty())
	{
		cout << "The stack is empty." << endl;
	}
	else
	{
		ret = stackArray[top];
		--top;
	}
}

bool IntStack::isFull() const
{
	if (top == size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IntStack::isEmpty() const
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void IntStack::display()
{
	int t = top;
	while(t >= 0)
	{
		cout << stackArray[t] << endl;
		--t;
	}
}

// dynamic stacks use linked lists to store their data
// two advantages: no need for a size variable, and it will never be full as long as there is free memory

// dynamic stack implementation

class DynamicStack
{
	private:
		struct Node
		{
			int data;
			Node * next;
		};
		Node * top;
	public:
		DynamicStack();
		~DynamicStack();
		void push(int);
		void pop(int &);
		bool isEmpty();
};

DynamicStack::DynamicStack()
{
	top = nullptr;
}

DynamicStack::~DynamicStack()
{
	Node * temp = top;
	Node * nextptr;
	while (temp != nullptr)
	{
		nextptr = temp->next;
		delete temp;
		temp = nextptr;
	}
}

void DynamicStack::push(int n)
{
	Node * temp = new Node;
	temp->data = n;
	temp->next = nullptr;
	if (isEmpty())
	{
		top = temp;
	}
	else
	{
		temp->next = top;
		top = temp;
	}
}

void DynamicStack::pop(int & ret)
{
	if (isEmpty())
	{
		cout << "The stack is empty." << endl;
	}
	else
	{
		Node * temp = top->next;
		ret = top->data;
		delete top;
		top = temp;
	}
}

bool DynamicStack::isEmpty()
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}