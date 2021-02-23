#include <iostream>
using namespace std;

//5.1.1 求最大值函数
int maximum(int a, int b) { //a和b为两个int 类型形参
	int c;					//用来保存结果
	c = a > b ? a : b;
	return c;
}

//5.1.1 函数
int fun() {
	int a = 0;				//a为局部自动对象
	static int b = 0;		//b为局部静态对象
	return ++b + ++a;
}

int main() {
	

	//5.1.2 调用函数
	{
		int x, y, z;
		cin >> x >> y;
		z = maximum(x, y); //调用函数maximum，x和y为实参
		cout << "The maximum value is " << z << endl;
	}

	//5.1.3 调用规则 
	{
		//maximum(1); //错误：实参数目不足
		//maximum("c++", "max"); //错误：类型不匹配
		//maxi(1, 2); //错误：函数名和被调函数名不一致
		//maximum(1, 2, 3); //错误：实参个数太多
		maximum(2.3, 4 + 1); //正确：第一个实参将被转换为int类型
	}

	

	
}