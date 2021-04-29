#include <iostream>

int main()
{
	int arr[20];
	arr[0] = 1;
	arr[1] = 2;
	*(arr + 1) = 3;
	std::cout << *(arr + 1) << std::endl;
}