#include<cstdlib>
#include<iostream>
#include<memory>

using namespace std;

/********************UniquePtrDeleter****************/
//We can implement custom deleter for unique pointer mainly in 4 callables
//1) Functio Object - A function has a state called Function Object, We will achieve this by overloading the
//					  Function call operator()
//2) Function Pointer
//3) Lamda Expression
//4) A global function

//1) using Function Object
class UP_Free
{
public:
	void operator()(int *p)
	{
		free(p);
		cout<<"UP:Pointer Freed using Function Object"<<endl<<endl;
	}
};
void UP_UsingFunctionObject()
{
	cout<<"Using Function Object"<<endl;
	cout<<"---------------------"<<endl;
	unique_ptr<int, UP_Free> p{(int*)malloc(4), UP_Free{}};
	*p = 100;
	cout<<"*p is:"<<*p<<endl;
	
}

//2) using Function Pointer
void UP_MallocFree(int *p)
{
	free(p);
	cout<<"UP:Pointer Freed using Function Pointer"<<endl<<endl;
}
void UP_UsingFunctionPointer()
{
	cout<<"Using Function Pointer"<<endl;
	cout<<"----------------------"<<endl;
	unique_ptr<int, void (*)(int*)> p{(int*)malloc(4), UP_MallocFree};
}

void UniquePtrDeleter()
{
	cout<<"*****UNIQ_PTR DELETER*****"<<endl;
	UP_UsingFunctionObject();
	UP_UsingFunctionPointer();
}

/********************SharedPtrDeleter****************/
//We can implement custom deleter for shared pointer mainly in 4 callables
//1) Functio Object
//2) Function Pointer
//3) Lamda Expression
//4) A global function

//1) using Function Object
class SP_Free
{
public:
	void operator()(int *p)
	{
		free(p);
		cout<<"SP:Pointer Freed using Function Object"<<endl<<endl;
	}
};
void SP_UsingFunctionObject()
{
	cout<<"SP:Using Function Object"<<endl;
	cout<<"---------------------"<<endl;
	shared_ptr<int> p{(int*)malloc(4), SP_Free{}};
	*p = 100;
	cout<<"*p is:"<<*p<<endl;
}

//2) using Function Pointer
void SP_MallocFree(int *p)
{
	free(p);
	cout<<"SP:Pointer Freed using Function Pointer"<<endl<<endl;
}
void SP_UsingFunctionPointer()
{
	cout<<"Using Function Pointer"<<endl;
	cout<<"----------------------"<<endl;
	shared_ptr<int> p{(int*)malloc(4), SP_MallocFree};
}

void SharedPtrDeleter()
{
	cout<<"*****SHARED_PTR DELETER*****"<<endl;
	SP_UsingFunctionObject();
	SP_UsingFunctionPointer();
}
int main()
{
	UniquePtrDeleter();
	cout<<endl<<endl;
	SharedPtrDeleter();
	return 0;
}