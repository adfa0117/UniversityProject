#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class VectorList{
	vector<double*> vItem;
	vector<int> vLength;
public:
	~VectorList(){
		for(double* item : vItem)
			delete[] item;
	}
	
	void append(double* _pArray	, int _length){
		vItem.push_back(_pArray);
		vLength.push_back(_length);
	}
	
	int findVector(double* _pArray, int _length){
		int size = vItem.size();
		
		for(int i = 0; i < size; i++)
			if(vLength[i] == _length){
				bool isSame = true;
				
				for(int j = 0; j < _length; j++)
					if(vItem[i][j] != _pArray[j]){
						isSame = false;
						break;
					}
						
				
				if(isSame)
					return i;
			}
				
		
		return -1;
	}
	
	void print_single_vector(int idx){
		int size = vItem.size();
		if(idx >= size || idx < 0){
			cout << "[Wrong index]" << endl;
		}
		else{
			cout << idx << "-th vector: ";
			for(int i = 0; i < vLength[idx]; i++){
				cout << setw(8) << vItem[idx][i];
			}
			cout << endl;
		}
	}
	void print_all_vectors(){
		int size = vItem.size();
		for(int i = 0; i < size; i++){
			this->print_single_vector(i);
		}
	}
};

int main(){
	
	VectorList vectorList;
	double* pTemp = new double[3]{1.1, 2.2, 3.3};
	vectorList.append(pTemp, 3);
	
	pTemp = new double[5]{10.1, 10.2, 10.3, 10.4, 10.5};
	vectorList.append(pTemp, 5);
	
	pTemp = new double[2]{4.5, 5.5};
	vectorList.append(pTemp, 2);
	
	vectorList.print_single_vector(-1);
	vectorList.print_single_vector(0);
	cout << endl;
	
	vectorList.print_all_vectors();
	cout << endl;
	
	double* pTemp1 = new double[2]{4.5, 5.5};
	double* pTemp2 = new double[4]{1.1, 2.2, 5.5, 4.4};
	
	cout << "Index of vector{4.5, 5.5} :" << vectorList.findVector(pTemp1, 2) << endl;
	cout << "Index of vector{1.1, 2.2, 3.3, 4.4} :" << vectorList.findVector(pTemp2, 4) << endl;

	delete[] pTemp1;
	delete[] pTemp2;
	
	return 0;
}