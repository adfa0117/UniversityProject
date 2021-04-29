#include <iostream>

using namespace std;

template<typename T>
class CList {
private:
	T m_Array[5];
	int m_Length;
public:
	CList();
	~CList();

	bool IsEmpty();
	bool IsFull();

	void Add(T data);
	void Delete(T data);
	void Print();
};

int command();

int main() {
	
	CList<int> list;
	int input;
	int com;

	while (1) {
		com = command();
		switch (com)
		{
		case 1:
			cout << "\n�߰��� ������: ";
			cin >> input;
			list.Add(input);
			break;
		case 2:
			cout << "\n������ ������: ";
			cin >> input;
			list.Delete(input);
			break;
		case 3:
			list.Print();
			break;
		case 4:
			cout << "\n\t���α׷��� �����մϴ�\n";
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}

template<typename T>
CList<T>::CList() {
	m_Length = 0;
}

template<typename T>
CList<T>::~CList() {
}

template<typename T>
bool CList<T>::IsEmpty() {
	if (m_Length == 0) return true;
	return false;
}

template<typename T>
bool CList<T>::IsFull() {
	if (m_Length == 5) return true;
	return false;
}

template<typename T>
void CList<T>::Add(T data) {
	if (this->IsFull()) {
		cout << "\tList is full" << endl;
		return;
	}
	
	if (this->IsEmpty()) {
		m_Array[0] = data;
		m_Length++;
		return;
	}

	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i] == data) {
			cout << " �ߺ��� �����Ͱ� �����մϴ�." << endl;
			return;
		}
		if (m_Array[i] > data) {
			for (int j = m_Length - 1; j >= i; j--) 
				m_Array[j + 1] = m_Array[j];
			m_Array[i] = data;
			m_Length++;
			return;
		}
	}

	m_Array[m_Length] = data;
	m_Length++;
}

template<typename T>
void CList<T>::Delete(T data) {
	if (this->IsEmpty()) {
		cout << "\tList is empty" << endl;
		return;
	}

	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i] == data) {
			for (int j = i; j < m_Length - 1; j++) 
				m_Array[j] = m_Array[j + 1];
			m_Length--;
			return;
		}
	}
}

template<typename T>
void CList<T>::Print() {
	cout << "�� Current List" << endl;
	for (int i = 0; i < m_Length; i++) {
		cout << m_Array[i] << " ";
	}
	cout << endl;
}

int command() {
	int num;

	cout << "\n\t----menu----" << endl;
	cout << "\t1. ����Ʈ �߰�" << endl;
	cout << "\t2. ����Ʈ ����" << endl;
	cout << "\t3. ����Ʈ ���" << endl;
	cout << "\t4. ���α׷� ����" << endl;
	cout << "\n\t�Է� --> ";
	cin >> num;
	return num;
}