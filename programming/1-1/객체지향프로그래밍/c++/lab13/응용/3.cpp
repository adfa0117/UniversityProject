#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	string rev;

	while (1) {
		cout << "���ڿ� �ϳ��� �Է����ּ��� : ";
		cin >> input;
		if (input == "Q" || input == "q") {
			cout << "�����մϴ�.";
			break;
		}

		[&rev](string origin){

			rev = origin;

			reverse(rev.begin(), rev.end());
		}(input);

		cout << "�Է��Ͻ� ���ڿ��� ���� : " << rev << endl;

		if (input == rev) cout << "�� ���ڴ� ȸ���Դϴ�." << endl;
		else cout << "�� ���ڴ� ȸ���� �ƴմϴ�" << endl;
	}

	return 0;
}