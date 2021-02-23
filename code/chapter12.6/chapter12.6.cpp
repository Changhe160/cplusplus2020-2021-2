#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<iostream>
#include<array>
#include<deque>
#include<forward_list>
#include<list>
#include<set>
#include<algorithm>
#include<map>
#include<memory>
#include<chrono>
#include<numeric>
#include<functional>
#include<bitset>
#include<chrono>
#include<iomanip>
#include <ctime> 
using namespace std;



int main() {
	{
		union ID {
			char char_type;
			int int_type;
			long long llong_type;
		};
		ID li;
		if (sizeof(li) == sizeof(long long)) {
			cout << "ok" << endl;
		}
		ID wang = { 'a' }; // 构造了一个ID类对象，为其第一个成员赋值
		cout << wang.char_type << endl; //输出a
		wang.int_type = 1001; // 激活使用第二个成员
		cout << wang.int_type << endl; //输出1001
		wang.llong_type = 20171001001; // 激活使用第三个成员
		cout << wang.llong_type << endl; //输出20171001001
	}

}