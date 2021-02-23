#include "Fraction.h"

void Fraction::reduce(){
	int num= gcd(abs(m_numerator), abs(m_denominator));
	m_denominator /= num;
	m_numerator /= num;
}
int Fraction::gcd(int x, int y)//Õ·×ªÏà³ý·¨
{
	if (y != 0)
		gcd(y, x%y); //recursive call by using arithmetic rules
	else 
		return x; //base case,return x when y equals 0
}
Fraction::Fraction(int a,int b)
	:m_numerator(a),m_denominator(b){ 
	cout << "default" << endl;

}
Fraction::Fraction(const Fraction& rhs):m_numerator(rhs.m_numerator),m_denominator(rhs.m_denominator){
	cout << "copy" << endl;
}
Fraction& Fraction::operator=(const Fraction& rhs) {
	cout << "copy" << endl;
	if(&rhs==this) return *this;   //do not assign itself, e.g. a=a;
	m_numerator=rhs.m_numerator;
	m_denominator=rhs.m_denominator;
	return *this;
}
Fraction Fraction::operator*(const Fraction&rhs)const {
	return Fraction(m_numerator*rhs.m_numerator,m_denominator*rhs.m_denominator); 
}
Fraction& Fraction::operator*=(const Fraction&rhs){
	m_numerator*=rhs.m_numerator;
	m_denominator*=rhs.m_denominator;
	return *this;
}
Fraction Fraction::reverse()const{
	return Fraction(m_denominator,m_numerator); 
}

bool Fraction::operator<(double real)const {
	if(m_numerator*1./m_denominator<real) return true;	
	return false;
}	
 ostream &operator<<( ostream & out, const Fraction& f) {
	out<< f.m_numerator << "/" << f.m_denominator;
	return out;
}
 void makeCommon(Fraction &a, Fraction &b) {
	 a.m_numerator *= b.m_denominator;
	 b.m_numerator *= a.m_denominator;
	 b.m_denominator = a.m_denominator *= b.m_denominator;
 }
 ostream &print(ostream & out, const Fraction &a) {
	 out << a.numerator() << "/" << a.denominator();
	 return out;
 }

 bool operator==(const Fraction &left, const Fraction &right) {	
	 return left.numerator()*right.denominator() == left.denominator()*right.numerator();
}
