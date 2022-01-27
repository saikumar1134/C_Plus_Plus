//Write a program, to represent distance in km unit only

#include<iostream>

using namespace std;

using ull = unsigned long long;

class Distance
{
	ull km{};
public:
	Distance(ull dist)
	{
		km = dist;
	}
	
	ull GetKM()
	{
		return km;
	}
};

//Meters to KM = meters/1000
//Miles to KM = miles * 1.6
ull operator"" _Miles(ull miles)
{
	return miles * 1.6;
}

ull operator"" _Meters(ull meters)
{
	return meters/1000;
}

int main()
{
	Distance d1{100_Miles};
	cout<<"100 miles in KM is:"<<d1.GetKM()<<endl;
	
	Distance d2{1000_Meters};
	cout<<"100 meters in KM is:"<<d2.GetKM()<<endl;
	return 0;
}
