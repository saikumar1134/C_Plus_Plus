/*
 * 1) Rule of 0:
 * If we do not have any dynamic/ownership type resource in our class, so it is simple calss and we don't need to have
 * Rule of 5 here. (Rule of 0 = ~Rule of 5)
 * 2) Why? Complier automatically synthesizes all constructors/assignement (by copy) for us
 * 3) But, in our example we did it little differently as follows
 * Since, we cannot see complier's synthesizing , we have created a one more class called Dummy and have an instance of "Test" there
 * So, when we try to do copy , assignment, temporary objects, r-value referencing and destructor
 * Dummy instance automatically invokes all functiions of Test class (Internally complier generates code and invokes it)
 * Note: Test this file using complier option : "g++ filename.cpp -fno-elide-constructors" (To avoid copy elision) 
 * */

#include<iostream>

using namespace std;

class Test
{
public:
	int *ptr;
	//Parameterized constructor
	Test(int val)
	{
		cout<<"Parameterized constructor"<<endl;
		ptr = new int{val};
	}
	
	//1. Copy Constructor
	Test(const Test &obj)
	{
		cout<<"Copy Constructor called"<<endl;
		ptr = new int(*obj.ptr);
	}
	
	//2. Copy Assignment Operator
	Test& operator=(const Test &obj)
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
	Test(Test &&obj)
	{
		cout<<"Move Constructor Called"<<endl;
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}
	
	//4. Move Assignment Operator
	Test& operator=(Test &&obj)
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
	
	//5.Destructor
	~Test()
	{
		if(ptr == nullptr)
		{
			cout<<"Destructor called for : nullptr"<<endl;
		}
		else
		{
			cout<<"Destructor called for : "<<*ptr<<endl;
		}
	}
};

class Dummy
{
	Test testObj;
public:
	Dummy(int val):testObj(val){}
};

Dummy createObject(int n)
{
    cout<<"Create object called"<<endl;
    Dummy temp(n);
	return temp;
}

int main()
{
	//Calling Parameterized constructor
	Dummy d1(10);
	
	//1. Calling copy constructor of Test class - compliler synthesizes internally
	auto d2(d1); 
	
	//2.Copy Assignment Operator
	d2 = d1; 
	
	//3. Move Constructor
	auto d3(createObject(100));
	
	//4. Move Assignment Operator
	d3 = createObject(200);

	return 0;
}