#include<iostream>
using namespace std;

class Smart
{
	int *data;
public:
	Smart(int* ptr = nullptr):data(ptr)
	{
		cout<<"Constructor called"<<endl;
		cout<<"data is"<<*data<<endl;
		cout<<"address of data is"<<data<<endl;
	}
	~Smart()
	{
		cout<<"Destructor called"<<endl;
		delete data;
	}
	
	int& operator*()
	{
		return *data;
	}
	
	int getData()
	{
		return *data;
	}
};

int main()
{
	int *p = new int(10);
	Smart s(p);
	cout<<*p<<endl;
	cout<<"address is"<<p<<endl;
	
	cout<<"operator * called and value is:"<<*s<<endl;
	*s = 20;
	cout<<*s<<endl;
	cout<<s.getData()<<endl;
	return 0;
}