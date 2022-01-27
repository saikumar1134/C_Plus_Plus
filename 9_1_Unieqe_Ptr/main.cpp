#include<iostream>
#include<memory>

using namespace std;

class Resource
{
public:
	Resource() {cout<<"Resource Acquired"<<endl;}
	~Resource() {cout<<"Resource Destroyed"<<endl;}
	void show() {cout<<"Resource::show"<<endl;}
};

void printHeader()
{
	cout<<"U1"<<"\tU2"<<"\tU3"<<endl;
	cout<<"---"<<"\t---"<<"\t---"<<endl;
}
template<class T>
void print(T &u1, T &u2, T &u3, T u4 = 0)
{
	(u1 != nullptr)?cout<<*u1:cout<<"empty";cout<<"\t";
	(u2 != nullptr)?cout<<*u2:cout<<"empty";cout<<"\t";
	(u3 != nullptr)?cout<<*u3:cout<<"empty";cout<<endl<<endl;
}
template<class T1>
void fun(T1 u5)
{
	cout<<"called by value, after this function, u5 goes out of scope"<<endl;
	return;
}

void usingPrimitiveType_C11_C14Style()
{
	/*1. C++14 Stype unique_ptr
	auto u1{ make_unique<int>(10) };
	auto u2{ make_unique<int>(20) };
	auto u3{ make_unique<int>(30) };*/
	
	//1. C++11 Stype unique_ptr
	unique_ptr<int> u1;
	unique_ptr<int> u2(new int{});
	unique_ptr<int> u3(new int(10));
	printHeader();
	//Passing unique_ptr objects as call by reference
	print(u1, u2, u3);
	//u1 = u3;	// compilatio error : since it tries to  do copy, and copy constructor and assignment are deleted in
				// unique pointer
	
	//1. Move - It moves the ownership from one object to another object
	cout<<"*****MOVE*****"<<endl;
	//u1 = u2; //will not work, since copy assignemnt and constructor are deleted here
	u1 = move(u3);	print(u1, u2, u3); 
	//*u2 = 20;		print(u1, u2, u3); 
	
	//2. Get - Returns the address of managed resource -> we can also access its value by *(u1.get) -->u1==u1.get()
	cout<<"*****GET*****"<<endl;
	cout<<u1.get()<<"\t"<<u2.get()<<"\t"<<u3.get()<<endl<<endl;
	
	//3. Swap - Exchanges the both content and pointer from one pointer to another pointer
	cout<<"*****SWAP*****"<<endl;
	u3.reset(new int(30));
	*u2 = 20;
	cout<<"Before swap"<<endl;
	print(u1, u2, u3);
	u1.swap(u2);
	cout<<"After swap"<<endl;
	print(u1, u2, u3);
	cout<<u1.get()<<"\t"<<u2.get()<<"\t"<<u3.get()<<endl<<endl;
	
	//4. Release - Two things will be done-->1. Value and Ownership will be given to some other pointer 
	//or null pointer (if nobody is taking)
	//Release the ownership without destroying it.
	cout<<"*****RELEASE*****"<<endl;
	u2.release(); //ownership will be replaced by null pointer
	print(u1,u2,u3);
	
	//u4 is manual pointer, so we need to manually deallocate the memory
	int *u4 = u1.release(); //value and owneship of u1 given to u4, u1 became nullptr now
	cout<<"*u4 is:"<<*u4<<endl; print(u1, u2, u3);
	
	//5. make unique_ptr call by value, and try to refere the pointer , where the function is called from
	cout<<"*****CALL BY VALUE*****"<<endl;
	unique_ptr<int> u5{new int{500}};
	fun(move(u5));
	if(!u5)
	{
		cout<<"u5 in nullptr"<<endl<<endl;;
	}
	//cout<<*u5<<endl; // Program will be crashed here
	
	cout<<"*****RESET*****"<<endl;
	//5. Reset - Reset the pointer completey, clear the content and remove the ownership by assigning to nullptr
	u1.reset(); u2.reset(); u3.reset();
	print(u1,u2,u3);

	delete u4;
}

int main()
{
	/*********************************************************************
		USING PRIMITIVE TYPE
		1. C++11 Stype unique_ptr
		2. c++14 make_unique
	**********************************************************************/
	
	usingPrimitiveType_C11_C14Style();
	

	return 0;
}