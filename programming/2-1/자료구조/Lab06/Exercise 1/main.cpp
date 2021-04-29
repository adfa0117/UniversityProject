#include <iostream>
#include "StackType.h"

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem)
{
	StackType temp;
	ItemType item;
	while (!stack.IsEmpty())
	{
		item = stack.Top();
		if (item == oldItem)
		{
			temp.Push(newItem);
		}
		else
		{
			temp.Push(item);
		}
		stack.Pop();
	}

	while (!temp.IsEmpty())
	{
		item = temp.Top();
		stack.Push(item);
		temp.Pop();
	}
}

int main()
{
	StackType stack;
	ItemType arr[] = { 0, 1, 2, 3, 5, 6 ,7, 7, 7, 8, 2, 7, 10 };
	for (ItemType i : arr)
	{
		stack.Push(i);
	}

	stack.ReplaceItem(7, 9);

	while (!stack.IsEmpty())
	{
		std::cout << stack.Top() << " ";
		stack.Pop();
	}

	return 0;
}