#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int colunm = 1, row = 1;
	while(row <= 10){
		colunm = 1;
		while(colunm <= 10){
			int val = 0;
			if (row == colunm)
				val = 1;
			cout << setw(4) << val;
			colunm++;
		}
		row++;
		cout << endl;
	}
	return 0;
}