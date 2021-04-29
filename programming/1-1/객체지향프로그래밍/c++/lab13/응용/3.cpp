#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	string rev;

	while (1) {
		cout << "문자열 하나를 입력해주세요 : ";
		cin >> input;
		if (input == "Q" || input == "q") {
			cout << "종료합니다.";
			break;
		}

		[&rev](string origin){

			rev = origin;

			reverse(rev.begin(), rev.end());
		}(input);

		cout << "입력하신 문자열의 역순 : " << rev << endl;

		if (input == rev) cout << "이 문자는 회문입니다." << endl;
		else cout << "이 문자는 회문이 아닙니다" << endl;
	}

	return 0;
}