#include<iostream>

using namespace std;

class Test
{
	int *data;
public:
	explicit Test(int *p=nullptr):data{p}
	{
		cout<<"Parameterized constructor called"<<endl;
		cout<<"data address in Test ctor:"<<data<<endl;
	}
	~Test()
	{
		cout<<"Destructor called"<<endl;
		delete data;
		data = nullptr; // To avoid dangling pointer
		cout<<"data address in Test dtor:"<<data<<endl;
	}
	
	int& operator * ()
	{
		cout<<"Operator * overloaded"<<endl;
		return *data;
	}
	int& operator -> ()
	{
		cout<<"Operator * overloaded"<<endl;
		return *data;
	}
};

int main()
{
	int *ptr = new int(20);
	cout<<"ptr address in main:"<<ptr<<endl;
	//Here, we obj is a test object and passed pointer ptr 
	//as a parameter to constructor
	Test obj(ptr);
	cout<<"*obj is:"<<*obj<<endl;
	ptr = nullptr; // To avoid dangling pointer
	cout<<"ptr address in main:"<<ptr<<endl;
}