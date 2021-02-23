#include <iostream>
#include<vector>
#include <algorithm> 
using namespace std;

//5.6.1 ����ָ��
bool compareInt(int, int) { return true; } //�Ƚ�����������С
typedef bool(*ppFun)(int, int);


//��5.3 
using pFun = double(*)(double);
double f_sphere(double x) {
	return x * x;
}
double f_default(double x) {
	return 0;
}
double f_sin(double x) {
	return sin(x);
}
double integrate(double l, double u, pFun pf = f_default, int n = 1000) {
	double sum = 0.0;
	double gap = (u - l) / n;  //ÿ������ĳ���
	for (int i = 0; i < n; i++)
		sum += (gap / 2.0) * (pf(l + i * gap) + pf(l + (i + 1)*gap));

	return sum;
}

int main() {

	//5.6.1 ����ָ��
	{
		bool(*pf)(int, int)=nullptr;
		//bool* pf(int, int);
		ppFun pf1 = compareInt;		//��ʽ��ʼ����pf1ָ��compareInt����
		ppFun pf2 = &compareInt;	//��ʽ��ʼ����pf2ָ��compareInt����
		ppFun pf3 = nullptr;		//pf3��ָ���κκ���
		bool b1 = pf1(1, 2);
		bool b2 = (*pf2)(1, 2);
		{
			void(*a[5])(int);
			void(*(*b)[5])(int)=nullptr;
			void(*c(int, void(*fp)(int)))(int);
			using PF = void(*)(int);

			PF a1[5] = { a[0] };
			PF (*b1)[5] =b ;
			PF c1(int, PF);
		}

		{
			using PF2 = bool(*)(int, int);
			PF2 *a1[5] = { &pf };
			PF2 a2[5] = { pf };
			bool(*a3[5])(int, int) = { pf };
		}

		
	}

	//5.6.2 lambda���ʽ
	{
		{
			auto fun = [](int i) {cout << i << endl; };
			fun(17); //���17
		}
		{
			int divisor = 5;
			vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
			for_each(numbers.begin(), numbers.end(), [divisor](int y) {
				if (y % divisor == 0)	//divisorΪ��Χdivisor�Ŀ���
					cout << y << endl;	//�����divisor������Ԫ��
			});
			int sum = 0;
			for_each(numbers.begin(), numbers.end(), [divisor, &sum](int y) {
				if (y % divisor == 0)	//sumΪ��Χsum ������
					sum += y;			//�ۼӱ�divisor������Ԫ�أ������ŵ���Χ����sum��
			});
		}
	}

	//��5.3 
	cout << "Ĭ�Ϻ���������[0:1]�ϵĻ���Ϊ��" << integrate(0, 1) << endl;
	cout << "Sphere����������[0:1]�ϵĻ���Ϊ��" << integrate(0, 1, f_sphere) << endl;
	cout << "sin����������[0:1]�ϵĻ���Ϊ��" << integrate(0, 1, f_sin) << endl;


}