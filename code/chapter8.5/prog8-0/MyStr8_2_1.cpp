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

//8.2.2��
MyStr::MyStr(const MyStr &rhs) : m_length(rhs.m_length),
m_buff(m_length>0 ? new char[m_length] : nullptr) {
	strncpy(m_buff, rhs.m_buff, m_length);//��������
}
//8.2.2��
MyStr& MyStr::operator=(const MyStr &rhs) {
	if (this != &rhs) { // ��������ֵ
		delete[] m_buff; // �ͷ�ԭ�����ڴ�
		m_length = rhs.m_length;
		m_buff = new char[m_length]; // ���·����ڴ�
		strncpy(m_buff, rhs.m_buff, m_length);//��������
	}
	return *this;
}
//8.2.3��
MyStr& MyStr::operator=(MyStr &&rhs) {
	if (this != &rhs) { //���д��벻��ȱ�٣���������ֵ�������ݴ���
		delete[] m_buff;
		m_length = rhs.m_length;
		m_buff = rhs.m_buff;
		rhs.m_buff = nullptr; //����ʱ����ָ���Ա��Ϊ��ָ��
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
	// TODO���˴��Ƿ�Ӧ�ü���MyStr��������ӵ��õĺ���Ӧ��������ȫ�������ռ��C��strncpy
	MyStr::strncpy(res.m_buff, s1.m_buff, s1.m_length);
	MyStr::strncpy(res.m_buff + s1.m_length, s2.m_buff, s2.m_length);
	return res; //���ؾֲ�����res
}
