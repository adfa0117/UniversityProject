#pragma once
#include "Item.h"

class OfficeItem : public Item {
private:
	string company;
public:
	void displayItem() const override;
	int readItemFromFile(ifstream& fin) override;
	void writeItemToFile(ofstream& fout) override;
};