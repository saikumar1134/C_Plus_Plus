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

bool compare(int a, int b)
{
	return (a<b);
}

//2.Bubble Sort
//Move the larger element towards end by doing pairwise swapping for every element
//->again start from zero till n-1,n-2,n-3....n-n
//here cmp -> "compare" function passed as parameter->which is of compare function
void bubble_sort(int arr[], int size, bool (&cmp)(int a, int b))
{	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			//pair wise swapping
			if(cmp(arr[j], arr[j+1]))
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
	
	//2.Bubble Sort
	//Move the larger element towards end
	bubble_sort(arr,size,compare);
	
	return 0;
}