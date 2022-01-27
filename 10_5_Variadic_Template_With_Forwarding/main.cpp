#include<iostream>
#include "Test.h"

using namespace std;

print()
{
	cout<<endl;
}

template<typename first, typename... rest>
void print(first &&f, rest&&... r)
{
	cout<<f;
	if(sizeof...(r) > 0)
	{
		cout<<",";
	}
	print(forward<rest>(r)...);
}

int main()
{
	//print(1, 2.5, 'C', "D", 5.5f);
	Test val(100);
	print(0, val, Test{200});
	return 0;
}