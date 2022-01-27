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
	int sum = 0, maxsum = arr[0];
	cout<<"All sub arrays are:"<<endl;
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			for(int k=i;k<=j;k++)
			{
				sum += arr[k];
				cout<<arr[k]<<",";
			}
			if(sum>maxsum)
				maxsum = sum;
			sum = 0;
			cout<<endl;
		}
	}
	cout<<"Maximum sub array sum is:"<<maxsum<<endl;
}