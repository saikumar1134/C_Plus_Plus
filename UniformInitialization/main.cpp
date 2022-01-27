#include<iostream>

using namespace std;

int main()
{
	//C++98
	cout<<"C++ 98/03 Initialization"<<endl;
	int A(10); //Direct Initialization
	int B = 20; // Copy Initialization
	int arr[5]={1,2,3}; //Aggregate Initialization
	int *ptr = new int(30);
	cout<<"A value is:"<<A<<endl;
	cout<<"B value is:"<<B<<endl;
	for(int i = 0; i<5; ++i)
		cout<<arr[i]<<"\t";
	cout<<endl;
	cout<<"*ptr is:"<<*ptr<<endl;
	cout<<endl;
	
	//C++11
	cout<<"C++11 Initialization"<<endl;
	int X{10}; //Assign value 10 to varibale X
	int Y{}; //Default initialization to 0
	int arr_1[5]{}; //All values be initilized to 0 by default
	int arr_2[5]{1,2,3}; // 1 2 3 0 0
	int *ptr_1 = new int{50}; //Memory initialized with value 50
	float f{10.5};
	int i{f};
	cout<<"i vlaue is:"<<i<<endl;
	
	cout<<"X value is:"<<X<<endl;
	cout<<"Y value is:"<<Y<<endl; 
	
	for(int i = 0; i<5; ++i)
		cout<<arr_1[i]<<"\t";
	cout<<endl;

	for(int i = 0; i<5; ++i)
		cout<<arr_2[i]<<"\t";
	cout<<endl;

	cout<<"*ptr_1 is:"<<*ptr_1<<endl;
	
	return 0;
}