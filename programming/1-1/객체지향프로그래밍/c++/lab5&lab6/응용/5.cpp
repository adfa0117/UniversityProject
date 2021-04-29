#include <iostream>
using namespace std;

int G(int a, int b);

int main(){
	int x, y;
	cout << "x : ";
	cin >> x;
	cout << "y : ";
	cin >> y;
	
	cout << "gcd(" << x << "," << y << ") = " <<G(x, y);
}

int G(int a, int b){
	int r = a % b;
	if(r == 0){
		return b;
	}
	else{
		return G(b, r);
	}
}