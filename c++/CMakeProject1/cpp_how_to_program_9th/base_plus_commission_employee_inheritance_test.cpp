#include "base_plus_commission_employee_inheritance.h"


/*
≤‚ ‘ π”√inheritanceµƒBasePlusCommissionEmployee
*/
int main() {
	BasePlusCommissionEmployee base_employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	base_employee.Print();
	cout << "\n\nEmployee earnings: " << base_employee.Earnings() << endl;
	//base_employee.SetGrossSales(8000);
	//base_employee.SetCommistionRate(.1);
	base_employee.SetBaseSalary(1000);
	cout << "\n";
	base_employee.Print();

	cout << "\n\nEmployee earnings: " << base_employee.Earnings() << endl;
	return 0;
}
