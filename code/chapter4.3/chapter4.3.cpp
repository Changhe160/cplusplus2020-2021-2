
#include <cstdlib>
#include <iostream>
#include<ctime>
#include<cmath>
#include<vector>
using namespace std;

int main() {

	//4.3.1
	{
		int arr[10];
		unsigned cnt = 10;
		//int arr[cnt];			//错误，cnt不是常量表达式
		constexpr int sz = 10;	//常量表达式（见2.4.2节，第18页）
		int arri[sz];			//正确：存放10个整型数据的数组
		//float arrf[10.];		//错误：数组长度必须是整型
		{
			int arr[5] = { 1, 2, 3, 4, 5 };
		}
		{
			int arr[5] = { 1, 2, 3 };		//等价于arr[5] = {1, 2, 3, 0, 0}
		}
		{
			int arr[] = { 1, 2, 3, 4, 5 };	//数组arr的长度为5
		}
		{
			char name[] = "Lisha";			//自动添加字符串结束符’\0’
		}
		{
			char name[] = { 'L', 'i', 's', 'h', 'a', '\0' };
			//name = "Lisha";				//错误：数组不允许赋值操作
		}
		{
			int arr[5];				//定义一个含有5个int类型元素的数组
			int *arrp[5];			//定义一个含有5个int*类型元素的数组，每个元素都是指针
			int(*parr)[5] = &arr;	//定义一个指向含有5个int类型元素的数组的指针
			int(&rarr)[5] = arr;	//定义arr的一个引用

			//parrp 和rarrp 分别为指向指针数组arrp的指针和引用
			int *(*parrp)[5] = &arrp;
			int *(&rarrp)[5] = arrp;
		}
	}

	//4.3.2
	{
		int arr[5] = { 1, 2, 3, 4, 5 };
		arr[0] = 10;			//写操作：修改第一个元素的值
		cout << arr[0] << endl; //读操作：读取第一个元素，输出结果为：10
		{
			int arr[5] = { 1,2,3,4,5 }; //定义并初始化一个含有5个整型数的数组
			for (auto i : arr) {		//i为arr 中当前元素的副本
				cout << i << endl;		//打印输出当前获取的整数
			}
			for (auto &i : arr) {		//i 为arr中当前元素的引用
				i = 0;					//写操作：每一个元素设置为0
			}
		}
	}

	//例4.1 计算30名学生数学科目平均成绩和标准差
	{
		int a2d[][2] = { 1,1,4 ,4,4 };
		srand(0);
		constexpr int sz = 30;
		int score[sz];
		int mean = 0;
		for (auto &i : score) {
			i = 50 + rand() % 50;
			mean += i;
		}
		mean /= sz;
		double dev = 0;
		for (int i = 0; i < sz; ++i) {
			dev += pow(score[i] - mean, 2);
		}
		dev = sqrt(dev / sz);
		cout << "平均成绩：" << mean << " 标准差：" << dev << endl;
	}

	//例4.2 八皇后问题
	{
		constexpr int sz = 8;
		int que[sz] = { 0 };	//每一行皇后都从第0列开始摆放
		int i = 0;				//从第0行开始摆放
		while (i >= 0) {
			int k = 0;
			while (k<i) {		//检查前面所有皇后是否和第i行皇后冲突
				if (que[k] != que[i] && (abs(que[i] - que[k]) != abs(i - k)))
					++k;		//第k行和第i行皇后没有冲突
				else
					break;		//第k行和第i行皇后产生冲突，退出，转到第15行
			}
			if (k < i) {		//检测到冲突
				++que[i];		//处理冲突：移动第i行皇后到当前位置的下一列
				while (que[i] == sz) {	//当前行所有尝试都失败，需要回溯
					que[i] = 0;			//重置当前行皇后位置
					--i;				//回溯到上一行
					if (i < 0)
						break;			//如果回溯到第0行之前，结束运行，转到第24行
					++que[i];			//前一行皇后后移一列
				}
				continue;				//从新检测是否与前面已安排皇后冲突，转到第7行
			}
			else {						//没有检测到冲突，安排下一行皇后
				++i;					//移动到下一行
				if (i < sz)
					continue;			//安排下一行皇后，已安排在第0列，转到第7行
				cout << "找到一个方案：";//否则找到一个方案并输出
				for (k = 0; k<sz; ++k)
					cout << que[k];
				cout << endl;
				break;					//结束运行，转到第37行
			}
		}
	}


	//例4.3 制作扫雷小游戏地图
	{
		srand(time(0));//
		constexpr int sz = 8;
		char map[sz][sz];
		for (auto &row : map) {
			for (auto &col : row) {
				int num = rand() % 100;
				if (num <= 50)			//设置一个地雷
					col = '*';
				else
					col = '0';
			}
		}
		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				if (map[i][j] != '*') continue;
				if (i + 1 < sz && map[i + 1][j] != '*') map[i + 1][j] += 1;
				if (i - 1 >= 0 && map[i - 1][j] != '*') map[i - 1][j] += 1;
				if (j + 1 < sz && map[i][j + 1] != '*') map[i][j + 1] += 1;
				if (j - 1 >= 0 && map[i][j - 1] != '*') map[i][j - 1] += 1;
			}
		}

		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}

		for (auto p = &map[0][0]; p < map[0] + sz * sz; ++p) {
			if ((p - &map[0][0]) % sz == 0) cout << endl;
			cout << *p << " ";
		}

	}


}