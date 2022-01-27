//Program to find Odd Sum and Even Sum from 1 to 1900000000

#include<iostream>
#include<chrono>
#include<thread>

using namespace std;
using namespace std::chrono;
#define MAX 1900000000

//Type Aliasing
using ull = unsigned long long;

//Even Sum
void evenSum(ull* even_sum)
{
	for(ull i = 1; i<=MAX; ++i)
	{
		if((i&1) == 0)
			*(even_sum) += i;
	}	
}

//Odd Sum
void oddSum(ull* odd_sum)
{
	for(ull i = 1; i<=MAX; ++i)
	{
		if((i&1) == 1)
			*(odd_sum) += i;
	}	
}

//1. Without Threads
void WithOutThreads()
{
	cout<<"***WITHOUT THREADS***"<<endl;
	ull even_sum = 0;
	ull odd_sum = 0;
	
	auto startTime = high_resolution_clock::now();
	evenSum(&even_sum);
	cout<<"Even Sum is:"<<even_sum<<endl;
	
	oddSum(&odd_sum);
	cout<<"Odd Sum is:"<<odd_sum<<endl;
	auto stopTime = high_resolution_clock::now();
	
	auto duration = duration_cast<seconds>(stopTime - startTime);
	cout<<"duration is:"<<duration.count()<<"seconds"<<endl;
}

void WithThreads()
{
	cout<<"***WITH THREADS***"<<endl;
	ull even_sum = 0;
	ull odd_sum = 0;
	
	auto startTime = high_resolution_clock::now();
	thread t1(evenSum, &even_sum);
	thread t2(oddSum, &odd_sum);
	t1.join();
	t2.join();
	
	cout<<"Even Sum is:"<<even_sum<<endl;
	cout<<"Odd Sum is:"<<odd_sum<<endl;
	auto stopTime = high_resolution_clock::now();
	
	auto duration = duration_cast<seconds>(stopTime - startTime);
	cout<<"duration is:"<<duration.count()<<"seconds"<<endl;
}

int main()
{
	WithOutThreads();
	WithThreads();
	return 0;
}