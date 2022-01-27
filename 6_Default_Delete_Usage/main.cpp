#include<iostream>

using namespace std;

class Test
{
private:
	int m_value {10};
public:
	/*Test()
	{
		m_value = 10
	}*/
	Test() = default;
	
	Test(int a)
	{
		m_value = a;
	}
	
	//Here, we are restricting user not to initliaze with floating data type
	Test(float)=delete;
	
	void print(){
		cout<<"m_value  is:"<<m_value<<endl;
	}
};

int main()
{
	Test t;
	t.print();
	Test t1(20);
	t1.print();
	return 0;
}