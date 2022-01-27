#include<iostream>

using namespace std;

//Example 1
template<int size>
void print()
{
	cout<<"size is:"<<size<<endl;
}

//Example2
template<typename T, int size1>
T sum(T (&a)[size1])
{
	cout<<"array size is:"<<size1<<endl;
	T s{};
	for(int i=0;i<size1;i++)
	{
		s += a[i];
	}
	return s;
}
int main()
{
	//Example 1
	print<3>();
	
	//Example 2
	int arr[]{1,2,3,4};
	cout<<"Sum of array of elements is:"<<sum(arr)<<endl;
	return 0;
}