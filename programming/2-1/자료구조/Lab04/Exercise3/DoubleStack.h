#pragma once
#define MAX_ITEMS 200


class DoubleStackType
{
public:
	DoubleStackType();
	void Push(int item);
	void Print();

private:
	int items[MAX_ITEMS];
	int top_small;
	int top_big;
};