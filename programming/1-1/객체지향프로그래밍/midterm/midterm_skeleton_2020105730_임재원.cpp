#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Utils
int findStudentById(vector<string> studentIds, string id);
int findLectureByCode(vector<string> lectureCodes, string code);
void deleteElement(vector<string>& v, int index);

// File read
void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// File write
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes);
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits);

// Get user input
string getInputId();
string getInputPassword();

// Login
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords);
bool adminLogin();
int login(const vector<string>& studentIds, const vector<string>& passwords);

// Common
void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user = -100);

// Admin
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// User
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user);
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void changePassword(vector<string>& passwords, const int& user);
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user);

int main() {
	int user = -1; //user index
	int status = -1;

	// Student Info
	vector<string> studentIds;
	vector<string> passwords;
	vector<string> names;
	vector<int> credits;
	vector<vector<string>> appliedLectureCodes;

	// Lecture Info
	vector<string> lectureCodes;
	vector<string> lectureNames;
	vector<int> lectureCredits;
	vector<int> limits;

	// Read from files
	readStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	readLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	// Login phase
	while (status == -1) {
		user = login(studentIds, passwords);

		if (user == -999) { // Login fail
			break;
		}
		else if (user == -1) { // Exit command
			break;
		}
		else if (user == -100) { // Admin login success
			status = runAdmin(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		}
		else { // Student login success
			status = runStudent(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
	}

	// Write to files
	writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	return 0;
}

int findStudentById(vector<string> studentIds, string id) {
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentIds[i] == id)
			return i;
	}
	return -1;
}

int findLectureByCode(vector<string> lectureCodes, string code) {
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (lectureCodes[i] == code)
			return i;
	}
	return -1;
}

void deleteElement(vector<string>& v, int index) {
	v.erase(v.begin() + index);
}

void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	ifstream fin("students.txt");
	string strInfo;
	int intInfo;
	vector<string> lectures;
	
	if(!fin.is_open()){
		cout << "Student를 읽어올 수 없습니다!!" << endl;
		return;
	}
	
	while(true){
		fin >> strInfo;
		
		if(!fin) break;

		studentIds.push_back(strInfo);
		
		fin >> strInfo;
		passwords.push_back(strInfo);
		
		fin >> strInfo;
		names.push_back(strInfo);
		
		fin >> intInfo;
		credits.push_back(intInfo);
		
		fin >> intInfo;
		for (int i = 0; i < intInfo; i++) {
			fin >> strInfo;
			lectures.push_back(strInfo);
		}

		appliedLectureCodes.push_back(lectures);

		lectures.clear();
	}
	
	fin.close();
}

void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	ifstream fin("lectures.txt");
	string strInfo;
	int intInfo;
	
	while(true){
		fin >> strInfo;
		
		if(!fin) break;
		
		lectureCodes.push_back(strInfo);
		
		fin >> strInfo;
		lectureNames.push_back(strInfo);
		
		fin >> intInfo;
		lectureCredits.push_back(intInfo);
		
		fin >> intInfo;
		limits.push_back(intInfo);
	}

	fin.close();
}

void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {
	ofstream fout("students.txt");
	int size = studentIds.size(), lectureSize;
	
	for(int i = 0; i < size; i++){
		fout << studentIds[i] << "\t" << passwords[i] << "\t" << names[i] << "\t" << credits[i] << "\t";
		lectureSize = appliedLectureCodes[i].size();
		fout << lectureSize;
		for(int j = 0; j < lectureSize; j++){
			fout << "\t" << appliedLectureCodes[i][j];
		}
		fout << endl;
	}
	
	fout.close();
}

void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {
	ofstream fout("lectures.txt");
	int size = lectureCodes.size();
	
	for(int i = 0; i < size; i ++){
		fout << lectureCodes[i] << "\t" << lectureNames[i] << "\t" << lectureCredits[i] << "\t" << limits[i] << endl;
	}
}

string getInputId() {
	string id;
	cout << "아이디: ";
	cin >> id;
	
	return id;
}

string getInputPassword() {
	string password;
	cout << "비밀번호: ";
	cin >> password;
	
	return password;
}

int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	int user = -1, size = studentIds.size();
	
	string id, password;
	id = getInputId();
	password = getInputPassword();
	
	for(int i = 0; i < size; i++)
		if(id == studentIds[i] && password == passwords[i]){
			user = i;
			break;
		}
		
	return user;
}

bool adminLogin() {
	string id, password;
	id = getInputId();
	password = getInputPassword();
	if(id == "admin" && password == "admin"){
		return true;
	}
	return false;
}

int login(const vector<string>& studentIds, const vector<string>& passwords) {
	int choice;
	int chance = 3;
	
	cout << "----------------------------------------------------------" << endl;
	cout << "1. 학생 로그인" << endl;
	cout << "2. 관리자 로그인" << endl;
	cout << "0. 종료" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << ">> ";
	cin >> choice;
	
	if(choice == 1){
		int user;
		for(int i = 0; i < chance; i++){
			user = studentLogin(studentIds, passwords);
			if(user != -1)
				return user;
			else {
				cout << "로그인 " << i + 1 << "회 실패 (3회 실패시 종료)" << endl;
			}
		}

		cout << "3회 실패하여 종료합니다.";
		return -999; 
	}
	else if(choice == 2){
		bool admin;
		for(int i = 0; i < chance; i++){
			admin = adminLogin();
			if(admin)
				return -100;
			else {
				cout << "로그인 " << i + 1 << "회 실패 (3회 실패시 종료)" << endl;
			}
		}

		cout << "3회 실패하여 종료합니다.";
		return -999;
	}
	else if(choice == 0)
		return -1;
}

void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	
	cout << "----------------------------------------------------------" << endl;
	cout << "과목코드\t강의명\t학점\t수강가능인원" << endl;
	cout << "----------------------------------------------------------" << endl;
	if(user == -100){
		int size = lectureCodes.size();
		for(int i = 0; i < size; i++){
			cout << lectureCodes[i] << "\t" << lectureNames[i] << "\t" << lectureCredits[i] << "\t" << limits[i] << endl;
		}
	}
	else{
		int i;
		int size = appliedLectureCodes[user].size();
		for(int j = 0; j < size; j ++){
			i = findLectureByCode(lectureCodes, appliedLectureCodes[user][j]);
			if(i != -1){
				cout << lectureCodes[i] << "\t" << lectureNames[i] << "\t" << lectureCredits[i] << "\t" << limits[i] << endl;
			}
		}
	}
	cout << "----------------------------------------------------------" << endl;
}

void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	string studentId;
	string password;
	string name;
	vector<string> lectures;

	cout << "----------------------------------------------------------" << endl;
	cout << "학번: ";
	cin >> studentId;
	cout << "비밀번호: ";
	cin >> password;
	cout << "학생 이름: ";
	cin >> name;
	cout << "----------------------------------------------------------" << endl;

	for (string id : studentIds) {
		if (id == studentId) {
			cout << "이미 존재하는 학번입니다." << endl;
			system("pause");
			return;
		}
	}

	studentIds.push_back(studentId);
	passwords.push_back(password);
	names.push_back(name);
	credits.push_back(0);
	appliedLectureCodes.push_back(lectures);

	cout << "성공적으로 등록되었습니다." << endl;
	system("pause");
}

void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	string lectureCode;
	string lectureName;
	int lectureCredit;
	int limit;

	cout << "----------------------------------------------------------" << endl;
	cout << "과목코드: ";
	cin >> lectureCode;
	cout << "과목명: ";
	cin >> lectureName;
	cout << "학점: ";
	cin >> lectureCredit;
	cout << "수강인원: ";
	cin >> limit;
	cout << "----------------------------------------------------------" << endl;

	for (string code : lectureCodes) {
		if (code == lectureCode) {
			cout << "이미 존재하는 과목코드입니다." << endl;
			system("pause");
			return;
		}
	}

	lectureCodes.push_back(lectureCode);
	lectureNames.push_back(lectureName);
	lectureCredits.push_back(lectureCredit);
	limits.push_back(limit);

	cout << "성공적으로 강의가 개설되었습니다." << endl;
	system("pause");
	return;

}

void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	string code;
	int size;
	while (true) {
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		cout << "삭제할 강의 코드 (0: 뒤로가기) >> ";
		cin >> code;
		if (code == "0")
			break;
		else {
			bool isAble = true;

			size = lectureCodes.size();
			for (int i = 0; i < size; i++) {
				if (code == lectureCodes[i]) {
					deleteElement(lectureCodes, i);
					deleteElement(lectureNames, i);
					lectureCredits.erase(lectureCredits.begin() + i);
					limits.erase(limits.begin() + i);
					int studentSize = appliedLectureCodes.size();
					for (int i = 0; i < studentSize; i++) {
						int lectureSize = appliedLectureCodes[i].size();
						for (int j = 0; j < lectureSize; j++) {
							deleteElement(appliedLectureCodes[i], j);
						}
					}
					isAble = false;

					cout << "성공적으로 강의가 폐쇄되었습니다." << endl;
					system("pause");
					break;
				}
			}

			if (isAble) {
				cout << "일치하는 코드가 없습니다." << endl;
				system("pause");
			}
		}
	}
	
}

int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	int choice;

	while (true) {
		cout << "----------------------------------------------------------" << endl;
		cout << "1. 학생 추가" << endl;
		cout << "2. 강의 개설" << endl;
		cout << "3. 강의 삭제" << endl;
		cout << "4. 로그아웃" << endl;
		cout << "0. 종료" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << ">> ";
		cin >> choice;
		if (choice == 1)
			addStudent(studentIds, passwords, names, credits, appliedLectureCodes);
		else if (choice == 2)
			addLecture(lectureCodes, lectureNames, lectureCredits, limits);
		else if (choice == 3)
			deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes);
		else if (choice == 4)
			return -1;
		else if (choice == 0)
			return 0;
	}

	return -1;
}

void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	cout << "----------------------------------------------------------" << endl;
	cout << "학번: " << studentIds[user] << "\t이름: " << names[user] << "\t수강가능학점: " << credits[user] << endl;
	cout << "----------------------------------------------------------" << endl;
}

void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	string code;
	
	while(true){
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		cout << "신청할 과목 코드(0: 뒤로가기) >> ";
		cin >> code;
		
		if(code == "0")
			break;
		else{
			int lectureIndex = findLectureByCode(lectureCodes, code);
			int studentLectureSize = appliedLectureCodes[user].size();
			bool isAble = true;
			
			if(lectureIndex != -1){
				
				if(limits[lectureIndex] <= 0 ){
					cout << "수강정원이 꽉 찼습니다." << endl;
					isAble = false;
				}
				
				if(credits[user] - lectureCredits[lectureIndex] < 0 && isAble){
					cout << "수강 가능 학점이 부족합니다." << endl;
					isAble = false;
				}
				
				if(isAble){
					for(int i = 0; i < studentLectureSize; i++){
					
						int studentLectureIndex = findLectureByCode(lectureCodes, appliedLectureCodes[user][i]);
					
						if(lectureCodes[lectureIndex] == lectureCodes[studentLectureIndex]){
							cout << "이미 해당 과목을 신청했습니다." << endl;
							isAble = false;
							break;
						}
					
						else if(lectureNames[lectureIndex] == lectureNames[studentLectureIndex]){
							cout << "이미 동일명의 과목을 신청했습니다." << endl;
							isAble = false;
							break;
						}
					
					}
				}
				
				if(isAble){
					credits[user] -= lectureCredits[lectureIndex];
					limits[lectureIndex] -= 1;
					appliedLectureCodes[user].push_back(lectureCodes[lectureIndex]);
					cout << "[" << lectureCodes[lectureIndex] << "] " << lectureNames[lectureIndex] << "(을)를 성공적으로 신청하였습니다." << endl;
				}
				
				system("pause");
			}
		}
	}
}

void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	string code;
	
	while (true) {
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		cout << "철회할 과목 코드(0: 뒤로가기) >> ";
		cin >> code;
		if (code == "0") {
			break;
		}
		else {
			int lectureStudentSize = appliedLectureCodes[user].size();
			for (int i = 0; i < lectureStudentSize; i++) {
				if (code == appliedLectureCodes[user][i]) {
					int lectureIndex = findLectureByCode(lectureCodes, code);
					deleteElement(appliedLectureCodes[user], i);
					limits[lectureIndex] += 1;
					credits[user] += lectureCredits[lectureIndex];
					cout << "[" << lectureCodes[lectureIndex] << "] " << lectureNames[lectureIndex] << "(을)를 철회하였습니다." << endl;
					break;
				}
			}
			system("pause");
		}
	}
}

void changePassword(vector<string>& passwords, const int& user) {
	
	string password;

	cout << "----------------------------------------------------------" << endl;
	cout << "본인 확인을 위해 비밀번호를 한 번 더 입력해주세요." << endl;
	cout << "비밀번호: ";
	cin >> password;
	cout << "----------------------------------------------------------" << endl;

	if (password == passwords[user]) {
		cout << "----------------------------------------------------------" << endl;
		cout << "새로 설정할 비밀번호를 입력하세요." << endl;
		cout << "비밀번호: ";
		cin >> password;
		passwords[user] = password;
		cout << "변경되었습니다." << endl;
		cout << "----------------------------------------------------------" << endl;
	}
	else {
		cout << "비밀번호가 일치하지 않습니다." << endl;
		system("pause");
	}

}

int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	int choice;
	
	while(true){
		cout << "----------------------------------------------------------" << endl;
		cout << "1. 수강 신청" << endl;
		cout << "2. 수강 현황" << endl;
		cout << "3. 수강 철회" << endl;
		cout << "4. 비밀번호 변경" << endl;
		cout << "5. 로그아웃" << endl;
		cout << "0. 종료" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << ">> ";
		cin >> choice;
	
		if (choice == 1)
			applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		else if (choice == 2) {
			printStudent(studentIds, names, credits, user);
			printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
			system("pause");
		}
		else if (choice == 3)
			disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		else if (choice == 4) 
			changePassword(passwords, user);
		else if (choice == 5)
			return -1;
		else if (choice == 0)
			return 0;
	}
}