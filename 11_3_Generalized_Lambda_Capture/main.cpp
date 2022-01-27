#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int a{10};
	//1. Simple generalized lambda capture list
	//Here, x is assigned with a, and type also deduced as 'a' type by compiler for variable 'x'
	[x = a](auto arg)
	{
		cout<<x + arg<<endl;
	}(20);
	
	//2. Write some content into a file, using generalized capture list
	//Observe the following things about generalized capture list
	//	1) If We make [out] - By value - It throws error since, ofstream obj is not copyable
	//	2) As an alternative to point1, we can use reference like [&out]
	//	3) But, in above two points nowhere we discussed about generalized caputre list
	//		Now, I want "out" should be accessed after write(500), since I dont want to write further into file
	//		I only want to write in lambda expression
	//	4) We cam do by making [out = out] (assigining same name) / [print = out] (with different name)
	//	5) But, 4 will fail in compilation, since "out (ofstream object)" is not copyable
	//		So, we do as [print = move(out)]
	//	6) Still, the compilation fails, since "print" is Not a reference variable(by value), 
	//		so we cannot change it inside lambda expression, so we made L.E "mutable"
	ofstream out{"output.txt"};
	auto write = [print = move(out)](auto arg)mutable
				{
					print<<arg;
				};
	write(500); //This calls overloaded () function
	//Open output folder, and check the text in output.txt
	return 0;
}