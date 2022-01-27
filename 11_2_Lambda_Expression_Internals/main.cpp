#include<iostream>
#include<vector>
#include<typeinfo>

using namespace std;

template<typename T>
void ForEach(vector<int>& v,T val )
{
	for(auto i : v)
		val(i);
}
static int staticVar = 200;
int globalVar = 300;

int main()
{
	// 1. A simple lambda expression, invoke at its declaration by calling its overloaded function
	// How does it work?
	// Internally compiler creates a class along with overloaded function call operator
	[]()
	{
		cout<<"Welcome to lambda expression"<<endl;
	}();
	
	//2. Create an instance to the lambda expression
	//Since, we don't know the class/struct name, we can create an instance of an class using "auto" keyword
	auto fn = [](){cout<<"created an instance for lambda class"<<endl;};
	fn(); // This calls an onverloaded function
	
	//3. How compiler synthesizes the lambda expression internally
	//Here are there are two approaches
	//1) A function object invokes operator() overloading function of the class/struct
	//2) Type conversion operator() - It return a function pointer, through this pointer we can invoke lambda expression
	//How? This pointer points to a static function inside of synthesized lambda expression
	//And, this static function internally invokes a function call operator()
	//This allows, to pass lambda expressions as an argument, which accepts function pointer. 
	//This way, a lambda expression can DECAY or DECOMPOSE into function pointer 
	//
	//
	//3.1 Compiler synthesization via function object 
	//int sum = [](int a, int b) -->it is not allowed, auto is must
	/*class Unnamed
	 * {
	 * public:
	 * 		int operator()(int a, int b)
	 * 		{
	 * 			return a+b;
	 * 		}
	 * };
	 * Unnamed un
	 * cout<<"un(10,20) is:"<<un(10,20)<<endl;
	 * */
	 //Usually, we don't need explicty write traing return type if
	 //		lambda expression is returning same type or void
	 //	But, If lambda expression has multiple return types, then we need to include trailing return type
	auto sum = [](int a, int b)->int
	{
		return a+b;
	};
	cout<<"sum(10,20) is:"<<sum(10,20)<<endl;
	
	//We will optimize above code to work for any type
	//Generic Lambda Expression - Introduced in C++14
	//noexcept - Means, lambda expression doesn't throw exception
	//noexcept(false) - Means, It throws exception if it is there
	auto sum1 = [](auto a, auto b)noexcept(false)
	{
		return a+b;
	};
	cout<<"sum1(10,20) is:"<<sum1(10,20)<<endl;
	
	//3.2 Compiler synthesizatin using type conversion operator
	
	//4. Capturing list in Lambda experssions
	//Here we will try to implement ForEach loop of vector using lambda expression
	//caputrelist can be 	1) By value 	- a		- Readonly, cannnot change its value inside lambda expression
	//						2) By Reference - &a	- Can change its value inside
	//						3) By Pointer 	- *a	- Can change its value inside
	//mutable - to change the varaiables which are captured by value
	int a = 300;
	vector<int> v{1,2,3,4,5};
	ForEach(v, [a](auto &x)mutable
				{
					a = 400;
					//Static & global variables doesn't need to be captured
					//They can be changed inside lambda expression
					staticVar = 500;
					globalVar = 600;
					x = x + a + staticVar + globalVar;
					cout<<x<<"\t";
				}
	);
	cout<<endl<<"a value is:"<<a<<endl;
	cout<<"staticVar value is:"<<staticVar<<endl;
	cout<<"globalVar value is:"<<globalVar<<endl;
	
	//5. Generalized lambda capture list - Introduced in C++14
	//This allows creation of new variables in caputre clause
	[x=a, y=staticVar, z=globalVar]()
	{
		cout<<"Assigned var's in generalized capture list"<<endl;
	}();
	cout<<endl<<"After generalized caputre list assignment"<<endl;
	cout<<"a value is:"<<a<<endl;
	cout<<"staticVar value is:"<<staticVar<<endl;
	cout<<"globalVar value is:"<<globalVar<<endl;
	return 0;
}