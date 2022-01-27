#include<iostream>
#include<string>

using namespace std;

int main()
{
	//1. Before C++11
	string str1{"C:\temp\newfile.txt"};
	cout<<"str1 is:"<<str1<<endl;
	
	string str2{"C:\\temp\\newfile.txt"};
	cout<<"str2 is:"<<str2<<endl;
	
	//2. Raw string in C++11
	string str3{R"(C:\temp\newfile.txt)"};
	cout<<"str3 is:"<<endl;
	
	//It throws error, delimeter ") takes as an end of string
	//string str4{R"(Introduced in "(in c++11)")"}
	
	//In this case, we can define custom delimeter
	//It is character array with the fixed length of 16
	//It should not have whitespaces and back spaces
	string str4{R"MSG(introduced in "(in C++11)")MSG"};
	cout<<"str4 is:"<<str4<<endl;
	
	return 0;
}