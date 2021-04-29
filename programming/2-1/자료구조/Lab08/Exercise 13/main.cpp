#include <iostream>

int Fibonacci_recursive(int n)
{
	if (n > 1)
		return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
	else if (n == 1)
		return 1;
	else
		return 0;
}

int Fibonacci_non_recursive(int N)
{
	int n = 0, m = 1, l;
	for (int i = 0; i < N; ++i, l = m + n, n = m, m = l);
	return n;
}


/*
����Լ��� �Լ��� ȣ��� �� ���� return address, ���� n ���� �����ǰ� ������� �͵��� ������
������Լ��� n, m, l, i, N 5���� ������ ��Ÿ ����� �� �� �����ǰ� ���̱� ������
��ͷ��� ���� ���� ����Լ��� ����� ���� ������ ��ͷ��� ���������� ������Լ��� ������ �ξ� �������Ƿ� ��͹����� ȿ������ ����Ű���� �ʴ´�.
*/
int main()
{
	std::cout << Fibonacci_recursive(10) << std::endl;
	std::cout << Fibonacci_non_recursive(10) << std::endl;

	return 0;
}