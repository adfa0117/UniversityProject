#include <iostream>
#include "StackType.h"

void ReplaceItem(StackType& a, int oldItem, int newItem)
{
	StackType temp;

	while (!a.IsEmpty())
	{
		temp.Push(a.Top());
		a.Pop();
	}

	while (!temp.IsEmpty())
	{
		int push = temp.Top() == oldItem ? newItem : temp.Top();
		a.Push(push);
		temp.Pop();
	}
}

int main()
{
	StackType stack;
	stack.Push(3);
	stack.Push(5);
	stack.Push(7);
	stack.Push(3);
	stack.Push(8);
	stack.Push(9);
	stack.Push(3);
	stack.Push(8);

	stack.ReplaceItem(3, 5);

	while (!stack.IsEmpty())
	{
		int item = stack.Top();
		stack.Pop();
		std::cout << item << std::endl;
	}
}