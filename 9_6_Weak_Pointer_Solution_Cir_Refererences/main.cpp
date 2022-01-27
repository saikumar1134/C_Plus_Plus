#include<iostream>
#include<memory>

using namespace std;

//Forward Declaration
class Employee;

class Project
{
public:
	shared_ptr<Employee> m_Emp;
	Project(){cout<<"Project CTOR"<<endl;}
	~Project(){cout<<"Project DTOR"<<endl;}
};

class Employee
{
public:
	weak_ptr<Project> m_Prj;
	Employee(){cout<<"Employee CTOR"<<endl;}
	~Employee(){cout<<"Employee DTOR"<<endl;}	
};

int main()
{
	shared_ptr<Project> prj{new Project};
	shared_ptr<Employee> emp{new Employee};
		
	//If we have following two lines of code, Destructor will not be called and underlying resources of
	//pointers m_Emp and m_Prj will not be deleted
	//reason: Pointers prj and emp will be deleted after the main function But,
	//The reference count will not become 0 for m_Prj and m_Emp (m_Prj = 1 and m_Emp = 1) 
	//To resolve this issue, we need make any of the m_Prj or m_Emp as weak pointer
	prj->m_Emp = emp;
	emp->m_Prj = prj;
	return 0;
}