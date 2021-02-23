/**************************************************************************
Base class of Operator & a series of Operators
**************************************************************************/

#ifndef OPERATOR_H
#define OPERATOR_H
class Operator{
public:
	Operator(char c, int numOprd, int pre) :m_symbol(c), m_numOprand(numOprd), m_precedence(pre){ }
	char symbol() const {	return m_symbol;	}
	int numOprand() const {	 return m_numOprand;	}
	int precedence() const { return m_precedence; }
	virtual double get(double a, double b) const = 0;
	virtual ~Operator() {}
protected:
	const char m_symbol; // 运算符符号						  
	const int m_numOprand;  // 运算符目数
	const int m_precedence;
};

class Plus : public Operator{ // 运算符+
public:
	Plus() :Operator('+', 2, 2) {}
	double get (double a, double b) const {
		return a + b;
	}
};

class Minus :public Operator{ // 运算符-
public:
	Minus() :Operator('-', 2, 2) {}
	double get (double a, double b) const {
		return a - b;
	}
};

class Multiply :public Operator{ // 运算符*
public:
	Multiply() :Operator('*', 2, 3) {}
	double get (double a, double b) const {
		return a*b;
	}
};


class Divide :public Operator{ // 运算符/
public: 
	Divide() :Operator('/', 2, 3) {}
	double get (double a, double b) const {
		return a / b;
	}
};


class Hash :public Operator{ // 运算符#
public:
	Hash() :Operator('#', 1, 1) {}
	double get (double a, double b) const {
		return a; // 本身#不需要进行任何运算, 但是仍然需要返回值
	}
};


class Equal :public Operator{ //表达式结束符=
public:
	Equal() :Operator('=', 2, 0) {}
	double get (double a, double b) const {
		return a;
	}
};

#endif
