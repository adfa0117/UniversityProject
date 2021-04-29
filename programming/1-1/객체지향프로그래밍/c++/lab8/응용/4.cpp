#include <iostream>
#include <vector>

using namespace std;

int inputGrade(float grade);
int* topGrade(const vector<int>& grade);

int main(){
	
	vector<int> grades;
	float _grade = 0;
	int* top;
	
	for(int i = 0; i < 3; i++){
		cout << "Input " << i << "-th grade(0~100):";
		int grade = inputGrade(_grade);
		grades.push_back(grade);
	}
	
	top = topGrade(grades);
	cout << "Top Grade: " << *top;
	
	return 0;
}

int inputGrade(float grade){
	cin >> grade;
	if((grade - (int)grade) != 0.0 || grade < 0 || grade > 100){
		cout << "invalid input!!" << endl;
		exit(EXIT_FAILURE);
	}
	else
		return grade;	
}

int* topGrade(const vector<int>& grade){
	int topGrade = 0;
	for(int elem : grade){
		if (elem > topGrade)
			topGrade = elem;
	}
	return &topGrade;
}