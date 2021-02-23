#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include<limits>
using namespace std;
//ostream print(ostream) {}

int main() {
	{
		ifstream in1, in2; //定义两个文件输入流对象（见10.3.1节，第220页）
		//in1 = in2; //错误：不能对流对象赋值
		//ostream print(ostream); //错误：ostream 对象不支持复制
		//print(std::cout);
	}

	{
		double x;
		cin >> x;

		//while (cin >> x);

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
			
		cin >> x;
		cout << x << endl;
	}

	{
		cout << "endl" << endl; //输出endl和一个换行，然后刷新缓冲区
		cout << "flush" << flush; //输出flush（无额外字符），然后刷新缓冲区
		cout << "ends" << ends; //输出ends和一个空字符（’\0’），然后刷新缓冲区
	}

}