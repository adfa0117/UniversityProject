#pragma once
#include <vector>
#include "item.h"
#include "FoodItem.h"
#include "OfficeItem.h"

class ApplicationClass
{
private:
	vector<Item*> vItem;
	string officeItemFileName;
	string foodItemFileName;
public:
	ApplicationClass(string officeName, string foodName);
	~ApplicationClass();

	void run();
	string getCommand();
	void displayAllitem();
	void displayFoodItem();
	void displayOfficeItem();
	void searchItemByCode();
};

