
#include <iostream>

using namespace std;

class A {
public:
	void foo() = delete;
};

class B : public A {
public:
	void foo() { cout << "foo" << endl; }
};

int main(int argc, char ** argv)
{
	A a;
	// a.foo(); ERROR!!!
	B b;
	b.foo();
	return 0;
}
