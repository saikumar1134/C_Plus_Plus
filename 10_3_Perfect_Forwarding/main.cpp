/*
Apart from accepting type & value in the template parameter. You can enable the template to accept 
both lvalue and rvalue references. 
And to do this you need to adhere to the rules of reference collapsing as follows:
T& & becomes T&
T& && become T&
T&& & becomes T&
T&& && becomes T&&
*/

#include "Test.h"
#include<iostream>
#include<string>

using namespace std;

class WithoutTemplates
{
	string name;
	Test testObj;
public:
	WithoutTemplates(const string &s, const Test &obj):name(s),testObj(obj)
	{
		cout<<"WOTemplates_CC"<<endl;
	}
	
	WithoutTemplates(string &&s, Test &&obj):name(s),testObj(move(obj))
	{
		cout<<"WOTemplates_MoveC"<<endl;
	}
};

void WOTemplates()
{
	cout<<"***WITHOUT TEMPLATES***"<<endl;
	cout<<"--------------------------------"<<endl;
	//Case1
	cout<<"Case 1 : d1{100}"<<endl;
	WithoutTemplates d1{"Hello", 100}; // R-Value
	cout<<endl;
	
	//Case 2
	cout<<"Case 2 : Test val{200}"<<endl;
	Test val{200};
	WithoutTemplates d2{"Sai", val}; // L-Value
	cout<<endl;
	
	//Case 3
	cout<<"Case 3 : d3{move(val)}"<<endl;
	string str = "Kumar";
	WithoutTemplates d3{str, move(val)}; //Made L-Value as R-Value Reference
	cout<<endl<<endl;
}

class WithoutForward
{
	string name;
	Test testObj;
public:
	template<typename T1, typename T2>
	WithoutForward(T1 &&str, T2 &&val):name(str), testObj(val)
	{
		cout<<"name(str), testObj(val)"<<endl;
	}
};

void WithoutForwarding()
{
	cout<<"***WITHOUT FORWARDING***"<<endl;
	cout<<"--------------------------------"<<endl;
	//Case1
	cout<<"Case 1 : d1{Test(100)}"<<endl;
	WithoutForward d1{"Hello", Test(100)}; // R-Value
	cout<<endl;
	
	//Case 2
	cout<<"Case 2 : Test val{200}"<<endl;
	Test val{200};
	WithoutForward d2{"sai", val}; // L-Value
	cout<<endl;
	
	//Case 3
	cout<<"Case 3 : d3{move(val)}"<<endl;
	string str = "kumar";
	WithoutForward d3{str, move(val)}; //Made L-Value as R-Value Reference
	cout<<endl<<endl;
}

class WithForward
{
	string name;
	Test testObj;
public:
	template<typename T1, typename T2>
	WithForward(T1 &&str, T2 &&val):name(forward<T1>(str)),testObj(forward<T2>(val))
	{
		cout<<"name(forward<T1>(str)),testObj(forward<T2>(val))"<<endl;
	}
};

void WithForwarding()
{
	cout<<"***WITH FORWARDING***"<<endl;
	cout<<"--------------------------------"<<endl;
	//Case1
	cout<<"Case 1 : d1{Test(100)}"<<endl;
	WithForward d1{"Hello", Test(100)}; // R-Value
	cout<<endl;
	
	//Case 2
	cout<<"Case 2 : Test val{200}"<<endl;
	Test val{200};
	WithForward d2{"sai", val}; // L-Value
	cout<<endl;
	
	//Case 3
	cout<<"Case 3 : d3{move(val)}"<<endl;
	string str = "kumar";
	WithForward d3{str, move(val)}; //Made L-Value as R-Value Reference
	cout<<endl<<endl;
}
int main()
{
	WOTemplates();
	WithoutForwarding();
	WithForwarding();
	return 0;
}