//��1.3 Բ������

#include<iostream>
using namespace std;		//ʹ�ñ�׼�����ռ�
							//���뾶�͸��Լ�һ��������Ĳ�����װ��һ���γ�һ�������ͣ���������Cylinder
class Cylinder {
	double m_radius, m_height;
public:
	double volume() {		//������һ����뾶�͸߹����Ĳ�����������������������
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


