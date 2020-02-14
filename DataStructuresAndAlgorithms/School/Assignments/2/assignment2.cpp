// Kevin Holst, kevin_holst1@my.vcccd.edu

#include <iostream>

using namespace std;

int main()
{
	 int x = 5; // sets up a variable named x, which has a memory address of &x.
	 cout << "x is now 5" << endl;
	 
	 int *p = &x; // declares a pointer that points to an int, which has a memory address of &p.  Initializes p to point to &x.
	 cout << "p now points to x" << endl;
	 
	 *p = 6; // assigns the value of 6 to the contents of the memory location stored in p.
	 cout << "*p, which is x, is now 6" << endl;
	 
	 int **q = &p; // declares a pointer that points to a pointer that points to an int, which has a memory address of &q.  Initializes q to point to &p.
	 cout << "q now points to p" << endl;
	 
	 int ***r = &q; // declares a pointer that points to a pointer that points to a pointer that points to an int, which has a memory address of &r.  Initializes r to &q.
	 cout << "r now points to q" << endl;
	 
	 cout << "x, which is 6: " << x << endl; // displays 6.
	 
	 cout << "&x: " << &x << endl; // displays &x.
	 
	 cout << "*p, which is x, which is 6: " << *p << endl; //  dereferences p, which returns x, displaying the value of 6.
	 
	 cout << "*q, which is p, which is &x: " << *q << endl; // dereferences q, which returns p, displaying &x.
	 
	 cout << "**q, which is *p, which is x, which is 6: " << **q << endl; // dereferences q, which returns p, then dereferences p, which returns x, displaying 6.
	 
	 cout << "**r, which is *q, which is p, which is &x: " << **r << endl; // dereferences r, which returns q, then dereferences q, which returns p, displaying &x.
	 
	 cout << "***r, which is **q, which is *p, which is x, which is 6: " << ***r << endl; // dereferences r, which returns q, then dereferences q, which returns p, then dereferences p, which returns x, displaying 6.
	 
	 ***r = 10; // dereferences r, which returns q, then dereferences q, which returns p, then dereferences p, which returns x, assigning the value of 10 to x.
	 cout << "***r, which is **q, which is *p, which is x, is now 10" << endl;
	 
	 cout << "x, which is 10: " << x << endl; // displays 10.
	 
	 **q = *p + 2; // dereferences q, which returns p, then dereferences p, which returns x, assigning the value of *p (which is x, which is 10) + 2 to x.
	 cout << "**q, which is *p, which is x, is now *p + 2, which is x + 2, which is 10 + 2, which is 12" << endl;
	 
	 cout << "x, which is 12: " << x << endl; // displays 12.
	 
	 system("pause");
	 return 0;
}