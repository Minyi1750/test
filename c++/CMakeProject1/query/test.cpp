#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<fstream>
using std::ifstream; using std::ostream;

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


void runQueries(ifstream& infile) {
	//TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		//print(cout, tq.query(s)) << endl;
	}
}

int g() {
	string filename = "F:/tmp/0309_332.txt";
	ifstream ifs(filename);
	string line;
	vector<string> text;
	//map<int, string>  text;
	int n = 1;
	if (ifs.is_open()) {
		while (getline(ifs, line)) {
			// cout << line << endl;
			text.push_back(line);
		}
	}
	// runQueries(ifs);
	for (auto s : text) {
		//cout << s << endl;
	}
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		for (auto t : text) {
			if (t == s) {
				cout << "找到该数据:\n";
				cout << s << endl;
			}
		}
		//print(cout, tq.query(s)) << endl;
	}

	//runQueries(ifs);
	cout << "hello world\n";
	return 0;
}