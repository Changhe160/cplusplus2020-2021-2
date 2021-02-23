#include<string>
#include<iostream>
#include "Fraction.h"

using namespace std;


int main() {
	//6.3.1
	{
		Fraction a(1, 5);	//直接初始化
		Fraction b(a);		//直接初始化，b为对象a的拷贝
		
		a / b;
		operator/(a, b);

		a *= b;				//调用重载的 * =
		a.operator *= (b);	//与 a*= b 等价
	}
	//6.3.2
	{
		Fraction a(1, 5);	//直接初始化
		Fraction b(a);		//直接初始化，b为对象a的拷贝

		5 / a;
		//int operator-(int, int); //错误，不能重新定义内置运算符

	}

	//6.3.3
	{
		Fraction a(1, 5);	//直接初始化
		Fraction b(a);		//直接初始化，b为对象a的拷贝
		cout << a << " " << b << endl;
		cin >> a;
	}

	//6.3.4
	{
		Fraction a(1, 5);	//直接初始化
		a++;
		++a;
	}

	//6.3.5
	{
		Fraction f;
		f(3, 5); //调用函数调用运算符
	}

	//6.3.6
	{
		Fraction f=2;
		double x = 1.5 + f;
		int i = f;
	}

}
