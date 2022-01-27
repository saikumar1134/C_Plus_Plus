#include<iostream>

using namespace std;
\
int Sum(int a, int b)
{
	return a+b;
}
int main()
{
	//Type int
	auto a = 10;
	cout<<"a value is:"<<a<<endl;
	
	//Type float, whichever is the biggest data type, wiill be converted into that
	auto b = a + 20.5f;
	cout<<"b value is:"<<b<<endl;
	
	//Type char
	auto c = a + b + 'z';//ASCII value of z will be replaced
	cout<<"c value is:"<<c<<endl;
	
	//Assign function return value to auto
	auto sum = Sum(a,b);
	cout<<"sum is"<<sum<<endl;
	
	//CONST Qualifier
	const auto d = 50;
	cout<<"d value is:"<<d<<endl;
	
	//Const qualifer assing to non-const, const was discorded, so e is non-const
	auto e = d; 
	cout<<"e value is:"<<e<<endl;
	
	//const with reference->Const qualifier will not be discorded, so f is const type
	auto &f = d;
	//f = 10; // It will throw error
	cout<<"f value is:"<<f<<endl;
	
	//const with pointer->Const qualifier will not be discorded, so g is const type
	//Need to prefix with * for pointer with auto
	auto ptr = &d;
	cout<<"*ptr :"<<*ptr<<endl;
	
	//Auto with initializer list
	auto list = {1,2,3,4,5};
	for(int i : list)
		cout<<i<<"\t";
	cout<<endl;
	
	//Initialization
	auto g {'G'};
	cout<<"g value is:"<<g<<endl;
	return 0;
}