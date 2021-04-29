#include "ApplicationClass.h"
#include <iostream>

ApplicationClass::ApplicationClass(string foodName, string officeName) {
	officeItemFileName = officeName;
	foodItemFileName = foodName;

	Item* temp = new OfficeItem;
	ifstream fin(officeItemFileName);
	while (temp->readItemFromFile(fin)) {
		vItem.push_back(temp);
		temp = new OfficeItem;
	}
	fin.close();

	temp = new FoodItem;
	fin.open(foodItemFileName);
	while (temp->readItemFromFile(fin)) {
		vItem.push_back(temp);
		temp = new FoodItem;
	}
	fin.close();
}

ApplicationClass::~ApplicationClass() {
	int  size = vItem.size();
	string code;
	ofstream foodOut(foodItemFileName);
	ofstream officeOut(officeItemFileName);

	for (int i = 0; i < size; i++) {
		code = vItem[i]->getCode();
		if (code[0] == 'C') vItem[i]->writeItemToFile(officeOut);
		if (code[0] == 'F') vItem[i]->writeItemToFile(foodOut);
		delete vItem[i];
		vItem[i] = NULL;
	}
}

void ApplicationClass::run() {
	string sOption;
	while (1) {
		sOption = getCommand();
		if (sOption == "1") displayAllitem();
		else if (sOption == "2") displayFoodItem();
		else if (sOption == "3") displayOfficeItem();
		else if (sOption == "4") searchItemByCode();
		else if (sOption == "5") break;
	}

	cout << "Exit the program..." << endl;
}

string ApplicationClass::getCommand() {
	string command;

	cout << "1. Display all items." << endl;
	cout << "2. Display food items." << endl;
	cout << "3. Display office items." << endl;
	cout << "4. Search item by code." << endl;
	cout << "5. Quit." << endl;
	cout << "input>";
	cin >> command;

	return command;
}

void ApplicationClass::displayAllitem(){
	int size = vItem.size();

	for (int i = 0; i < size; i++) {
		vItem[i]->displayItem();
	}
}

void ApplicationClass::displayFoodItem() {
	int size = vItem.size();
	string code;

	for (int i = 0; i < size; i++) {
		code = vItem[i]->getCode();
		if (code[0] == 'F') vItem[i]->displayItem();
	}
}

void ApplicationClass::displayOfficeItem(){
	int size = vItem.size();
	string code;

	for (int i = 0; i < size; i++) {
		code = vItem[i]->getCode();
		if (code[0] == 'C') vItem[i]->displayItem();
	}
}

void ApplicationClass::searchItemByCode(){
	string code;
	int size = vItem.size();

	cout << "Enter the code : ";
	cin >> code;

	for (int i = 0; i < size; i++) {
		if (vItem[i]->getCode() == code) {
			vItem[i]->displayItem();
			return;
		}
	}

	cout << "No items found." << endl;
}