//http://cpp.sh/3f55a
#include<iostream>
#include<thread>
using namespace std;

//1. Using Function Pointer
void fun(int x) { cout<<"X is:"<<x<<endl; }
void UsingFunctionPointer() { thread t(fun, 10); t.join(); }

//2. Using Lambda Expression
auto f = [](int x) { cout<<"X is:"<<x<<endl; };
void UsingLambdaExpression() { thread t(f, 20); t.join(); }

//3. Using Function Object / functor
class Functor { public: void operator()(int x) { cout<<"X is:"<<x<<endl; } };
void UsingFunctionObject() { thread t(Functor(), 30); t.join(); }

//4. Using Non-static Member function
class NonStatic { public: void fun(int x) { cout<<"X is:"<<x<<endl; } };
void UsingNonStaticFunction() { NonStatic ns; thread t(&NonStatic::fun, &ns, 40); t.join(); }

//4. Using static Member function
class Static { public: static void fun(int x) { cout<<"X is:"<<x<<endl; } };
void UsingStaticFunction() { thread t(&Static::fun, 50); t.join(); }

int main()
{
    UsingFunctionPointer();
    UsingLambdaExpression();
    UsingFunctionObject();
    UsingNonStaticFunction();
    UsingStaticFunction();

	return 0;
}