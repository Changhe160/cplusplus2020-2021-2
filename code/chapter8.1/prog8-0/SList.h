//8.3.1�� ������
#include<iostream>

using namespace std;

//8.3.6��
template<typename T> class SList; //ǰ������

template<typename T>
class Node {
	T m_data; //������
	Node *m_next = nullptr; //ָ����һ������ָ��

	//8.3.6��
	friend class SList<T>; //��SList ����ΪNode����Ԫ

public:
	Node(const T &val) :m_data(val) {}
	const T& data() const { return m_data; } //const�汾
	T& data() { return m_data; } //��const �汾
	Node* next() { return m_next; }

	//8.3.6��
	Node(const Node &rhs) = delete;
	Node& operator =(const Node &rhs) = delete;
	//������Ա������8.3.1�ڣ���173ҳ����ͬ

};

//8.3.5��
//ǰ��������������Ԫʱ��Ҫ
template<typename T> ostream& operator<<(ostream&, const SList<T>&);

template<typename T>
class SList {
	Node<T> *m_head = nullptr, *m_tail = nullptr;
public:
	SList() = default;//ʹ��Ĭ�Ϲ��캯��
	~SList();
	void clear();//�������
	void push_back(const T &val);//β��һ�����
								 //��λ��pos �����һ���½��
	Node<T>* insert(Node<T> *pos, const T &val);
	void erase(const T &val); //ɾ����һ��ֵΪval ��Ԫ��
	Node<T>* find(const T &val); //���ص�һ��ֵΪval ��Ԫ�صĵ�ַ

	//8.3.5��
	friend ostream& operator<< <T>(ostream&, const SList<T>&);
	//������Ա������8.3.1�ڣ���174ҳ����ͬ

	//8.3.6��
	SList(const SList &) = delete;
	SList& operator=(const SList &) = delete;
	//������Ա������8.3.1�ڣ���174ҳ����ͬ
};

//8.3.2��
template<typename T>
void SList<T>::push_back(const T &val) {
	Node<T> *node = new Node<T>(val); //����һ���½��
	if (m_head == nullptr)
		m_head = m_tail = node;
	else {
		m_tail->m_next = node;
		m_tail = node;
	}
}
//8.3.2��
template<typename T>
Node<T>* SList<T>::insert(Node<T> *pos, const T &val) {
	Node<T> *node = new Node<T>(val); //����һ���½��node
	node->m_next = pos->m_next; //nodeָ����ָ��pos �ĺ�̽��
	pos->m_next = node; //��node��Ϊpos�ĺ�̽��
	if (pos == m_tail) //�ж�pos�Ƿ�Ϊβ���
		m_tail = node; //�޸�tailָ��
	return node;
}
//8.3.2��
template<typename T>
Node<T>* SList<T>::find(const T &val) {
	Node<T> *p = m_head;
	while (p != nullptr && p->m_data != val) //�ҵ�val�״γ��ֵ�λ��
		p = p->m_next;
	return p;
}

//8.3.3��
template<typename T>
void SList<T>::erase(const T &val) {
	Node<T> *p = m_head, *q = p;
	while (p != nullptr && p->m_data != val) {
		q = p; //ָ��qָ��p
		p = p->m_next; //ָ��p����
	} //ָ��pָ���ɾ����㣬ָ��q ָ��p��ǰ��
	if (p) //���p �ǿգ������p���������Ƴ�
		q->m_next = p->m_next;
	if (p == m_tail)//���p Ϊ��βԪ�أ��޸�tailָ��
		m_tail = q;
	delete p;//�ͷ�p��ָ����ڴ�
}

//8.3.4��
template<typename T>
void SList<T>::clear() {
	Node<T> *p = nullptr;
	while (m_head != nullptr) {
		p = m_head; //pָ��ǰ��ͷ���
		m_head = m_head->m_next; //��ͷ������
		delete p; //�ͷ�p��ָ����ڴ�
	}
	m_tail = nullptr;//��βָ��tail�ÿ�
}

//8.3.5��
template<typename T>
SList<T>::~SList() {
	clear();
}
//8.3.5��
template<typename T>
ostream& operator<<(ostream &os, const SList<T>& list) {
	Node<T> *p = list.m_head;
	while (p != nullptr) {
		os << p->data() << " ";
		p = p->next();
	}
	return os;
}