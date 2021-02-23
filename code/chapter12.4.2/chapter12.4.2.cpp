/**************************************************************************
Copyright: Yongfeng Liu
Author: Yongfeng Liu
Date: 2017-06-20
Description:A simple calculator based on stack
**************************************************************************/

#include<string>
#include<iostream>
#include"Calculator.h"
#include"OperatorFactory.h"

using namespace std;

map<char, function<unique_ptr<Operator>()>> Factory::ms_operator; // 定义存储ObjectCreator的静态map
// 使用宏对Operator进行注册
REGISTRAR(Plus, '+');
REGISTRAR(Minus, '-');
REGISTRAR(Multiply, '*');
REGISTRAR(Divide, '/');
REGISTRAR(Equal, '=');

int main()
{
	Factory::ms_operator.emplace('+', []() {return make_unique<Plus>(); });
	string exp;
	Calculator cclt;
	while (getline(cin, exp))
	{
		try {
			cout << cclt.doIt(exp) << endl;
		}
		catch (const char* str) {
			cerr << "Exception:" << str << endl;
		}
	}
	system("pause");
	return 0;
}