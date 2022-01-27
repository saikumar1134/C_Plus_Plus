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

void swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b =temp;
}
//1.Selection Sort
//Get the minimum element->swap->then increase i
void selection_sort(int arr[], int size)
{	
	for(int i=0;i<size;i++)
	{
		int min_index = i;
		for(int j=i;j<size;j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index = j;
			}
		}
		swap(arr[i], arr[min_index]);
	}
	cout<<"Elements after Selection Sort"<<endl;
	print(arr,size);
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
	
	//1.Selection Sort
	////Get the minimum element->swap->then increase i
	selection_sort(arr,size);
	
	return 0;
}