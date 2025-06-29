#include <iostream>

using std::cout;

class SlaveA {
public:
	SlaveA() {
		cout << "default con SlaveA\n";
	}
	SlaveA(const SlaveA& copy) {
		cout << "copy con SlaveA\n";
	}
	SlaveA& operator=(const SlaveA& copy) {
		cout << "copy ass SlaveA\n";
		return *this;
	}
	~SlaveA() {
		cout << "destructing SlaveA\n";
	}
};
class SlaveB {
public:
	SlaveB() {
		cout << "default con SlaveB\n";
	}
	SlaveB(const SlaveB& copy) {
		cout << "copy con SlaveB\n";
	}
	SlaveB& operator=(const SlaveB& copy) {
		cout << "copy ass SlaveB\n";
		return *this;
	}
	~SlaveB() {
		cout << "destructing SlaveB\n";
	} 
};
class SlaveC {
public:
	SlaveC() {
		cout << "default con SlaveC\n";
	}
	SlaveC(const SlaveC& copy) {
		cout << "copy con SlaveC\n";
	}
	SlaveC& operator=(const SlaveC& copy) {
		cout << "copy ass SlaveC\n";
		return *this;
	}
	~SlaveC() {
		cout << "destructing SlaveC\n";
	}
};

class Master {
	
	SlaveA a;
	SlaveB b;
	SlaveC c;
	int x;

public:
	Master() {
		cout << "default con Master\n";
	}
	Master(int X):x(X) {
		cout << "int con Master\n";
	}
	Master(const Master& copy):a(copy.a), b(copy.b), c(copy.c), x(copy.x) {
		cout << "copy con Master\n";
	}
	Master& operator=(const Master& copy) {
		a = copy.a;
		b = copy.b;
		c = copy.c;
		x = copy.x;
		cout << "copy ass Master\n";
		return *this;
	}
	~Master() {
		cout << "destructing Master\n";
	}
};

void funcy(Master& m)
{
}

class DynamicIntArray
{
	int* parr = nullptr;
	int size = 0;
	void copyContent(int* arr, int size) {
		for (int x = 0; x < size; x++) {
			parr[x] = arr[x];
		}
	}
public:
	DynamicIntArray(int size) :parr(new int[size]), size(size) {}
	DynamicIntArray(const DynamicIntArray& copy) {
		parr = new int[copy.size];
		copyContent(copy.parr, copy.size);
	}
	DynamicIntArray& operator=(const DynamicIntArray& copy) {
		if (parr)
			delete[]parr;
		parr = new int[copy.size];
		copyContent(copy.parr, copy.size);
		return *this;
	}

	~DynamicIntArray()
	{
		delete[]parr;
		parr = nullptr;
	}
	int& operator[](int index) {
		return parr[index];
	}
};


int main() {



	return 0;
}