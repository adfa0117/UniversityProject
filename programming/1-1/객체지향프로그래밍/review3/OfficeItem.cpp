#include "OfficeItem.h"
#include <iostream>

void OfficeItem::displayItem() const {
	cout << code << "\t" << name << "\t" << price << "\t" << company << endl;
}

int OfficeItem::readItemFromFile(ifstream& fin) {
	string _code;
	string _name;
	int _price;
	string _company;
	bool isAble = true;

	fin >> _code;
	if (!fin) isAble = false;
	fin >> _name;
	if (!fin) isAble = false;
	fin >> _price;
	if (!fin) isAble = false;
	fin >> _company;
	if (!fin) isAble = false;

	if (isAble) {
		code = _code;
		name = _name;
		price = _price;
		company = _company;
		return 1;
	}
	else return 0;

}

void OfficeItem::writeItemToFile(ofstream& fout) {
	fout << code << "\t" << name << "\t" << price << "\t"<< company <<endl;
}