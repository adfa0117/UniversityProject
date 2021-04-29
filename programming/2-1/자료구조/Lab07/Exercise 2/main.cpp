#include <iostream>
#include "StackType.h"

int main()
{
	StackType stack1;
	StackType stack2;
	int item;

	int arr[] = { 1, 2 ,3, 4, 5, 6, 7, 8 };
	for (int i : arr)
	{
		stack1.Push(i);
	}

	stack1.Copy(stack2);

	while (!stack2.IsEmpty())
	{
		item = stack2.Top();
		std::cout << item << " ";
		stack2.Pop();
	}
}