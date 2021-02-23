
#include <iostream>
using namespace std;

//5.4.1 无值返回
	void Swap(int &x, int &y) {
		if (x == y)
			return;		//显式返回主调函数
		int z(x);
		x = y;
		y = z;
		//隐式返回主调函数，无需return语句
	}

//5.4.2 有值返回
int maximum(int a, int b) {
	return a > b ? a : b;
}

int & setMaximum(int &a, int &b) {
	return a > b ? a : b; //返回对象a 或对象b 的引用
}

int main() {
	
	//5.4.2 有值返回
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