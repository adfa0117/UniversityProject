#pragma once
#include <string>
#include "Unit.h"

using namespace std;

class Attacker : public Unit {
protected:
	int attack_point;
public:
	Attacker(int _type, string _name, int _price, int _attack_point);
	int action() override;
};