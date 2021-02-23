#include<iostream>
#include<vector>
using namespace std;

//5.3.1 值传递
void Swap(int x, int y) {
	int z(x);
	x = y;
	y = z;
}

void Swap(int *x, int *y) {	//指针x和y分别指向实参i 和j
	int z(*x);				//z 保存指针x指向的对象的值（实参i）
	*x = *y;				//解引用不能省略
	*y = z;
}

//5.3.3 const形参
void f_cval(const int i); //i为const对象
void f_cptr(const int *i);//i指向const类型的实参
void f_cref(const int &i);//i为const类型实参的引用
void f_ref(int &i);//引用形参

//5.3.4 数组形参 
void fun(int *p) {}
//void fun(int p[]);	//数组的方式
//void fun(int p[5]);	//“指明”数组的长度
void print(char *str, unsigned size) {
	for (unsigned i = 0; i < size; ++i)
		cout << str[i];
}
void print(char *str) {
	if (str)					//如果str不是一个空指针
		while (*str)			//当前指针指向非空字符
			cout << *str++;		//输出当前指针指向的字符并指向下一个字符
}
void print(char *beg, char * end) {//输出beg和end之间的元素（包含beg但不包含end指向的元素）
	while (beg != end)
		cout << *beg++;				//输出当前指针指向的字符并指向下一个字符
}
void print(const char *str);
void print(const char *str, unsigned size);
void print(const char *beg, const char * end);
void fun(int(*a2d)[5]) {}		//a2d指向一个含有5个元素的一维实参数组

//例5.1 回文函数
bool is_palindrome(int x) {
	vector<int> digit;
	while (x != 0) {
		digit.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0, j = digit.size() - 1; i < j; ++i, --j) {
		if (digit[i] != digit[j])
			return false;
	}
	return true;
}

int main() {
	
	//5.3 参数传递
	{
		int i(4), j(5);
		Swap(i, j);		//调用Swap函数，实参i和j分别初始化Swap函数的形参x和y
		cout << "i=" << i << ",j=" << j << endl;//输出i=4,j=5
	}
	//5.3.1 值传递
	{
		int i(4), j(5);
		Swap(&i, &j);	//将实参i和j的地址传递给Swap函数
		cout << "i=" << i << ",j=" << j << endl;//输出i=5,j=4
	}
	//5.3.3 const形参
	{
		const int cx = 1;
		int x = 1;
		//f_ref(41);	//错误：左值引用不能绑定字面值常量
		//f_ref(cx);	//错误：左值引用不能绑定常量
		//f_ref(x + 1);	//错误：左值引用不能绑定右值表达式
	}
	//5.3.4 数组形参
	{
		int arr[5] = { 1, 2 };
		fun(arr);		//正确：数组名转化为首元素的地址
		fun(&arr[0]);	//正确：显式传递首元素的地址
		{
			char arr[] = "Hello C++";
			print(arr);
		}
		{
			char arr[] = "Hello C++";
			print(begin(arr), end(arr));
		}
		{
			int matrix[4][5] = {};
			fun(matrix); //传递matrix首元素地址，即一个具有5个元素的一维数组
		}
	}

	//例5.1 找出10到1000之内的所有回文数
	for (int i = 10; i <= 1000; ++i) {
		if (is_palindrome(i))
			cout << i << endl;
	}
	
}