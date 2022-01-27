#include <iostream>
using namespace std;
 
class Empty {
};
 
class Empty1{
};
class Derived1 : public Empty {
};
 
class Derived2 : virtual public Empty {
};
 
class Derived3 : public Empty {
    char c;
};
 
class Derived4 : virtual public Empty {
    char c;
};
 
class Derived5 : public Empty, public Empty1
{
    
};

class Derived6 : virtual public Empty, virtual public Empty1
{
    
};
class Dummy {
    int c;
};


class Hello{
public:
	virtual void hey();
	int a;
};
//Though having private inheritance, we will still have an instance of Hello in Hi object memory
//So size will be 4
class Hi:public Hello{
	
};
 
int main()
{
    cout << "sizeof(Empty) " << sizeof(Empty) << endl;
    cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
    cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
    cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
    cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;
    cout << "sizeof(Derived5) " << sizeof(Derived5) << endl;
    cout << "sizeof(Derived6) " << sizeof(Derived6) << endl;
	
	cout << "sizeof(Hi) " << sizeof(Hi) << endl;
    return 0;
}