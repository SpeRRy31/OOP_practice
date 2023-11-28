#include <iostream>

template<typename T>
class Vector {
	T* array = new T[10];
	int size;
	int capacity;

public:
	Vector();
	~Vector();

	int getSize();
	int getCapacity();

	void push_back(T element);
	void pop_back();

	T at(int index);
	T operator[](int index);

	void display();
};

template<typename T>
Vector<T>::Vector() {
	this->size = 0;
	this->capacity = 10;
}

template<typename T>
int Vector<T>::getCapacity() {
	return this->capacity;
}

template<typename T>
int Vector<T>::getSize() {
	return this->size;
}

template<typename T>
void Vector<T>::push_back(T element){
	if(size==capacity){
		T* addArray = new T[capacity * 2];
		for (int i = 0; i < size; i++) {
			addArray[i] = array[i];
		}
		delete[] array;
		array = addArray;
		capacity *= 2;
	}
	array[size++] = element;
}

template<typename T>
void Vector<T>::pop_back() {
	if (size > 0) {
		size--;
	}
}

template<typename T>
T Vector<T>::at(int index) {
	if (index >= 0 && index < size) {
		return array[index];
	}
	else {
		std::cout << "не існує елемента з таким індексом";
	}
}

template<typename T>
T Vector<T>::operator[](int index) {
	return at(index);
}

template<typename T>
void Vector<T>::display() {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
template<typename T>
Vector<T>::~Vector() {
	delete[] array;
}