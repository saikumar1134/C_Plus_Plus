#include<iostream>

using namespace std;
class Test
{
private:
	int a, b;
public:
	//Delegated to Test(5)
	Test():Test(5) 
	{
		cout <<"Default constructor called"<<endl;
	}
	//Delegated to Test(x,10)
	Test(int x):Test(x,10)
	{
		cout<<"Constructor with single argument called"<<endl;
	}
	//Final constructor, where the actual intitilization happened
	Test(int y, int z)
	{
		cout<<"Constructor with two arguments, where actual intitiazation happened"<<endl;
		a = y;
		b = z;
		cout<<"a is:"<<a<<"\t b is:"<<b<<endl;
	}
};

int main()
{
	Test t;
	return 0;
}