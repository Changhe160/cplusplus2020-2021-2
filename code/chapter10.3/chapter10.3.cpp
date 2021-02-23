#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>
#include<sstream>

#include"Array.h"

using namespace std;

void fstream_() {
	int max_rst = 10, max_hen;
	max_rst = 100 / 5;
	max_hen = 100 / 3;

	ofstream out("result.txt");
	if (out) {
		out << setw(10) << "¹«¼¦" << setw(10) << "Ä¸¼¦" << setw(10) << "Ð¡¼¦";

		for (int i = 0; i < max_rst; ++i) {
			for (int j = 0; j < max_hen; ++j) {
				int k = 100 - i - j;
				if (k % 3) continue;
				if (5 * i + 3 * j + k / 3 == 100) {
					out <<'\n'<< setw(10) << i << setw(10) << j << setw(10) << k;
				}
			}
		}
		out.close();
	}

	/*ifstream in("result.txt");
	if (in) {
		string head;
		getline(in, head);
		cout << head << endl;
		int r[3];
		while (!in.eof()) {			
			in >> r[0] >> r[1] >> r[2];
			cout<< setw(10) << r[0] << setw(10) << r[1] << setw(10) << r[2] << endl;
		}
		in.close();
	}*/



}

void sstream_() {
	vector<string> wds;
	string line,word;
	while (getline(cin,line)){
		istringstream iss(line);
		while (iss >>word) {
			wds.push_back(word);
		}
	} 
	
	ostringstream print;
	for (auto &i : wds) {
		print << i << ":" << i.length()<<'\n';
	}
	cout << print.str();
}

int main() {
	sstream_();
	//fstream_();
	//double x;
	//cin >> x;
	//if (!cin)
	//	cin.clear();
	//cout << "flash" << flush;
	//cout << "endl" << endl;
	//cout << "ends" << ends;
	
	//string s;
	//getline(cin, s);
	cout << showbase<<uppercase;
	cout << "default:" << 26 << endl;
	cout << "octal:" << oct << 26 << endl;
	cout << "decimal:" << dec << 26 << endl;
	cout << "hex:" << hex << 26 << endl;
	cout << noshowbase << nouppercase<<dec;

	//int i, j, k;
//	cin >> oct >> i;
//	cin >> hex >> j;

	double x = 1.2152;
	int dp=cout.precision(3);
	cout<< "precision:"<<cout.precision() <<", x="<< x << endl;
	cout<<setprecision(4);
	cout << "precision:" << cout.precision() << ", x=" << x << endl;

	cout.precision(dp);

	cout << "default format: " <<10*exp(1.0) << endl;
	cout << "scientific: " <<scientific<< 10*exp(1.0) << endl;
	cout << "fixed decimal: " << fixed << 10 * exp(1.0) << endl;
	cout << "default float: " << defaultfloat << 10 * exp(1.0) << endl;
	//cout << "dexfloat: " << hexfloat << 100 * sqrt(2.0) << endl;


	cout << 1.0 << endl;
	cout << showpoint << 1.0 << noshowpoint << endl;

	int i = -10;

	cout << "i: " << setw(10) << i << '\n' << "x: " << setw(10) << x << endl;
	cout <<setfill('*')<< "x: " << setw(10) << x << endl;

	ofstream in("hello.txt",ios_base::app);
	if (in) {
		cout << "sucess" << endl;
	}
	in.close();
	in.open("hi.txt");
	if (!in) {
		cout << "fail" << endl;
	}


	for (char c; (c = cin.get()) != '\n';)
		cout << c;
	cout << endl;
}