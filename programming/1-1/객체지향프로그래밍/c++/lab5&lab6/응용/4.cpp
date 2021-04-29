#include <iostream>
using namespace std;

int main(){
	int num;
	while(true){
		cout << "단 수를 입력하세요: ";
		cin >> num;
		if(num > 0 && num < 10){
			for(int i = 1; i <= num; i ++){
				cout << num << "*" << i << " = " << num * i << endl;
			}
			cout << endl;
		}
		else if (num == -1){
			cout << "종료합니다";
			break;
		}
		else{
			cout << "1 부터 9까지의 정수를 입력해주세요." << endl << endl;
		}
	}
}