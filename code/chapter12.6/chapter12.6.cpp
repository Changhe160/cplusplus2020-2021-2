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
		ID wang = { 'a' }; // ������һ��ID�����Ϊ���һ����Ա��ֵ
		cout << wang.char_type << endl; //���a
		wang.int_type = 1001; // ����ʹ�õڶ�����Ա
		cout << wang.int_type << endl; //���1001
		wang.llong_type = 20171001001; // ����ʹ�õ�������Ա
		cout << wang.llong_type << endl; //���20171001001
	}

}