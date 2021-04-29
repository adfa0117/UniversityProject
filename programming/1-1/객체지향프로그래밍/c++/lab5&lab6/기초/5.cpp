#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n, m;
	
	cout << "Enter n for n x m matrix: ";
	cin >> n;
	cout << "Enter m for n x m matrix: ";
	cin >> m;
	
	int num = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j ++){
			cout << setw(4) << num;
			num++;
		}
		cout << endl;
	}
}