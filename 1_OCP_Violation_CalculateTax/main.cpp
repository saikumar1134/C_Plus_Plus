#include<iostream>
#include<string>
#define FULL_SALARY 5000
using namespace std;

class Employee
{
	string id;
	string name;
	string empType;
	//string type[3]{"FullTime","Contract","Freelancing"};
public:
	Employee(string a, string b, string c)
	{
		id = a;
		name = b;
		empType = c;
	}
	string getType()
	{
		return empType;
	}
};

class Tax
{
	double tax;
public:
	double calculateTax(Employee emp)
	{
		if(emp.getType() == "FullTime")
		{
			tax = 3000.5;
		}
		else if(emp.getType() == "Contract")
		{
			tax = 2000.8;
		}
		else
		{
			tax = 1000.3;
		}
		return tax;
	}
};

int main()
{
	Employee FullTimeEmployee("101", "sai", "FullTime");
	Employee ContractEmployee("102", "kumar", "Contract");
	Employee FreelanceEmployee("103", "nakkina", "FreeLancer");
	
	Tax taxObj;
	cout<<"Full time employee tax is:"<<taxObj.calculateTax(FullTimeEmployee)<<endl;
	cout<<"Contact type employee tax is:"<<taxObj.calculateTax(ContractEmployee)<<endl;
	cout<<"Free lancer tax is:"<<taxObj.calculateTax(FreelanceEmployee)<<endl;
	return 0;
}