#include "ApplicationType.h"

ApplicationType::ApplicationType(){
	unit_list_in_barracks = { new Attacker(1, "swordsman", 300, 10), new Attacker(1, "champion", 1200, 16), new Miner(0, "farmor", 200, 20), new Miner(0, "landlord", 500, 50) };
	curr_turn = 1;
	MAX_turn = 50;
	gold = 1000;
	enemy_hp = 500;
	flag_status = 0;
}

ApplicationType::~ApplicationType(){
	for (Unit* unit : unit_list_in_barracks) {
		delete unit;
	}

	for (Unit* unit : unit_list) {
		delete unit;
	}
}

void ApplicationType::incresase_turn() {

}

void ApplicationType::print_unit_list_in_barracks() {

}

void ApplicationType::print_unit_list(){

}

void ApplicationType::run() {
	string sOption;
	while (flag_status == 0) {
		sOption = get_command();
		if (sOption == "1") hire_unit();
		else if (sOption == "2") attack_to_enemy();
		else if (sOption == "3") gather_money();
		else if (sOption == "4") print_unit_list();
		else if (sOption == "5") break;

	}
	cout << "Exit the program..." << endl;
}

string ApplicationType::get_command(){
	cout << "Trun: " << curr_turn << "/" << MAX_turn << endl;
	cout << "Gold: " << gold << endl;
	cout << "Enemy HP: " << enemy_hp << endl << endl;

	cout << "1. Hire Unit" << endl;
	cout << "2. Attack to Enemy" << endl;
	cout << "3. Gather Money" << endl;
	cout << "4. Print Units" << endl;
}

bool ApplicationType::hire_unit() {

}

void ApplicationType::attack_to_enemy() {

}

void ApplicationType::gather_money() {

}