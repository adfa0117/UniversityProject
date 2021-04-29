#include <iostream>
#include <string>

using namespace std;

void ChangeStr(string* msg);

int main(){
	
	string str = "This is default value";
	
	cout << "기본값 출력> " << str << endl;
	
	ChangeStr(&str);
	
	cout << "변환된 값 출력> " << str << endl;
	
	return 0;
}

void ChangeStr(string* msg){
	cout << "input> ";
	cin >> *msg;
}