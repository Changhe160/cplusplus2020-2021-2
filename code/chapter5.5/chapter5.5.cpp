#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//5.5.1 函数重载
const int& getMax(const int &a, const int &b) {
	return a > b ? a : b;
}
const int& getMax(const int &a, const int &b, const int &c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
const string& getMax(const string &a, const string &b) {
	return a > b ? a : b;
}
//5.5.2 默认参数
void turnoff(int time = 21) {}
//void turnoff(int time = getTime());
void print(int a, int b, int c = 3);			//正确：部分参数具有默认值
//void print(int a, int b = 2, int c);			//错误：最右侧参数没有默认值
//void print(int a = 1, int b = 2, int c = 3);	//正确：所有参数具有默认值
void print(int a, int b = 2);		//正确：声明时为形参b指定默认值
/*void print(int a, int b = 2) {	//错误：形参b的默认值已经指定
	cout << a << "," << b << endl;
}*/

//5.5.4 constexpr函数
const int num = 30;
const int getNumber() { return 10; }
constexpr int f() { return 10; }
constexpr int getNumber(int i) { return i; }

//例5.2 swap函数
inline void swap(int & x, int &y) {
	int z(x);
	x = y;
	y = z;
}

int main() {

	enum class stoplight
	{
		red, green, yellow

	};

	stoplight l = stoplight::red;
	switch (l) {
	case stoplight::red:
		cout << "stop!" << endl;
		break;
	case stoplight::green:
		cout << "pass carefully" << endl;
		break;
	case stoplight::yellow:
		cout << "slow down" << endl;
		break;
	default:
		cout << "light broken, call 110" << endl;
		break;
	}

	//5.5.1 函数重载
	{
		getMax(7, 8); //调用第一个重载函数
		getMax("C++", "Programming"); //调用第三个重载函数
	}
	//5.5.2 默认参数
	{
		turnoff();		//省略实参，形参使用默认值，即21点关闭手机
		turnoff(22);	//包含实参，形参接受实参值，即22点关闭手机
	}
	//5.5.4 constexpr函数
	{
		const int numStudent = getNumber();
		//int arr[numStudent];
		int stu1[getNumber(10)];		//正确：getNumber(10)是常量表达式
		int num = 10;
		//int stu2[getNumber(num)];		//错误：运行时才能确定num的值
	}

	//例5.2 冒泡排序法
		srand(0);
		vector<int> score(10);
		for (auto &i : score)
			i = rand() % 100;
		for (int i = 0; i < score.size() - 1; ++i) {
			for (int j = score.size() - 1; j > i; --j) {//每一轮冒泡过程将最小的数浮出来
				if (score[j] < score[j - 1])			//相邻的两个数比较，从下向上冒泡
					swap(score[j], score[j - 1]);
			}
		}
		for (auto &i : score)
			cout << i << endl;

		return 0;
}
