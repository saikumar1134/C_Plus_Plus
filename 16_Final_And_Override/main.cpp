#include<iostream>
using namespace std;

class Base
{
public:
	virtual void print(){ cout<<"Base::print()"<<endl; }
};

class Derived1 : public Base
{
public:
	void print() override final { cout<<"Derived1::print()"<<endl; }	
};

class Derived2 : public Derived1
{
public:
	//It throws an error
	void print(){ cout<<"Derived2::print()"<<endl; }
};

int main()
{
	Base *b = new Derived1;
	b->print();
	Derived1 *d = new Derived2;
	//d->print();
	return 0;
}