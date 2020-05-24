#include<iostream>
using std::cout; using std::endl;

#include<list>
using std::list;

#include<string>
using std::string;

class Quote {
public:
	Quote() = default;
	Quote(const string& book, double sales_price) :
		bookNo(book), price(sales_price) {

	}

	string isbn() { return bookNo; }

	/*
		virtual double net_price(size_t n) const {
		return n * price;
	}
	*/

	//virtual ~Quote() = default;
private:
	string bookNo = "base-123456";
protected:
	double price = 0.0;

};


class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string&, double, size_t, double);

	double net_price(size_t) const;

	string isbn() {
		return "derived-56789";
	}

private:
	size_t min_qty = 0;
	double discount = 0.0;
	
};

Bulk_quote::Bulk_quote(const string& book, double p, size_t qty, double disc) :
	Quote(book, p), min_qty(qty), discount(disc) {

}

double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= min_qty) {
		return cnt * (1 - discount) * price;
	}
	else return cnt * price;

}

class NoDerived final {};


class Base {

};

/*
class Driverd : public Driverd {

};
*/

class Derived : private Base {

};

// class Derived2 : public Derived2 {};

class Derived3 : public Base {

};

int hello() {
	cout << "hello world!";
	list<int> ilist;
	for (size_t ix = 0; ix != 4; ++ix)
		ilist.push_back(ix);

	Bulk_quote bulk;
	cout << bulk.isbn() << endl;
	Quote* itemp = &bulk;
	cout << itemp->isbn() << endl;

	Quote base;
	//Bulk_quote* bulkP = &base;



	return 0;
}