
#ifndef STACK_H
#define STACK_H

#include<iostream>
using namespace std;

template<typename T> class Stack;
template<typename T> ostream& operator<<(ostream&, const Stack<T>&);

// 节点类
template<typename T>
class Node { // 只需要node可以支持move构造即可
	friend class Stack<T>;
	// 节点数据
	T m_value;
	// 下一节点指针
	Node *m_next = nullptr;
public:
	Node() = default; // 默认构造函数
	Node(const Node &rhs) = delete; // 禁用拷贝构造函数
	Node & operator =(const Node &rhs) = delete; // 禁用拷贝构造算子
	// 天哪, 移动构造函数默认是不启用的? yes, it does.
	// Node(Node&& rhs) = default;
	// Node& operator =(Node&& rhs) = default;
	
	Node(const T &val) :m_value(val) {} // 含参构造函数
	Node(T &&val) :m_value(std::move(val)) { } // 含参移动构造函数
	const T& value() const { return m_value; }
	Node *next() { return m_next; }
};

template<typename T>
class Stack {
	Node<T> *m_top = nullptr;
public:
	Stack() = default;
	Stack(const Stack &) = delete;
	Stack& operator=(const Stack &) = delete;

	~Stack();
	void clear();
	void push(const T &val);
	void push(T&& val); // 我重载了呀? yes, I have overloaded it, and it's enough. Something wrong happend somewhere else
	void pop();
	bool empty()const {
		return m_top == nullptr;
	}
	const T& top() {
		return m_top->m_value;
	}
	friend ostream& operator<< <T>(ostream&, const Stack<T>&);
};

template<typename T>
Stack<T>::~Stack() {
	clear();
}

template<typename T>
void Stack<T>::push(const T &val) {
	Node<T> *node = new Node<T>(val);
	node->m_next = m_top;
	m_top = node;
}

// 支持move的push函数
template<typename T>
void Stack<T>::push(T &&val) {
	Node<T> *node = new Node<T>(move(val)); // val is a lvalue, so I should move it to a rvalue
	node->m_next = m_top;
	m_top = node;
}

template<typename T>
void Stack<T>::clear() {
	Node<T> *p = nullptr;
	while (m_top != nullptr) {
		p = m_top;
		m_top = m_top->m_next;
		delete p;
	}
}

template<typename T>
void Stack<T>::pop() {
	Node<T> *p = m_top;
	m_top = m_top->m_next;
	delete p;
}

template<typename T>
ostream& operator<<(ostream &os, const Stack<T>& s) {
	Node<T> *p = s.m_top;
	while (p != nullptr) {
		os << p->value() << " ";
		p = p->next();
	}
	return os;
}


#endif // !STACK_H