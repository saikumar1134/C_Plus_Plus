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

void swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b =temp;
}

//3.Insertion Sort
//Insert the element at the "right" position, by comparing with preceding elements
//Ex: Deck of cards
void bubble_sort(int arr[], int size)
{	
	for(int i=0;i<size-1;i++)
	{
		int j=i+1;
		int element=arr[j];
		while()
		{
			if(arr[i]>a[j])
			{
				arr[j] = arr[i];
				j = i;
				i = j-1;
			}
		}
		for(int j=0;j<size-i;j++)
		{
			//pair wise swapping
			if(arr[j]>arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
	cout<<"Elements after Bubble Sort"<<endl;
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
	
	//3.Insertion Sort
	//Insert the element at the "right" position, by comparing with preceding elements
	//Ex: Deck of cards
	//insertion_sort(arr,size);
	
	return 0;
}