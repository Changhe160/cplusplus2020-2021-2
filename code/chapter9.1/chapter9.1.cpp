#include<iostream>
#include <string>
using namespace std;

//9.1.1 基类
class Person {
protected:
	string m_name; //名字
	int m_age; //年龄
public:
	Person(const string &name = "", int age = 0) : m_name(name),
		m_age(age) {}
	virtual ~Person() = default; //default关键字见6.2.1节（第136页）
	const string& name() const { return m_name; }
	int age() const { return m_age; }
	void plusOneYear() { ++m_age; } //年龄自增
};

//9.1.2 派生类
class PartTimeWorker :public Person { //兼职人员类，公有继承Person
private:
	double m_hour; //工作小时数
	static double ms_payRate; //每小时工资
public:
	PartTimeWorker(const string &name, int age, double h = 0) :Person(
		name, age), m_hour(h) {}
	void setHours(double h) { m_hour = h; }
	double salary() { return m_hour * ms_payRate; }
};
double PartTimeWorker::ms_payRate = 7.53;	//静态成员初始化

class Course { //课程类
	string m_name; //课程名
	int m_score; //成绩
public:
	Course(const string &name = "", int score = 0) :m_name(name),
		m_score(score) { }
	void setScore(int score) { m_score = score; }
	int score() const { return m_score; }
	const string& name()const { return m_name; }
};

class Student :public Person { //学生类，公有继承Person
private:
	Course m_course; //课程信息
public:
	Student(const string &name, int age, const Course &c) :
		Person(name, age), m_course(c) {}
	Course& course() { return m_course; }
};

//9.1.3
class Base {
private:
	int m_pri; //private 成员
protected:
	int m_pro; //protected 成员
public:
	int m_pub; //public 成员
};
class PubDerv :public Base {
	void foo() {
		//m_pri = 10;//错误：不能访问 Base 类私有成员
		m_pro = 1; //正确：可以访问 Base 类受保护成员
	}
};

class PriDerv :private Base {//私有继承不影响派生类成员对基类的访问
	void foo() {
		m_pro = 1; //正确：可以访问 Base 类受保护成员
		m_pub = 1; //正确：可以访问 Base 类公有成员
	}
};

int main() {
	//9.1.3
	{
		Base b;
		//b.m_pro = 10;//错误：不能访问 Base 受保护成员
	}
	{
		PubDerv d1;
		PriDerv d2;
		d1.m_pub = 10; //正确：m_pub 在 PubDerv 中是公有的
		//d2.m_pub = 1; //错误：m_pub 在 PriDerv 中是私有的
	}

	class PubDerv :public Base {
	public:
		using Base::m_pro; //声明为公有的
	};
	{
		PubDerv d;
		d.m_pro; //正确
	}

	class Base {
	protected:
		int m_data;
	public:
		void foo(int) { }
	};
	class Derived : public Base {
	protected:
		int m_data;// 基类 m_data 被隐藏
	public:
		int foo() {// 基类 foo 成员被隐藏
			return m_data;// 返回 Derived::m_data
		}
	};
	{
		Base b;
		Derived d;
		b.foo(10); //正确：调用 Base::foo
		d.foo(); //正确：调用 Derived::foo
		//d.foo(10); //错误：Base::foo 被隐藏了
	}

	//9.1.4
	{
		PartTimeWorker w("Kevin", 21);
		Person p,*ptr;
		ptr = &w; //基类指针 ptr 指向派生类对象 w
		Person &p2 = w; //基类引用绑定到派生类对象 w
		p = w; //派生类对象赋值给基类对象

		//PartTimeWorker *w2 = &p; //错误：不能将基类转换为派生类
		//w = p; //错误：不能将基类转换为派生类
	}
	{
		PartTimeWorker w("Kevin", 21); //派生类对象
		Person p(w); //利用派生类对象构造基类对象
	}
	{
		PriDerv d; //PriDerv 私有继承 Base
		//Base b(d); //错误：PriDerv 不能转换为 Base
	}
}

