#include <iostream>
#include <vector>

using namespace std;

void print(int** m, int nRow, int nCol);

int main(){
	
	int nRow = 2, nCol = 2;
	int ** matrix2 = new int*[nRow];
	for(int i = 0; i < nRow; i++)
		matrix2[i] = new int[nCol];
	
	matrix2[0][0] = 1; matrix2[0][1] = 2;
	matrix2[1][0] = 3; matrix2[1][1] = 4;
	
	print(matrix2, nRow, nCol);
	
	for(int i = 0; i < nRow; i++)
		delete[] matrix2[i];
	
	delete[] matrix2;
	
	return 0;
}

void print(int** m, int nRow, int nCol){
	
	for(int i = 0; i < nRow; i++)
		for(int j = 0; j < nCol; j++)
			cout << *(*(m+i)+j) << "\t";
		
}