//8.4.1 链栈
#include"SList.h"
template<typename T>
class Stack {
	Node<T> *m_top = nullptr;
public:
	Stack() = default; //使用默认构造函数
	Stack(const Stack &) = delete; //禁止复制
	Stack& operator=(const Stack &) = delete; //禁止赋值
	~Stack();
	void clear(); //清空栈操作
	void push(const T &val); //进栈操作
	void pop(); //出栈操作
	bool empty() const { return m_top == nullptr; } //是否为空
	const T& top() { return m_top->m_data; } //取栈顶元素
};

template<typename T>
void Stack<T>::push(const T &val) {
	Node<T> *node = new Node<T>(val); //创建一个新结点node
	node->m_next = m_top; //将结点node压栈
	m_top = node; //修改栈顶指针
}

template<typename T>
void Stack<T>::pop() {
	Node<T> *p = m_top; //将栈顶元素地址存放到指针p 中
	m_top = m_top->m_next; //修改栈顶指针
	delete p; //释放指针p 指向的内存
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
Stack<T>::~Stack() {
	clear();
}