#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

bool compare(int a, int b)
{
	return (a>b);
}

int main()
{
	int size;
	cout<<"Enter size of an array"<<endl;
	cin>>size;
	int arr[size]={0};
	cout<<"Elements initialized with zero"<<endl;
	print(arr,size);
	
	cout<<"Enter array elements"<<endl;
	for(int& x:arr)
	{
		cin>>x;
	}
	print(arr,size);
	
	//Inbuild sort function
	//starting index, last index and comparitor (asceding or descending order)
	cout<<"In ascending order"<<endl;
	sort(arr,arr+size);
	print(arr,size);
	
	//Descending order
	cout<<"In descending order"<<endl;
	sort(arr,arr+size,compare);
	print(arr,size);
	return 0;
}