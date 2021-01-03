/*
Author: Shehzad Khan
Date: 14.12.2020
Alpha version
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Array {
	float* data;
	int size;
	Array create(int size) {
		Array a;
		a.data = new float[size];
		a.size = size;
		return a;
	}
	void destroy(Array& a) {
		delete[] a.data;
		a.data = nullptr;
		a.size = 0;
	}
	void print() {
		for (int i = 0; i < size; i++)
			cout << *(data + i) << " ";
		cout << endl;
	}
	void fillRandom() {
		srand(time(nullptr));
		for (int i = 0; i < size; i++)
			*(data + i) = rand();
	}
	void copy(Array& b) {
		if (size > b.size) {
			Array c = c.create(size);
			for (int i = 0; i < b.size; i++)
				*(c.data + i) = *(b.data + i);
			destroy(b);
			b = c;
		}
		for (int i = 0; i < size; i++)
			*(b.data + i) = *(data + i);
	}
	void resize(int aSize) {
		if (aSize < size)
			return;
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
