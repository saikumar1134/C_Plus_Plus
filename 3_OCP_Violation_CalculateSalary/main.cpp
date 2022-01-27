#include <iostream>
#include <string>

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

class TaxCalculator
{	
public:
	double calculateTax(Employee* emp)
	{
		if(emp->getType() == "FullTime")
		{
			return 1000.5;          
		}
		else if(emp->getType() == "Contract")
		{
			return 2000.5;
		}
		else
		{
			return 3000.5;
		}
	}
};

class calculateSalary
{
	TaxCalculator tc;
public:
	double ActualSalary(Employee* emp)
	{
		return (5000 - tc.calculateTax(emp));
	}
};

int main()
{
	Employee *FullTimeEmployee = new Employee{"101", "sai", "FullTime"};
	Employee *ContractEmployee = new Employee{"102", "kumar", "Contract"};
	Employee *FreelanceEmployee = new Employee{"103", "nakkina", "FreeLancer"};
	
	calculateSalary calSalary;
	cout<<"Full time employee salary is:"<<calSalary.ActualSalary(FullTimeEmployee)<<endl;
	cout<<"Contract employee salary is:"<<calSalary.ActualSalary(ContractEmployee)<<endl;
	cout<<"Freelancer salary is:"<<calSalary.ActualSalary(FreelanceEmployee)<<endl;
	
	delete FullTimeEmployee;
	delete ContractEmployee;
	delete FreelanceEmployee;
	
	return 0;
}