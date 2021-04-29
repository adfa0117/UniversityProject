#include <iostream>
#include <string>
#include "Text.h"
#include "FancyText.h"
#include "FixedText.h"

using namespace std;

int main(){
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;
	
	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;
	
	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;

	return 0;
}