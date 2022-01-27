#include<iostream>
using namespace std;

class Tax
{
public:
	//Abstract method
	virtual double calculateTax() = 0;
};

class FullTimeEmployee : public Tax
{
public:
	double calculateTax()
	{
		return 3000.5;
	}
};

class ContractEmployee : public Tax
{
public:
	double calculateTax()
	{
		return 2000.8;
	}
};

class FreeLancer : public Tax
{
public:
	double calculateTax()
	{
		return 1000.9;
	}
};

int main()
{
	FullTimeEmployee ft;
	ContractEmployee ct;
	FreeLancer fl;
	cout<<"Full time employee tax is:"<<ft.calculateTax()<<endl;
	cout<<"Contact type employee tax is:"<<ct.calculateTax()<<endl;
	cout<<"Free lancer tax is:"<<fl.calculateTax()<<endl;
	return 0;
}