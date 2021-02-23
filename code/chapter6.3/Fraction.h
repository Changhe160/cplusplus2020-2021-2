/*
分数类
*/

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;

class Fraction {
	int m_numerator = 0;				
	int m_denominator = 1;				
public:
	Fraction& operator=(const Fraction &);			//重载=运算符
	Fraction& operator*=(const Fraction &);			//重载=*运算符
						
	Fraction& operator++();//前置++
	Fraction& operator--();//前置--
	Fraction operator++(int); //后置++
	Fraction operator--(int);//后置--

	const Fraction& operator()(int a, int b); //函数调用运算符
	operator double() const; //类型转换

	Fraction(int a = 0, int b = 1);		//默认的构造函数
	Fraction(const Fraction &rhs);		//拷贝构造函数
	~Fraction() {}
	
	void reverse();			//倒置
	Fraction reciprocal()const;			//求倒数
	void reduce(); //约分
	double value() const { return static_cast<double>(m_numerator) / m_denominator; }
	int numerator() const { return m_numerator; }
	int denominator() const { return m_denominator; }
private:
	int gcd(int x, int y);				//最大公约数

	//友元函数声明
	friend ostream& operator<<(ostream &out, const Fraction &f);
	friend istream& operator>>(istream &is, Fraction &a);
	friend Fraction operator/(int left, const Fraction &right);
	friend Fraction operator/(const Fraction &left, const Fraction &right);

};

//辅助函数声明
ostream &operator<<(ostream &out, const Fraction &f);
istream& operator>>(istream &is, Fraction &a);
Fraction operator/(const Fraction &left, const Fraction &right);
Fraction operator/(int left, const Fraction &right);

//普通函数声明
bool operator==(const Fraction &left, const Fraction &right);

#endif