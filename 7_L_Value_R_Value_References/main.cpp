#include<iostream>

using namespace std;

//Return R-Value
int Add(int a, int b)
{
	return a+b;
}

//Return L-Value
int& Transform(int &a)
{
	a = a*a;
	return a;
}

//L-Vaue reference
int print(int &a)
{
	cout<<"print(int &a)"<<endl;
}

//R-Value reference
int print(int &&a)
{
	cout<<"print(int &&a)"<<endl;
}

//The following function will be called at different times both for L-Value and R-Value
//L-Value : If we don't R-Value reference by default, it acts as L-Value reference
//R-Value : Whether we have L-Value const reference or not, R-Value takes precedence and acts like that
int print(const int &a)
{
	cout<<"print(const int &a)"<<endl;
}
int main()
{
	//L-Value References
	int a = 10; // a is L-value, 10 is R-value (temporary)
	int b = 20;
	int sum = Add(a,b); //Return by value, is temporary
	int &mul = Transform(a); //Return by reference, is L-Value
	cout<<"a value is"<<a<<endl;
	cout<<"mul value is"<<mul<<endl;
	
	//R-Value References
	int &&r1 = 10;
	int &&r2 = Add(3,2);
	cout<<"r2 value is:"<<r2<<endl;
	int x = 0;
	//int &&r3 = x; //Error:Cannot bind L-Value to R-Value
	
	//Calls L-Value reference
	print(x);
	
	//If we don't have an R-Value reference definition, output will be "print(const int &a)"
	//Since we have R-Value reference, output is "print(int &&a)"
	print(5);
	
	return 0;
}