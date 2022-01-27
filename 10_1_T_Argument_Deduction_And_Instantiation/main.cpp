#include<iostream>
#include<string.h>
#include<typeinfo>

using namespace std;

template<typename T>
T Max(T a, T b)
{
	cout<<"Type:"<<typeid(T).name()<<"\t";
	return (a > b)?a:b;
}

//Explict Instantiation
template char Max(char a, char b);

//Explicit Specilization - char*
//template<> const char * Max<const char*>(const char* a, const char* b) - optional syntax
template<> const char * Max(const char* a, const char* b)
{
	cout<<"Max<const char*>"<<endl;
	return strcmp(a,b)>0?a:b;
}
int main()
{
	//1. Template Function is invoked
	cout<<"Max(10,20) is:"<<Max(10,20)<<endl; // 10 and 20 will be deduced as INT by compiler
	cout<<"Max(10,20.5f) is:"<<Max(static_cast<float>(10), 20.5f)<<endl; // 10 is type casted to float and deduction type is : float
	cout<<"Max(10, 20.5) is:"<<Max<double>(10, 20.5)<<endl;
	
	//2. Using address of template function
	//Here, we not invoking Max function for float type,
	//But we got the address, that is what complier instatnitate Max function float type
	float (*ptr)(float, float) = Max;
	//Template invocation happens here
	cout<<"Max(20.5f, 30.5f) is:"<<ptr(20.5f, 30.5f)<<endl;
	int (*ptr1)(int, int) = Max;
	
	//3. Explicit Instatntiation
	//Note that, here we are not invoking the char template, 
	//instead it instatiate char template - generates code
	//template char Max(char a, char b);
	cout<<"Max(c,d) is:"<<Max('c','d')<<endl;
	
	//4. Explicit Specilization - used for some specific type
	const char *b{"B"};
	const char *a{"A"};
	cout<<"Max(A,B) is:"<<Max(a, b)<<endl;
	
	return 0;
}