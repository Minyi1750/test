#include<boost/algorithm/string.hpp>
#include<boost/random.hpp>
using boost::mt19937;

#include<string>
using std::string;

#include<iostream>
using std::cout; using std::endl; using std::cin;

#include<ctime>

#include<boost/progress.hpp>

#include<chrono>

int main() {
	string str1("Samus"), str2("samus");
	//assert(!is_equal()(str1, str2));
	//assert(is_less()(str1, str2));
	boost::progress_timer t;
	mt19937 rng(time(0));

	cout << mt19937::min() << "<->" << mt19937::max() << endl;

	for (int i = 0; i < 100000; ++i) {
		cout << rng() << endl;
	}


}