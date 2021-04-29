#include <iostream>
#include <ctime>
#include "QueType.h"

int main()
{
	srand((unsigned int)time(NULL));

	QueType queue;
	ItemType item;
	ItemType inputItem[] = { rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000 };
	
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