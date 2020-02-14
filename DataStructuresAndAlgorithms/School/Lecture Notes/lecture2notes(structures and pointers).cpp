#include <iostream>
#include <string>

// abstract data types (ADT): structs and pointers.
// an ADT is a programmer-defined data type, versus something like int, double, char, which are primitive data types.
// data types: type of data we can store and type of operations we are allowed to perform.
// abstraction: a definition that captures general characteristics without details.
// structures: c++ provides the capability to let multiple variables be grouped together.

struct Student // <- structure tag.
{
	int studentID;
	string name;                  // <- structure members.
	double gpa;
	short yearsInSchool;
};

// a struct declaration doesn't allocate memory or create variables.
Student st1; // <- an instance of a Student abstract data type.
Student bill;
double rate; // <- same declaration as a primitive data type.
cout << st1.gpa << endl; // <- prints the gpa member variable.
cin >> st1.studentID; // <- member variables can be updated.
st1.gpa = 3.9;
getline(cin, st1.name);

struct Payroll
{
	int employeeID;
	string name;
	double hours;
	double payrate;
	double pay;
};

Payroll p1;
p1.payrate = 20;
p1.hours = 21;
p1.pay = p1.payrate * p1.hours;
cout << p1; // <- generates an error.
cout << p1.name << endl;
cout << bill .gpa << endl;
if (bill == p1) {} // <- generates an error.  Cannot compare data of different types directly.
if (bill.gpa == p1.gpa) {} // this is valid, because we are comparing two doubles with each other.

Student s = {12345, "Joan", 3.6, 3}; // <- initializes a struct upon declaration.
s.name = "Joanna";
s.gpa = 3.65;

Student david = {9876}; // <- can only initialize some of the member variables.  *note: cannot skip over members, they must be in order or of the same type.

// arrays of structures: structures can be defined as an arrays.

const int NUM = 100;
Student studentList[NUM];

// we can use index notation to access structure members.

cout << studentList[9].studentID << endl;
cout << studentList[9].gpa << endl;

// nested structures: a structure can contain other structures as its members.

struct personInfo
{
	string name, address, city;
};

struct Student
{
	string studentID;
	personInfo pData;
	short yearsInSchool;
	double gpa;
};

Student s;
s.pData.name = "Sara";
s.pData.city = "Moorpark";

// structures can be used as function arguments.

showData(p1); // <- function call with a structure as an argument.

// can use a reference parameter if function needs to modify the contents of the structure variable.

void showData (Student s)
{
	cout << s.name << endl;
	cout << s.gpa << endl;
}

void showItem (const InventoryItem & p)
{
	cout << "Part number: " << p.partNum << endl;
	...
	cout << "Price is: " << p.price << endl;
}

// returning a struct re from a function:  function can return a structure, as long as its return type is that of the structure.

Student getStudentData()
{
	Student temp;
	cin >> temp.name;
	cin >> temp.gpa;
	...
	
	return temp;
}

// pointers to structires: structure variables have addresses, which can be assigned to pointer variables.

Student * studentptr;
studentptr = &s;
cout << (*sptr).gpa << endl;
cout << sptr->gpa << endl; // <- *note: "->" is the structure pointer operator.
sptr->studentID = 12345;

// we can dynamically allocate structures with pointers.

Circle * circleptr = nullptr;
circleptr = new Circle;
cptr->radius = 10;

// array of structures.

Circle * circleArray = nullptr;
circleArray = new Circle[20];
for (int i = 0; i < 20; ++i)
{
	cout << circleArray[i].radius;
}

// pointers: each variable in the program is stored at a unique address.
// use "&" to obtain the address of a variable.

int num = 35;
cout << &num << endl; // <- prints address of num in hexidecimal.

// pointer variable: a variable that holds the address of a memory location.
// pointers can then access the data that is stored at that address.
// pointers are more low-level than references.

int * iptr; // <- pointer which can hold the address of a memory location that can hold an integer value.

 // "*" is called the indirection operator.  It defererences the pointer to obtain the data stored at that memory location.
 
 int x = 25;
 int * iptr = &x;
 cout << x << endl; // displays 25.
 cout << *iptr << endl; // displays 25 as well.
 *iptr = 100;
 cout << x << endl; // displays 100.
 cout << *iptr << endl; // displays 100.
 
 // relationship between arrays and pointers
 
 int vals[] = {4, 7, 11};
 cout << vals; // displays address of the first element of vals.
 cout << vals[0]; // displays 4.
 cout << *vals; // displays 4 as well.
 
 // pointers can be used as array names.
 
 int *itpr = vals;
 cout << iptr[1]; // displays 7.
 cout << *(iptr + 1); // displays 7.
 cout << *(iptr + 2); // displays 11.
 cout << *iptr + 2; // displays *iptr (4) + 2 = 6.
 
 // array[i] is equivalent to *(array  + i).
 
 // pointer opperations.
 
 int vals[] = {4, 7, 11};
 int *iptr = vals;
 ++iptr; // points to &(vals[1]).
 --iptr; // points to &(vals[0]).
 iptr+= 2; // points to &(vals[2]).
 cout << iptr - val; // gives the difference between iptr and vals (in bytes).
 
 // initializing pointers.
 
 int num, *iptr = &num;
 int vals[3], *iptr = vals;
 
 double cost = 2.75;
 int *iptr = &cost; // <- error: types do not agree.
 cout << *iptr; //  <- error (from previous error).
 
 // comparing pointers.
 
 if (ptr1 == ptr2) {} // checks if two addresses are equal.
 if (*ptr1 == *ptr2) {} // checks if contents of two pointers are equal.
 
 // pointers as function parameters.
 
 void getNum(int *ptr); // function prototype.
 getNum(&num); // uses address of num as parameter.
 cin >> *ptr;
 
 // ex.
 
 int main()
 {
	 int num1 = 2, num2 = 5;
	 swap(&num1, &num2);
	 
	 return 0;
 }
 
 void swap(int *x, int *y)
 {
	 int temp = *x;
	 *x = *y*;
	 *y = temp;
 }
 
 // ex.
 
 int main()
 {
	 int x = 5; // address 225
	 int *p = &x; // address 215
	 *p = 6; // changes x.
	 int **q = &p; // address 205
	 int ***r = &q; // address 195
	 cout << *p << endl; // 6
	 cout << *q << endl; // 225
	 cout << **q << endl; // 6
	 cout << **r << endl; // 225
	 cout << ***r << endl; // 6
	 ***r = 10;
	 cout << x << endl; // 10
	 **q = *p + 2;
	 cout << x << endl; // 12
	 
	 return 0;
 }