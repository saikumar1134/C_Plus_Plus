#include<iostream>

using namespace std;

int main()
{
	//C++98
	int arr[5] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"C++98 FOR LOOP:"<<endl;
	//Here for every element in array, a copy will be performed into i and then prints
	//so, it is not that efficient
	for(int i=0;i<size;++i)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	
	//C++11
	int arr1[5]{1,2,3,4,5};
	cout<<"C++11 FOR LOOP"<<endl;

	for(auto i : arr1)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	//Loop with auto reference
	//Two Advatanges : 1) No need of copy operation
	//2) We can change values of array
	//If you do not want to change the values make it for(const auto &i : arr) 
	for(auto &i : arr1)
	{
		i = 5; // It changes every element of an array to 5
		cout<<i<<"\t";
	}
	
	//How internally range based for loop works
	auto range = arr1;
	//We cannot pass range as an argument to begin() and end(), funciotn since it doesnot accept pointers
	//if we want to pass range, we need make the code as follows
	//auto &&range = arr1; // forward 
	//auto *begin = std::begin(range)
	auto *begin = std::begin(arr1);
	auto *end = std::end(arr1);
	cout<<endl<<"*begin is:"<<*begin<<"\t"<<"*end is:"<<*end<<endl;
	
	for(;begin != end;begin++)
	{
		cout<<*begin<<"\t";
	}
	
	return 0;
}