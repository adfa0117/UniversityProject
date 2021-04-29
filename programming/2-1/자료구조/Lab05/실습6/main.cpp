#include <iostream>
#include "QueType.h"

int main()
{

	QueType queue;
	ItemType item;
	ItemType inputItem[] = {5, 4, 2, 3, 1, 8};
	ItemType inputItem2[] = { 6, 7 };
	
	std::cout << "Enqueue: ";

	for (ItemType i : inputItem)
	{
		queue.Enqueue(i);
		std::cout << i << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		queue.MinDequeue(item);
		std::cout << item << " ";
	}
	std::cout << std::endl;

	for (ItemType i : inputItem2)
	{
		queue.Enqueue(i);
	}

	std::cout << "Dequeue: ";

	while(!queue.IsEmpty()){
		queue.MinDequeue(item);
		std::cout << item << " ";
	}

	std::cout << std::endl;

	return 0;
}