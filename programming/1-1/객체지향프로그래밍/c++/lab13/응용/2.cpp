#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
	
	vector<int> vec1;
	vector<int> vec2;
	int min = 0, max = 0;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++) {
		vec1.push_back(rand() % 11);
		vec2.push_back(rand() % 21);
	}

	auto begin1 = begin(vec1);
	auto begin2 = begin(vec2);
	auto end1 = end(vec1);
	auto end2 = end(vec2);

	cout << "<vector 1>" << endl;
	for (auto iter = begin1; iter != end1; iter++) {
		cout << *iter << " ";
	}

	cout << endl;

	cout << "<vector 2>" << endl;
	for (auto iter = begin2; iter != end2; iter++) {
		cout << *iter << " ";
	}

	cout << endl;

	for (auto iter1 = begin1; iter1 != end1; iter1++)
		for (auto iter2 = begin2; iter2 != end2; iter2++) {
			int mult = (*iter1) * (*iter2);
			if (mult > max) max = mult;
			if (mult < min) min = mult;
		}

	cout << "ÃÖ´ñ°ª = " << max << endl;
	cout << "ÃÖ¼Ú°ª = " << min << endl;

	return 0;

}