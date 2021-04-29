#include <iostream>
#include <string>

using namespace std;

class Account{
	string name;
	string id;
	int balance;
	
	static int returnBalance;
	
public:
	Account(string _name, string _id, int _balance){
		this -> name = _name;
		this -> id = _id;
		this -> balance = _balance;
	}

	Account() {
		this->name = "";
		this->id = "";
		this->balance = 0;
	}
	
	string getId(){
		return this->id;
	}
	
	~Account(){
		returnBalance += this->balance;
	}
	
	int getReturnBalance(){
		return returnBalance;
	}

	void setInfo(string _name, string _id, int _balance) {
		this->name = _name;
		this->id = _id;
		this->balance = _balance;
	}
	
};

int Account::returnBalance = 0;

int main(){
	
	int size;
	
	cout << "총 학생 수 입력: ";
	cin >> size;
	
	Account* acnt = new Account[size];
	
	string id;
	string name;
	int balance;
	bool overlap = false;
	
	for(int i = 0; i < size; i++){
		cout << i+1 << "번째 학생 계좌 입력 : " << "학번 : ";
		cin >> id;
		
		cout << endl << "이름 : ";
		cin >> name;
		
		cout << endl << "잔액 : ";
		cin >> balance;
		
		cout << "==============";
		
		for(int j = 0; j < i; j++){
			if(acnt[j].getId() == id){
				overlap = true;
				break;
			}
		}

		if (overlap) break;
		
		acnt[i].setInfo(name, id, balance);

		cout << endl << endl;
	}
	
	delete[] acnt;
	
	cout << "회수된 금액 : " << Account().getReturnBalance() << endl;
	
	return 0;
}