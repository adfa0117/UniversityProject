#include <iostream>
using namespace std;

int main(){
	for(int i = 1; i <= 5; i++){
		int num;
		cout << i << "번째 정수 : ";
		cin >> num;
		if(num%2 == 0){
			cout << num << "은(는) 짝수입니다." << endl;
		}
		else{
			cout << num << "은(는) 홀수입니다." << endl;
		}
	}

	return 0;
}