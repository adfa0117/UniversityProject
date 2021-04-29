#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Unit.h"
#include "Attacker.h"
#include "Miner.h"

using namespace std;

class ApplicationType {
private:
	vector<Unit*> unit_list_in_barracks;
	vector<Unit*> unit_list;
	int curr_turn;
	int MAX_turn;
	int gold;
	int enemy_hp;
	int flag_status;
public:
	ApplicationType();
	~ApplicationType();

	void incresase_turn();
	void print_unit_list_in_barracks();
	void print_unit_list();

	void run();
	string get_command();
	bool hire_unit();
	void attack_to_enemy();
	void gather_money();
};