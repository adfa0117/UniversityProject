#include "Item.h"
#include <iomanip>

Item::Item(string _code, string _name, int _price) {
	code = _code;
	name = _name;
	price = _price;
}

void Item::setCode(string _code) {
	code = _code;
}

string Item::getCode() {
	return code;
}

void Item::setName(string _name) {
	name = _name;
}

string Item::getName() {
	return name;
}

void Item::setPrice(int _price) {
	price = _price;
}

int Item::getPrice() {
	return price;
}

void Item::setItem(string _code, string _name, int _price) {
	code = _code;
	name = _name;
	price = _price;
}