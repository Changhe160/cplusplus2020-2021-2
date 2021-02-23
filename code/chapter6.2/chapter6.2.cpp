#include "Fraction.h"

class Foo {
	int &m_ref;
	const int m_con;
public:
	Foo(int &i) :m_ref(i), m_con(i) {
	
	}
};
class Employee {
	int m_id;
	string m_name;
public:
	Employee(int id = 0, const string &name = "") :m_id(id), m_name(name) {
	
	}

	Employee(const string &name) :Employee(0, name) {//ί�й��캯��
	
	}

	Employee(const Employee &) = delete;

};

int main() {
	//6.2.1
	{
		Fraction a;			//Ĭ�Ϲ��캯��
		Fraction b(1, 5);	//ֱ�ӳ�ʼ��
		int i;
		Foo f(i);
		
		Employee member("Kevin"); 
	}
	//6.2.2
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		Fraction c = Fraction(3, 2); //���Ƴ�ʼ��
		Fraction d = 7;		//���Ƴ�ʼ��

		//Fraction d2 = static_cast<Fraction>(7); //�����ǽ� Fraction ���Ĭ�Ϲ��캯������Ϊ explicit ֮��

		Fraction e = divide(b, c);

		Employee e1;
		//Employee e2(e1);//���󣺲��ܵ���ɾ���ĸ��ƹ��캯��
	}
	{
		class Point {
			double m_x = 0, m_y = 0;
		public:
			Point(double x=0,double y=0):m_x(x),m_y(y) { 
				cout << "Constructor of Point" << endl; 
			}
			Point(const Point &p) :m_x(p.m_x), m_y(p.m_y) {
				cout << "Copy constructor of Point" << endl;
			}
			~Point() { cout << "Destructor of Point" << endl; }
		};
		class Circle {
			Point m_center; //Բ��
			double m_radius = 1.0;//�뾶
		public:
			Circle(double r = 1, const Point &p = Point()) :
				m_center(p), m_radius(r) {
				cout << "Constructor of Circle" << endl;
			}
			~Circle() {
				cout << "Destructor of Circle" << endl;
			}
		};

		Circle a(2, Point(1, 1));
	}
}