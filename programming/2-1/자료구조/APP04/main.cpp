#include <iostream>
#include "ItemType.h"
#include "StackType.h"

int main()
{
	StackType stack;
	int length;
	int count = 0;
	ItemType item;
	ItemType maxItem = 0;

	std::cin >> length;

	for (int i = 0; i < length; ++i)
	{
		int input;
		std::cin >> item;
		stack.Push(item);
	}

	while (!stack.IsEmpty())
	{
		item = stack.Top();
		if (item > maxItem)
		{
			maxItem = item;
			++count;
		}
		stack.Pop();
	}

	std::cout << count;
}