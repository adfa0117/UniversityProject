#include <iostream>
using namespace std;

void print_DOB(int year = 1900, int month = 1, int day = 1);

int main(){
	int year, month, day;
	
	print_DOB();
	cout << "year 입력 : ";
	cin >> year;
	cout << "month 입력 : ";
	cin >> month;
	cout << "day 입력 : ";
	cin >> day;
	print_DOB(year, month, day);
	
	return 0;
}

void print_DOB(int year, int month, int day){
	cout << "생년월일은 " << year << "년 " << month << "월 " << day << "일입니다." << endl;
}