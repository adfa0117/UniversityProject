#include <iostream>
#include "QueType.h"

int Length(QueType& queue)
{
	QueType temp;
	ItemType item;
	int count = 0;

	while (!queue.IsEmpty())
	{
		queue.Dequeue(item);
		temp.Enqueue(item);
		++count;
	}

	while (!temp.IsEmpty())
	{
		temp.Dequeue(item);
		queue.Enqueue(item);
	}

	return count;
}

int main()
{
	QueType queue;
	ItemType item;
	ItemType inputItem[] = { 1, 2, 3, 4, 5, 6, 7 };
	
	std::cout << "Enqueue: ";

	for (ItemType i : inputItem)
	{
		queue.Enqueue(i);
		std::cout << i << " ";
	}

	std::cout << std::endl;
	
	std::cout << queue.Length() << std::endl;

	std::cout << "Dequeue: ";

	while(!queue.IsEmpty()){
		queue.Dequeue(item);
		std::cout << item << " ";
	}

	std::cout << std::endl;

	return 0;
}