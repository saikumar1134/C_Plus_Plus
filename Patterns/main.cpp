#include <iostream>

using namespace std;

//1. Print lower half pyramid using *
//*
//* *
//* * *
//* * * *
//* * * * *
void PrintLowerHalfPyramidUsingStar()
{
	cout<<"lower half pyramid using *:"<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<=i;j++)
		{
			/*Logic 1*/
			cout<<"* ";
			
			/*Logic2
			for(int j=0;j<5;j++)
			if(i>=j)
			{
				cout<<"* ";
			}*/
		}
		cout<<endl;
	}
	cout<<endl;
}

//2. Print lower inverted half pyramid using *
//* * * * *
//* * * *
//* * * 
//* *
//*
void PrintLowerInvertedHalfPyramidUsingStar()
{
	cout<<"Print lower inverted half pyramid using *:"<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5-i;j++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	cout<<"Another method"<<endl;
	int n=5;
	for(int i=1;i<=n;i++)
	{
		for(int j=n-i+1;j>0;j--)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//3. Print upper half pyramid using *
//        *
//      * *
//    * * *
//  * * * *
//* * * * *
void PrintUpperHalfPyramidUsingStar()
{
	cout<<"Print upper half pyramid using *:"<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if((i+j)>(5-1))
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//4. Print upper inverted half pyramid using *
//* * * * *
//  * * * *
//    * * * 
//      * *
//        *
void PrintUpperInvertedHalfPyramidUsingStar()
{
	cout<<"Print upper inverted half pyramid using *:"<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j>=i)
			{
				cout<<"*";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}

//5. Full pyramid using *
//        *
//      * * *
//    * * * * *
//  * * * * * * *
//* * * * * * * * *
void PrintFullPyramidUsingStar()
{
	cout<<"Full pyramid using *"<<endl;
	int n = 10;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=(n-i);j++)
		{
			cout<<" ";
		}
		
		for(int k=1;k<=(2*i)-1;k++)
		{
			cout<<"*";
		}
			
		for(int l=1;l<=(n-i);l++)
		{
			cout<<" ";
		}
		cout<<endl;
	}
}

//6. Full inverted pyramid using *
//* * * * * * * * *
//  * * * * * * *
//    * * * * *
//      * * *
//        *
void PrintInvertedFullPyramidUsingStar()
{
	cout<<"Full inverted pyramid using *"<<endl;
	int n = 10;
	for(int i=1;i<=n;i++)
	{
		static int h = 0;
		for(int j=1;j<i;j++)
		{
			cout<<" ";
		}
		
		for(int k=1;k<=(2*n-i)-h;++k)
		{
			cout<<"*";
		}
			
		for(int l=1;l<i;l++)
		{
			cout<<" ";
		}
		++h;
		cout<<endl;
	}
}

//7. Print half pyramid using numbers
//1
//1 2
//1 2 3
//1 2 3 4
//1 2 3 4 5
void PrintLowerHalfPyramidUsingNumbers()
{
	int n = 10;
	cout<<"Print half pyramid using numbers"<<endl;
	for(int i = 1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

//5. Print half pyramid using Alphabets
//A
//B B
//C C C
//D D D D
//E E E E E
void PrintLowerHalfPyramidUsingChars()
{
	for(char i= 65;i<=75;i++)
	{
		for(char j=65;j<=i;j++)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
	cout<<"Another Logic"<<endl;
	for(char i= 'A';i<='K';i++)
	{
		for(char j='A';j<=i;j++)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	//1. Print lower half pyramid using *
	//*
	//* *
	//* * *
	//* * * *
	//* * * * *
	PrintLowerHalfPyramidUsingStar();

	//2. Print lower inverted half pyramid using *
	//* * * * *
	//* * * *
	//* * * 
	//* *
	//*
	PrintLowerInvertedHalfPyramidUsingStar();

	//3. Print upper half pyramid using *
	//        *
	//      * *
	//    * * *
	//  * * * *
	//* * * * *
	PrintUpperHalfPyramidUsingStar();
 
	//4. Print upper inverted half pyramid using *
	//* * * * *
	//  * * * *
	//    * * * 
	//      * *
	//        *
	PrintUpperInvertedHalfPyramidUsingStar();
	
	//5. Full pyramid using *
	//        *
	//      * * *
	//    * * * * *
	//  * * * * * * *
	//* * * * * * * * *
	PrintFullPyramidUsingStar();

	//6. Full inverted pyramid using *
	//* * * * * * * * *
	//  * * * * * * *
	//    * * * * *
	//      * * *
	//        *
	PrintInvertedFullPyramidUsingStar();
	
	//7. Print half pyramid using numbers
	//1
	//1 2
	//1 2 3
	//1 2 3 4
	//1 2 3 4 5
	PrintLowerHalfPyramidUsingNumbers();
	
	//8. Print half pyramid using Alphabets
	//A
	//B B
	//C C C
	//D D D D
	//E E E E E
	PrintLowerHalfPyramidUsingChars();
	 /* 
	//8. Print inverted half pyramid using numbers
	//1 2 3 4 5
	//1 2 3 4 
	//1 2 3
	//1 2
	//1
	PrintInvertedLowerHalfPyramidUsingNumbers();
	

	
	//6. Print Invertedhalf pyramid using Characters
	//A A A A A
	//B B B B
	//C C C
	//D D 
	//E 
	PrintInvertedLowerHalfPyramidUsingChars();
	
	*/
	return 0;
}