#include <iostream>
#include <string>

using namespace std;

class Avengers {
protected:
	string name;
	int attack_point;
	int defense_point;
	int health;
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}

	virtual void set(string _name, int _attack, int _defense, int _health) {}
	virtual int attack() { return 0; }
	virtual void defense(int _attack_point) {}
	virtual void prin_info() {}
};

class Character : public Avengers {
public:
	void set(string _name, int _attack, int _defense, int _health) override{
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}

	int attack() override { 
		return attack_point; 
	}

	void defense(int _attack_point) override {
		int damage = _attack_point - defense_point;
		if (damage < 0) damage = 0;
		health -= damage;
		if (health < 0) health = 0;
	}

	void prin_info() override {
		cout << "Name: " << name << endl;
		cout << "Attack_Point: " << attack_point << endl;
		cout << "Defense_Point: " << defense_point << endl;
		cout << "Health: " << health << endl;
	}

	int get_health() {
		return health;
	}
};

int main() {
	Character my_char;
	Character enemy_char;

	Character IronMan;
	Character CaptainAmerica;
	Character Thor;

	IronMan.set("Iron Man", 70, 40, 100);
	CaptainAmerica.set("Captain America", 60, 50, 100);
	Thor.set("Thor", 100, 10, 100);

	string chara;

	cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
	cin >> chara;

	if (chara == "IronMan") {
		my_char = IronMan;
		enemy_char = CaptainAmerica;
	}
	else if (chara == "CaptainAmerica") {
		my_char = CaptainAmerica;
		enemy_char = Thor;
	}
	else if (chara == "Thor") {
		my_char = Thor;
		enemy_char = IronMan;
	}

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t" << "Enemy Life: " << enemy_char.get_health() << endl;

	while (1) {
		enemy_char.defense(my_char.attack());
		cout << "My Life: " << my_char.get_health() << "\t" << "Enemy Life: " << enemy_char.get_health() << endl;
		if (enemy_char.get_health() <= 0) {
			cout << "You WIn!";
			break;
		}

		my_char.defense(enemy_char.attack());
		cout << "My Life: " << my_char.get_health() << "\t" << "Enemy Life: " << enemy_char.get_health() << endl;
		if (my_char.get_health() == 0) {
			cout << "You Lose..";
			break;
		}
		
	}

	return 0;
}