
#include <iostream>
using namespace std;

//5.4.1 ��ֵ����
	void Swap(int &x, int &y) {
		if (x == y)
			return;		//��ʽ������������
		int z(x);
		x = y;
		y = z;
		//��ʽ������������������return���
	}

//5.4.2 ��ֵ����
int maximum(int a, int b) {
	return a > b ? a : b;
}

int & setMaximum(int &a, int &b) {
	return a > b ? a : b; //���ض���a �����b ������
}

int main() {
	
	//5.4.2 ��ֵ����
	{
		{
			int a = 10, b = 5;
			int c = maximum(a, b);
		}
		{
			//int x, y;
			//cin >> x >> y;
			//int z = maximum(x, y);
			//const int &ref = maximum(x, y);
		}
		{
			int x = 0, y = 1;
			setMaximum(x, y) = 10;
		}
		{
			//int x, y;
			//cin >> x >> y;
			//*setMaximum(x, y) = 10;
		}
	}
}