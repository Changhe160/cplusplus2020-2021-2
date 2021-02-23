#include <iostream>
#include<string>
#include "Fraction.h"
#include "template.h"
using namespace std;

int main() { 

	// 7.1.2 节
	{
		cout << "7.1.2 节：" << endl;
		cout << getMax(1.0, 2.5) << endl; //T为double

		cout << getMax<double>(1.0, 2.5) << endl; //显式指明T为double
		cout << getMax<string>("Hi ", "C++") << endl; //显式指明T为string

		Fraction a(3, 4), b(2, 5);
		cout << getMax(a, b) << endl; //T为Fraction类型
	}

	// 7.1.3 节
	{
		cout << "7.1.3 节：" << endl;
		int arr[10] = { 1,8,5,3 };
		int x = maxElem(arr); //或者显式调用maxElem<int,10>(arr);
		
		int a = 1, b = 2;
		getMax(&a, &b);
		{
			const char* a = "Hi", *b = "C++";
			cout << getMax(a, b) << endl; //调用特例化版本，输出Hi
		}
		int c = 1, d = 2;
		Swap(c, d);
		cout << c << " " << d << endl;
	}

	// 7.1.4 节
	{
		cout << "7.1.4 节：" << endl;
		int i = 0;
		double d = 0;
		X x;
		x.reset(&i); //或者x.reset<int>(&i);
		x.reset(&d); //或者x.reset<double>(&d);
	}

	// 7.1.5 节
	{
		cout << "7.1.5 节：" << endl;
		foo(); //输出：0
		foo(1, 1.5); //输出：2
		foo(1, 1.5, "C++"); //输出：3

		print(cout, 1, 2.5, "C++") << endl; //输出1 2.5 C++

		forwardValue(42); //错误：不能将int转化成int&&

		fun("abc", 42);
	}

	{
		expand(1, "C++", 3.14);
	}
}