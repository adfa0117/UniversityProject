#include <iostream>
using namespace std;

int main(){
	double temper_F, temper_C;
	cout << "Please enter Fahrenheit value: ";
	cin >> temper_F;
	temper_C = 5.0 / 9.0 * (temper_F - 32);
	cout << "Celsius value is " << temper_C;
}