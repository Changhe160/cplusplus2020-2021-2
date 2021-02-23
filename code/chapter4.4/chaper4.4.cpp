
#include <iostream>  
#include <string>  
using namespace std;

int main() {
	
	//4.4.1
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int *p = arr;					//arr被转换成arr[0]的地址
		{
			int *p = &arr[0];
		}
		cout << arr << "," << &arr[0];	//在我们的系统下，输出:010FF774,010FF774
		auto pa = arr;		//pa 为int *类型，显然是一个指针
		cout << *pa;		//输出arr[0]的值1
		decltype(arr) ar2;	//ar2 为存放5个整型数的一维数组
		int a2d[3][5];
		int(*p2d)[5] = a2d; //指向a2d 的第一个元素
		{
			int(*p2d)[5] = &a2d[0]; //a2d 第一个元素的地址
		}
		{
			int *p2d[5];
		}
		{
			int * const p = &arr[0]; //arr可以理解为const 指针p
			cout << sizeof(arr) << " " << sizeof(p);
		}
	}

	//4.4.2
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int *p = arr;		//p指向数组arr
		int *p2 = p + 3;	//返回p后面第3个元素的地址，即&arr[3]
		int *p3 = p++;		//p后移一个位置，p3 指向p原来的位置&arr[0]
		int *p4 = ++p;		//p 继续后移一个位置，p4 和p指向同一个位置&arr[2]
		p2 = &arr[0];		//正确：指向第一个元素，等价于p2 = arr;
		p2 = &arr[5];		//正确：指向尾元素后面的一个位置，等价于p2 = arr + 5;
		{
			int *p = arr;			//p 指向数组arr
			int val = *(p + 2) + 1; //等价于int val = arr[2] + 1;
			int val2 = p[2];		//等价于int val2 = arr[2];
		}
		{
			int a2d[3][5];
			int(*p2d)[5] = a2d;
			p2d[1][1] = 1;
			*(*(p2d + 1) + 1) = 1; *(*(a2d + 1) + 1) = 1;
			*(p2d[1] + 1) = 1; *(a2d[1] + 1) = 1;
		}
		{
			int a2d[3][5] = { { 1 },{ 1 },{ 1 } };
			for (auto p = a2d; p < a2d + 3; ++p) {	//p的类型为int (*)[5]
				for (auto q = *p; q < *p + 5; ++q) {//q的类型为int *
					cout << *q << " ";
				}
				cout << endl;
			}

			for (auto p = &a2d[0][0]; p < a2d[0] + 15; ++p) {
				if ((p - a2d[0]) % 5 == 0)	//a2d[0]等价于&a2d[0][0]
					cout << endl;			//每打印5个元素后换行
				cout << *p << " ";
			}
		}
	}
}