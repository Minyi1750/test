#include "base_plus_commission_employee_inheritance.h"
//#include "commission_employee.h"


BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string& first,
	const string& last,
	const string& ssn,
	double sales,
	double rate,
	double salary) 
	: CommissionEmployee(first, last, ssn, sales, rate)
{
	SetBaseSalary(salary);
}


void BasePlusCommissionEmployee::SetBaseSalary(double salary) {
	if (salary >= 0.0) {
		base_salary_ = salary;
	}
	else {
		cout << "Salary must be >= 0.0";
	}
}

double BasePlusCommissionEmployee::GetBaseSalary() const {
	return base_salary_;
}

double BasePlusCommissionEmployee::Earnings() const {
	return base_salary_ + (commission_rate_ * gross_sales_);
}

void BasePlusCommissionEmployee::Print() const {
	cout << "\ncommission employee: " << first_name_ << " " << last_name_
		<< "\nsocial security number: " << social_security_number_
		<< "\ngross sales: " << gross_sales_
		<< "\ncommission rate: " << commission_rate_
		<< "\nbase salary: " << base_salary_;
}

