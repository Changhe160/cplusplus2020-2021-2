#include<iostream>
#include <string>
using namespace std;

//9.1.1 ����
class Person {
protected:
	string m_name; //����
	int m_age; //����
public:
	Person(const string &name = "", int age = 0) : m_name(name),
		m_age(age) {}
	virtual ~Person() = default; //default�ؼ��ּ�6.2.1�ڣ���136ҳ��
	const string& name() const { return m_name; }
	int age() const { return m_age; }
	void plusOneYear() { ++m_age; } //��������
};

//9.1.2 ������
class PartTimeWorker :public Person { //��ְ��Ա�࣬���м̳�Person
private:
	double m_hour; //����Сʱ��
	static double ms_payRate; //ÿСʱ����
public:
	PartTimeWorker(const string &name, int age, double h = 0) :Person(
		name, age), m_hour(h) {}
	void setHours(double h) { m_hour = h; }
	double salary() { return m_hour * ms_payRate; }
};
double PartTimeWorker::ms_payRate = 7.53;	//��̬��Ա��ʼ��

class Course { //�γ���
	string m_name; //�γ���
	int m_score; //�ɼ�
public:
	Course(const string &name = "", int score = 0) :m_name(name),
		m_score(score) { }
	void setScore(int score) { m_score = score; }
	int score() const { return m_score; }
	const string& name()const { return m_name; }
};

class Student :public Person { //ѧ���࣬���м̳�Person
private:
	Course m_course; //�γ���Ϣ
public:
	Student(const string &name, int age, const Course &c) :
		Person(name, age), m_course(c) {}
	Course& course() { return m_course; }
};

//9.1.3
class Base {
private:
	int m_pri; //private ��Ա
protected:
	int m_pro; //protected ��Ա
public:
	int m_pub; //public ��Ա
};
class PubDerv :public Base {
	void foo() {
		//m_pri = 10;//���󣺲��ܷ��� Base ��˽�г�Ա
		m_pro = 1; //��ȷ�����Է��� Base ���ܱ�����Ա
	}
};

class PriDerv :private Base {//˽�м̳в�Ӱ���������Ա�Ի���ķ���
	void foo() {
		m_pro = 1; //��ȷ�����Է��� Base ���ܱ�����Ա
		m_pub = 1; //��ȷ�����Է��� Base �๫�г�Ա
	}
};

int main() {
	//9.1.3
	{
		Base b;
		//b.m_pro = 10;//���󣺲��ܷ��� Base �ܱ�����Ա
	}
	{
		PubDerv d1;
		PriDerv d2;
		d1.m_pub = 10; //��ȷ��m_pub �� PubDerv ���ǹ��е�
		//d2.m_pub = 1; //����m_pub �� PriDerv ����˽�е�
	}

	class PubDerv :public Base {
	public:
		using Base::m_pro; //����Ϊ���е�
	};
	{
		PubDerv d;
		d.m_pro; //��ȷ
	}

	class Base {
	protected:
		int m_data;
	public:
		void foo(int) { }
	};
	class Derived : public Base {
	protected:
		int m_data;// ���� m_data ������
	public:
		int foo() {// ���� foo ��Ա������
			return m_data;// ���� Derived::m_data
		}
	};
	{
		Base b;
		Derived d;
		b.foo(10); //��ȷ������ Base::foo
		d.foo(); //��ȷ������ Derived::foo
		//d.foo(10); //����Base::foo ��������
	}

	//9.1.4
	{
		PartTimeWorker w("Kevin", 21);
		Person p,*ptr;
		ptr = &w; //����ָ�� ptr ָ����������� w
		Person &p2 = w; //�������ð󶨵���������� w
		p = w; //���������ֵ���������

		//PartTimeWorker *w2 = &p; //���󣺲��ܽ�����ת��Ϊ������
		//w = p; //���󣺲��ܽ�����ת��Ϊ������
	}
	{
		PartTimeWorker w("Kevin", 21); //���������
		Person p(w); //���������������������
	}
	{
		PriDerv d; //PriDerv ˽�м̳� Base
		//Base b(d); //����PriDerv ����ת��Ϊ Base
	}
}

