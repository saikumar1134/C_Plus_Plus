#include<iostream>

using namespace std;

class complex
{
public:
	int real;
	int img;

	complex(int r = 0, int i = 0)
	{
		real = r; img = i;
	}
	
	complex operator + (complex com)
	{
		complex temp;
		temp.real = real + com.real;
		temp.img = img + com.img;
		return temp;
	}
};

class complex2
{
private:
	int real, img;
public:
	complex2(int r=0, int i=0)
	{
		real = r;
		img = i;
	}
	
	friend complex2 operator + (complex2 c1, complex2 c2);
	friend ostream & operator << (ostream &out,complex2 &c2);
	friend istream & operator >> (istream &in,complex2 &c2);
	complex2 operator = (const complex &obj)
	{
		cout<<"Overloaded assignement(=) operator"<<endl;
		complex2 temp;
		temp.real = obj.real;
		temp.img = obj.img;
		return temp;
	}
};

complex2 operator + (complex2 c1, complex2 c2)
{
	complex2 temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	cout<<"overloaded the + operator using friend function:"<<temp.real<<"+i"<<temp.img<<endl;
	return temp;
}

ostream & operator << (ostream &out,complex2 &c2)
{
	out<<c2.real<<"+i"<<c2.img<<endl;
	return out;
}

istream & operator >> (istream &in,complex2 &c2)
{
	cout<<"Enter real part:";
	in>>c2.real;
	cout<<"Enter imaginary part:";
	in>>c2.img;
	return in;
}
int main()
{
	//overloading + operator - normal operation
	complex c1(10,20), c2(30,40);
	complex c3 = c1 + c2;
	cout<<"Overloaded the + operator - normal approach:"<<c3.real<<"+i"<<c3.img<<endl;
	
	//overloading + operator using friend function
	complex2 c4(10,20), c5(30,40);
	complex2 c6 = c4 + c5;
	
	//overloading insertion << operator using friend function
	cout<<"overloaded << operator using friend function:"<<c6;
	
	//overloading extraction operator using friend function
	complex2 c7;
	cin>>c7;
	cout<<"overloaded >> operator and values extracted are:"<<c7<<endl;
	
	//overloading assignment operator
	c6 = c7;
	cout<<"overloaded << operator using friend function:"<<c6;
	return 0;
}