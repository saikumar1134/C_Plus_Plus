#include<iostream>

using namespace std;

class Test
{
private:
	int a,b;
public:
	//Not fine
	//OUTPUT
	//a value is:4194442
	//b value is:10
	/*Test():b(10),a(b+10)
	{
		cout<<"a value is:"<<a<<endl;
		cout<<"b value is:"<<b<<endl;
	}*/
	
	//Works fine
	//OUTPUT
	//a value is:10
	//b value is:20
	/*Test():a(10),b(a+10)
	{
		cout<<"a value is:"<<a<<endl;
		cout<<"b value is:"<<b<<endl;
	}*/
	
	//Works fine
	//OUTPUT
	//a value is:10
	//b value is:20
	Test():b(a+10),a(10)
	{
		cout<<"a value is:"<<a<<endl;
		cout<<"b value is:"<<b<<endl;
	}
};

int main()
{
	Test t;
	return 0;
}
