/*
分数类
*/

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;

class Fraction{
	int m_numerator=0;				// 分子
	int m_denominator=1;				//分母
	int gcd(int x, int y);  //最大公约数
public:
	Fraction(int a=0,int b=1);		//默认的构造函数
	Fraction(const Fraction& rhs);		//拷贝构造函数
	~Fraction() {}
	int numerator() { return m_numerator; }
	int denominator() { return m_denominator; }
	

	Fraction& operator=(const Fraction&);//重载=运算符
	Fraction operator*(const Fraction&rhs)const;	// 两分数相乘, 注意返回值类型为引用	
	Fraction &operator*=(const Fraction&);	// 两分相乘
	//bool operator<(const Fraction&)const;	// 两分数小于比较
	bool operator<(double)const;
	Fraction reverse()const;			// 求倒数
	void reduce();				//约分
	Fraction& operator++() {
		++m_numerator;
		return *this;
	}
	Fraction& operator--() {
		--m_numerator;
		return *this;
	}

	Fraction operator++(int) {
		Fraction a(*this);
		m_numerator++;
		return a;
	}

	double value() const{	return static_cast<double>(m_numerator) / m_denominator; }
	int numerator() const { 	return m_numerator;	}
	int denominator() const {	return m_denominator;}
	const Fraction& operator()(int a, int b) {
		m_numerator = a;
		m_denominator = b;
		return *this;
	}

	friend void makeCommon(Fraction &a, Fraction &b);
	friend ostream &operator<<(ostream & out, const Fraction& f);
	friend Fraction operator/(int left, const Fraction& right);
	//friend bool operator>(const Fraction&lhs, const Fraction&rhs);  // 7.1.2 节


	operator double() const {
		return 1.*m_numerator / m_denominator;
	}
};

void makeCommon(Fraction &a, Fraction &b);
ostream &operator<<(ostream &out, const Fraction &f);

bool operator==(const Fraction &left, const Fraction &right);
Fraction operator/(const Fraction &left, const Fraction &right);
Fraction operator/(int left, const Fraction &right);

ostream &print(ostream &out, const Fraction &f);
//bool operator>(const Fraction&lhs, const Fraction&rhs);

#endif