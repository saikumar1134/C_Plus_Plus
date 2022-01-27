#include <iostream>

using namespace std;

class one
{
public:
	virtual void show()
	{
		cout<<"class one show"<<endl;
	}
};

class two : public one
{
public:
	void show()
	{
		cout<<"class two show"<<endl;
	}	
};

int main()
{
	one obj1;
	two obj2;
	obj1.show();
	obj2.show();
	
	one* ptr2 = &obj2;
	ptr2->show();
	return 0;
}