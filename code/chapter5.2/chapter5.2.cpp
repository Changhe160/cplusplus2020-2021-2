#include <iostream>
using namespace std;

int sum = 10;

extern int g_val;
static int gs_val = 20;

//5.2.2 局部对象
int fun() {
	int a = 0; //a为局部自动对象
	static int b = 0; //b为局部静态对象
	return ++b + ++a;
}

int main() {

//5.2.2 局部对象
for (int i = 0; i < 3; ++i) {
	cout << fun() << endl;
}

//5.2.3 全局对象
{
	int sum = 1; //定义局部对象
	std::cout << sum << std::endl; //访问局部对象sum，打印输出1
	std::cout << ::sum << std::endl; //访问全局对象sum，打印输出10
	cout << g_val + gs_val;
}
}