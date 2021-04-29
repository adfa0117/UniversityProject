#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void LoadStr(string& msg, string file){
	ifstream fin;
	fin.open(file);
	string temp;
	
	while(getline(fin, temp)){
		msg = msg + temp + "\n";
	}
	
	fin.close();
}

int main(){
	ofstream fout("output.txt");
	string msg = "";
	
	LoadStr(msg, "msg_1.txt");
	msg += "\n";
	LoadStr(msg, "msg_2.txt");
	
	fout << msg;
	
	fout.close();
}

