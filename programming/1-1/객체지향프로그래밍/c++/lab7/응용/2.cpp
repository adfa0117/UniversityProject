#include <iostream>
#include <string>
using namespace std;

int main(){
	string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
	int word_start = 0, word_end = 0;
	int pos = 0;
	string keyword;
	string word;

	cout << "키워드 : ";
	cin >> keyword;

	cout << endl;
	
	cout << "검색결과 : ";
	while(data.find(",", word_end) != string::npos){
		word_end = data.find(",", word_end +1);
		word = data.substr(word_start, word_end - word_start);
		pos = word.find(keyword);
		if (pos != string::npos)
			cout << word << " ";
		word_start = word_end + 1;
	}
}