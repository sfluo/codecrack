
#include <iostream>

using namespace std;

class A {
private:
	int a;
	const int b;

public:
	A() : a(3), b(4) {}

	// can be called by const obj
	void foo() const 
	{
		cout << "const foo: " << a << endl;
	}

	void foo1() 
	{
		cout << "foo1:  " << b << endl;
	}

	void foo() 
	{
		a = 5;
		cout << "foo, a=" << 5 << endl;
	}

	// can be called by const volatile object
	void foo2() const volatile
	{
		cout << "const volatile foo2, b=" << b << endl;
	}
};

int main(int argc, char** argv)
{
	A a;
	const A c{};
	a.foo();
	a.foo1();
	c.foo();
	//c.foo1(); // Error !!!
	c.foo2();

	const A volatile d{};
	d.foo2();
	// d.foo1(); // Error!!

	const A a3;
	const A& ra = a3;
	ra.foo();
	A& a2 = const_cast<A&>(ra);
	a2.foo();

	return 0;
}
