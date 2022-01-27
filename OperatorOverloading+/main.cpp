#include<iostream>
using namespace std;

class Complex
{
public:
	int real, imag;
	Complex(int r = 0, int i = 0)
	{
		real = r;
		imag = i;
	}
	
	Complex operator + (Complex const &obj)
	{
		Complex res;
		cout<<"obj.real"<<obj.real<<endl;
		res.real = this->real + obj.real;
		res.imag = this->imag + obj.imag;
		return res;
	}
};


int main()
{
	Complex c1(10,20), c2(30,40);
	Complex c3 = c1 + c2;
	cout<<c3.real<<"+i"<<c3.imag<<endl;
	return 0;
}