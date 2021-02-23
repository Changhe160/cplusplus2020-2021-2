/*
分数类
*/

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;

class Fraction{
	int m_numerator;				// 分子
	int m_denominator;				//分母
public:
	//Fraction() = default;
	//Fraction(int above, int below) :m_numerator(above), m_denominator(below) {}
	Fraction(int above = 0, int below = 1);//默认构造函数
	Fraction(const Fraction &rhs);		//复制构造函数
	~Fraction();//析构函数

	//explicit Fraction(int above = 0, int below = 1);//抑制隐式类型转换

	int numerator() const { return m_numerator; }
	int denominator() const { return m_denominator; }
};

Fraction divide(const Fraction &left, const Fraction &right);
#endif