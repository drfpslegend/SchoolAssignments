#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

template <class T>
class vector
{
	private:
		T * array;
		int numElements;
		void memError();
		void subError();
	public:
		vector();
		vector(int);
		vector(const vector &);
		~vector();
		int size();
		T at(int);
		T & operator[](const int &);
};

template <class T>
void vector<T>::memError()
{
	cout << "Error: Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

template <class T>
void vector<T>::subError()
{
	cout << "Error: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

template <class T>
vector<T>::vector()
{
	array = nullptr;
	numElements = 0;
}

template <class T>
vector<T>::vector(int n)
{
	try
	{
		array = new T [n];
		numElements = n;
	}
	catch (bad_alloc)
	{
		memError();
	}
	
	for (int i = 0; i < numElements; ++i)
	{
		*(array + i) = 0;
	}
}

template <class T>
vector<T>::vector(const vector & v)
{
	try
	{
		array = new T [v.size()];
		numElements = v.size();
	}
	catch(bad_alloc)
	{
		memError();
	}
	
	for (int i = 0; i < numElements; ++i)
	{
		*(array + i) = *(v.array + i);
	}
}

template <class T>
vector<T>::~vector()
{
	if (numElements > 0)
	{
		delete [] array;
	}
}

template <class T>
int vector<T>::size()
{
	return numElements;
}

template <class T>
T vector<T>::at(int i)
{
	if (i < 0 || i >= numElements)
	{
		subError();
	}
	else
	{
		return array[i];
	}
}

template <class T>
T & vector<T>::operator[](const int & i)
{
	if (i < 0 || i >= numElements)
	{
		subError();
	}
	else
	{
		return array[i];
	}
}

#endif