#pragma once
#include <string>

using namespace std;

class Unit{
protected:
	int type;
	string name;
	int price;
public:
	Unit(int _type, string _name, int _price);
	virtual int action() = 0;
	int get_type();
	string get_name();
	int get_price();	
};