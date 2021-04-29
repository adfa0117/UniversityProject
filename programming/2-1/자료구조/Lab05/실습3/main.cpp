#include <iostream>
#include "QueType.h"

bool Identical(QueType& queue1, QueType& queue2)
{
	QueType temp;
	QueType temp1;
	QueType temp2;
	ItemType item1;
	ItemType item2;

	while (!queue1.IsEmpty())
	{
		queue1.Dequeue(item1);
		temp.Enqueue(item1);
	}

	while (!temp.IsEmpty())
	{
		temp.Dequeue(item1);
		queue1.Enqueue(item1);
		temp1.Enqueue(item1);
	}

	while (!queue2.IsEmpty())
	{
		queue2.Dequeue(item1);
		temp.Enqueue(item1);
	}

	while (!temp.IsEmpty())
	{
		temp.Dequeue(item1);
		queue2.Enqueue(item1);
		temp2.Enqueue(item1);
	}

	while (!temp1.IsEmpty() && !temp2.IsEmpty())
	{
		temp1.Dequeue(item1);
		temp2.Dequeue(item2);
		if (item1 != item2)
		{
			return false;
		}
	}

	return temp1.IsEmpty() == temp2.IsEmpty();
}

int main()
{
	QueType queue1, queue2;
	ItemType item;
	ItemType inputItem1[] = { 2, 6, 7, 4, 5, 6, 10, 15, 3 };
	ItemType inputItem2[] = { 2, 6, 7, 4, 5, 6, 12, 15, 3 };
	
	std::cout << "Enqueue queue1: ";

	for (ItemType i : inputItem1)
	{
		queue1.Enqueue(i);
		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::cout << "Enqueue queue2: ";

	for (ItemType i : inputItem2)
	{
		queue2.Enqueue(i);
		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::cout << queue1.Identical(queue2);

	return 0;
}