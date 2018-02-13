//============================================================================
// Name        : tongjidanci.cpp
// Author      : minyi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;
using std::string;

int main() {
	//统计一段文本中的字符次数
	pair<string, string> author{"James", "Joyce"};
	map<string, size_t> word_count;
	set<string> exclude = {"am", ".", ","};
	string s;
	string line;
	string buffer;
	cout << "Please Input:\n";
	ifstream infile("test.txt");
	ofstream outfile("jg.txt");
	//能否将嵌套while，变成并列while条件。否则当文件大小超过2GB，则何如？
	if (infile.is_open()){
		cout << "file open success.\n";
		while (getline(infile, line)){
			cout << line << endl;
			istringstream record(line);
			while (record >> s){
				if (exclude.find(s) == exclude.end()){
					//cout << s << endl;
					++word_count[s]; }
			}
		}
	}
	cout << "\nBegin saticase\n";
	for (const auto w : word_count)
		cout << w.first << " occurs " << w.second
				<< ( w.second > 1 ? " times." : " time.") << endl;
	//将输出内容输入文件
	for (const auto w : word_count)
		outfile << w.first << " occurs " << w.second
				<< ( w.second > 1 ? " times." : " time.\n");

	infile.close();
	outfile.close();
	return 0;
}
