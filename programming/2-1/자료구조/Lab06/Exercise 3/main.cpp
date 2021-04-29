#include <iostream>
using namespace std;
#include "SortedType.h"
//#include "UnsortedType.h"

/*
template<typename ItemType>
void MergeList(SortedType<ItemType>& l_a, SortedType<ItemType>& l_b, SortedType<ItemType>& result)
{
	ItemType item;

	l_a.ResetList();

	for (int i = 0; i < l_a.LengthIs(); ++i)
	{
		l_a.GetNextItem(item);
		result.InsertItem(item);
	}

	l_b.ResetList();

	for (int i = 0; i < l_b.LengthIs(); ++i)
	{
		l_b.GetNextItem(item);
		result.InsertItem(item);
	}
}
*/

/*
template<typename ItemType>
void MergeList(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result)
{
	ItemType item;

	l_a.ResetList();

	for (int i = 0; i < l_a.LengthIs(); ++i)
	{
		l_a.GetNextItem(item);
		result.InsertItem(item);
	}

	l_b.ResetList();

	for (int i = 0; i < l_b.LengthIs(); ++i)
	{
		l_b.GetNextItem(item);
		result.InsertItem(item);
	}
}
*/


int main()
{
	int arr1[] = { 0, 1, 2, 5, 6 };
	int arr2[] = { 3, 4 };
	int item;


	SortedType<int> sort1;
	SortedType<int> sort2;
	SortedType<int> sortResult;
	
	for (int i : arr1)
	{
		sort1.InsertItem(i);
	}

	for (int i : arr2)
	{
		sort2.InsertItem(i);
	}

	sort1.MergeList(sort2, sortResult);
	

	sortResult.ResetList();

	for (int i = 0; i < sortResult.LengthIs(); ++i)
	{
		sortResult.GetNextItem(item);
		std::cout << item << " ";
	}

	/*
	UnsortedType<int> unsort1;
	UnsortedType<int> unsort2;
	UnsortedType<int> unsortResult;

	for (int i : arr1)
	{
		unsort1.InsertItem(i);
	}

	for (int i : arr2)
	{
		unsort2.InsertItem(i);
	}

	unsort1.MergeList(unsort2, unsortResult);

	unsortResult.ResetList();

	for (int i = 0; i < unsortResult.LengthIs(); ++i)
	{
		unsortResult.GetNextItem(item);
		std::cout << item << " ";
	}
	*/

	return 0;
}