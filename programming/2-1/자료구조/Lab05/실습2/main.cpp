#include <iostream>
#include "QueType.h"

void ReplaceItem(QueType& queue, ItemType oldItem, ItemType newItem)
{
	QueType temp;
	while (!queue.IsEmpty())
	{
		ItemType item;
		queue.Dequeue(item);
		if (item == oldItem)
		{
			item = newItem;
		}
		temp.Enqueue(item);
	}

	while (!temp.IsEmpty())
	{
		ItemType item;
		temp.Dequeue(item);
		queue.Enqueue(item);
	}
}

int main()
{
	QueType queue;
	ItemType item;
	ItemType inputItem[] = {2, 6, 7, 4, 5, 6, 10, 15, 6};

	std::cout << "Enqueue: ";

	for (ItemType i : inputItem)
	{
		queue.Enqueue(i);
		std::cout << i << " ";
	}

	
	
	std::cout << std::endl;
	
	queue.ReplaceItem(6, 20);

	std::cout << "Dequeue: ";

	while (!queue.IsEmpty())
	{
		queue.Dequeue(item);
		std::cout << item << " ";
	}

	std::cout << std::endl;

	return 0;
}