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
재귀함수는 함수가 호출될 때 마다 return address, 변수 n 같이 생성되고 사라지는 것들이 많지만
비재귀함수는 n, m, l, i, N 5가지 변수와 기타 몇가지가 한 번 생성되고 끝이기 때문에
재귀량이 적을 때는 재귀함수가 우월할 수도 있지만 재귀량이 많아질수록 비재귀함수가 성능이 훨씬 좋아지므로 재귀버전은 효율성을 향상시키지는 않는다.
*/
int main()
{
	std::cout << Fibonacci_recursive(10) << std::endl;
	std::cout << Fibonacci_non_recursive(10) << std::endl;

	return 0;
}