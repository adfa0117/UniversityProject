#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void readStudentFile() {
	ifstream fin("students.txt");
	string a;
	
	if(!fin.is_open()){
		cout << "Student를 읽어올 수 없습니다!!" << endl;
		return;
	}
	
	while(true){
		fin >> a;
		if(!fin) break;
		cout << a << endl;
	}
	system("pause");
	fin.close();
}

int main(){
	readStudentFile();

	return 0;
}