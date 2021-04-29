#pragma once
#include <string>
#include <fstream>

using namespace std;

class Item
{
protected:
	string code;
	string name;
	int price;
public:
	Item(string _code = "", string _name = "", int _price = 0);

	void setCode(string _code);
	string getCode();

	void setName(string _name);
	string getName();

	void setPrice(int _price);
	int getPrice();

	void setItem(string _code, string _name, int _price);

	virtual void displayItem() const = 0;
	virtual int readItemFromFile(ifstream& fin) = 0;
	virtual void writeItemToFile(ofstream& fout) = 0;
};

