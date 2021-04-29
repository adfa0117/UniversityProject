#include <iostream>
#include <string>

using namespace std;

class Account{
	string name;
	string id;
	int balance;
	
public:
	Account(string _name, string _id, int _balance) {
		this->name = _name;
		this->id = _id;
		this->balance = _balance;
	}

	Account& operator+(Account& ac){
		this->balance += ac.balance;
		return (*this);
	}
	
	Account& operator+(int bal){
		this->balance += bal;
		return (*this);
	}
	
	Account& operator-(Account& ac){
		this->balance -= ac.balance;
		return (*this);
	}
	
	Account& operator-(int bal){
		this->balance -= bal;
		return (*this);
	}
	
	string getName(){
		return this->name;
	}
	
	string getId(){
		return this->id;
	}
	
	int getBalance(){
		return this->balance;
	}
};

ostream& operator<<(ostream& cout, Account& ac) {
	cout << "학번 : " << ac.getId() << ", 이름 : " << ac.getName() << ", 잔액 : " << ac.getBalance();
	return cout;
}

int main(){
	
	Account acnt[3] = {
		Account("장윤호", "2014", 10000), 
		Account("김유민", "2019", 0), 
		Account("박진배", "2013", 5000)
	};
	
	string sender, receiver;
	int senderIndex = -1, receiverIndex = -1;
	
	while(1){

		senderIndex = -1, receiverIndex = -1;

		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> sender;
		
		if(sender == "종료"){
			cout << "종료합니다." << endl;
			break;
		}
		
		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		cin >> receiver;
		
		if(sender == receiver){
			cout << "돈을 보내는 학생과 보낼 학생의 학번이 똑같습니다. 다시 입력해주세요." << endl;
			continue;
		}
		
		for(int i = 0; i < 3; i++){
			if(acnt[i].getId() == sender) senderIndex = i;
			else if(acnt[i].getId() == receiver) receiverIndex = i;
		}
		
		if(senderIndex == -1 || receiverIndex == -1){
			cout << "보내는 학생 혹은 받은 학생은 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
			continue;
		}
		
		if(acnt[senderIndex].getBalance() == 0){
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
			continue;
		}
		
		acnt[receiverIndex] = acnt[receiverIndex] + acnt[senderIndex];
		acnt[senderIndex] = acnt[senderIndex] - acnt[senderIndex];
		
		cout << "보낸 학생의 잔액 => " << acnt[senderIndex] << endl;
		cout << "받은 학생의 잔액 => " << acnt[receiverIndex] << endl;
	}
	
	for(int i = 0; i < 3; i++){
		cout << acnt[i] << endl;
	}
	
	
	
	return 0;
}