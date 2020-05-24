#include "commission_employee.h"

CommissionEmployee::CommissionEmployee(
	const string& first,
	const string& last,
	const string& ssn,
	double sales,
	double rate) 
{
	first_name_ = first;
	last_name_ = last;
	social_security_number_ = ssn;
	SetGrossSales(sales);
	SetCommistionRate(rate);
}


void CommissionEmployee::SetFirstName(const string& first) {
	first_name_ = first;
}

string CommissionEmployee::GetFirstName() const {
	return first_name_;
}

void CommissionEmployee::SetLastName(const string& last) {
	last_name_ = last;
}

string CommissionEmployee::GetLastName() const {
	return last_name_;
}

void CommissionEmployee::SetSocialSecurityNumber(const string& ssn) {
	social_security_number_ = ssn;
}

string CommissionEmployee::GetSocialSecurityNumber() const {
	return social_security_number_;
}

void CommissionEmployee::SetGrossSales(double sales) {
	if (sales >= 0) {
		gross_sales_ = sales;
	}
	else {
		//throw invalid_argument("Gross sales must be >= 0.0");
		cout << "Gross sales must be >= 0.0\n";
	}
}

double CommissionEmployee::GetGrossSales() const {
	return gross_sales_;
}


void CommissionEmployee::SetCommistionRate(double rate) {
	if (rate > 0.0 && rate < 1.0) {
		commission_rate_ = rate;
	}
	else {
		// throw invalid_argument("commission rate must be > 0.0 and < 1.0");
		cout << "commission rate must be > 0.0 and < 1.0\n";

	}
}

double CommissionEmployee::GetCommistionRate() const {
	return commission_rate_;
}

double CommissionEmployee::Earnings() const {
	return commission_rate_ * gross_sales_;
}

void CommissionEmployee::Print() const {
	cout << "\ncommission employee: " << first_name_ << " " << last_name_
		<< "\nsocial security number: " << social_security_number_
		<< "\ngross sales: " << gross_sales_
		<< "\ncommission rate: " << commission_rate_;
}
