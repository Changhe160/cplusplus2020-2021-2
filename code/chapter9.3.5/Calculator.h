// Calculator based on stack
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <vector>
#include <memory>
#include "Operator.h"
#include "Stack.h"

class Calculator {
private:
	Stack<double> m_num; // 数字栈
	Stack<unique_ptr<Operator>> m_opr; // 运算符栈
	double readNum(string::const_iterator &it); 	// 读取操作数
	bool isNum(string::const_iterator &c) { // 判断字符是否为数字
		return *c >= '0'&&*c <= '9' || *c == '.';
	}
	void calculate();
public:
	Calculator() { m_opr.push(make_unique<Hash>()); }
	double doIt(const string &exp);
};

#endif // !CALCULATOR_H

