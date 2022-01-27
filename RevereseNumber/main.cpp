#include <iostream>
#include <vector>

using namespace std;

int SumOfDigits(int n)
{
	int sum = 0, rem = 0;
	while(n != 0)
	{
		rem = n%10;
		sum += rem;
		n = n/10;
	}
	return sum;
}

int ReverseOfNumber(int n)
{
	//Formula is rev = (rev * 10)+(remainder);
	int rev = 0, rem = 0;
	while(n != 0)
	{
		rem = n%10;
		rev = (rev * 10) + rem;
		n = n/10;
	}
	return rev;
}

//True if reversal of a number and number are same
bool PalindromeOfNumber(int n)
{
	if(ReverseOfNumber(n) == n)
		return true;
	else
		return false;
}

int Factorial(int n)
{
	int fact = 1;
	if(n == 0)
	{
		fact = 1;
	}
	else if(n>=1)
	{
		for(int i = 1;i<=n;i++)
		{
			fact *= i;
		}
	}
	else
	{
		cout<<"factorial for negative number is undefined"<<endl;
		fact = 0;
	}
	return fact;
}

//Number is armstrong if, sum of digits of cubes of numbers is equal to the given number
bool CheckArmstrong(int n)
{
	int sum = 0, rem = 0;
	int temp = n;
	while(n != 0)
	{
		rem = n%10;
		sum += (rem * rem *rem);
		n = n/10;
	}
	if(sum == temp)
		return true;
	else
		return false;
}

//Number will be prime if it is divided by itself and one
bool CheckPrime(int n)
{
	int counter = 0;
	for(int i=1;i<=n;i++)
	{
		if(n%i == 0)
		{
			counter += 1;
			if(counter > 2)
			{
				break;
			}
		}
	}
	if(counter > 2)
	{
		return false;
	}
	else
	{
		return true;	
	}
}		

vector<int> FactorsOfNumber(int n)
{
	vector<int> factors;
	for(int i=1;i<=n;i++)
	{
		if(n%i == 0)
		{
			factors.push_back(i);
		}
	}
	return factors;
}

bool CheckPerfect(int n)
{
	int sum = 0;
	vector<int> v = FactorsOfNumber(n);
	vector<int>::iterator itr;
	for(itr = v.begin();itr<v.end();++itr)
	{
		sum += *itr;
	}
	cout<<"sum of factors is:"<<sum<<endl;
	if(sum == (n*2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//if an year div by 4 should be zero, and if it is a century year, it should be div by 400
//if both the above conditions are not met, it is not a leap year
bool CheckLeap(int n)
{
	bool ret = true;
	if(n%4 ==0)
	{
		if(n%400 == 0)
		{
			cout<<"year:"<<n<<"is a leap year"<<endl;
		}
		else
		{
			ret = false;
			cout<<"year:"<<n<<"is not a leap year"<<endl;
		}
	}
	else
	{
		ret = false;
		cout<<"year:"<<n<<"is not a leap year"<<endl;
	}
	return ret;
}

//GCD keep on subtract from larger number among a and b, till you a an b are equal
int GCDOfToNumbers(int a, int b)
{
	while(a != b)
	{
		if(a>b)
			a = a-b;
		else
			b = b-a;
	}
	return a;
}

int main()
{
	int n;
	vector<int> v;
	cout<<"Enter a number:";
	cin>>n;
	cout<<"Sum of digits of a number:"<<SumOfDigits(n)<<endl;
	cout<<"Reverse of a number:"<<ReverseOfNumber(n)<<endl;
	cout<<"Whether palindrome or not:"<<PalindromeOfNumber(n)<<endl;
	cout<<"Factorial of a number"<<Factorial(n)<<endl;
	cout<<"Whether Armstrong or not:"<<CheckArmstrong(n)<<endl;
	cout<<"Whether Prime Number of not:"<<CheckPrime(n)?cout<<"Prime":cout<<"Not a prime"<<endl;
	cout<<"Factors Of a Number are:"<<endl;
	v = FactorsOfNumber(n);
	vector<int>::iterator itr;
	for(itr = v.begin();itr<v.end();++itr)
	{
		cout<<*itr<<"\t";
	}
	cout<<endl;
	cout<<"Whether Perfect number or not:"<<CheckPerfect(n)?cout<<"Perfect Number":cout<<"Not a perfect number"<<endl;
	cout<<"Whether leap year or not:"<<CheckLeap(n)<<endl;
	cout<<"Enter two numbers for GCD Calucalation:"<<endl;
	int a,b;
	cin>>a>>b;
	cout<<"GCD of two numbers:"<<GCDOfToNumbers(a,b)<<endl;
	return 0;
}