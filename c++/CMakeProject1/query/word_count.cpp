#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<fstream>
using std::ifstream; using std::ostream; using std::ofstream;

#include<sstream>
using std::istringstream;

#include<vector>
using std::vector;

#include<string>
using std::string; using std::getline;

#include<memory>
using std::shared_ptr;

#include<map>
using std::map;

#include<set>
using std::set;


#include<boost/version.hpp>
#include<boost/timer.hpp>
using boost::timer;

#include<boost/progress.hpp>

int main(int argc, char** argv) {
	boost::progress_timer t;

	map<string, size_t> word_count;
	string word;
	string filename = "F:/tmp/0309_332.txt";
	ifstream ifs(filename);
	vector<string> v;
	ofstream ofs("./test.txt");
	if (ifs.is_open()) {
		while (getline(ifs, word)) {
			++word_count[word];
		}
	}

	

	for (auto w : word_count) {
		word = w.first + " occurs " + std::to_string(w.second) + ((w.second > 1) ? " times " : " time ");
		//cout << w.first << " occurs " << w.second
		//	<< ((w.second > 1) ? " times " : " time ") << endl;
		cout << word << endl;
		for (int i = 0; i < 100000; ++i) {
			v.push_back(word);
		}
	}

	
	boost::progress_display pd(v.size());
	for (auto& x : v) {
		ofs << x << endl;
		++pd;
	}


	cout << "argc: " << argc << ", argv: " << argv[0] << endl;

	cout << "BOOST_LIB_VERSION: " << BOOST_LIB_VERSION << endl;
	cout << "BOOST_VERSION: " << BOOST_VERSION << endl;
	/*
	timer t;
	
	cout << t.elapsed_min() << "s" << endl;
	cout << t.elapsed_max() << "s" << endl;
	cout << t.elapsed() / 3600 << "h" << endl;

	
	*/
	
}