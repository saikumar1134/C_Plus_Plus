#include <iostream>  
using namespace std;  
class Demo  
{  
     
    int a;  
    int b;  
    int *p;  
  public: 
    Demo()  
    {  
        p=new int;  
    } 
	~Demo()
	{
		delete p;
	}
    //Demo(Demo &d)  
    //{  
    //    a = d.a;  
    //    b = d.b;  
    //    p = new int;  
    //    *p = *(d.p);  
    //}  
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
	cout<<"****SHALLOW COPY****"<<endl;
	Demo d1;  
	d1.setdata(4,5,7);  
	Demo d2 = d1; 
	cout<<"After immediate copy from D1 to D2"<<endl;
	cout<<"D1 DATA"<<endl;
	d1.showdata();
	cout<<endl;
	cout<<"D2 DATA"<<endl;
	d2.showdata();
	cout<<endl;
	
	
	cout<<"Changing data here of D1"<<endl;
	d1.setdata(10,20,30);
	cout<<"D1 DATA"<<endl;
	d1.showdata();
	cout<<endl;
	cout<<"D2 DATA"<<endl;
	d2.showdata();
	cout<<endl;
  return 0;  
  
}