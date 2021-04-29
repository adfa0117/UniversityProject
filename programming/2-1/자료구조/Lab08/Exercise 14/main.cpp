#include <iostream>
#include <cmath>

float SqrRoot_recursion(float number, float approx, float tol)
{
	if (fabs(approx * approx - number) <= tol)
		return approx;
	else
		return SqrRoot_recursion(number, (approx * approx + number) / (2 * approx), tol);
}

float SqrRoot_non_recursion(float number, float approx, float tol)
{
	for (; fabs(approx * approx - number) > tol; approx = (approx * approx + number) / (2 * approx));
	return approx;
}

int main()
{
	std::cout << SqrRoot_recursion(2, 1.4, 0.000001) << std::endl;
	std::cout << SqrRoot_non_recursion(2, 1.4, 0.000001) << std::endl;

	return 0;
}