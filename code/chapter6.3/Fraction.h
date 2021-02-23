/*
������
*/

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;

class Fraction {
	int m_numerator = 0;				
	int m_denominator = 1;				
public:
	Fraction& operator=(const Fraction &);			//����=�����
	Fraction& operator*=(const Fraction &);			//����=*�����
						
	Fraction& operator++();//ǰ��++
	Fraction& operator--();//ǰ��--
	Fraction operator++(int); //����++
	Fraction operator--(int);//����--

	const Fraction& operator()(int a, int b); //�������������
	operator double() const; //����ת��

	Fraction(int a = 0, int b = 1);		//Ĭ�ϵĹ��캯��
	Fraction(const Fraction &rhs);		//�������캯��
	~Fraction() {}
	
	void reverse();			//����
	Fraction reciprocal()const;			//����
	void reduce(); //Լ��
	double value() const { return static_cast<double>(m_numerator) / m_denominator; }
	int numerator() const { return m_numerator; }
	int denominator() const { return m_denominator; }
private:
	int gcd(int x, int y);				//���Լ��

	//��Ԫ��������
	friend ostream& operator<<(ostream &out, const Fraction &f);
	friend istream& operator>>(istream &is, Fraction &a);
	friend Fraction operator/(int left, const Fraction &right);
	friend Fraction operator/(const Fraction &left, const Fraction &right);

};

//������������
ostream &operator<<(ostream &out, const Fraction &f);
istream& operator>>(istream &is, Fraction &a);
Fraction operator/(const Fraction &left, const Fraction &right);
Fraction operator/(int left, const Fraction &right);

//��ͨ��������
bool operator==(const Fraction &left, const Fraction &right);

#endif