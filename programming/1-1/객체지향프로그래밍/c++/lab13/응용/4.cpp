#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int size = 0;

	cout << "홀수 숫자를 하나 입력해 주세요 : ";
	cin >> size;

	if (size % 2 == 0) {
		cout << "짝수를 입력하셨습니다. " << endl;
		return 0;
	}

	int x = size / 2, y = 0;
	int nxtX, nxtY;
	int count = 0;

	int** mat = new int*[size];
	for (int i = 0; i < size; i++) {
		mat[i] = new int[size];
		for (int j = 0; j < size; j++) {
			mat[i][j] = 0;
		}
	}

	for (int i = 0; i < size * size; i++) {
		count++;
		mat[x][y] = count;
		nxtX = x + 1;
		nxtY = y - 1;
		if (nxtX > size - 1) nxtX = 0;
		if (nxtY < 0) nxtY = size - 1;
		if (mat[nxtX][nxtY] != 0) {
			nxtX = x;
			nxtY = y + 1;
		}
		if (nxtY > size - 1) nxtY = 0;

		x = nxtX;
		y = nxtY;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(4) << mat[j][i];
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		delete[] mat[i];
	}

	delete[] mat;

	return 0;
}