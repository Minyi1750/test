#include "commission_employee.h"

/*
≤‚ ‘class: CommissionEmployee
*/
int main() {
	CommissionEmployee employee("Sue", "Jones", "222-22-2222", 10000, .06);

	employee.Print();
	employee.SetGrossSales(8000);
	employee.SetCommistionRate(.1);
	employee.Print();

	cout << "\n\nEmployee earnings: " << employee.Earnings() << endl;
	return 0;
}
