#include <iostream>

using namespace std;


void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}	
	cout<<endl;
}

int SumOfArrayElements(int arr[],int n)
{
	int sum = 0;
	for(int i=0;i<n;++i)
	{
		sum += arr[i];
	}
	return sum;
}

//3 - Find maximum
int FindMax(int arr[], int n)
{
	
	//Method 1
	/*int max = arr[0];
	for(int i = 0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;*/
	
	//Method 2
	/*
	int max = INT_MIN;
	for(int x:arr)
	{
		if(x>max)
			max = x;
	}
	*/

}

//4 - Find minimum
int FindMin(int arr[], int n)
{
	int min = arr[0];
	for(int i = 0;i<n;i++)
	{
		if(arr[i]<min)
		{
			min = arr[i];
		}
	}
	return min;
	
	//Method 2
	/*
	int min = INT_MAX;
	for(int x:arr)
	{
		if(x<min)
			min = x;
	}
	*/
}

//5.No of positive numbers
int CountPosNo(int arr[], int n)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=0)
		{
			++count;
		}
	}
	return count;
}

//6. Find number using linear search
void FindNoLinearSearch(int arr[], int n)
{
	cout<<"Enter a key (Linear Search):"<<endl;
	int key;
	cin>>key;
	for(int i=0;i<n;++i)
	{
		if(arr[i] == key)
		{
			cout<<"Element found at index:"<<i<<endl;
			return;
		}
	}
	return;
}

//7. Find number using Binary search
//Prerequisite - Array should be in sorted order
void FindNoBinarySearch(int arr[], int n)
{
	cout<<"Enter a key (Binary Search):"<<endl;
	int key;
	cin>>key;
	int low = 0, high = (n-1), mid;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(arr[mid] == key)
		{
			cout<<"Element found at index:"<<mid<<endl;
			return;
		}
		else if(key < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return;
}

int main()
{
	int n;
	cout<<"Enter size of an array"<<endl;
	cin>>n;
	int arr[n]={0};
	cout<<"All initilized with zero"<<endl;
	print(arr,n);
	
	cout<<"Enter array elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//1. Print array elements
	print(arr,n);
	
	//2.Print sum of array of elements
	cout<<"Sum of array of elements is:"<<SumOfArrayElements(arr,n)<<endl;
	
	//3.Find Maximum element in an array
	cout<<"Maximum Element:"<<FindMax(arr,n)<<endl;
	
	//4.Find Minimum element in an array
	cout<<"Minimum Element:"<<FindMin(arr,n)<<endl;
	
	//5.Count number of positive numbers in array
	cout<<"No of positive numbers are:"<<CountPosNo(arr,n)<<"\t"<<"No of Negatigve numbers are:"<<(n-(CountPosNo(arr,n)))<<endl;

	//6.Linear search - Find the element
	FindNoLinearSearch(arr,n);
	
	//7.Binary search - Find the element
	FindNoBinarySearch(arr,n);
	
	return 0;
}