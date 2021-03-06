#pragma once
#ifndef BASEPLUS_H
#define BASEPLUS_H
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;


//��ʹ��inheritance 
class BasePlusCommissionEmployee {
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

	void SetFirstName(const string&);
	string GetFirstName() const;

	void SetLastName(const string&);
	string GetLastName() const;
	
	void SetSocialSecurityNumber(const string&);
	string GetSocialSecurityNumber() const;

	void SetGrossSales(double);
	double GetGrossSales() const;

	void SetCommistionRate(double);
	double GetCommistionRate() const;

	double Earnings() const;
	void Print() const;

	//diffirence
	void SetBaseSalary(double);
	double GetBaseSalary() const;

private:
	string first_name_;
	string last_name_;
	string social_security_number_;
	double gross_sales_;
	double commission_rate_;

	// diffirence
	double base_salary_;

};
#endif // !BASEPLUS_H
