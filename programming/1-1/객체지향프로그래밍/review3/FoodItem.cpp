#include "FoodItem.h"
#include <iostream>

void FoodItem::displayItem() const{
	cout << code << "\t" << name << "\t" << price << "\t" << dueDate << endl;
}

int FoodItem::readItemFromFile(ifstream& fin) {
	string _code;
	string _name;
	int _price;
	int _dueDate;
	bool isAble = true;

	fin >> _code;
	if (!fin) isAble = false;
	fin >> _name;
	if (!fin) isAble = false;
	fin >> _price;
	if (!fin) isAble = false;
	fin >> _dueDate;
	if (!fin) isAble = false;

	if (isAble) {
		code = _code;
		name = _name;
		price = _price;
		dueDate = _dueDate;
		return 1;
	}
	else return 0;

}

void FoodItem::writeItemToFile(ofstream& fout) {
	fout << code << "\t" << name << "\t" << price << "\t" << dueDate <<endl;
}