#include <iostream>
#define MAX_LEGNTH 10

int BinarySearch(int array[], int sizeOfArray, int value);
int BinarySearch_B(int array[], int sizeOfArray, int value);
int BinarySearch_C(int array[], int sizeOfArray, int value);

int main()
{
	int list[MAX_LEGNTH] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10 };
	int result = BinarySearch(list, MAX_LEGNTH, 11);
	std::cout << result << std::endl;
	result = BinarySearch(list, MAX_LEGNTH, 7);
	std::cout << result << std::endl;
	result = BinarySearch_B(list, MAX_LEGNTH, 6);
	std::cout << result << std::endl;
	result = BinarySearch_C(list, MAX_LEGNTH, 6);
	std::cout << result << std::endl;
}

int BinarySearch(int array[], int sizeOfArray, int value)
{
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	while (moreToSearch)
	{
		midPoint = (first + last) / 2;
		
		if (array[midPoint] > value)
		{
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] < value)
		{
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else
		{
			return midPoint;
		}
	}

	return -1;
}

int BinarySearch_B(int array[], int sizeOfArray, int value)
{
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	while (moreToSearch)
	{
		midPoint = (first + last) / 2;

		if (array[midPoint] > value)
		{
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] < value)
		{
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else
		{
			return array[midPoint];
		}
	}

	return array[first-1];
}

int BinarySearch_C(int array[], int sizeOfArray, int value)
{
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	while (moreToSearch)
	{
		midPoint = (first + last) / 2;

		if (array[midPoint] > value)
		{
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] < value)
		{
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else
		{
			return array[midPoint];
		}
	}

	return array[last+1];
}