#include<iostream>

using namespace std;

int MissingNumMeth1(int arr[], int n)
{
	cout<<"array size in meth1 is:"<<n<<endl;
	int sum = ((n+1)*(n+2))/2;
	int arrsum = 0;
	for (int i = 0; i<n;i++)
	{
		arrsum = arrsum + arr[i];
	}
	return sum - arrsum;
}

int MissingNumMeth2(int arr[], int n)
{
	cout<<endl;
	int sum = 0;
	for(int i=1;i<=(n+1);i++)
	{
		sum ^= i;
	}
	cout<<"sum value is:"<<sum<<endl;
	int arrsum = 0;
	for(int i = 0;i<n;i++)
	{
		arrsum ^= arr[i];
	}
	int result = (sum ^ arrsum);
	cout<<"result is:"<<result<<endl;
	return result;
}
int main()
{
	int arr[] = {1,2,3,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Length of an array is:"<<n<<endl;
	//1. Finding using formula - normal method
	cout<<"Missing number is (method1):"<<MissingNumMeth1(arr,n)<<endl;
	cout<<"Missing number is (using XOR):"<<MissingNumMeth2(arr,n)<<endl;
	return 0;
}