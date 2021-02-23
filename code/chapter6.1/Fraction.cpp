#include "Fraction.h"

void Fraction::reduce(){
	int num= gcd(m_numerator, m_denominator);
	m_denominator /= num;
	m_numerator /= num;
}
//6.1.3
int Fraction::gcd(int x, int y)
{
	if (y == 0)
		return x; //base case,return x when y equals 0
	else 
		gcd(y, x%y); //recursive call by using arithmetic rules
	return 0;
}

//6.1.5
ostream& print(ostream &os, const Fraction &a) {
	//os << a.m_numerator << "/" << a.m_denominator;//错误：不能访问私有成员
	os << a.numerator() << "/" << a.denominator();
	return os;
}
//6.1.5
void makeCommon(Fraction &a, Fraction &b) {
	a.m_numerator *= b.m_denominator;
	b.m_numerator *= a.m_denominator;
	b.m_denominator = a.m_denominator *= b.m_denominator;
}

