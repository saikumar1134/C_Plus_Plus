#include <iostream>

using namespace std;

int main()
{
	int a , b , c = 5;
	//Pre increment
	a = ++c;
	cout<<"a value is:"<<a<<endl;
	cout<<"c value is:"<<c<<endl;
	
	//Post increment
	b = c++;
	cout<<"b value is:"<<b<<endl;
	cout<<"c value is:"<<c<<endl;
	
	//l-value
	++a = 50;
	cout<<"a value is:"<<a<<endl;

	return 0;
}