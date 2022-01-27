#include <iostream>
#include <string>
using namespace std;

class Employee
{
    int *id;
    string name;
    string role;
public:
    Employee(int i, string n, string r)
    {
		cout<<"Ctor Called"<<endl;
        id = new int;
        *id = i;
        name = n;
        role = r;
    }
    ~Employee(){cout<<"DTOR Called"<<endl; delete id;}
    
    Employee(const Employee& obj)
    {
		cout<<"CC CALLED"<<endl;
        id = new int; 
        *id = *(obj.id);
        name = obj.name;
        role = obj.role;
    }
    void PrintDetails()
    {
        cout<<"Employee Id:"<<*id<<id<<endl;
        cout<<"Employee Name:"<<name<<&name<<endl;
        cout<<"Employee Role:"<<role<<&role<<endl;
    }
};

int main()
{
    Employee sai(101, "SaiKumar", "Team Member");
    sai.PrintDetails();
    
    Employee kumar = sai;
    kumar.PrintDetails();
    
    return 0;
}
