#include<iostream>
#include<string.h>

using namespace std;

template<class T>
class Maximum
{
	T a,b;
public:
	Maximum(T x, T y):a(x), b(y)
	{
		cout<<"Generic Template called"<<endl;
	}
	
	T Max()
	{
		return (a>b)?a:b;
	}
};

template<>
class Maximum<char*>
{
	const char* a;
	const char* b;
public:
	Maximum(const char* x, const char* y):a(x), b(y)
	{
		cout<<"Specialized template called"<<endl;
	}
	
	const char* Max() const
	{
		return strcmp(a,b)>0?a:b;
	}
};

int main()
{
	//1. Generic Template
	Maximum<int> m(10,20);
	cout<<"Max of (10,20) is:"<<m.Max()<<endl;
	
	//2. Specialized template works for "char *" type
	Maximum<char*> m1("A","B"); 
	cout<<"Max of (A,B) is:"<<m1.Max()<<endl;
	return 0;
}