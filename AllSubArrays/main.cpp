#include <iostream>

using namespace std;

void print(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
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
	cout<<"All sub arrays are:"<<endl;
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			for(int k=i;k<=j;k++)
			{
				cout<<arr[k]<<",";
			}
			cout<<endl;
		}
	}
}