#include<iostream>

using namespace std;

//Consider following requirements were given,
// From Finance Team - Include new benifits while calculating monthly salary
// 		So we need to change calculateMonthlySalaryReport()

// From HR Team - Change hours report format to comply with regulations
//		So we need to change calculateMonthlyHoursReport()

//From R&D Team - Migrate to new database technology
//		So we need to change saveModifications()

//here, we can say class PayRoll violates the SRP
//Since, it can be changed for 3 reasons (But, to satisfy SRP - it should only have only reason)
class PayRoll
{
public:
	double calculateMonthlySalaryReport();
	double calculateMonthlyHoursReport();
	void saveModifications();
};


int main()
{
	PayRoll pr;
}