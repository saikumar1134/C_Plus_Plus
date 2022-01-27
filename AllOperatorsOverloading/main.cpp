#include<iostream>

using namespace std;

class complex
{
public:
	int real, imag;
	complex(int r=0, int i=0):real(r), imag(i){}
	//Copy constructor
	complex(const complex &obj);
	
	//Overloading + operator
	//We should not make complex& as return, since temp is local and temporary
	complex operator+(const complex &obj);
	
	//Assignment operator
	complex& operator=(const complex &obj1);
	
	//Pre-increment operator
	complex& operator ++();

	//Post-increment operator
	complex& operator ++(int);
	
	//Insertion operator
	friend ostream & operator<<(ostream &out, const complex obj);
	
	//Extraction operator
	friend istream & operator >> (istream &in, complex &obj);
	
	//Equality operator
	friend bool operator == (const complex &obj1, const complex &obj2);
	
/*	//Pointing to operatror ->
	complex& operator -> (void);*/
};
complex complex::operator+(const complex &obj)
{
	complex temp;
	temp.real = real + obj.real;
	temp.imag = imag + obj.imag;
	return temp;
}

complex::complex(const complex &obj)
{
	this->real = obj.real;
	this->imag = obj.imag;
}

complex& complex::operator=(const complex &obj1)
{
	if(this != &obj1)
	{
		this->real = obj1.real;
		this->imag = obj1.imag;
	}
	return *this;
}

ostream & operator<<(ostream &out, const complex obj)
{
	out<<obj.real<<"+i"<<obj.imag;
	return out;
}

//Second parameter should not be const, since we are writing into it
istream & operator >> (istream &in, complex &obj)
{
	cout<<"Enter real part:";
	in>>obj.real;
	cout<<"Enter imaginary part:";
	in>>obj.imag;
	return in;
}

bool operator == (const complex &obj1, const complex &obj2)
{
	if((obj1.real == obj2.real) && (obj1.imag == obj2.imag))
		return true;
	else
		return false;
}

//Unary operator takes zero args with function
//if it with friend fucntion, takes one arg
//pre-increment
complex& complex::operator ++()
{
	this->real = ++real;
	this->imag = ++imag;
	return *this;
}

//post-increment
complex& complex::operator ++(int)
{
	this->real = ++real;
	this->imag = ++imag;
	return *this;
}
/*complex& complex::operator -> (void)
{
	return *this;
}*/

int main()
{
	complex c1(10,20),c2(30,40);
	cout<<"Addition operator (+) "<<endl;
	complex c3 = c1 + c2;
	cout<<"(C3 = C1 + C2)-->"<<c3.real<<"+i"<<c3.imag<<endl;
	cout<<endl;
	
	//Copying existing object c3 to new object c4, copy constructor
	cout<<"Copy constructor "<<endl;
	complex c4 = c3;
	cout<<"(C4 = C3)-->"<<c4.real<<"+i"<<c4.imag<<endl;
	cout<<endl;
	
	//Assigining existing object c4 to,another existing object c2
	cout<<"Assignment operator (=) "<<endl;
	c2 = c4;
	cout<<"(C2 = C4)-->"<<c2.real<<"+i"<<c2.imag<<endl;
	cout<<endl;
	
	//Now C2,C3,C4 has same data 
	//Print any object by overloading insertion << operator, like cout<<c2
	cout<<"Insertion operator (<<) "<<endl;
	cout<<"(cout<<C2)-->"<<c2<<endl;
	cout<<endl;
	
	//Read input from istream(display screen), store in object C5
	cout<<"Extraction operator (>>) "<<endl;
	complex c5;
	cin>>c5;
	cout<<"(cin>>C5)-->"<<c5<<endl;
	cout<<endl;
	
	//Compare whether two objects are same or not
	//compare c2 & c3
	cout<<"Equality operator (==) "<<endl;
	(c2 == c3)?cout<<"(C2 == C3) Equal":cout<<"(C2 != C3) Not equal";
	cout<<endl<<endl;
	
	//Pre-increment an object value
	cout<<"Pre increment operator (++C5) "<<endl;
	cout<<++c5<<endl;
	cout<<endl;
	
	//Post-increment an object value
	cout<<"Post increment operator (C5++) "<<endl;
	cout<<c5++<<endl<<endl;
	cout<<"Since post-increment evaluate in next line , printing C5 get latest value"<<endl;
	cout<<c5<<endl;
	cout<<endl;
	
/*	complex c6(100,200);
	complex* ptr = &c6;
	cout<<"(C6.real)="<<c6.real<<"\t"<<"(C6.imag)="<<c6.imag<<endl;
	cout<<"(ptr->real)="<<ptr->real<<"\t"<<"(ptr->imag)="<<ptr->imag<<endl;
	//cout<<"(c6->real)="<<c6->real<<"\t"<<"(c6->imag)"<<c6->imag<<endl;*/
	return 0;
}
