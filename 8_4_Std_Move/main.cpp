#include<iostream>

using namespace std;

class Test
{
	int *ptr;
public:
	Test(int val):ptr(new int(val))
	{
		cout<<"Paratmeterized constructor called"<<endl;
		//ptr = new int(val);
	}
	
	~Test()
	{
		if(ptr == nullptr)
		{
			cout<<"Destructor called for:nullptr"<<endl;
		}
		else
		{
			cout<<"Destructor called for:"<<*ptr<<endl;
		}
	}
	//Copy constructor
	Test(const Test &obj)
	{
		cout<<"Copy constructor called"<<endl;
		*ptr = *(obj.ptr);
	}
	
	//Move Constructor
	Test(Test &&obj)
	{
		cout<<"Move constructor called"<<endl;
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}	
	
	void print()
	{
	    cout<<"*ptr:"<<*ptr<<endl;
	}
	
	void setPtr(int val)
	{
		if(ptr == nullptr)
		{
			ptr = new int(val);
		}
		else
			*ptr = val;
	}
};

int main()
{
	Test t1(10);
	t1.print();
	//Test t2(t1); // This calls copy constructor
	//But if i don't want to have it as a copy constructor instead, I want to move my object from t1 to t2
	//Method 1:
	//Test t2(static_cast<Test&&>(t1));
	//cout<<"t2.value"<<t2.value<<endl;
	
	//Method2
	//We see method1 is not that readble
	Test t2(std::move(t1));
	t2.print();
	
	//re-initiliaze
	t1.setPtr(100);
	t1.print();
	return 0;
}