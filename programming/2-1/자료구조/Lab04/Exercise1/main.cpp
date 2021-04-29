#include <iostream>
#include "StackTType.h"

int main()
{
	StackType<int> stack;
	for (int i = 0; i < 6; ++i)
	{
		stack.Push(i+1);
	}

	while (!stack.IsEmpty())
	{
		int result = stack.Top();
		stack.Pop();
		std::cout << result << std::endl;
	}
}