#include <iostream>
#include "StackTType.h"

template<typename ItemType>
StackType<ItemType> CopyStack(StackType<ItemType>& a)
{
	StackType<ItemType> temp;
	StackType<ItemType> b;

	while (!a.IsEmpty())
	{
		temp.Push(a.Top());
		a.Pop();
	}

	while (!temp.IsEmpty())
	{
		a.Push(temp.Top());
		b.Push(temp.Top());
		temp.Pop();
	}

	return b;
}

int main()
{
	StackType<int> stack1;
	stack1.Push(3);
	stack1.Push(5);
	stack1.Push(7);
	stack1.Push(4);
	stack1.Push(8);
	stack1.Push(9);

	StackType<int> stack2 = CopyStack(stack1);

	std::cout << "stack1" << std::endl;

	while (!stack1.IsEmpty())
	{
		int result = stack1.Top();
		stack1.Pop();
		std::cout << result << std::endl;
	}

	std::cout << "stack2" << std::endl;

	while (!stack2.IsEmpty())
	{
		int result = stack2.Top();
		stack2.Pop();
		std::cout << result << std::endl;
	}
}