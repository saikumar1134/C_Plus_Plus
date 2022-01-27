#include<iostream>

using namespace std;

class Test
{
	int *p;
public:
	Test()
	{
		p = new int;
		cout<<"Constructor called"<<endl;
	}
	
	~Test()
	{
		delete p;
		cout<<"Destructor called"<<endl;
	}
};

int main()
{
	//Test t[3]; 
	Test t1;
	Test* t = new Test;
	delete t;
	return 0;
}