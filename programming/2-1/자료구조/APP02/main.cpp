#include <iostream>
#include "unsorted.h"

int main()
{
	UnsortedType list;
	ItemType item;
	int input;
	int max;
	int length;
	int output = 0;

	item.Initialize(0);
	std::cin >> max;

	for (int i = 0; i < max; ++i)
	{
		std::cin >> input;

		if (input > 0)
		{
			item.Initialize(input);
			list.InsertItem(item);
		}
		else if (input < 0)
		{
			item.Initialize(-input);
			list.DeleteItem_c(item);
		}
		else
		{
			length = list.LengthIs();
			list.ResetList();
			for (int i = 0; i < length; ++i)
			{
				list.GetNextItem(item);
			}
			list.DeleteItem_a(item);
		}
	}

	length = list.LengthIs();
	list.ResetList();

	for (int i = 0; i < length; ++i)
	{
		list.GetNextItem(item);
		output += item.GetValue();
	}

	std::cout << output;

	return 0;
}