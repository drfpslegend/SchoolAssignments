#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <thread>

using namespace std;

void writeRoots();
void writeSquares();

int main()
{
	clock_t start;
	clock_t finish;
	
	start = clock();
	
	writeRoots();
	writeSquares();
	
	finish = clock();
	
	cout << "Runtime (normal) = " << (finish - start)/CLK_TCK << " seconds" << endl << endl;
	
	/*start = clock();
	
	thread t1(writeRoots);
	thread t2(writeSquares);
	
	t1.join();
	t2.join();
	
	finish = clock();
	
	cout << "Runtime (multithreading) = " << (finish - start)/CLK_TCK << " seconds" << endl << endl;*/
	
	system("pause");
	return 0;
}

void writeRoots()
{
	fstream file("roots.txt", ios::out);
	for (int i = 1; i <= 1000000; ++i)
	{
		file << sqrt(i);
	}
	file.close();
}

void writeSquares()
{
	fstream file("squares.txt", ios::out);
	for (int i = 1; i <= 1000000; ++i)
	{
		file << i*i;
	}
	file.close();
}