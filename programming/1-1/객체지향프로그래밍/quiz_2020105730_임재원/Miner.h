#pragma once
#include <string>
#include "Unit.h"

using namespace std;

class Miner : public Unit{
protected:
	int mining_point;
public:
	Miner(int _type, string _name, int _price, int _mining_point);
	int action() override;
};