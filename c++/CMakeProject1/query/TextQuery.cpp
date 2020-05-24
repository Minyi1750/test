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


class TextQuery {

public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	//QueryResult query(const string&) const;
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};



TextQuery::TextQuery(ifstream& is):
	file(new vector<string>)
{
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;

		while (line >> word) {
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}

	}

}



//QueryResult query(const string&) const;
QueryResult
TextQuery::query(const string& sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}


class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);
public:
	typedef std::vector<std::string>::size_type line_no;
	QueryResult(string s,
		shared_ptr<set<line_no>> p,
		shared_ptr<vector<string>> f) :
		sought(s), lines(p), file(f) {

	}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};



string make_plural(size_t ctr, const string& word, const string& ending) {
	return (ctr > 1) ? word + ending : word;
}


ostream& print(ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "times", "s") << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") "
			<< *(qr.lines->begin() + num) << endl;
	}
	return os;
}


void runQueries(ifstream& infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int test() {
	string filename = "E:/tmp/test.text";
	ifstream ifs(filename);
	//runQueries(ifs);
	return 0;
}