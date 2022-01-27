#include<iostream>
using namespace std;

class Animal // An abstract class
{
public:
	virtual void feed() = 0; // Pure virtual function
	virtual void groom() = 0; // Pure virtual function
	
};

class Dog : public Animal
{
public:
	void feed() { cout<<"Dog::feed"<<endl; }
	void groom() { cout<<"Dog::groom"<<endl; }
};


class Tiger : public Animal
{
public:
	void feed() { cout<<"Tiger::feed"<<endl; }
	void groom() { cout<<"Tiger::groom"<<endl; }
};

int main()
{
	Dog d;
	d.feed(); d.groom();
	
	Tiger t;
	t.feed();
	t.groom();
	return 0;
}