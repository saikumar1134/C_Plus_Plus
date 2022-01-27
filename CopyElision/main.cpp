#include<iostream>

using namespace std;

class Test
{
public:
	Test(int a)
	{
		cout<<"Constructor called"<<endl;
	}
	
	Test(const Test &obj)
	{
		cout<<"Copy constructor called"<<endl;
	}
};

int main()
{
	Test t = 2;
	return 0;
}