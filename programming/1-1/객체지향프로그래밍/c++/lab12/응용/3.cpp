#include <iostream>

using namespace std;

class Train {
protected:
	int mPeople;
public:
	Train() {}
	Train(int people) {
		mPeople = people;
	}
	~Train() {}

	virtual int station(int takeOff, int takeOn) {
		if (mPeople < takeOff) return -1;
		mPeople -= takeOff;
		if (mPeople + takeOn > 300) return -2;
		mPeople += takeOn;
		return 1;
	}
};

class Ktx : public Train{
public:
	Ktx() : Train(0){}
	Ktx(int people) : Train(people) {}
	~Ktx() {}

	int station(int takeOff, int takeOn) override{
		if (mPeople < takeOff) return -1;
		mPeople -= takeOff;
		if (mPeople + takeOn > 300) return -2;
		mPeople += takeOn;
		return 1;
	}

	int getPeople() {
		return mPeople;
	}
};

int main() {
	Ktx k;
	int count = 0;
	int people[5];
	int takeOn, takeOff;
	int result;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번역: ";
		cin >> takeOff >> takeOn;
		result = k.station(takeOff, takeOn);
		if (result == -1) {
			cout << "정원 미달입니다." << endl;
			break;
		}
		else if (result == -2) {
			cout << "정원 초과입니다." << endl;
			break;
		}
		count++;
		people[i] = k.getPeople();
	}

	if (count == 5) {
		int max = 0;
		for (int i = 0; i < 5; i++) {
			if (max < people[i]) max = people[i];
		}

		cout << "가장 많은 사람이 탑승 했을 때의 사람 수 : " << max << endl;
	}


	return 0;
}