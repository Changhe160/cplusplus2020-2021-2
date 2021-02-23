#include "Fraction.h"

void Fraction::reduce() {
	int num = gcd(abs(m_numerator), abs(m_denominator));//��ȡ���ӷ�ĸ�����Լ����
	m_denominator /= num;
	m_numerator /= num;
}
int Fraction::gcd(int x, int y)//շת�����
{
	if (y != 0)
		gcd(y, x%y); //�ݹ����
	else //����ʡ��
		return x; //y=0ʱ�����ؽ��
}
Fraction::Fraction(int a, int b)
	:m_numerator(a), m_denominator(b) {

}
Fraction::Fraction(const Fraction& rhs) : m_numerator(rhs.m_numerator), m_denominator(rhs.m_denominator) {
	
}
Fraction& Fraction::operator=(const Fraction &rhs) {
	
	if (&rhs == this) return *this;   //do not assign itself, e.g. a=a;
	m_numerator = rhs.m_numerator;
	m_denominator = rhs.m_denominator;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction &rhs) {
	m_numerator *= rhs.m_numerator;
	m_denominator *= rhs.m_denominator;
	return *this;
}
Fraction Fraction::reciprocal()const {
	return Fraction(m_denominator, m_numerator);
}
void Fraction::reverse() {
	int i = m_denominator;
	m_denominator = m_numerator;
	m_numerator = i;
}
Fraction::operator double() const { 
	return 1.*m_numerator / m_denominator;
}

const Fraction& Fraction::operator()(int a, int b) { 
	m_numerator = a;
	m_denominator = b;
	return *this;
}


Fraction& Fraction::operator++() {
	++m_numerator;
	return *this;
}
Fraction& Fraction::operator--() {
	--m_numerator;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction a(*this);
	m_numerator++;
	return a;
}

Fraction Fraction::operator--(int) {
	Fraction a(*this);
	m_numerator++;
	return a;
}


ostream& operator<<(ostream & out, const Fraction& f) {
	out << f.m_numerator << "/" << f.m_denominator;
	return out;
}

istream& operator>>(istream &is, Fraction &a) {
	is >> a.m_numerator >> a.m_denominator;
	return is;
}

bool operator==(const Fraction &left, const Fraction &right) {
	return left.numerator()*right.denominator() == left.denominator()*right.numerator();
}

Fraction operator/(const Fraction &left, const Fraction &right) {
	return Fraction(left.m_numerator*right.m_denominator, left.m_denominator*right.m_numerator);
}
Fraction operator/(int left, const Fraction &right) {
	return Fraction(left*right.m_denominator, right.m_numerator);
}