#include<string>
#include<iostream>
#include "Fraction.h"

using namespace std;


int main() {
	//6.3.1
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		
		a / b;
		operator/(a, b);

		a *= b;				//�������ص� * =
		a.operator *= (b);	//�� a*= b �ȼ�
	}
	//6.3.2
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���

		5 / a;
		//int operator-(int, int); //���󣬲������¶������������

	}

	//6.3.3
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		cout << a << " " << b << endl;
		cin >> a;
	}

	//6.3.4
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		a++;
		++a;
	}

	//6.3.5
	{
		Fraction f;
		f(3, 5); //���ú������������
	}

	//6.3.6
	{
		Fraction f=2;
		double x = 1.5 + f;
		int i = f;
	}

}
