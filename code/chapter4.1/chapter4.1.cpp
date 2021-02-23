
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){ 

	//4.1
	{
		int counter = 0;
		int &refCnt = counter;	//refCnt引用counter对象的内容
		//int &refCnt2;			//错误：定义引用时必须和一个对象绑定
		refCnt = 2;				//修改了counter 所在的内存空间的内容
		int i = refCnt;			//通过引用读取counter 对象的内容，并初始化对象i
		int &r1 = i, j = 0, &r2 = r1; // r1和r2都是i的引用，而j是int类型

		//只能引用同类型的对象；
		double d = 0;
		//int &r3 = d;				//错误：r3只能引用int类型对象

		//引用的对象必须是非const左值（见2.5.1节，第21页）；
		//int i = 0; const int ci = 0;
		//int &r4 = 100, &r5 = i + 1, &r6 = ci; //错误：只能引用非const左值
	}

	//4.1.1
	{
		const int ci = 0;
		const int &r1 = ci;		//r1引用const 对象ci
		//r1 = 1;				//错误：相当于修改const对象ci 的值
		int i = 0;
		//const int &r1 = i;	//正确：使用左值对象初始化
		const int &r2 = 1;		//正确：使用字面值常量初始化
		const int &r3 = i + 1;	//正确：使用表达式i+1的结果初始化
		const int &r4 = 3.14;	//正确：使用double类型数据初始化
	}

	//4.1.2
	{
		int i = 0, &ri = i;
		auto r = ri;			//r是int类型而不是int 类型引用，auto被推导为int
		//auto &r = i;			//r 是int类型引用
		const int ci = 0;
		auto &cr = ci;			//cr 是const int类型引用，auto被推导为const int
	}
	
	//4.1.3
	{
		int i = 0, &r1 = i;
		decltype (r1) r2 = i;	//r2为int引用
		//decltype (r1 + 0) r2; //r2为int类型
		const int ci = 0;
		auto &cr = ci;			//cr 是const int类型引用，auto被推导为const int
		//decltype ((i)) r2;	//错误：r2为int引用，必须初始化
	}

	//4.1.4
	{
		int i = 0;
		int &&rr1 = i + 1;		//正确：rr1为右值引用，绑定到一个临时对象
		//int &&rr2 = i;		//错误：rr2为右值引用，不能绑定到左值对象
		//int &&rr3 = rr1;		//错误：rr1为左值，rr3不能绑定到左值对象
		int &&rr3 = std::move(rr1); //将rr1转换成右值
	}

	//4.1.4
	{
		int i = 0;
		auto &&rr1 = 10;	//rr1为右值引用
		auto &&rr2 = i;		//rr2为左值引用
	}
}