#include<iostream>

using namespace std;

const int GetNumber()
{
	return 5;
}

//Retuns value at compiletime
constexpr int GetNumber_1()
{
	return 5;
}

constexpr int Add(int a, int b)
{
	return a+b;
}
int main()
{
	//1. Const keyword
	const int i = GetNumber();
	//int arr[i]; //Not recommended
	//Normal Function
	int j = GetNumber(); //This works
	
	
	
	//2. Constexpr keyword
	//Context 1: constepxr to const is possible
	const int k = GetNumber_1(); //This also works
	
	//Context 2: Const to constexpr not possible
	//constexpr int b = GetNumber(); // This doesn't work
	
	//It doesn't work, since GetNumber() can be evaluated until runtime, it can return any value
	//But, constexpr accepts value at compile time
	//constexpr int a = GetNumber(); 
	
	constexpr int a = 10;
	constexpr int c = GetNumber_1(); 
	
	constexpr int sum = Add(3,5);
	int x = 5;
	//Right hand expression should also be constexpr, when initiliazing constexpr. Here, x is not a literal
	//constexpr int sum_1 = Add(x, 3);
	return 0;
} 