#include <iostream>
#include "ItemType.h"
#include "sorted.h"

void MergeList(SortedType list1, SortedType list2, SortedType& result);

int main() 
{
	SortedType s_list1, s_list2, s_list3;
	ItemType item1, item2, item3, item;
	int length;

	item1.Initialize(1);
	item2.Initialize(2);
	item3.Initialize(3);

	s_list1.InsertItem(item1);
	s_list1.InsertItem(item3);
	s_list2.InsertItem(item2);

	s_list1.ResetList();
	length = s_list1.LengthIs();

	std::cout << "list1" << std::endl;

	for (int i = 0; i < length; ++i)
	{
		s_list1.GetNextItem(item);
		item.Print(std::cout);
	}

	std::cout << std::endl;
	
	s_list2.ResetList();
	length = s_list2.LengthIs();

	std::cout << "list2" << std::endl;

	for (int i = 0; i < length; ++i)
	{
		s_list2.GetNextItem(item);
		item.Print(std::cout);
	}

	std::cout << std::endl;

	MergeList(s_list1, s_list2, s_list3);

	s_list3.ResetList();
	length = s_list3.LengthIs();

	std::cout << "list3" << std::endl;

	for (int i = 0; i < length; ++i)
	{
		s_list3.GetNextItem(item);
		item.Print(std::cout);
	}

	return 0;
}

//Big-O: O(n^2)

void MergeList(SortedType list1, SortedType list2, SortedType& result)
{
	int length;
	ItemType item;

	list1.ResetList();
	list2.ResetList();

	length = list1.LengthIs();

	for (int i = 0; i < length; ++i)
	{
		list1.GetNextItem(item);
		result.InsertItem(item);
	}

	length = list2.LengthIs();

	for (int i = 0; i < length; ++i)
	{
		list2.GetNextItem(item);
		result.InsertItem(item);
	}
}