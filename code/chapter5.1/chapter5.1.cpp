#include <iostream>
using namespace std;

//5.1.1 �����ֵ����
int maximum(int a, int b) { //a��bΪ����int �����β�
	int c;					//����������
	c = a > b ? a : b;
	return c;
}

//5.1.1 ����
int fun() {
	int a = 0;				//aΪ�ֲ��Զ�����
	static int b = 0;		//bΪ�ֲ���̬����
	return ++b + ++a;
}

int main() {
	

	//5.1.2 ���ú���
	{
		int x, y, z;
		cin >> x >> y;
		z = maximum(x, y); //���ú���maximum��x��yΪʵ��
		cout << "The maximum value is " << z << endl;
	}

	//5.1.3 ���ù��� 
	{
		//maximum(1); //����ʵ����Ŀ����
		//maximum("c++", "max"); //�������Ͳ�ƥ��
		//maxi(1, 2); //���󣺺������ͱ�����������һ��
		//maximum(1, 2, 3); //����ʵ�θ���̫��
		maximum(2.3, 4 + 1); //��ȷ����һ��ʵ�ν���ת��Ϊint����
	}

	

	
}