#include <iostream>
#include "VecType.h"

using namespace std;

VecType compute(VecType&A, VecType&B, VecType&C){
	int a = A.GetA() * 3 + B.GetA() * 2 - C.GetA() * 5;
	int b = A.GetB() * 3 + B.GetB() * 2 - C.GetB() * 5;
	int c = A.GetC() * 3 + B.GetC() * 2 - C.GetC() * 5;

	VecType returnValue = VecType(a, b, c);

	return returnValue;
}

int main() 
{	
	int a, b, c;
	int d, e, f;
	int g, h, i;

	cout << "A : ";
	cin >> a >> b >> c;
	cout << "B : ";
	cin >> d >> e >> f;
	cout << "C : ";
	cin >> g >> h >> i;

	VecType A(a, b, c);
	VecType B(d, e, f);
	VecType C(g, h, i);
	VecType D;
	
	D = compute(A, B, C); //3A+2B-5C 계산

	int result = D.sum(); //D의요소의합계산

	cout << result;

	return 0;
}