#include <iostream>
#include <vector>

using namespace std;

bool found_char(const char* s, char ch);

int main(){
	
	const char* phrase = "phrase";
	
	for(char ch = 'a'; ch <= 'z'; ch++){
		cout << ch << " is ";
		if(!found_char(phrase, ch))
			cout << "NOT";
		cout << " in (" << phrase << ")" << endl;
	}
	
	return 0;
}

bool found_char(const char* s, char ch){
	int i = 0;
	while(*(s + i) != '\0'){
		if(*(s + i) == ch)
			return true;
		i++;
	}
	
	return false;
}