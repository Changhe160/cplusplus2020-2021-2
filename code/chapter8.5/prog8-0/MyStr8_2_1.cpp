#include "MyStr8_2_1.h"

int MyStr::strlen(const char * ptr) {
	int len = 0;
	while (ptr && *ptr++ != '\0')
		++len;
	return len;
}
void MyStr::strncpy(char *dest, const char *src, int n) {
	for (int i = 0; i < n; ++i)
		dest[i] = src[i];
}

MyStr::MyStr(const char* val) :m_length(strlen(val)),
m_buff(m_length > 0 ? new char[m_length] : nullptr) {
	strncpy(m_buff, val, m_length);
}

//8.2.2节
MyStr::MyStr(const MyStr &rhs) : m_length(rhs.m_length),
m_buff(m_length>0 ? new char[m_length] : nullptr) {
	strncpy(m_buff, rhs.m_buff, m_length);//复制数据
}
//8.2.2节
MyStr& MyStr::operator=(const MyStr &rhs) {
	if (this != &rhs) { // 避免自身赋值
		delete[] m_buff; // 释放原来的内存
		m_length = rhs.m_length;
		m_buff = new char[m_length]; // 从新分配内存
		strncpy(m_buff, rhs.m_buff, m_length);//复制数据
	}
	return *this;
}
//8.2.3节
MyStr& MyStr::operator=(MyStr &&rhs) {
	if (this != &rhs) { //这行代码不能缺少，避免自身赋值引发内容错误
		delete[] m_buff;
		m_length = rhs.m_length;
		m_buff = rhs.m_buff;
		rhs.m_buff = nullptr; //将临时对象指针成员置为空指针
		rhs.m_length = 0;
	}
	return *this;
}

ostream& operator <<(ostream& os, const MyStr& s) {
	for (int i = 0; i < s.m_length; ++i)
		os << s.m_buff[i];
	return os;
}

MyStr operator+(const MyStr &s1, const MyStr &s2) {
	MyStr res;
	res.m_length = s1.m_length + s2.m_length;
	res.m_buff = new char[res.m_length];
	// TODO：此处是否应该加上MyStr？如果不加调用的函数应该是属于全局命名空间的C的strncpy
	MyStr::strncpy(res.m_buff, s1.m_buff, s1.m_length);
	MyStr::strncpy(res.m_buff + s1.m_length, s2.m_buff, s2.m_length);
	return res; //返回局部对象res
}
