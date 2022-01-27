#include<iostream>

using namespace std;

print()
{
	cout<<endl;
}

template<typename first, typename... rest>
void print(first f, rest... r)
{
	cout<<f;
	if(sizeof...(r) > 0)
	{
		cout<<",";
	}
	print(r...);
}

int main()
{
	print(1, 2.5, 'C', "D", 5.5f);
	return 0;
}