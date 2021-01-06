/*
author: Shehzad Khan
date: 14.12.2020
version: Alpha 0.1
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Array {
	float* data; //attribute is a pointer for values in the heap section
	int size; //attribute will contain the size of the array
	Array create(int size) {
		Array a;
		a.data = new float[size]; //reserves space in the heap section
		a.size = size;
		return a;
	}
	void destroy(Array& a) {
		delete[] a.data; //sets reserved space free
		a.data = nullptr;
		a.size = 0;
	}
	void print() {
		for (int i = 0; i < size; i++)
			cout << *(data + i) << " "; //outputs every element of the array
		cout << endl;
	}
	void fillRandom() {
		srand(time(nullptr));
		for (int i = 0; i < size; i++)
			*(data + i) = rand(); //fills array with random values
	}
	void copy(Array& b) {
		if (size > b.size) {
			Array c = c.create(size); //creates new array if there is not enough space in the array where the values have to be copied
			for (int i = 0; i < b.size; i++)
				*(c.data + i) = *(b.data + i);
			destroy(b);
			b = c;
		}
		for (int i = 0; i < size; i++)
			*(b.data + i) = *(data + i); //copies values into the target array
	}
	void resize(int aSize) {
		if (aSize < size)
			return; //quits function if the new size is smaller than the current size of the array
		Array a = a.create(aSize);
		copy(a);
		destroy(*this);
		*this = a;
	}
};

//functionality demonstration
int main()
{
	Array a = a.create(5);
	a.print();
	a.fillRandom();
	a.print();
	Array b = b.create(3);
	b.print();
	a.copy(b);
	b.print();
	b.resize(9);
	b.print();
	b.fillRandom();
	b.print();
	a.destroy(a);
	b.destroy(b);
	return 0;
}
