#include<iostream>

using namespace std;

template<typename T1, typename T2>
T1 compute(T1 a, T2 Max)
{
	return a + Max(10,20);
}

//1. Function Pointer
int maximum_fptr(int a, int b)
{
	return a>b?a:b;
}

//2. Function Object:
class maximum_fobj
{
public:
	int operator()(int a, int b)
	{
		return a>b?a:b;
	}
};

int main()
{
	int a = 50;
	
	//1. Function pointer and its disadvantages:
	//1) Since Maximum is a global function, it doesn't have a state, so its difficult to get updated values (we can manage using global variable)
	//2) A function call (call back) explicityly made from Max(), this is overhaed to compiler
	//3) In other way we can say this is not inlined, while compiler generates the code
	int sum_fptr = compute(a, maximum_fptr);
	cout<<"sum using fptr is:"<<sum_fptr<<endl;
	
	//2. Function Object:
	//Advantages over function pointer
	//1) Since class/struct, its instance has a state
	//2) Here alos function call will be made to operaotr() function, but it is inlined by the compiler
	//3) Thus, Faster than function pointer
	maximum_fobj ob;
	//ob(30,40); //ob.operator()(30,40)
	int sum_fobj = compute(a, ob);
	cout<<"sum using fobj is:"<<sum_fobj<<endl;
	return 0;
}