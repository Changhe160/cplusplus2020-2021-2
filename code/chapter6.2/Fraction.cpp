#include "Fraction.h"


Fraction::Fraction(const Fraction& rhs):m_numerator(rhs.m_numerator),m_denominator(rhs.m_denominator){
	cout << "Copy constructor called" << endl;
}

Fraction::Fraction(int above, int below) :m_numerator(above), m_denominator(below) {

}

Fraction::~Fraction() { 
	cout << "Destructor called!" << endl; 
}


Fraction divide(const Fraction &left, const Fraction &right) {
	//Fraction result(left.numerator()*right.denominator(), left.denominator()*right.numerator());
	//return result;

	return Fraction(left.numerator()*right.denominator(), left.denominator()*right.numerator()); //返回值优化
}
