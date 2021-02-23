#include <iostream>
#include<vector>
#include <algorithm> 
using namespace std;

//5.6.1 函数指针
bool compareInt(int, int) { return true; } //比较两个整数大小
typedef bool(*ppFun)(int, int);


//例5.3 
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
	double gap = (u - l) / n;  //每个间隔的长度
	for (int i = 0; i < n; i++)
		sum += (gap / 2.0) * (pf(l + i * gap) + pf(l + (i + 1)*gap));

	return sum;
}

int main() {

	//5.6.1 函数指针
	{
		bool(*pf)(int, int)=nullptr;
		//bool* pf(int, int);
		ppFun pf1 = compareInt;		//隐式初始化，pf1指向compareInt函数
		ppFun pf2 = &compareInt;	//显式初始化，pf2指向compareInt函数
		ppFun pf3 = nullptr;		//pf3不指向任何函数
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

	//5.6.2 lambda表达式
	{
		{
			auto fun = [](int i) {cout << i << endl; };
			fun(17); //输出17
		}
		{
			int divisor = 5;
			vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
			for_each(numbers.begin(), numbers.end(), [divisor](int y) {
				if (y % divisor == 0)	//divisor为外围divisor的拷贝
					cout << y << endl;	//输出被divisor整除的元素
			});
			int sum = 0;
			for_each(numbers.begin(), numbers.end(), [divisor, &sum](int y) {
				if (y % divisor == 0)	//sum为外围sum 的引用
					sum += y;			//累加被divisor整除的元素，结果存放到外围对象sum中
			});
		}
	}

	//例5.3 
	cout << "默认函数在区间[0:1]上的积分为：" << integrate(0, 1) << endl;
	cout << "Sphere函数在区间[0:1]上的积分为：" << integrate(0, 1, f_sphere) << endl;
	cout << "sin函数在区间[0:1]上的积分为：" << integrate(0, 1, f_sin) << endl;


}