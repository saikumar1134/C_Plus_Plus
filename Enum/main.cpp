#include <iostream>

using namespace std;

enum day {sun=10, mon, tue, wed, thu, fri, sat};

int main()
{
	day d;
	d = wed;
	cout<<d<<endl;
	if(d == wed)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	
	for(int i = sun; i<=sat ; i++)
	{
		cout<<i<<endl;
	}
}