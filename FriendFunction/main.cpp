#include<iostream>

using namespace std;

class Test
{
	int length, breadth;
public:
	Test(int l, int b):length(l),breadth(b)
	{}
	
	friend void calcArea(Test t);
};

void calcArea(Test t)
{
	cout<<"Area is:"<<t.length * t.breadth<<endl; 
}

int main()
{
	Test obj(10,20);
	cout<<"sizeof(obj)"<<sizeof(obj)<<endl;
	calcArea(obj);
	return 0;
}