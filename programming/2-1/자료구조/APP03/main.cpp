#include <iostream>
#include "ItemType.h"
#include "sorted.h"

int main()
{
	SortedType list1;

	int N;
	std::cout << "Input N: ";
	std::cin >> N;

	std::cout << "Input list Item: ";
	for (int i = 0; i < N; i++)
	{
		int input;
		ItemType item;
		std::cin >> input;
		item.Initialize(input);
		list1.InsertItem(item);
	}
	std::cout << std::endl;

	while (1)
	{
		int X;
		std::cout << "Input X: ";
		std::cin >> X;

		if (X == 0)
		{
			int length = list1.LengthIs();
			ItemType item;

			list1.ResetList();

			for (int i = 0; i < length; ++i)
			{
				list1.GetNextItem(item);
				item.Print(std::cout);
				std::cout << " ";
			}

			break;
		}

		int Y;
		std::cout << "Input Y: ";
		std::cin >> Y;

		ItemType item;
		bool isIn;
		item.Initialize(X);

		list1.RetrieveItem(item, isIn);
		if (isIn)
		{
			list1.DeleteItem(item);
			item.Initialize(Y);
			list1.RetrieveItem(item, isIn);
			if (!isIn)
			{
				list1.InsertItem(item);
			}
		}

		std::cout << "Operation completed." << std::endl << std::endl;
	}

	return 0;
}