#include <iostream>

class base
{
	protected:
		int x;
};

class derived: public base
{
	public:
		derived();
		void incrementX();
		void print();
};

derived::derived()
{
	x = 0;
}

void derived::incrementX()
{
	++x;
}

void derived::print()
{
	std::cout << x << std::endl;
}

int main()
{
	derived temp;
	temp.incrementX();
	temp.print();
	
	system("pause");
	return 0;
}