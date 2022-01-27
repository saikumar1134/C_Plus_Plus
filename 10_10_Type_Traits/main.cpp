#include<iostream>
#include<type_traits>

using namespace std;

//1.
template<typename T>
T Divide(T a, T b)
{
	// If the type is other than float, it returns 0 (is_floating_point<T>::value)
	// expression "is_floating_point<T>::value" evaluated at complie time and note down either true or false
	// But, the checking happens at runtime like (true == false / false == false)
	if(is_floating_point<T>::value == false)
	{
		cout<<"Use floating point types only"<<endl;
		return 0;
	}
	return (a/b);
}

//2. Transform the properties of a type
template<typename T>
void CheckReference(T&&)
{
	cout<<boolalpha;
	cout<<"is_reference()? "<<is_reference<T>::value<<endl;
	cout<<"After remvoing the reference: "<<is_reference<typename remove_reference<T>::type>::value<<endl;
}

int main()
{
	//1. Deduce the value at compile time and evaluate at run time
	cout<<Divide<float>(3,2)<<endl;
	cout<<Divide<int>(3,2)<<endl;
	cout<<endl;
	//2. Transfrm the type
	CheckReference(5); // R-Value
	int val{};
	CheckReference(val); //L-Value
	return 0;
}