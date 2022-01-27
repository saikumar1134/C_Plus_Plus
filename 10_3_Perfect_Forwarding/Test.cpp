#include "Test.h"
#include<iostream>
#include<string>

using namespace std;

//Parameterized constructor
Test::Test(int val)
{
	cout<<"Parameterized constructor"<<endl;
	ptr = new int{val};
}

//1. Copy Constructor
Test::Test(const Test &obj)
{
	cout<<"Copy Constructor called"<<endl;
	ptr = new int(*obj.ptr);
}

//2. Copy Assignment Operator
Test& Test::operator=(const Test &obj)
{
	cout<<"Copy Assignment Operator called"<<endl;
	if(this == &obj)
	{
		return *this;
	}
	else
	{
		delete ptr;
		ptr = new int(*obj.ptr);
		return *this;		
	}
}

//3. Move Constructor
Test::Test(Test &&obj)
{
	cout<<"Move Constructor Called"<<endl;
	ptr = obj.ptr;
	obj.ptr = nullptr;
}

//4. Move Assignment Operator
Test& Test::operator=(Test &&obj)
{
	cout<<"Move Assignment Operator Called"<<endl;
	if(this == &obj)
	{
		return * this;
	}
	else
	{
		delete ptr;
		ptr = new int(*obj.ptr);
		return *this;		
	}
}

ostream & Test::operator<<(ostream &out, const Test obj)
{
	out<<*(obj.ptr)<<endl;
	return out;
}
//5.Destructor
Test::~Test()
{
	//Intentionally commented the below code, to avoid more print statements on out screen
/*	if(ptr == nullptr)
	{
		cout<<"Destructor called for : nullptr"<<endl;
	}
	else
	{
		cout<<"Destructor called for : "<<*ptr<<endl;
	}*/
	delete ptr;
}