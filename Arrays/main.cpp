#include <iostream>
#include <climits>
using namespace std;

void print(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void MinMaxElements(int arr[], int size)
{
	int largest = INT_MIN;
	int smallest = INT_MAX;
	
	for(int i=0;i<size;i++)
	{
		largest = max(largest, arr[i]);
		smallest = min(smallest, arr[i]);
	}
	cout<<"Largest:"<<largest<<"\t"<<"Smallest"<<smallest<<endl;
}

int main()
{
	int size;
	cout<<"Enter size of an array:";
	cin>>size;
	
	int A[size]={0};
	
	cout<<"Initiliazed with zero"<<endl;
	print(A,size);
	
	cout<<"Enter array elemets"<<endl;
	for(auto& x:A)
	{
		cin>>x;
	}
	print(A, size);
	
	//Maximum and minimum elements in aray
	MinMaxElements(A, size);
	return 0;
}