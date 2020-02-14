#include <iostream>

void populateArrayPtr(int arr[], int * arrPtr[], const int size);
void arrSelectSort(int * arr[], const int size);
void showArray(int arr[], const int size);
void showArrayPtr(int * arr[], const int size);

int main()
{
	const int NUM_DONATIONS = 10;
	int donations[NUM_DONATIONS] = {69, 27, 18, 49, 100, 85, 30, 50, 25, 75};
	int * arrPtr[NUM_DONATIONS] = {nullptr};
	
	populateArrayPtr(donations, arrPtr, NUM_DONATIONS);	
	
	arrSelectSort(arrPtr, NUM_DONATIONS);
	
	showArray(donations, NUM_DONATIONS);
	
	showArrayPtr(arrPtr, NUM_DONATIONS);
	
	system("PAUSE");
	return 0;
}

void populateArrayPtr(int arr[], int * arrPtr[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		arrPtr[i] = &arr[i];
	}
	
	return;
}

void arrSelectSort(int * arr[], const int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = i; j < size; ++j)
		{
			if(*arr[j] < *arr[i])
			{
				int * temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	return ;
}

void showArray(int arr[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << std::endl;
	
	return;
}

void showArrayPtr(int * arr[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << *arr[i] << " ";
	}
	std::cout << std::endl << std::endl;
	
	return;
}