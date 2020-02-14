#include <iostream>
using namespace std;

class Circle
{
	private:
		double radius;
	public:
		Circle() // default constructor
		{
			radius = 0.0;
		}
		Circle(double r) // overloaded constructor
		{
			radius = r;
		}
		Circle(Circle& t) // copy constructor
		{
			radius = t.radius;
		}
		void setRadius(double r) // setter
		{
			radius = r;
		}
		double getRadius() // getter
		{
			return radius;
		}
		double getArea() // member function
		{
			return 3.14159265 * radius * radius;
		}
		~Circle() // destructor
		{
			
		}
};

int main()
{
	Circle c1; // default constructor
	Circle c2(2.7); // overloaded constructor
	Circle c3(c2); // copy constructor
	
	cout << c1.getArea() << endl;
	cout << c2.getArea() << endl;
	cout << c3.getArea() << endl;
	
	return 0;
}

// Inheritance: a class can inherit from another class
// Base(Parent/Super) class
// Derived(Child/Sub) class
// Inheritance means there is an "is a" relationship between one or more base classes and one or more derived classes.
// Composition means there is a "has a" relationship between one or more classes.  ex: a person has a name
// Inheritance is a specialization or refining of a base class into one or more derived classes
// Multiple inheritance means when a class inherits from two or more base classes

class Shape
{
	protected:
		double width, height;
	public:
		Shape(double a, double b)
		{
			weight = a;
			height = b;
		}
};

class Rectangle : public Shape
{
	public:
		Rectangle(double x, double y) : Shape(x, y) { }
		double area()
		{
			return width*height;
		}
};

class Triangle : public Shape
{
	public:
		Triangle(double x, double y) : Shape(x, y) { };
		double area()
		{
			return width*height/2;
		}
};

int main()
{
	Rectangle rect(2.6, 5.9);
	Triangle tri(1.4, 8.3);
	
	cout << rect.area() << endl;
	cout << tri.area() << endl;
	
	return 0;
}

class Rectangle
{
	private:
		double length, width;
	public:
		Rectangle()
		{
			length = 0.0;
			width = 0.0;
		}
		Rectangle(double l, double w)
		{
			length = l;
			width = w;
		}
		double area()
		{
			return length*width;
		}
};

class Box : public Rectangle
{
	private:
		double height;
	public:
		Box()
		{
			height = 0.0;
		}
		Box(double l, double w, double h) : Rectangle(l, w)
		{
			height = h;
		}
		double volume()
		{
			return area()*height;
		}
};

int main()
{
	Box b1;
	Box b2(4, 8, 5);
	
	cout << b1.volume() << endl;
	cout << b2.volume() << endl;
	
	return 0;
}

// Function overriding

class Mother
{
	public:
		void display()
		{
			cout << "Mother display function" << endl;
		}
};

class Daughter : public Mother
{
	public:
		void display()
		{
			cout << "Daughter display function" << endl;
			Mother::display(); // calls the Mother display function
		}
};

int main()
{
	Mother Sara;
	Sara.display();
	
	Daughter Rita;
	Rita.display();
	
	return 0;
}

// Virtual functions
// The "virtual" keyword tells the compiler to wait to define it until it is called, "automatically" in a derived class.
// If a function is virtual and a new definition of the function is given in a derived class, then for any object of the derived class,
// 		that object will always use the new definition.  This is called late/dynamic binding.

// Pointer of base class

class Shape
{
	protected:
		double width, height;
	public:
		void set_data(double a, double b)
		{
			width = a;
			height = b;
		}
		virtual double area() // gets overridden in the Rectangle class
		{
			return 0.0;
		}
};

class Rectangle : public Shape
{
	public:
		double area()
		{
			return width * height;
		}
};

int main()
{
	Shape * sptr;
	Rectangle rect;
	
	sptr = &rect; // makes sptr point to the rect object
	sptr->set_data(5, 7);
	
	cout << sptr->area() << endl; // will not work unless the area function is defined as virtual in the base class
	// displays an error because a pointer of a base class cannot point to member functions defined in a derived class.  Instead, we can typecast it to the derived class.
	
	cout << static_cast<Rectangle*>(sptr)->area() << endl; // displays area properly because sptr was statically cast to a rectangle object
	
	return 0;
}

// The advantage of having a virtual function is that you are able to access the functions of a derived class with a pointer variable of a base class

// Early binding example

class Base
{
	public:
		void show()
		{
			cout << "Base class." << endl;
		}
};

class Derived : public Base
{
	public:
		void show()
		{
			cout << "Derived class." << endl;
		}
};

int main()
{
	Base b1;
	Derived d1;
	
	b1.show(); // Early/Static binding
	d1.show();
	
	return 0;
}

// Late binding example

class Base
{
	public:
		virtual void show()
		{
			cout << "Base class." << endl;
		}
};

class Derived : public Base
{
	public:
		void show()
		{
			cout << "Derived class." << endl;
		}
};

int main()
{
	Base * b;
	Derived d;
	
	b = &d;
	b->show(); // Late/Dynamic binding.  Displays the output of the overridden member function in the derived class
	
	return 0;
}

// Multiple inheritance example

class Polygon
{
	protected:
		int width, height;
	public:
		Polygon(int a, int b) : width(a), height(b) {}
};

class Output
{
	public:
		void print(int i)
		{
			cout << i << endl;
		}
};

class Rectangle : public Polygon, public Output
{
	public:
		Rectangle(int a, int b) : Polygon(a, b) {}
		int area()
		{
			return width * height;
		}
};

class Triangle : public Polygon, public Output
{
	public:
		Triangle(int a, int b) : Polygon(a,b) {}
		int area()
		{
			return width * height / 2;
		}
};

int main()
{
	Rectangle rect(4, 5);
	Triangle tri(6, 8);
	
	rect.print(rect.area());
	tri.print(tri.area());
	
	return 0;
}

// Abstract classes and pure virtual functions

virtual double area() = 0; // pure virtual function definition

// An abstract class is a class that has at least one pure virtual function
// You cannot create an object of an abstract class

class Shape
{
	public:
		virtual void draw() = 0;
};

class Circle : public Shape
{
	public:
		void print()
		{
			cout << "I am a circle." << endl;
		}
};

class Rectangle : public Shape
{
	public:
		void draw()
		{
			cout << "Drawing a Rectangle." << endl;
		}
};

int main()
{
	Rectangle rect;
	Circle c;
	
	rect.draw(); // prints "Drawing a Rectangle." to the screen
	c.print(); // Results in an error, because the virtual draw() function was not overridden in the Circle class
	
	return 0;
}