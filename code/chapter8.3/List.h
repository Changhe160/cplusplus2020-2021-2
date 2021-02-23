#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include<iostream>
using namespace std;

template<typename T> class SList;
template<typename T> ostream& operator<<(ostream&, const SList<T>&);

template<typename T>
class Node{
	friend class SList<T>;
	T m_data;
	Node *m_next = nullptr;
public:
	Node(const Node &rhs) = delete;
	Node & operator =(const Node &rhs) = delete;

	Node(const T &val) :m_data(val) {	}
	const T& data()const {	return m_data;	}
	T& data() { return m_data; }
	Node *next() {	return m_next;	}
}; 

template<typename T>
class SList {
	Node<T> *m_head= nullptr,*m_tail= nullptr;
public:
	~SList();
	void clear();
	void push_back(const T &val);
	Node<T>* insert(Node<T> *pos, const T &val); //在pos后面插入一个结点
	void erase(const T &val); //删除第一次出现的元素
	Node<T>* find(const T &val); //返回第一次出现的元素位置

	//deleted functions
	SList()=default;
	SList(const SList &) = delete;
	SList & operator=(const SList &) = delete;

	friend ostream& operator<< <T>(ostream& , const SList<T>&);
};

template<typename T>
SList<T>::~SList() {
	clear();
}
template<typename T>
void SList<T>::push_back(const T &val) {
	Node<T> *node = new Node<T>(val);
	if (m_head == nullptr) {
		m_head = m_tail= node;		
	}
	else {
		m_tail->m_next = node;
		m_tail = m_tail->m_next;
	}	
}

template<typename T>
void SList<T>::clear() {
	Node<T> *p = nullptr;
	while (m_head != nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
	}
	m_tail = nullptr;
}
template<typename T>
Node<T>* SList<T>::insert(Node<T> *pos, const T &val) {

	Node<T> *node = new Node<T>(val);
	node->m_next = pos->m_next;
	pos->m_next = node;
	if (pos == m_tail)
		m_tail = node;
	return node;
}
template<typename T>
void SList<T>::erase(const T &val) { //删除第一次出现的元素
	Node<T> *p = m_head, *q=p;
	while (p!=nullptr&&p->m_data != val) {
		q = p;//q指向p
		p = p->m_next;//p后移
	}
	if(p)	
		q->m_next = p->m_next;
	if (p == m_tail) 
		m_tail = q;
	if (p == m_head && p)			//如果 p 为表头元素，修改 head 指针
		m_head = p->m_next;
	delete p;
}

template<typename T>
Node<T>* SList<T>::find(const T &val) {
	Node<T> *p = m_head;
	while (p!=nullptr&&p->m_data != val) 	
		p = p->m_next;
	return p;
}

template<typename T>
ostream& operator<<(ostream &os, const SList<T>& list) {
	Node<T> *p = list.m_head;
	while (p != nullptr) {
		os << p->data() << " ";
		p = p->next();
	}
		
	return os;
}

#endif
