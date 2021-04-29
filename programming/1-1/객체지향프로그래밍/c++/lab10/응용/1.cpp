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
	
	CStudent s1;
	s1.Display();

	CStudent s2("공지철", 1999000000, "영극영화과");
	s2.Display();
	
	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl << endl;

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