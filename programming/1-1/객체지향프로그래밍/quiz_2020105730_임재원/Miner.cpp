#include "Miner.h"

Miner::Miner(int _type, string _name, int _price, int _mining_point) : Unit::Unit(_type, _name, _price), mining_point(_mining_point) {}

int Miner::action() {
	return mining_point;
}