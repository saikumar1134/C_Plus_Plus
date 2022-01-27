/* Rule of 5:
 * 1) Copy Constructor
 * 2) Copy Assignment Operator
 * 3) Move Constructor
 * 4) Move Assignment Operator
 * 5) Destructor
 * 
 * If we have any dynamic/ownership type of resources in our class, we better to follow Rule of 5 by defining above all
 * Why because, user will perform both copy and move based on the expression without the complier synthesizing it for us
 * If complier synthesizes internally, means it is time taking (since copy operation will only be involved - no move) 
 * 
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
	
	//Generic print function
	void print()
	{
		cout<<"current *ptr is:"<<*ptr<<endl;
	}
};

Test createObject(int n)
{
    cout<<"Create object called"<<endl;
    Test temp(n);
	return temp;
}

int main()
{
	//Calling Parameterized constructor
	Test t1(10);
	t1.print();
	Test t2(20);
	t2.print();
	cout<<endl;
	
	//1. Calling copy constructor
	Test t3(t1); // t3 = t1 = 10
	t3.print();
	
	//2.Copy Assignment Operator
	t3 = t2; //t3 = t2 = 20
	t3.print();
	
	//3. Move Constructor
	auto t4(createObject(100));
	t4.print();
	
	//4. Move Assignment Operator
	t4 = createObject(200);
	t4.print();

	return 0;
}