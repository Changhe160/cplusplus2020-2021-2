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

	Employee(const string &name) :Employee(0, name) {//委托构造函数
	
	}

	Employee(const Employee &) = delete;

};

int main() {
	//6.2.1
	{
		Fraction a;			//默认构造函数
		Fraction b(1, 5);	//直接初始化
		int i;
		Foo f(i);
		
		Employee member("Kevin"); 
	}
	//6.2.2
	{
		Fraction a(1, 5);	//直接初始化
		Fraction b(a);		//直接初始化，b为对象a的拷贝
		Fraction c = Fraction(3, 2); //复制初始化
		Fraction d = 7;		//复制初始化

		//Fraction d2 = static_cast<Fraction>(7); //当我们将 Fraction 类的默认构造函数声明为 explicit 之后

		Fraction e = divide(b, c);

		Employee e1;
		//Employee e2(e1);//错误：不能调用删除的复制构造函数
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
			Point m_center; //圆心
			double m_radius = 1.0;//半径
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