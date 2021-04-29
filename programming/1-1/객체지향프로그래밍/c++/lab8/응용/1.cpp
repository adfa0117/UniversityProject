#include <iostream>
using namespace std;

void pow(int* x) { *x = *x * *x; }

int main(){
	
	int x;
	
	cout << "input> ";
	cin >> x;
	
	pow(&x);

	cout << "제곱값> " <<  x;
	
	return 0;
}