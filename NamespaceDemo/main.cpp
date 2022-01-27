#include <iostream>
using namespace std;

namespace ns1
{
    //local to namespace ns1
    int var = 100;
    int print()
    {
        return var;
    }
    
    //Nested namespace
    namespace subns1
    {
        int subns1var = 110;
    }
    
    //Inline namespaces
    /*members of an inline namespace are treated as if they are members of the enclosing namespace in many situations (listed below). 
    This property is transitive: if a namespace N contains an inline namespace M, which in turn contains an inline namespace O, 
    then the members of O can be used as though they were members of M or N.*/
    inline namespace inl1ns1
    {
        inline namespace inl2ns1
        {
            int inlinevar = 120;
        }
        //Usage of USING is->to avoid scope using resolution operator
        using namespace inl2ns1;
    }
    using namespace inl1ns1;
    
    //Class within namesapce with declaration and Definition
    class A
    {
        public:
            void display()
            {
                cout<<"ns1::A::display()"<<endl;
            }
            //Only declaring here
            void display2();
    };
    
    //Class can also be declared inside namespace and defined outside namespace
    class B;
}

//Definition of class B using namespacename::class name
class ns1::B
{
    void display()
    {
        cout<<"ns1::B::display()"<<endl;
    }
};

//We can define class methods also outside the namespace
void ns1::A::display2()
{
    cout<<"ns1::A::display2()"<<endl;
}

//extending namespace ns1
// In simpler words, we can say that both the namespaces are not different but actually the same, which are being defined in parts.
namespace ns1
{
    int extendedvar = 130;
}

//Aliasing subns1
/*In C++, you can use an alias name for your namespace name, for ease of use. Existing namespaces can be aliased with new names, with the following syntax:
namespace new_name = current_name;*/
namespace alias = ns1::subns1;

namespace ns2
{
    //local to namespace ns2
    int var = 200;
    int var2 = 210;
    //Same function name existed in ns1 too
    int print()
    {
        return var;
    }
}
//If using directive is used, no need to call with namespace::var/function
using namespace ns2;

//unnamed namespace
/*They are directly usable in the same program and are used for declaring unique identifiers.
In unnamed namespaces, name of the namespace in not mentioned in the declaration of namespace.
The name of the namespace is uniquely generated by the compiler.
The unnamed namespaces you have created will only be accessible within the file you created it in.
Unnamed namespaces are the replacement for the static declaration of variables.*/
namespace
{
    int unnamedvar = 300;
}
//Global declaration
int var = 0;

int main()
{
    int var = 50;
    
    
    //1. Accessing of varibale at different scopes
    //local variable
    cout<<"var value in main:"<<var<<endl;
    //globally declared variable 
    cout<<"var value in global scope:"<<::var<<endl;

    
    //2. Having same variable name and function name in two different namespaces ns1,ns2
    cout<<"ns1::var:"<<ns1::var<<endl;
    cout<<"ns1::print():"<<ns1::print()<<endl;
    cout<<"ns2::var:"<<ns2::var<<endl;
    cout<<"ns2::print():"<<ns2::print()<<endl;
    
    //3. Accessing class members inside namespace using class namespace::class::members
    ns1::A aobj;
    aobj.display();
    aobj.display2();
    
    //4.Accessing extending namespace value
    cout<<"ns1::extendedvar"<<ns1::extendedvar<<endl;
    
    //5.Accessing unnamed namespace variable->compiler automatically prepend with unique generated namespace
    cout<<"Unnamed variable value:"<<unnamedvar<<endl;

    //6.Different ways to access namespace members
    //Normal way
    cout<<"ns2::var:"<<ns2::var<<endl;
    //using directive - using namespace ns2
    cout<<"ns2::var2:"<<var2<<endl;
    
    //7.Accessing nested namespace subns1 value
    cout<<"ns1::subns1::subns1var:"<<ns1::subns1::subns1var<<endl;
    
    //8.Accessing nested namesapce subns1 value using alias
    cout<<"alias::subns1var(ns1::subns1::subns1var)"<<alias::subns1var<<endl;
    
    //9.Accessing inline members 
    cout<<"ns1::inl1ns1::inl2ns1::inlinevar:"<<ns1::inl1ns1::inl2ns1::inlinevar<<endl;
    cout<<"ns1::inl1ns1::inlinevar:"<<ns1::inl1ns1::inlinevar<<endl;
    cout<<"ns1::inlinevar:"<<ns1::inlinevar<<endl;
    
    //10.Another method of accessing inline var with "USING" directive
    cout<<"ns1::inlinevar(using directive):"<<ns1::inlinevar<<endl;
    
    //11.using namesapce ns2 in main function
    using namespace ns2;
    cout<<"ns2::var2:"<<var2<<endl;
    
    return 0;
}

/*
Output:
var value in main:50
var value in global scope:0
ns1::var:100
ns1::print():100
ns2::var:200
ns2::print():200
ns1::A::display()
ns1::A::display2()
ns1::extendedvar130
Unnamed variable value:300
ns2::var:200
ns2::var2:210
ns1::subns1::subns1var:110
alias::subns1var(ns1::subns1::subns1var)110
ns1::inl1ns1::inl2ns1::inlinevar:120
ns1::inl1ns1::inlinevar:120
ns1::inlinevar:120
ns1::inlinevar(using directive):120
ns2::var2:210
*/