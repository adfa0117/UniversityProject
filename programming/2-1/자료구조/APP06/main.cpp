#include <iostream>
#include "StackType.h"

int main()
{
	StackType leftStack;
	StackType rightStack;
	char item;

	char* input = new char[100];
	std::cin >> input;

	for (int i = 0; i < 100; ++i)
	{
		char c = input[i];
		if (c == NULL)
		{
			break;
		}
		switch (c)
		{
		case '<':
			if (!leftStack.IsEmpty())
			{
				item = leftStack.Top();
				leftStack.Pop();
				rightStack.Push(item);
			}
			break;

		case '>':
			if (!rightStack.IsEmpty())
			{
				item = rightStack.Top();
				rightStack.Pop();
				leftStack.Push(item);
			}
			break;

		case '-':
			if (!leftStack.IsEmpty())
			{
				leftStack.Pop();
			}
			break;

		default:
			leftStack.Push(c);
			break;
		}
	}

	while (!leftStack.IsEmpty())
	{
		item = leftStack.Top();
		leftStack.Pop();
		rightStack.Push(item);
	}

	while (!rightStack.IsEmpty())
	{
		item = rightStack.Top();
		rightStack.Pop();
		std::cout << item;
	}

	return 0;
}