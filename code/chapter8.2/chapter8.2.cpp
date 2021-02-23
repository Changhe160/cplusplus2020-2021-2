#include<iostream>
#include<memory>
#include<vector>
#include"MyStr.h"
using namespace std;

int main() {
	{
		struct  A{
			int *m_array; // 指向动态整型数组
			A(size_t size) : m_array(new int[size] {1}) {}
			A(const A &rhs) : m_array(rhs.m_array) {}
			~A() { 
				//delete[] m_array;
			}
		};
		int *p = nullptr;
		{
			A a1(10); // 创建并初始化A类型对象a1
			p = a1.m_array;
		}
		//cout << p[0] << endl;
		{
			A a1(10); // 创建并初始化A类型对象a1
			cout << a1.m_array[0] << endl;
			{
				A a2(a1); // 用a1复制构造a2
			}
			cout << a1.m_array[0] << endl;
		}

	}
	{//8.2.1
		{
			MyStr s("dynamic memory"); //执行构造函数
			cout << s << endl; //打印输出dynamic memory
		} 
	}

	{//8.2.2
		MyStr s1("dynamic");
		MyStr s2(s1);
		MyStr s3;
		s3 = s1;
		cout << s3 << endl;
	}

	{//8.2.3
		MyStr s1("move "), s2("constructor");
		MyStr s3(s1 + s2);
		cout << s3 << endl;
	}
	{//8.2.3
		MyStr s1("move "), s2("assignment"), s3;
		s3 = s1 + s2;
		cout << s3;
	}
}