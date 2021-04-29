#include <iostream>
using namespace std;

int main(){
	char key;
	cout << "Enter a key (p or q): ";
	cin >> key;
	switch(key){
		case 'P':
		case 'p':
			cout << "Pause";
			break;
		case 'Q':
		case 'q':
			cout << "Quit";
			break;
		default :
			cout << "Default";
			break;
	}
	
	return 0;
}