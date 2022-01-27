#pragma once
#include<iostream>
#include<string>

using namespace std;

class Test
{
public:
	int *ptr;
	//Parameterized constructor
	Test(int val);
	
	//1. Copy Constructor
	Test(const Test &obj);
	
	//2. Copy Assignment Operator
	Test& operator=(const Test &obj);
	
	//3. Move Constructor;
	Test(Test &&obj);
	
	//4. Move Assignment Operator
	Test& operator=(Test &&obj);
	
	//5. Operator << overloaded
	friend ostream & operator<<(ostream &out, const Test obj);
	
	//5.Destructor
	~Test();
};