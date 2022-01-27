#include<iostream>
#include "string.h"
using namespace std;

void print(string s1, string s2)
{
	cout<<"String1 is:"<<s1<<"\tString2 is:"<<s2<<endl;	
}

swap(string &s1, string &s2)
{
	string tmp(std::move(s1)); // It calls move constructor
	s1 = std::move(s2); // It calls move assignment operator
	s2 = std::move(tmp); // It calls move assignment operator
}
int main()
{
	string str1("sai");
	string str2("kumar");
	cout<<"Before swap"<<endl;
	print(str1,str2);
	
	//swap
	swap(str1, str2);
	cout<<"After swap"<<endl;
	print(str1,str2);
}