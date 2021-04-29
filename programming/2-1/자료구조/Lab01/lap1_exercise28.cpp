/*
---------
구격 명세
---------

구조
matrix: 크기가 50 50인 int형 2차원 배열
currentN: 현재 matrix의 실질적 크기

연산
MakeEmpty(n)
기능: matrix의 n행 내부를 0으로 초기화
조건: n의 최대 크기는 50
결과: n안의 행 열은 0으로 초기화

StoreValue(i, j, value)
기능: matrix의 i행 j열에 value를 저장
조건: i와 j의 최대 크기는 currentN
결과: matrix의 i행 j열에 value를 저장

Add(other)
기능: matrix와 other를 더한다
조건: matrix와 other의 currentN이 같을 것
결과: matrix에 other의 값을 더해서 넣는다

Subtract(other)
기능: matrix와 other를 뺀다
조건: matrix와 other의 currentN이 같을 것
결과: matrix에 other의 값을 빼서 넣는다

Copy(other)
기능: matrix에 other를 복사한다.
조건: other의 currentN이 1 이상일 것
결과: matrix의 currentN에 other의 currentN을 붙어넣고 matrix에 other의 모든 값을 복사한다

Print()
기능: matrix의 값을 확인하기 위한 함수
조건: 없음
결과: matrix의 값을 콘솔에 출력한다
*/
#include <iostream>

class SquareMatrix
{
private:
	int matrix[50][50];
	int currentN;
public:
	void MakeEmpty(int);
	void StoreValue(int, int, int);
	void Add(const SquareMatrix&);
	void Subtract(const SquareMatrix&);
	void Copy(const SquareMatrix&);
	void Print();
};

void SquareMatrix::MakeEmpty(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	currentN = n;
}

void SquareMatrix::StoreValue(int i, int j, int value)
{
	matrix[i][j] = value;
}

void SquareMatrix::Add(const SquareMatrix& other)
{
	if (currentN == other.currentN)
	{
		for (int i = 0; i < currentN; ++i)
		{
			for (int j = 0; j < currentN; ++j)
			{
				matrix[i][j] += other.matrix[i][j];
			}
		}
	}
}

void SquareMatrix::Subtract(const SquareMatrix& other)
{
	if (currentN == other.currentN)
	{
		for (int i = 0; i < currentN; ++i)
		{
			for (int j = 0; j < currentN; ++j)
			{
				matrix[i][j] -= other.matrix[i][j];
			}
		}
	}
}

void SquareMatrix::Copy(const SquareMatrix& other)
{
	if (other.currentN > 0)
	{
		for (int i = 0; i < other.currentN; ++i)
		{
			for (int j = 0; j < other.currentN; ++j)
			{
				matrix[i][j] = other.matrix[i][j];
			}
		}
		currentN = other.currentN;
	}
}

void SquareMatrix::Print()
{
	for (int i = 0; i < currentN; ++i)
	{
		for (int j = 0; j < currentN; ++j)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

/*
--------
시험계획
--------

int main()
{
	SquareMatrix matrix1;
	SquareMatrix matrix2;

	matrix1.MakeEmpty(10);
	matrix2.MakeEmpty(10);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrix1.StoreValue(i, j, 10 * i + j);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrix2.StoreValue(i, j, 10 * j + i);
		}
	}

	std::cout << "matrix1" << std::endl;
	matrix1.Print();
	std::cout << "matrix2" << std::endl;
	matrix2.Print();

	matrix1.Subtract(matrix2);
	std::cout << "matrix1" << std::endl;
	matrix1.Print();

	matrix1.Add(matrix2);
	std::cout << "matrix1" << std::endl;
	matrix1.Print();

	matrix1.Subtract(matrix1);
	std::cout << "matrix1" << std::endl;
	matrix1.Print();

	matrix1.MakeEmpty(5);
	std::cout << "matrix1" << std::endl;
	matrix1.Print();

	matrix1.Copy(matrix2);
	std::cout << "matrix1" << std::endl;
	matrix1.Print();

	return 0;
}
*/