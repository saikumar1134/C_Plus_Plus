#include<iostream>

using namespace std;

class RectangleArea
{
	int length, breadth;
public:
	RectangleArea(int l, int b):length(l),breadth(b){}
	
	friend class printClass;
};

class printClass
{
	public:
		printArea(RectangleArea rect)
		{
			cout<<"Area is:"<<rect.length * rect.breadth<<endl;
		}
};

int main()
{
	RectangleArea r(10,20);
	printClass p;
	p.printArea(r);
	return 0;
}