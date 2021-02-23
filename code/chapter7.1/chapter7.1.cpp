#include <iostream>
#include<string>
#include "Fraction.h"
#include "template.h"
using namespace std;

int main() { 

	// 7.1.2 ��
	{
		cout << "7.1.2 �ڣ�" << endl;
		cout << getMax(1.0, 2.5) << endl; //TΪdouble

		cout << getMax<double>(1.0, 2.5) << endl; //��ʽָ��TΪdouble
		cout << getMax<string>("Hi ", "C++") << endl; //��ʽָ��TΪstring

		Fraction a(3, 4), b(2, 5);
		cout << getMax(a, b) << endl; //TΪFraction����
	}

	// 7.1.3 ��
	{
		cout << "7.1.3 �ڣ�" << endl;
		int arr[10] = { 1,8,5,3 };
		int x = maxElem(arr); //������ʽ����maxElem<int,10>(arr);
		
		int a = 1, b = 2;
		getMax(&a, &b);
		{
			const char* a = "Hi", *b = "C++";
			cout << getMax(a, b) << endl; //�����������汾�����Hi
		}
		int c = 1, d = 2;
		Swap(c, d);
		cout << c << " " << d << endl;
	}

	// 7.1.4 ��
	{
		cout << "7.1.4 �ڣ�" << endl;
		int i = 0;
		double d = 0;
		X x;
		x.reset(&i); //����x.reset<int>(&i);
		x.reset(&d); //����x.reset<double>(&d);
	}

	// 7.1.5 ��
	{
		cout << "7.1.5 �ڣ�" << endl;
		foo(); //�����0
		foo(1, 1.5); //�����2
		foo(1, 1.5, "C++"); //�����3

		print(cout, 1, 2.5, "C++") << endl; //���1 2.5 C++

		forwardValue(42); //���󣺲��ܽ�intת����int&&

		fun("abc", 42);
	}

	{
		expand(1, "C++", 3.14);
	}
}