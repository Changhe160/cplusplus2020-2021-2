#pragma once
#ifndef TEMPLATE__H
#define TEMPLATE__H
// 7.1 节 实例化
//const int& getMax(const int &a, const int &b) {
//	return a > b ? a : b;
//} 
//const string& getMax(const string &a, const string &b) {
//	return a > b ? a : b;
//}

// 7.1.1 节
template <typename T>
const T &getMax(const T &a, const T &b) {
	return a > b ? a : b;
}

// 7.1.2 节 实例化
//const double& getMax(const double &a, const double &b) {
//	return a > b ? a : b;
//}
//bool operator>(const Fraction &lhs, const Fraction &rhs) {
//	return lhs.m_numerator*rhs.m_denominator >
//		lhs.m_denominator*rhs.m_numerator;
//}

// 7.1.3 节
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
	T c(a);//复制构造对象c
	a = b;
	b = c;
}

template<>
void Swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

// 7.1.4 节
class X {
	void *m_p = nullptr;
public:
	template <typename T>
	void reset(T *t) { m_p = t; }
};

// 7.1.5 节
template<typename... Args >
void foo(Args... args) {
	cout << sizeof...(args) << endl; //打印参数包args中参数的个数
}

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest) {
	os << t << " "; //打印第一个参数
	return print(os, rest...); //递归调用
}

template<typename T>
ostream& print(ostream &os, const T &t) {
	return os << t; //打印最后一个参数
}

void rvalue(int &&val) {}
template<typename T>
void forwardValue(T &&val) {
	//rvalue(val); //错误：rvalue函数接受右值形参
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