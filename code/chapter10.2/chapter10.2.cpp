#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
//ostream print(ostream) {}

int main() {


	{
		//for (char c; (c = cin.get()) != '\n'; )
		//	cout << c;
		//cout << endl;
	}

	{
		string s;
		//getline(cin, s);
	}

	{
		cout << showbase << uppercase; //显示进制信息，十六进制数以大写形式输出
		cout << "default:" << 26 << endl;
		cout << "octal:" << oct << 26 << endl;
		cout << "decimal:" << dec << 26 << endl;
		cout << "hex:" << hex << 26 << endl;
		cout << noshowbase << nouppercase << dec;
	}

	{
		int i, j;
		//cin >> oct >> i; //八进制数据
		//cin >> hex >> j; //十六进制数据
	}

	{
		int old_precision = cout.precision();
		double x = 12.152;
		cout.precision(3);
		cout << "precision:" << cout.precision() << ", x=" << x << endl;
		cout << setprecision(4);
		cout << "precision:" << cout.precision() << ", x=" << x << endl;

		cout.precision(old_precision);
	}

	{
		cout << "default format: " << 10 * exp(1.0) << endl;
		cout << "scientific: " << scientific << 10 * exp(1.0) << endl;
		cout << "fixed decimal: " << fixed << 10 * exp(1.0) << endl;
		cout << "default float: " << defaultfloat << 10 * exp(1.0) << endl;
	}

	{
		cout << 1.0 << endl; //打印1
		cout << showpoint << 1.0 << noshowpoint << endl; //打印1.00000
	}

	{
		int i = -10;
		double x = 1.2152;
		cout << "i:" << setw(10) << i << endl;
		cout << "x:" << setw(10) << x << endl;
		cout << setfill('*') << "x:" << setw(10) << x << endl;
	}

	{
		vector<string> wds; //保存读取的单词
		string line, word;
		while (getline(cin, line)) {//利用getline获取一行文本
			istringstream iss(line); //创建输入string流对象，保存line的一个拷贝
			while (iss >> word) //读取每个单词
				wds.push_back(word); //将读取的单词尾插到wds中

			ostringstream out; //创建输出string流对象
			for (auto &i : wds) //处理每一个单词
				out << i << ":" << i.length() << '\n'; //将数据写入输出流对象中
			cout << out.str(); //打印输出

			out.str(""); //清空原有数据
		}
	}
}