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
	int arr[size]={0},cumulativeSum[size]={0};
	cout<<"Elements initialized with zero"<<endl;
	print(arr,size);
	
	cout<<"Enter array elements"<<endl;
	for(int& x:arr)
	{
		cin>>x;
	}
	print(arr,size);
	int sum = 0, maxsum = arr[0];
	cumulativeSum[0]=arr[0];
	cout<<"All sub arrays are:"<<endl;
	for(int i=1;i<size;i++)
	{
		cumulativeSum[i] = arr[i] + cumulativeSum[i-1];
	}
	cout<<"Cumulative sub array is:"<<endl;
	print(cumulativeSum,size);
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			sum = cumulativeSum[j] - cumulativeSum[i-1];
			if(sum>maxsum)
			{
				maxsum = sum;
			}
			sum = 0;
		}
	}
	
	cout<<"Maximum sub array sum is:"<<maxsum<<endl;
}