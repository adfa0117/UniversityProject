#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void ProcInit(vector<vector<int>>& proc);
void ProcPrint(const vector<vector<int>>& proc);
vector<vector<int>> ProcMult(const vector<vector<int>>& proc_A, const vector<vector<int>>& proc_B);

int main(){
	
	srand((unsigned int)time(NULL));

	int row_A, col_A, row_B, col_B;
	vector<vector<int>> proc_fail = { {0} };

	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	cin >> row_A >> col_A;

	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> row_B >> col_B;

	if (row_A <= 0 || col_A <= 0 || row_B <= 0 || col_B <= 0) {
		cout << "행렬을 생성할 수 없습니다." << endl;
	}
	else {
		vector<vector<int>> proc_A(row_A, vector<int>(col_A));
		vector<vector<int>> proc_B(row_B, vector<int>(col_B));

		ProcInit(proc_A);
		ProcInit(proc_B);

		cout << "A 행렬 :" << endl;
		ProcPrint(proc_A);

		cout << endl;

		cout << "B 행렬 :" << endl;
		ProcPrint(proc_B);

		cout << endl;

		vector<vector<int>> proc_AB = ProcMult(proc_A, proc_B);

		if (proc_AB == proc_fail)
			cout << "두 행렬을 곱할 수 없습니다.";
		else{
			cout << "AB 곱행렬 : " << endl;
			ProcPrint(proc_AB);
		}
	}

	return 0;
}

void ProcInit(vector<vector<int>>& proc){
	for(auto& row : proc)
		for(auto& col : row)
			col = rand()%19 - 9;
}
void ProcPrint(const vector<vector<int>>& proc){
	for(auto& row : proc){
		for(auto& col : row)
			cout << setw(4) << col;
		cout << endl;
	}
}
vector<vector<int>> ProcMult(const vector<vector<int>>& proc_A, const vector<vector<int>>& proc_B){
	vector<vector<int>> proc_AB = {{0}};
	int row_A = proc_A.size();
	int col_A = proc_A[0].size();
	int row_B = proc_B.size();
	int col_B = proc_B[0].size();
	
	if (col_A != row_B)
		return proc_AB;

	proc_AB = vector<vector<int>>(row_A, vector<int>(col_B));

	for (int i = 0; i < row_A; i++)
		for (int j = 0; j < col_A; j++)
			for (int k = 0; k < col_B; k++)
				proc_AB[i][k] += proc_A[i][j] + proc_B[j][k];
	return proc_AB;
}