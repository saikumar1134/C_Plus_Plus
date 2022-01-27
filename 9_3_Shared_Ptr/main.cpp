#include<iostream>
#include<memory>

using namespace std;

class Resource
{
	int x;
public:
	Resource(int a=0):x(a){cout<<"Resource Acquired"<<endl;}
	~Resource() {cout<<"Resource Destroyed"<<endl;}
	int GetX() {return x;}
};

void printHeader()
{
	cout<<"S1"<<"\tS2"<<"\tS3"<<endl;
	cout<<"---"<<"\t---"<<"\t---"<<endl;
}
template<class T>
void print(T &s1, T &s2, T &s3, T s4 = 0)
{
	(s1 != nullptr)?cout<<s1->GetX()<<" ("<<s1.use_count()<<")":cout<<"empty";cout<<"\t";
	(s2 != nullptr)?cout<<s2->GetX()<<" ("<<s2.use_count()<<")":cout<<"empty";cout<<"\t";
	(s3 != nullptr)?cout<<s3->GetX()<<" ("<<s3.use_count()<<")":cout<<"empty";cout<<endl<<endl;
}
template<class T1>
void fun(T1 s5)
{
	cout<<"called by value, after this function, s5 goes out of scope"<<endl;
	return;
}

void usingClassType_C11_C14_Style()
{	
	shared_ptr<Resource> s1(new Resource(10));
	shared_ptr<Resource> s2{};
	auto s3 = make_shared<Resource>(0);
	
	printHeader();
	//Passing unique_ptr objects as call by reference
	print(s1, s2, s3);
	
	//1. Copy - It copies the reference to other object, i.e., two object points to the same resource
	cout<<"*****COPY*****"<<endl;
	s2 = s1;	print(s1, s2, s3);
	
	//2. Get - Returns the address of managed resource -> we can also access its value by *(u1.get) -->u1==u1.get()
	cout<<"*****GET*****"<<endl;
	cout<<s1.get()<<"\t"<<s2.get()<<"\t"<<s3.get()<<endl<<endl;
	
	//3. Swap - Exchanges the both content and pointer from one pointer to another pointer
	cout<<"*****SWAP*****"<<endl;
	*s3 = 30;
	cout<<"Before swap"<<endl;
	print(s1, s2, s3);
	s1.swap(s3);
	cout<<"After swap"<<endl;
	print(s1, s2, s3);
	cout<<s1.get()<<"\t"<<s2.get()<<"\t"<<s3.get()<<endl<<endl;
	
	//5. make unique_ptr call by value, and try to refere the pointer , where the function is called from
	cout<<"*****CALL BY VALUE*****"<<endl;
	//shared_ptr<Resource> s5{new Resource{500}};
	fun(s2);
	if(!s2)
	{
		cout<<"s5 in nullptr"<<endl<<endl;;
	}
	else
	{
		print(s1, s2, s3);
	}
	
	cout<<"*****RESET*****"<<endl;
	//5. Reset - Reset the pointer completey, clear the content and remove the ownership by assigning to nullptr
	s1.reset();  
	print(s1,s2,s3);
	s2.reset();
	print(s1,s2,s3);
	s3.reset();
	print(s1,s2,s3);
	
}

int main()
{
	/*********************************************************************
		USING PRIMITIVE TYPE
		1. C++11 Stype unique_ptr
		2. c++14 make_unique
	**********************************************************************/
	usingClassType_C11_C14_Style();

	return 0;
}