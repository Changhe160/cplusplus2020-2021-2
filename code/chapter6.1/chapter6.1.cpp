#include "Fraction.h"

//6.1.5 友元类
class Circle;
class Point {
	friend class Circle;
private:
	double m_x = 0, m_y = 0;
};

class Circle {
	Point m_center;
	double m_radius = 1.0;
public:
	void moveXTo(double val) {
		m_center.m_x = val;
	}
};

int main(){
	//6.1.2
	{
		Fraction a;					//定义一个对象 a，a 的数据成员使用默认值
		cout << a.value() << endl;	//通过对象 a 调用成员函数 value
	}
	//6.1.3
	{
		Fraction a;					//定义一个对象 a，a 的数据成员使用默认值
		print(cout, a);
	}

	//6.1.5
	{
		Fraction a,b;
		makeCommon(a, b);

		Circle c;
		c.moveXTo(1);
	}

	return 0;
}