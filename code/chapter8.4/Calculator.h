// Calculator based on stack

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Calculator {
private:
	Stack<double> m_num; // 数字栈
	Stack<char> m_opr; // 运算符栈

	// 知识, 得到运算符优先级
	int precedence(const char &s) const;

	// 读取操作数
	double readNum(string::const_iterator &it);

	// 动作, 使用运算符栈和操作数栈顶的元素进行计算并修改两个栈
	void calculate();

	bool isNum(string::const_iterator &c) const	{
		return *c >= '0'&&*c <= '9' || *c == '.';
	}

public:
	// 无参构造函数
	Calculator() { m_opr.push('#'); }
	double doIt(const string &eqt);
};



