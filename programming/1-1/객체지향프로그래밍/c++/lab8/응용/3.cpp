#include <iostream>
#include <vector>

using namespace std;

void ReverseVector(vector<int>& vec);
void PrintVector(vector<int>& vec);

int main(){
	
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	cout << "기본 Vector 값:" << endl;
	PrintVector(vec);

	ReverseVector(vec);
	
	cout<< "함수 실행 후 Vector값:" << endl;
	PrintVector(vec);
	
	return 0;
}

void ReverseVector(vector<int>& vec){
	int size = vec.size();
	int temp;
	for(int i = 0; i <= size/2 - 1; i ++){
		temp = vec[i];
		vec[i] = vec[size - i - 1];
		vec[size - i - 1] = temp;
	}
}

void PrintVector(vector<int>& vec){
	for(int elem : vec)
		cout << " " << elem;
	cout << endl;
}