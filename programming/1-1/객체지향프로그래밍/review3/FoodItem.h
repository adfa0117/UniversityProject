#pragma once
#include "Item.h"

class FoodItem : public Item {
private:
	int dueDate;
public:
	void displayItem() const override;
	int readItemFromFile(ifstream& fin) override;
	void writeItemToFile(ofstream& fout) override;
};