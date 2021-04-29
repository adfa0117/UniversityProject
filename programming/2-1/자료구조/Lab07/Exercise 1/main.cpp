using namespace std;
#include "SortedType.h"

int main()
{
	SortedType<int> list;
	int arr[] = { 1, 2 ,3, 4, 5, 6, 7, 8 };
	for (int i : arr)
	{
		list.InsertItem(i);
	}

	list.PrintReverse();
}