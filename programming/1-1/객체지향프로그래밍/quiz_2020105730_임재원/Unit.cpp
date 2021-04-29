#include "Unit.h"

Unit::Unit(int _type, string _name, int _price) : type(_type), name(_name), price(_price) {}

int Unit::get_type(){
	return type;
}

string Unit::get_name(){
	return name;
}

int Unit::get_price(){
	return price;
}