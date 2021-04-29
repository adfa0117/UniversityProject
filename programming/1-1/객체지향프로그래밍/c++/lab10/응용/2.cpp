#include <iostream>
#include <string>

using namespace std;

class CStudent{
	string name;
	int number;
	string major;
	public:
		CStudent(string _name = "홍길동", int _number = 2018000000, string _major = "컴퓨터공학과");
		
		void setName(string _name);
		void setNumber(int _number);
		void setMajor(string _major);
		
		string getName();
		int getNumber();
		string getMajor();
		
		void Display();

};

int main(){
	
	CStudent s[3];
	int inputNumber;
	string inputName, inputMajor;
	int length = 0;
	
	while (1) {
		bool isPrime = true;
		cout << length + 1 << "번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;

		for (int i = 0; i < length; i++) {
			if (inputNumber == s[i].getNumber()) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			s[length] = CStudent(inputName, inputNumber, inputMajor);
			length++;
			cout << "※입력 완료" << endl << endl;
		}
		else
			cout << "※중복된 학번이 존재합니다." << endl << endl;

		if (length >= 3) {
			cout << "---모든입력이 완료되었습니다---" << endl;
			for (int i = 0; i < 3; i ++) {
				cout << i + 1 << "학생정보" << endl;
				s[i].Display();
			}
			break;
		}

	}

	return 0;
}

CStudent::CStudent(string _name, int _number, string _major) : name(_name), number(_number), major(_major){}
void CStudent::setName(string _name){
	name = _name;
}
void CStudent::setNumber(int _number){
	number = _number;
}
void CStudent::setMajor(string _major){
	major = _major;
}

string CStudent::getName(){
	return name;
}
int CStudent::getNumber(){
	return number;
}
string CStudent::getMajor(){
	return major;
}

void CStudent::Display(){
	cout << "학번 :" << number << endl;
	cout << "이름 :" << name << endl;
	cout << "전공 :" << major << endl << endl;
}