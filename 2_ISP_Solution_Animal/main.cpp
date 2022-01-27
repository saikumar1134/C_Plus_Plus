#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void feed() = 0;
};

class Pet : public Animal
{
public:
	virtual void groom() = 0;
};

class Dog : public Pet
{
public:
	void feed() { cout<<"Dog::feed"<<endl; }
	void groom() { cout<<"Dog::groom"<<endl; }
};

class Tiger : public Animal
{
public:
	void feed() { cout<<"Tiger::feed"<<endl; }
};

int main()
{
	Dog d;
	d.feed(); d.groom();
	
	Tiger t;
	t.feed();
	return 0;
}