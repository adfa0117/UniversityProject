#include <iostream>
#include <string>

using namespace std;

class Base{
protected:
	void print_base(){cout << "Base" << endl;}
};

class Derived : private Base{
public:
	void print_derived(){
		Base::print_base();
		cout << "Derived" << endl;
	}
};

int main(){
	Base base;
	Derived derived;
	
	derived.print_derived();
	
	return 0;
}