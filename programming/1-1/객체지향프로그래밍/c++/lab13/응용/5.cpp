#include <iostream>

using namespace std;

template<typename T>
class Queue{
private:
	T* p_list;
	int size;
	int MAX_SIZE;
public:
	Queue(int _MAX_SIZE = 1000);
	~Queue();

	int find_index(T _item);
	void Enqueue(T _item);
	T Dequeue();

	void print() const;
	int get_size();
	T get_item(int _index);
};

template<typename T>
Queue<T>::Queue(int _MAX_SIZE) {
	size = 0;
	MAX_SIZE = _MAX_SIZE;
	p_list = new T[MAX_SIZE];
}

template<typename T>
Queue<T>::~Queue() {
	delete[] p_list;
}
template<typename T>
int Queue<T>::find_index(T _item) {
	for (int i = 0; i < size; i++) {
		if (p_list[i] == _item)
			return i;
	}

	return -1;
}

template<typename T>
void Queue<T>::Enqueue(T _item) {
	if (size >= MAX_SIZE) {
		cout << "Error: out of memory" << endl;
		return;
	}
	if (find_index(_item) == -1) {
		p_list[size] = _item;
		size++;
	}
}

template<typename T>
T Queue<T>::Dequeue() {
	if (size <= 0) {
		cout << "Error: No item exist in the list" << endl;
	}

	T result = p_list[0];
	for (int i = 1; i < size; i++) {
		p_list[i - 1] = p_list[i];
	}
	size--;

	return result;
}


template<typename T>
void Queue<T>::print() const {
	
	cout << "Items in the list : ";

	for (int i = 0; i < size; i++) {
		cout << p_list[i] << ", ";
	}
	cout << endl;
}

template<typename T>
int Queue<T>::get_size() {
	return size;
}

template<typename T>
T Queue<T>::get_item(int _index) {
	if (_index < size)
		return p_list[_index];
}

int main() {

	Queue<int> int_queue;
	Queue<float> float_queue;
	Queue<char> char_queue;

	int_queue.Enqueue(1);
	int_queue.Enqueue(2);
	int_queue.Enqueue(2);
	int_queue.Enqueue(5);

	float_queue.Enqueue(4.3f);
	float_queue.Enqueue(2.5f);
	float_queue.Enqueue(3.7f);
	float_queue.Enqueue(3.7f);

	char_queue.Enqueue('b');
	char_queue.Enqueue('b');
	char_queue.Enqueue('c');
	char_queue.Enqueue('a');

	cout << "<Before Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();

	int_queue.Dequeue();
	float_queue.Dequeue();
	float_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();

	cout << "<After Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();

	return 0;
}