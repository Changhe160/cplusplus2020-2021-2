//8.2.1节 简单字符串类
#include<iostream>

using namespace std;

class MyStr {
	int m_length; // 字符数组的长度
	char *m_buff; // 指向动态字符数组
public:
	MyStr(const char* val = nullptr); //默认构造函数
	~MyStr() { delete[] m_buff; }
	int size() { return m_length; }

	//8.2.2节
	MyStr(const MyStr &rhs);
	//8.2.2节
	MyStr& operator=(const MyStr &rhs);

	//8.2.3节
	MyStr(MyStr &&rhs);
	MyStr& operator=(MyStr &&rhs);

	//辅助函数声明
	friend ostream& operator<<(ostream &, const MyStr &);//打印字符串
	friend MyStr operator+(const MyStr &, const MyStr &);//字符串相加
private: //私有静态成员函数
	static int strlen(const char *ptr); //获取C风格字符串的长度
	//复制src指向的数组中前n 个字符到dest指向的数组中
	static void strncpy(char *dest, const char *src, int n);
};



