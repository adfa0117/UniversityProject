#include <iostream>
#include "QueType.h"

int main()
{

	QueType queue(6);
	ItemType item;
	ItemType inputItem[] = {1, 2, 3, 4, 5, 6};
	
	std::cout << "Enqueue: ";

	for (ItemType i : inputItem)
	{
		queue.Enqueue(i);
		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::cout << "Dequeue: ";

	while(!queue.IsEmpty()){
		queue.Dequeue(item);
		std::cout << item << " ";
	}

	std::cout << std::endl;

	return 0;
}