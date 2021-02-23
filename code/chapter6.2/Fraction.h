/*
������
*/

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;

class Fraction{
	int m_numerator;				// ����
	int m_denominator;				//��ĸ
public:
	//Fraction() = default;
	//Fraction(int above, int below) :m_numerator(above), m_denominator(below) {}
	Fraction(int above = 0, int below = 1);//Ĭ�Ϲ��캯��
	Fraction(const Fraction &rhs);		//���ƹ��캯��
	~Fraction();//��������

	//explicit Fraction(int above = 0, int below = 1);//������ʽ����ת��

	int numerator() const { return m_numerator; }
	int denominator() const { return m_denominator; }
};

Fraction divide(const Fraction &left, const Fraction &right);
#endif