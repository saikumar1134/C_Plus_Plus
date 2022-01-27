#include<iostream>
using namespace std;

class Test
{
public:
	int *ptr;
	Test(int val)
	{
		cout<<"Paramaterized construtor called"<<endl;
		ptr = new int(val);
	}
	~Test()
	{
		if(ptr == nullptr)
		{
		    cout<<"Destructor is called for: nullptr"<<endl;
		}
		else
		{
		    cout<<"Destructor is called for:"<<*ptr<<endl;
		}
		delete ptr;
	}
	
	//L-Value reference : before c++11 we used to call simply reference, that is by default L-Value
	Test(const Test &obj)
	{
		cout<<"Copy constructor called"<<endl;
		ptr = new int;
		*ptr = *(obj.ptr);
	}
	
	//R-Value reference, introduced newly in C++11
	Test(Test &&obj)
	{
	    cout<<"Move constructor called"<<endl;
		ptr = obj.ptr; //Shallow copy 
		obj.ptr = nullptr; //But, making the old object point to null
	} 
};

Test createObject()
{
	cout<<"create Object called"<<endl;
	//temp is to create a temporary object
	Test temp(10);
	//When the following statement executed, temp goes out of scope and another 
	//temporary object will be created by compiler, that inturn calls move constructor
	//since temporary values or temporary objects are R-Value references
	//if we compile with "-fno-elide-constructors"
	return temp;
}

int main()
{
    /*
    Understanindg of complete program:
    1.  createObject() will be called
        print : create Object called
        Object named "temp" will be created by initiliazing with value 10(in Paramaterized constructor), so *ptr = 10 
        print : Paramaterized constructor called
        
    2.  Whenever the line "return temp" is executed
        Compiler creates a temporary object internally (lets call it as tempObj)
        As we know, whenever temporary object is created by compilier, either of following will be done
            1) It may call copy constructor (If its L-Value reference) Note: No move constructor should be present
            2) It may call move constructor (If its temporary object) Note: Here, precedence will be given to Move constructor though copy construcotr existed
               Since it is temporary objects are bound to R-Value references    
               
    3.  According to point 2.2, control goes to Move construcotr
        print: Move constructor called
        Here, shallow copy will be performed from "object obj(in our case temp)" to "temporary object (in our case tempObj)"
        Now assigned the nullptr to old object obj(in our case obj)
        WHY? 
            This is what called move semantics. i.e., (moving pointer instead of copying entire content)
            Since, obj and tempObj are pointing to same memory location (due to shallow copy)
				1. If we change anyone out of two , the other will affect
				2. If one object is destryoed, other other will become dangling pointer
            So, first change the old obj to nullptr and then delete, why old obj only? since this will goes out of scope after end of Move constructor
            Destructor will be called for nullptr
            
    4.  Now control comes to line Test t1 = createObject()
        So, we have some R-Value now with us i.e., createObject()
        So, this calls move construcotr
        This time, createObject is equal to obj and will be assigned to t1(current instance - this) object.
        As per point no 3, 
            Obj will be assigned with nullptr
            It goes out of scope 
            Destructor will be called for nullptr
            
    5.  At last, now t1 has the value 10
        It goes out of scope, at the end of main
        So, Destructor called for : t1 with value 10 
        
    6.  Note: Copy Elision/Copy Omission
		All modern compilers comes with copy elision technique, which means temporary objects will not be created
		by compiler to avoid unnecessary copying. So, in our example if you compile with modern compilier
		Move cosntructor will omitted (since it is accepting temporary object and R-Value reference)
		
		Hence, compile using following command, to avoid copy elision and to make call to move constructor
		$ g++ Move_Semantics.cpp -fno-elide-constructors
		
    */
	Test t1 = createObject();
	return 0;
}