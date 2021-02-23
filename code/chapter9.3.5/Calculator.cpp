#include "Calculator.h"
#include<string>
using namespace std;

// 读取操作数
double Calculator::readNum(string::const_iterator &it){
	string t;
	while (isNum(it))
		t += *it++;
	return stod(t);
}

// 动作, 使用运算符栈和操作数栈顶的元素进行计算
void Calculator::calculate(){
	// 操作数出栈并传入Operator进行计算, 在此只考虑单目和双目运算符
	double a[2] = {0};
	for (auto i = 0; i < m_opr.top()->numOprand(); ++i) {
		a[i] = m_num.top();
		m_num.pop();
	}
	m_num.push(m_opr.top()->get(a[1], a[0]));
	m_opr.pop();
}


double Calculator::doIt(const string & exp){
	for (auto it = exp.begin(); it != exp.end();) {
		// 如果是操作数, 压栈之
		if (isNum(it))
			m_num.push(readNum(it));
		else {// 如果是运算符, 压栈或计算
			  // 将readOpr得到的string转化为Operator
			char o = *it++;
			unique_ptr<Operator> oo;
			if (o == '+')
				oo = make_unique<Plus>();
			else if (o == '-')
				oo = make_unique<Minus>();
			else if (o == '*')
				oo = make_unique<Multiply>();
			else if (o == '/')
				oo = make_unique<Divide>();
			else if (o == '=')
				oo = make_unique<Equal>();

			// 如果栈顶优先级高, 则计算
			while (oo->precedence() <= m_opr.top()->precedence()) {
				if (m_opr.top()->symbol() == '#')
					break;
				calculate();
			}
			// "="从不入栈
			if (oo->symbol() != '=')
				m_opr.push(std::move(oo));
		}
	}
	double result = m_num.top();
	m_num.pop();
	return result;
}
