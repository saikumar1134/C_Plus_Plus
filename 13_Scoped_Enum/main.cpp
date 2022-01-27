#include<iostream>

using namespace std;

//By default, enum/scoped enum underlined type is INTEGRAL
//Changed the underlined type to char from Integral, which holds ASCII values
enum class Color:char{Red = 'A', Green, Yellow};
void FillColor(Color col)
{
	if(col == Color::Red) 
	{ 
		cout<<"Red"<<endl; 
	}
	else if(col == Color::Green)
	{
		cout<<"Green"<<endl;
	}
	else
		cout<<"Yellow"<<endl;
}

int main()
{
	Color c = Color::Red; //Accessing with scope resolution operator like namespace
	FillColor(c);
	FillColor(Color::Green);
	FillColor(static_cast<Color>('B')); //Without static_cast, it throws compilation error
	return 0;
}