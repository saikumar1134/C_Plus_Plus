#include <iostream>  
using namespace std;  
class A  
{  
   public:  
    int x;  
    A(int a)                // parameterized constructor.  
    {  
      x=a;  
    }  
    A(const A &obj)               // copy constructor  
    {  
        x = obj.x;  
    }  
	void showData()
	{
		cout<<"x:"<<x<<endl;
		cout<<"address of x is:"<<&x<<endl;
	}
	void changeData(int d)
	{
		x = d;
	}
};  
int main()  
{  
	A a1(20);               // Calling the parameterized constructor.  
	A a2(a1);                //  Calling the copy constructor.  
	a1.showData();
	cout<<endl;
	a2.showData();
	
	a1.changeData(100);
	a1.showData();
	cout<<endl;
	a2.showData();
	return 0;  
}  