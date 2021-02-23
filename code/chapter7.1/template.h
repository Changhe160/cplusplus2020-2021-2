#pragma once
#ifndef TEMPLATE__H
#define TEMPLATE__H
// 7.1 �� ʵ����
//const int& getMax(const int &a, const int &b) {
//	return a > b ? a : b;
//} 
//const string& getMax(const string &a, const string &b) {
//	return a > b ? a : b;
//}

// 7.1.1 ��
template <typename T>
const T &getMax(const T &a, const T &b) {
	return a > b ? a : b;
}

// 7.1.2 �� ʵ����
//const double& getMax(const double &a, const double &b) {
//	return a > b ? a : b;
//}
//bool operator>(const Fraction &lhs, const Fraction &rhs) {
//	return lhs.m_numerator*rhs.m_denominator >
//		lhs.m_denominator*rhs.m_numerator;
//}

// 7.1.3 ��
template<typename T, int size>
const T& maxElem(T(&arr)[size]) {
	T *p = &arr[0];
	for (auto i = 0; i < size; ++i)
		if (*p < arr[i])
			p = &arr[i];
	return *p;
}

template <typename T>
T* const & getMax(T* const &a, T* const &b) {
	return *a > *b ? a : b;
}

template <>
const char* const &getMax(const char* const &a, const char* const &b) {
	return strcmp(a, b) > 0 ? a : b;
}

template<typename T>
void Swap(T &a, T &b) {
	T c(a);//���ƹ������c
	a = b;
	b = c;
}

template<>
void Swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

// 7.1.4 ��
class X {
	void *m_p = nullptr;
public:
	template <typename T>
	void reset(T *t) { m_p = t; }
};

// 7.1.5 ��
template<typename... Args >
void foo(Args... args) {
	cout << sizeof...(args) << endl; //��ӡ������args�в����ĸ���
}

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest) {
	os << t << " "; //��ӡ��һ������
	return print(os, rest...); //�ݹ����
}

template<typename T>
ostream& print(ostream &os, const T &t) {
	return os << t; //��ӡ���һ������
}

void rvalue(int &&val) {}
template<typename T>
void forwardValue(T &&val) {
	//rvalue(val); //����rvalue����������ֵ�β�
	rvalue(std::forward<T>(val));
}

template<typename... Args>
void fun(Args&&... args) {
	foo(std::forward<Args>(args)...);
}

void foo(const string &s, int &&i) {
	cout << s << i << endl;
}

template <typename... Args>
void expand(Args... args) {
	std::initializer_list<int>{([&] {cout << args << endl; }(), 0)...};
}
#endif