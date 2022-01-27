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
	cout<<"SP1"<<"\t\t\tWP1"<<"\t\tWP2"<<endl;
	cout<<"---"<<"\t\t\t---"<<"\t\t---"<<endl;
}

template<class T1, class T2>
void print(T1 &sp1, T2 &wp1, T2 &wp2)
{
	(sp1 != nullptr)?cout<<sp1->GetX()<<" ("<<sp1.use_count()<<")":cout<<"empty";cout<<"\t\t";
	(wp1.expired())?cout<<"Expired":cout<<"Not Expired"<<" ("<<wp1.use_count()<<")";cout<<"\t\t";
	(wp2.expired())?cout<<"Expired":cout<<"Not Expired"<<" ("<<wp2.use_count()<<")";cout<<endl<<endl;
	//(sp2 != nullptr)?cout<<*sp2<<" ("<<sp2.use_count()<<")":cout<<"empty";cout<<endl<<endl;
}

void usingClassType_C11_C14_Style()
{	
	auto sp1 = make_shared<Resource>(10);
	auto wp1 = weak_ptr<Resource>{sp1};
	auto wp2 = weak_ptr<Resource>{sp1};
	
	printHeader();
	//Passing unique_ptr objects as call by reference
	print(sp1, wp1, wp2);
	
	//1. Copy
	cout<<"*****COPY*****"<<endl;
	wp2 = wp1;	print(sp1, wp1, wp2);
	
	//2. LOCK
	cout<<"*****LOCK*****"<<endl;
	if(shared_ptr<Resource> sp2 = wp1.lock())
	{
		//The scope of sp2 is in this block only
		print(sp1, wp1, wp2);
		(sp2 != nullptr)?cout<<"sp2: "<<sp2->GetX()<<" ("<<sp2.use_count()<<")":cout<<"empty";cout<<endl;
	}
	
	//3. Swap - Exchanges the both content and pointer from one pointer to another pointer
	cout<<"*****SWAP*****"<<endl;
	cout<<"Before swap"<<endl;
	print(sp1, wp1, wp2);
	wp1.swap(wp2);
	cout<<"After swap"<<endl;
	print(sp1, wp1, wp2);

	//4. RESET
	cout<<"*****RESET*****"<<endl;
	cout<<"*****RESET WP1*****"<<endl;
	wp1.reset();
	print(sp1, wp1, wp2);
	
	cout<<"*****RESET SP1*****"<<endl;
	sp1.reset(); // wp2 also reset, when sp was reset
	print(sp1, wp1, wp2);
	
	if(shared_ptr<Resource> sp2 = wp2.lock())
	{
		//It will not enter here, because shared pointe sp1 was reset, hence weakpointer doesn't point anything now
	}
	else
	{
		cout<<"No Resource Available"<<endl;
	}
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