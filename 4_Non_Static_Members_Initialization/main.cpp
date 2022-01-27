#include<iostream>
#include<tuple>
using namespace std;

class Test1
{
private:
	//Non-static members initiliazation
	int a{10}; float f = 20.5; char c{'s'};
public:
	// Default Constructor synthesizes above non-static members initiazatio in it by default
	Test1(){} 
	
	//Paramaterized constructor
	Test1(int x,float y, char z):a(x),f(y),c(z){}
	
	void print()
	{
		cout<<"a is:"<<a<<"\t f is:"<<f<<"\t c is:"<<c<<endl;
	}
};

int main()
{
	//It calls default constructor, that inturn synthesizes the values
	Test1 t1;
	t1.print();
	//Initilazing via constructor
	Test1 t2(50, 50.5f, 'k');
	t2.print();
	return 0;
}