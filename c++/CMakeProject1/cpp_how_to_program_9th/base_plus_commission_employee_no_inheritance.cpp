#include "base_plus_commission_employee_no_inheritance.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string& first,
	const string& last,
	const string& ssn,
	double sales,
	double rate,
	double salary
) {
	first_name_ = first;
	last_name_ = last;
	social_security_number_ = ssn;
	SetGrossSales(sales);
	SetCommistionRate(rate);
	SetBaseSalary(salary);
}


void BasePlusCommissionEmployee::SetFirstName(const string& first) {
	first_name_ = first;
}

string BasePlusCommissionEmployee::GetFirstName() const {
	return first_name_;
}

void BasePlusCommissionEmployee::SetLastName(const string& last) {
	last_name_ = last;
}

string BasePlusCommissionEmployee::GetLastName() const {
	return last_name_;
}

void BasePlusCommissionEmployee::SetSocialSecurityNumber(const string& ssn) {
	social_security_number_ = ssn;
}

string BasePlusCommissionEmployee::GetSocialSecurityNumber() const {
	return social_security_number_;
}

void BasePlusCommissionEmployee::SetGrossSales(double sales) {
	if (sales >= 0) {
		gross_sales_ = sales;
	}
	else {
		//throw invalid_argument("Gross sales must be >= 0.0");
		cout << "Gross sales must be >= 0.0\n";
	}
}

double BasePlusCommissionEmployee::GetGrossSales() const {
	return gross_sales_;
}


void BasePlusCommissionEmployee::SetCommistionRate(double rate) {
	if (rate > 0.0 && rate < 1.0) {
		commission_rate_ = rate;
	}
	else {
		// throw invalid_argument("commission rate must be > 0.0 and < 1.0");
		cout << "commission rate must be > 0.0 and < 1.0\n";

	}
}

double BasePlusCommissionEmployee::GetCommistionRate() const {
	return commission_rate_;
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




