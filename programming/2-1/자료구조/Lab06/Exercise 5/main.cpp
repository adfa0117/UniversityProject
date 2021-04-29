#include <iostream>
using namespace std;
#include "SortedType.h"


int main()
{
	int arr[] = { 0, 0, 1, 2, 0, 0, 5, 6, 0, 0, 1, 1, 2, 3 };
	int item;

	SortedType<int> sort;

	for (int i : arr)
	{
		sort.InsertItem(i);
	}

	sort.DeleteItem(2);

	sort.ResetList();

	for (int i = 0; i < sort.LengthIs(); ++i)
	{
		sort.GetNextItem(item);
		std::cout << item << " ";
	}

	return 0;
}