#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<typename t>
t sum(t a, t b)
{
	return a+b;
}

void printValues(int value)
{
	cout<<"Vector values are:"<<value<<endl;
}

//Here we accepted functiona a second parameter, it means val pointer points, printValues function address
void ForEach(vector<int>& v, void(*val)(int))
{
	for(auto i : v)
		val(i);
}

int main()
{
	//Section : 1 - Creation of function pointer
	//The following is basic and actual creation of function pointer
	//Since there is a return type integer, we typecasted with int 
	int(*p)(int,int)= sum;
	
	float(*p1)(float,float)= sum;
	
	double(*p2)(double,double)= sum;
	
	cout<<p(5,10)<<endl;
	cout<<p1(100.5f,200.5f)<<endl;
	cout<<p2(5.5,10.5)<<endl;
	
	//Section : 2 - Passing function pointer
	//Main use is - when we pass function as a parameter, function pointer concepts helps
	//Here, we will implement ForEach function on our own, which prints the values in vector
	vector<int> vect = {5, 1, 2, 4, 3};
	ForEach(vect, printValues);
	
	//Section: 3 - Passing lamda functions to function pointer
	//use : We can get rid of defining multiple functions, since lamda doesn't have any function name
	//which is precise and execute there itself
	//in our above example, we can replace printValues
	
	//Here, no capturing list
	ForEach(vect, [](int i){cout<<"val is"<<i<<endl;});
	
	//Here, we have caputring list, which takes outside varaiables and print them
	//string str = "Hello Sai";
	//auto fun = [str](){cout<<str<<endl;};
	void(*fun)(string) = [](string str){cout<<str<<endl;};
	fun("sai kumar");
	
	return 0;
}