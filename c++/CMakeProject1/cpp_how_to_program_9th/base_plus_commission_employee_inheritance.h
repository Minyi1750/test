#pragma once
#ifndef BASEPLUSINHERITANCE_H
#define BASEPLUSINHERITANCE_H
//#include "commission_employee.h"
#include "commission_employee.h"
//#include "base_plus_commission_employee_no_inheritance.h"

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
	BasePlusCommissionEmployee(
		const string&,
		const string&,
		const string&,
		double = 0.0,
		double = 0.0,
		//diffirence
		double = 0.0
	);

	//diffirence
	void SetBaseSalary(double);
	double GetBaseSalary() const;

	//¸²¸Ç
	double Earnings() const;
	void Print() const;
private:
	double base_salary_;
};
#endif // !BASEPLUSINHERITANCE_H
