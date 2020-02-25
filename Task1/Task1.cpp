#include <iostream>
using namespace std;
class B1 {
	int a;
public:
	B1() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B1(int x) {
		a = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~B1() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class B2 {
	int a2;
public:
	B2() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B2(int x) {
		a2 = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~B2() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D1 :virtual public B1 {
	int b;
public:

	D1(int x, int y) :B1(y) {
		b = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D1() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D2 : virtual protected B1, public B2 {
	int c;
public:
	D2(int x, int y, int i) :B1(y), B2(i) {
		c = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D2() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D3 :public D1, virtual protected D2 {
	int d;
public:
	D3(int x, int y, int z, int i, int j, int k) :D1(y, z), D2(i, j, k) {
		d = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D3() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

int main()
{
	//D3 temp(1, 2, 3, 4, 5, 6);
}