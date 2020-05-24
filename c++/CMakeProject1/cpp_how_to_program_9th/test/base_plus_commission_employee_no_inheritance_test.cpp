#include "base_plus_commission_employee_no_inheritance.h"

/*
≤‚ ‘class: BasePlusCommissionEmployee ≤ª π”√inheritance
*/
int main() {
	BasePlusCommissionEmployee base_employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	base_employee.Print();
	//base_employee.SetGrossSales(8000);
	//base_employee.SetCommistionRate(.1);
	base_employee.SetBaseSalary(1000);
	base_employee.Print();

	cout << "\n\nEmployee earnings: " << base_employee.Earnings() << endl;
	return 0;
}