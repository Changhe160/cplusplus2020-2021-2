// Calculator based on stack

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Calculator {
private:
	Stack<double> m_num; // ����ջ
	Stack<char> m_opr; // �����ջ

	// ֪ʶ, �õ���������ȼ�
	int precedence(const char &s) const;

	// ��ȡ������
	double readNum(string::const_iterator &it);

	// ����, ʹ�������ջ�Ͳ�����ջ����Ԫ�ؽ��м��㲢�޸�����ջ
	void calculate();

	bool isNum(string::const_iterator &c) const	{
		return *c >= '0'&&*c <= '9' || *c == '.';
	}

public:
	// �޲ι��캯��
	Calculator() { m_opr.push('#'); }
	double doIt(const string &eqt);
};



