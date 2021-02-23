//8.3.1节 单链表
#include<iostream>

using namespace std;

//8.3.6节
template<typename T> class SList; //前向声明

template<typename T>
class Node {
	T m_data; //数据域
	Node *m_next = nullptr; //指向下一个结点的指针

	//8.3.6节
	friend class SList<T>; //将SList 声明为Node的友元

public:
	Node(const T &val) :m_data(val) {}
	const T& data() const { return m_data; } //const版本
	T& data() { return m_data; } //非const 版本
	Node* next() { return m_next; }

	//8.3.6节
	Node(const Node &rhs) = delete;
	Node& operator =(const Node &rhs) = delete;
	//其它成员定义与8.3.1节（第173页）相同

};

//8.3.5节
//前向声明，声明友元时需要
template<typename T> ostream& operator<<(ostream&, const SList<T>&);

template<typename T>
class SList {
	Node<T> *m_head = nullptr, *m_tail = nullptr;
public:
	SList() = default;//使用默认构造函数
	~SList();
	void clear();//清空链表
	void push_back(const T &val);//尾插一个结点
								 //在位置pos 后插入一个新结点
	Node<T>* insert(Node<T> *pos, const T &val);
	void erase(const T &val); //删除第一个值为val 的元素
	Node<T>* find(const T &val); //返回第一个值为val 的元素的地址

	//8.3.5节
	friend ostream& operator<< <T>(ostream&, const SList<T>&);
	//其它成员定义与8.3.1节（第174页）相同

	//8.3.6节
	SList(const SList &) = delete;
	SList& operator=(const SList &) = delete;
	//其它成员定义与8.3.1节（第174页）相同
};

//8.3.2节
template<typename T>
void SList<T>::push_back(const T &val) {
	Node<T> *node = new Node<T>(val); //创建一个新结点
	if (m_head == nullptr)
		m_head = m_tail = node;
	else {
		m_tail->m_next = node;
		m_tail = node;
	}
}
//8.3.2节
template<typename T>
Node<T>* SList<T>::insert(Node<T> *pos, const T &val) {
	Node<T> *node = new Node<T>(val); //创建一个新结点node
	node->m_next = pos->m_next; //node指针域指向pos 的后继结点
	pos->m_next = node; //将node置为pos的后继结点
	if (pos == m_tail) //判断pos是否为尾结点
		m_tail = node; //修改tail指针
	return node;
}
//8.3.2节
template<typename T>
Node<T>* SList<T>::find(const T &val) {
	Node<T> *p = m_head;
	while (p != nullptr && p->m_data != val) //找到val首次出现的位置
		p = p->m_next;
	return p;
}

//8.3.3节
template<typename T>
void SList<T>::erase(const T &val) {
	Node<T> *p = m_head, *q = p;
	while (p != nullptr && p->m_data != val) {
		q = p; //指针q指向p
		p = p->m_next; //指针p后移
	} //指针p指向待删除结点，指针q 指向p的前驱
	if (p) //如果p 非空，将结点p从链表中移除
		q->m_next = p->m_next;
	if (p == m_tail)//如果p 为表尾元素，修改tail指针
		m_tail = q;
	delete p;//释放p所指向的内存
}

//8.3.4节
template<typename T>
void SList<T>::clear() {
	Node<T> *p = nullptr;
	while (m_head != nullptr) {
		p = m_head; //p指向当前表头结点
		m_head = m_head->m_next; //表头结点后移
		delete p; //释放p所指向的内存
	}
	m_tail = nullptr;//将尾指针tail置空
}

//8.3.5节
template<typename T>
SList<T>::~SList() {
	clear();
}
//8.3.5节
template<typename T>
ostream& operator<<(ostream &os, const SList<T>& list) {
	Node<T> *p = list.m_head;
	while (p != nullptr) {
		os << p->data() << " ";
		p = p->next();
	}
	return os;
}