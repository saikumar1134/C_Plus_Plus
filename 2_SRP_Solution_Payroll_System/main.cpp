#include <iostream>
#include <string>

using namespace std;

class Employee
{
	string EmpId;
public:	
	string getID()
	{
		return EmpId;
	}
};

//StandAlone class1 : Salary
class Salary
{
public:
	double calculateMonthlySalaryReport(Employee emp);
};

//StandAlone class2 : WorkHours
class WorkHours
{
public:
	double calculateMonthlyHoursReport(Employee emp);
};

//StandAlone class3 : EmployeeDB
class EmployeeDB
{
public:
	double saveModifications(Employee emp);
};

int main()
{
	return 0;
}