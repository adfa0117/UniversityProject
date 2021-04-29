/*
---------
���� ��
---------

����
matrix: ũ�Ⱑ 50 50�� int�� 2���� �迭
currentN: ���� matrix�� ������ ũ��

����
MakeEmpty(n)
���: matrix�� n�� ���θ� 0���� �ʱ�ȭ
����: n�� �ִ� ũ��� 50
���: n���� �� ���� 0���� �ʱ�ȭ

StoreValue(i, j, value)
���: matrix�� i�� j���� value�� ����
����: i�� j�� �ִ� ũ��� currentN
���: matrix�� i�� j���� value�� ����

Add(other)
���: matrix�� other�� ���Ѵ�
����: matrix�� other�� currentN�� ���� ��
���: matrix�� other�� ���� ���ؼ� �ִ´�

Subtract(other)
���: matrix�� other�� ����
����: matrix�� other�� currentN�� ���� ��
���: matrix�� other�� ���� ���� �ִ´�

Copy(other)
���: matrix�� other�� �����Ѵ�.
����: other�� currentN�� 1 �̻��� ��
���: matrix�� currentN�� other�� currentN�� �پ�ְ� matrix�� other�� ��� ���� �����Ѵ�

Print()
���: matrix�� ���� Ȯ���ϱ� ���� �Լ�
����: ����
���: matrix�� ���� �ֿܼ� ����Ѵ�
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
�����ȹ
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