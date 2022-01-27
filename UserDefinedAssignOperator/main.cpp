#include <iostream>  
using namespace std;  
class Demo  
{  
    public:  
    int a;  
    int b;  
    int *p;  
  
    Demo()  
    {  
        p=new int;  
    } 
	~Demo()
	{
		delete p;
	}
    Demo& operator = (const Demo &d)  
    {  
		cout<<"Assignment operator called"<<endl;
        a = d.a;  
        b = d.b;  
        //p = new int;  
        *p = *(d.p); 
		return *this;
    }  
    void setdata(int x,int y,int z)  
    {  
        a=x;  
        b=y;  
        *p=z;  
    }  
    void showdata()  
    {  
        std::cout << "value of a is : " <<a<< std::endl;  
        std::cout << "value of b is : " <<b<< std::endl;  
        std::cout << "value of *p is : " <<*p<< std::endl;  
		std::cout << "a address is : " <<&a<< std::endl;
		std::cout << "b address is : " <<&b<< std::endl;
		std::cout << "p address is : " <<p<< std::endl;
    }  
};  
int main()  
{  
	Demo d1;  
	d1.setdata(10,20,30);  
	Demo d2;
	d2 = d1; //Assignemnt operator should be called, not copy constructor
	cout<<"After immediate assignement from D1 to D2"<<endl;
	cout<<"D1 DATA"<<endl;
	d1.showdata();
	cout<<endl;
	cout<<"D2 DATA"<<endl;
	d2.showdata();
	cout<<endl;
	
	
	cout<<"Changing data here of D1"<<endl;
	d1.setdata(4,5,7);
	cout<<"D1 DATA"<<endl;
	d1.showdata();
	cout<<endl;
	cout<<"D2 DATA"<<endl;
	d2.showdata();
	cout<<endl;
  return 0;  
  
}