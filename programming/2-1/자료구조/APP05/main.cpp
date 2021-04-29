#include <iostream>
#include "QueType.h"

int main()
{
	int N;
	ItemType item;
	QueType queue;

	std::cin >> N;

	for (int i = 1; i < N + 1; ++i)
	{
		queue.Enqueue(i);
	}

	for (int i = 0; i < N - 1; ++i)
	{
		queue.Dequeue(item);
		std::cout << item << " ";
		queue.Dequeue(item);
		queue.Enqueue(item);
	}

	queue.Dequeue(item);
	std::cout << item << " ";
}