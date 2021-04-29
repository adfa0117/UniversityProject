#include "Attacker.h"

Attacker::Attacker(int _type, string _name, int _price, int _attack_point) : Unit::Unit(_type, _name, _price), attack_point(_attack_point){}

int Attacker::action(){
	return attack_point;
}