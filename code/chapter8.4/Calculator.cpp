#include "Calculator.h"

using namespace std;

int Calculator::precedence(const char & s) const{	
	switch (s)	{
		case '=': 	return 0;
		case '#': 	return 1;
		case '+': case '-':	return 2;
		case '*':case '/':	return 3;
	}
}

double Calculator::readNum(string::const_iterator &it){
	string t;
	while (isNum(it))
		t += *it++;
	return stod(t);
}

void Calculator::calculate(){
	double b = m_num.top();
	m_num.pop();
	double a = m_num.top();
	m_num.pop();
	if (m_opr.top() == '+')
		m_num.push(a + b);
	else if (m_opr.top() == '-')
		m_num.push(a - b);
	else if (m_opr.top() == '*')
		m_num.push(a * b);
	else if (m_opr.top() == '/')
		m_num.push(a / b);
	m_opr.pop();
}

double Calculator::doIt(const string & exp){
	m_num.clear();
	for (auto it = exp.begin(); it != exp.end();)	{
		if (isNum(it))	
			m_num.push(readNum(it));		
		else{		
			while (precedence(*it) <= precedence(m_opr.top())){
				if (m_opr.top() == '#')				
					break;			
				calculate();
			}
			if (*it != '=')
				m_opr.push(*it);
			++it;
		}
	}
	return m_num.top();
}
