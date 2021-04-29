#include <iostream>
using namespace std;
#include "UnsortedType.h"


int main()
{
	int arr[] = { 0, 0, 1, 2, 0, 0, 5, 6, 0, 0 };
	int item;

	UnsortedType<int> unsort;

	for (int i : arr)
	{
		unsort.InsertItem(i);
	}

	unsort.DeleteItem(0);

	unsort.ResetList();

	for (int i = 0; i < unsort.LengthIs(); ++i)
	{
		unsort.GetNextItem(item);
		std::cout << item << " ";
	}

	return 0;
}