#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream fin("msg.txt");
	ofstream fout("print.txt");
	string msg = "";
	char ch;
	int maxLen = 0;

	cout << "length = ";
	cin >> maxLen;

	while (true) {
		for (int i = 0; i < maxLen; i++) {
			fin.get(ch);
			if (ch != '\n')
				msg += ch;
			else
				msg += " ";
			if (!fin)
				break;
			
		}
		if (!fin)
			break;
		msg += "\n";
	}

	fout << msg;
	
	fin.close();
	fout.close();
}