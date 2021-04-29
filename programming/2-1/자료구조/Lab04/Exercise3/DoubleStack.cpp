#pragma once
#include <iostream>
#include "DoubleStack.h"

DoubleStackType::DoubleStackType()
{
	top_small = -1;
	top_big = MAX_ITEMS;
}

void DoubleStackType::Push(int item)
{
	if (item > 1000)
	{
		items[--top_big] = item;
	}
	else
	{
		items[++top_small] = item;
	}
}

void DoubleStackType::Print()
{
	for (int i = top_small; i > -1; --i)
	{
		std::cout << items[i] << " ";
	}
	std::cout << std::endl;
	for (int i = top_big; i < MAX_ITEMS; ++i)
	{
		std::cout << items[i] << " ";
	}
}
