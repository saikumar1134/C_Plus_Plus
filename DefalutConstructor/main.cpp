#include<iostream>

using namespace std;

class Test
{
	int value;
public:
	/*Test()
	{
		cout<<"Default constructor"<<endl;
	}*/
	Test(int v){
		value = v;
		cout<<"Parameterized constructor"<<endl;
	}
	
	~Test()
	{
		cout<<"Destructor called"<<endl;
	}
};

int main()
{
	//This program throws error, since there is no matching call to Test()
	//if we uncomment the code, it works
	Test t2;
	//Test t1(10);
	return 0;
}
