//This program demonstrates the time taken to write into a file 
//using endl and \n
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int main()
{
	ofstream file1("file1.txt");
	ofstream file2("file2.txt");
	
	//Writing into file1 using endl
	auto start = high_resolution_clock::now();
	for(int i = 0;i<100000;++i)
	{
		file1<<"Hello world"<<std::endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"Time taken to insert into file1 using endl is:"<<duration.count()<<endl;
	
	//Writing into file1 using \n
	start = high_resolution_clock::now();
	for(int i = 0;i<100000;++i)
	{
		file2<<"Hello world\n";
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout<<"Time taken to insert into file1 using \\n is:"<<duration.count()<<endl;
	
	file1.close();
	file2.close();
	return 0;
}