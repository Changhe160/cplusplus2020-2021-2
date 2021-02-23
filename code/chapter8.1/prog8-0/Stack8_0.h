//8.4.1 ��ջ
#include"SList.h"
template<typename T>
class Stack {
	Node<T> *m_top = nullptr;
public:
	Stack() = default; //ʹ��Ĭ�Ϲ��캯��
	Stack(const Stack &) = delete; //��ֹ����
	Stack& operator=(const Stack &) = delete; //��ֹ��ֵ
	~Stack();
	void clear(); //���ջ����
	void push(const T &val); //��ջ����
	void pop(); //��ջ����
	bool empty() const { return m_top == nullptr; } //�Ƿ�Ϊ��
	const T& top() { return m_top->m_data; } //ȡջ��Ԫ��
};

template<typename T>
void Stack<T>::push(const T &val) {
	Node<T> *node = new Node<T>(val); //����һ���½��node
	node->m_next = m_top; //�����nodeѹջ
	m_top = node; //�޸�ջ��ָ��
}

template<typename T>
void Stack<T>::pop() {
	Node<T> *p = m_top; //��ջ��Ԫ�ص�ַ��ŵ�ָ��p ��
	m_top = m_top->m_next; //�޸�ջ��ָ��
	delete p; //�ͷ�ָ��p ָ����ڴ�
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