#include<iostream>

using namespace std;

class Test
{
	static int a;
	static int b;
public:	
	Test()
	{
		++a;
	}

	static void print()
	{
		++b;
		cout<<"a value is:"<<a<<"b value is:"<<b<<endl;
	}
};

int Test::a = 10;
int Test::b = 20;

int main()
{
	Test::print();
	cout<<"size of(Test):"<<sizeof(Test)<<endl;
	return 0;
}