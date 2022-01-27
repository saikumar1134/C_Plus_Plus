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
	
	
	int max_sum = arr[0];
	for(int i=0;i<size;i++)
	{
		if(arr[i] != 0)
		{
			max_sum = arr[i];
			break;
		}
	}
	cout<<"Initial non-zero element is:"<<max_sum<<endl;
	
	for(int i=0;i<size;i++)
	{
		if((max_sum < arr[i]) && (max_sum > 0))
		{
			max_sum += arr[i];
		}
	}
	
	cout<<"Maximum sub array sum is:"<<max_sum<<endl;
}