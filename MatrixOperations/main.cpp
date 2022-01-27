#include <iostream>

using namespace std;


int main()
{
	int r1,c1,r2,c2;
	
	cout<<"Enter size of matrix A(Row Column):";
	cin>>r1>>c1;
	
	cout<<"Enter size of matrix B(Row Column):";
	cin>>r2>>c2;
	
	int A[r1][c1], B[r2][c2];
	cout<<"Enter elements for matrix A:"<<endl;
	for(auto& x:A)
	{
		for(auto& y:x)
		{
			cin>>y;
		}
	}
	PrintMatrixA(r1,c1,A);
	for(auto& x:A)
	{
		for(auto& y:x)
		{
			cout<<y;
		}
		cout<<endl;
	}
	//1. Matrix Addition
	//2. Matrix Subtraction
	//3. Matrix Multiplication
	return 0;
}