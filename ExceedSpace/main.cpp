#include <iostream>
using namespace std;

int main()
{
	//Here I am taking singed & unsigned short int as an example
	//The same logic applies to other data types as well
	signed short int a; // Range = -32768 to +32767
	a = -32768;
	cout<<"Within Range:"<<a<<endl;

	a = 32767;
	cout<<"Within Range:"<<a<<endl;
	
	a = -37813; //Decreased by one number
	cout<<"Decreased by one number:"<<a<<endl;
	
	a = 32800; //Increased by one number
	cout<<"Increased by one number:"<<a<<endl;	
	
	//Unsinged int
	unsigned short int b; // Range = 0 to +65535
	b = 0;
	cout<<"Within Range:"<<b<<endl;

	b = 65535;
	cout<<"Within Range:"<<b<<endl;
	
	b = -1; //Decreased by one number
	cout<<"Decreased by one number:"<<b<<endl;
	
	b = 65536; //Increased by one number
	cout<<"Increased by one number:"<<b<<endl;	
		
	return 0;
}