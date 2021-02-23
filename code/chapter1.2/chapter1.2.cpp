//例1.3 圆柱体类

#include<iostream>
using namespace std;		//使用标准命名空间
							//将半径和高以及一个求体积的操作封装在一起，形成一个类类型，其名字是Cylinder
class Cylinder {
	double m_radius, m_height;
public:
	double volume() {		//定义了一个与半径和高关联的操作，即求体积并返回体积値
		return 3.14*m_radius*m_radius*m_height;
	}
	Cylinder(double i = 0, double h = 0) :m_radius(i), m_height(h) {}
	Cylinder(const Cylinder& c) {
		cout << "2";
	}
};

int main() {

	Cylinder object(1, 1);
	double vol = object.volume();
	cout << vol << endl;
	return 0;
}


