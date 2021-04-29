#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
	string name;
	int number;
	string depart;
	vector<string> subject;
	vector<char> grade;
public:
	Student(string _name = "default", int _number = 0, string _depart = "depart");

	void setName(string _name);
	void setNumber(int _number);
	void setDpt(string _depart);
	void print();

	void addGrade(string _subject, char _grade);
	void printGrades();
	float getGPA();

	void getYear(int _year);
};

int main(){

	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programing", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setNumber(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}

Student::Student(string _name, int _number, string _depart) : name(_name), number(_number), depart(_depart){}

void Student::setName(string _name){
	name = _name;
}
void Student::setNumber(int _number){
	number = _number;
}
void Student::setDpt(string _depart){
	depart = _depart;
}
void Student::print(){
	cout << name << " " << number << " " << depart << endl;
}

void Student::addGrade(string _subject, char _grade){
	subject.push_back(_subject);
	grade.push_back(_grade);
}

void Student::printGrades(){
	for(int i = 0; i < subject.size(); i++)
		cout << subject[i] << " " << grade[i] << endl;
	cout << "GPA : " << getGPA() << endl;
}
float Student::getGPA(){
	int sum = 0;
	
	for(char c : grade){
		switch(c){
			case 'A':
				sum +=1;
			case 'B':
				sum +=1;
			case 'C':
				sum +=1;
			case 'D':
				sum +=1;
			case 'F':
				break;
		}
	}
	
	return (float)sum / grade.size();
}

void Student::getYear(int _year){
	int year = number/1000000;
	
	int _grade = _year - year + 1;
	
	switch(_grade){
		case 1:
			cout << "Freshmen";
			break;
		case 2:
			cout << "Sophomore";
			break;
		case 3:
			cout << "Junior";
			break;
		case 4:
			cout << "Senior";
			break;
		case 5:
			cout << "About to graduate";
			break;
	}
	
	cout << "(" << _grade << "학년)" << endl;
}