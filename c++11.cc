
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int b = 0;

int x() { 
 return b++;
}
int y() { 
 return ++b;
}
int z() {
	++b;
 return (b + 1);
}

class C {
public:
	C() { cout << " Construct C" << endl; }
	~C() { cout << "Destroy C " << endl;}
	
};

class A {
public:
	A() { cout << " Construct A" << endl; }
	virtual ~A() { cout << "Destroy A " << endl;}
	void exec() { // task semantics
		foo1();
		foo2();
	}
private:
	void foo3() { cout << " From A3 " << endl; }
	// private virtual methods for Template Method Pattern
	// algorithm steps allowed derived class to overridde
	virtual void foo1() { cout << " From A1 " << endl;}
	virtual void foo2() { cout << " From A2 " << endl;}
};

class B : public A {
private:
	C c;
public:
	B() { cout << "Construct B" << endl; }
	~B() { cout << "Destroy B " << endl;}
	void foo3(int n) { int a[n]; int x = 5;  cout << " From B3: " << sizeof(a) << ", x=" << x << endl; } // not overriding
	virtual void foo1() { cout << " From B1 " << endl;};
	virtual void foo2() { cout << " From B2 " << endl;};
};

int main(int argc, char ** argv)
{
	A *d;
	B *c = new B;

	d = dynamic_cast<A*>(c);
	d->exec();
	c->foo3(5);

	/*
	// c++11 new features: for_each, iota, lambda
	int a[5] = {0};
	iota(a, a+5, 10);
	for_each(a, a+5, [] (int i) { cout << i << " "; });

	vector<int> b = {1, 3, 4, 5};

	cout << endl << b.size() << endl;
	for_each(b.begin(), b.end(), [] (int i) { cout << i << " "; });
	*/

	try {
		vector<int> b = {1, 3, 4, 5};
		cout << " No. 6=" << b[6] << endl;
	} catch (...) {
		cout << "Something is wrong!" << endl;
	}

	delete d; // constructor (body exec) order A->C->B
				// destructor (body exec) order B->C->A

	// x(), y(), z() functions may be called in any order
	cout << x() - y() + z() << endl;

 	// unsequenced order
	// i=(i++);
	int i = 0;
	cout << i << endl;

	return 0;
}
