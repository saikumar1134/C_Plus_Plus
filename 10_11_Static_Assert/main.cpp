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
	
	static_assert(is_floating_point<T>::value,"Only floating point numbers are allowed");
	
	return (a/b);
}

int main()
{
	cout<<Divide<float>(3,2)<<endl; // Override argument deduction here
	cout<<Divide(3.5,2.5)<<endl; //Compiler automatically deducts its type
	//cout<<Divide<int>(3,2)<<endl;
	cout<<endl;
	return 0;
}