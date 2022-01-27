#include<iostream>
using namespace std;

class Base
{
public:
	virtual void fun1(){
		cout<<"Base::fun1()"<<endl;
	}
};

class Derived : public Base
{
public:
	void fun1(){
		cout<<"derived::fun1()"<<endl;
	}
};

int main()
{
	Base *b = new Derived;
	b->fun1();
	
}
