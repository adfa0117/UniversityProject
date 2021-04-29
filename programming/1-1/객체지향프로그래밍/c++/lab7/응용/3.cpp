#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	ofstream fout("temp.txt");
	int row = 10, col = 10;
	int num;
	srand((unsigned int)time(NULL));
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			num = rand()%101;
			fout << num << " ";
		}
		fout << endl;
	}
	fout.close();
}