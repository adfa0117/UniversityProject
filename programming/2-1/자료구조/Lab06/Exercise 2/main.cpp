#include <iostream>
using namespace std;
#include "QueType.h"

template<typename ItemType>
void ReplaceItem(QueType<ItemType>& queue, ItemType oldItem, ItemType newItem)
{
	QueType<ItemType> temp;
	ItemType item;
	while (!queue.IsEmpty())
	{
		queue.Dequeue(item);
		if (item == oldItem)
		{
			temp.Enqueue(newItem);
		}
		else
		{
			temp.Enqueue(item);
		}
	}

	while (!temp.IsEmpty())
	{
		temp.Dequeue(item);
		queue.Enqueue(item);
	}
}

int main()
{
	QueType<int> queue;
	int arr[] = { 0, 1, 2, 3, 5, 6 ,7, 7, 7, 8, 2, 7, 10 };
	for (int i : arr)
	{
		queue.Enqueue(i);
	}

	queue.ReplaceItem(7, 9);

	while (!queue.IsEmpty())
	{
		int item;
		queue.Dequeue(item);
		std::cout << item << " ";
	}

	return 0;
}