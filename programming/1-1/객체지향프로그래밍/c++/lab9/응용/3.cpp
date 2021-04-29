#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* ArrInit(int n);
void ArrPrint(int* arr, int len);
bool ArrChkDup(int* arr, int len);

int main(){
	
	srand((unsigned int)time(NULL));
	
	int n, len;
	int* arr = NULL;
	
	while(true){
		cout << "Please enter a number: ";
		cin >> n;
		
		if(n < 2){
			cout << "Wrong number!!!";
			break;
		}
		
		arr = ArrInit(n);
		len = n / 2;
		
		cout << "Size of random array: " << len << endl;
		
		ArrPrint(arr, len);
		if(ArrChkDup(arr, len))
			cout << "Duplicates found." << endl;
		else
			cout << "Duplicates not found." << endl;
		
		cout << endl;
		
	}
	
	return 0;
}

int* ArrInit(int n){
	
	int len = n / 2;
	static int* arr;
	delete[] arr;
	arr = new int[len];
	
	for(int i = 0; i < len; i++){
		arr[i] = rand()%n + 1;
	}

	return arr;
}

void ArrPrint(int* arr, int len){
	
	cout << "[ Array ]" << endl;
	
	for(int i = 0; i < len; i++){
		cout << arr[i] << " ";
	}
	
	cout << endl;
}

bool ArrChkDup(int* arr, int len){
	
	for(int i = 0; i < len; i ++)
		for(int j = i + 1; j < len; j++)
			if(arr[i] == arr[j])
				return true;
	
	return false;
}
