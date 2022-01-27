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

/*int binary_search(int arr[],int size, int low, int high, int second)
{
	bool found = true;
	while(low<high)
	{
		int mid = (low+high)/2;
		if(arr[mid] == second)
		{
			return arr[mid];
		}
		else if(second < arr[mid])
		{
			high = mid - 1;
		}
		else if(second > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			found = false;
		}
	}
	if(found == false)
	{
		return -1;
	}
	
	
}*/

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
	int k;
	cout<<"Enter target sum value:"<<endl;
	cin>>k;
	bool found = false;
	//Bruteforce approach - O(N2)
	//Traverse through each element and sum it with 'i'
	for(int i = 0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if((arr[i] + arr[j]) == k)
			{
				found = true;
				cout<<"Pair is:"<<"("<<arr[i]<<"+"<<arr[j]<<")"<<"="<<k<<endl;
			}
		}
	}
	if(found == false)
		cout<<"Matching pair was not found"<<endl;
		
	//O(N.LogN) approach
	//Take element and find its difference using binary search
	//ex: 1 2 3 4 5-   >key = 9   ->a= 4 , b = 9-4 = 5 = binarysearch(5)
/*	int second;
	int i;
	for(i=0;i<size-1;i++)
	{
		int second_element = k-arr[i];
		cout<<"second element is:"<<second_element<<endl;
		second = binary_search(arr, size, i, size, second_element);
		if(second != -1)
		{
			break;
		}
	}
	
	if(second != -1)
	{
		cout<<"(BS)Pair is:"<<"("<<arr[i]<<"+"<<second<<")"<<"="<<k<<endl;
	}
	else
	{
		cout<<"(BS)Matching pair was not found"<<endl;
	}*/
	
	//O(N) approach
	//two pointer approach
	int i = 0, j = size-1;
	while(i != j)
	{
		if(arr[i] + arr[j] == k)
		{
			cout<<"Pair is:"<<"("<<arr[i]<<"+"<<arr[j]<<")"<<"="<<k<<endl;
			++i;
			--j;
		}
		else if((arr[i] + arr[j]) < k)
		{
			++i;
		}
		else if((arr[i] + arr[j]) > k)
		{
			--j;
		}
		else
		{
			found = false;
		}
	}
	if(found == false)
		cout<<"(new method)Matching pair was not found"<<endl;
}