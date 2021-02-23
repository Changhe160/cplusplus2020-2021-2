#include <cstdlib>
#include <iostream>
#include <ctime>
#include<cmath>

using namespace std;

int main() {

	//例3.7 画出sin(x)在[0:2pi]内的曲线
	{
		double step = 0.2;//x增加的步长
		double x = 0;//x从0开始
		while (x < 6.28) {//画一个周期的曲线
			int val = 30 * (sin(x) + 1);//计算sin(x)左侧的空格数
			for (int i = 0; i < val; ++i) {//画出所有空格
				cout << " ";
			}
			cout << "*" << endl;//在相应的位置打印*
			x += step;//处理下一个x
		}
	}

	//例3.8 石头剪刀布游戏
	{
		srand(time(0));
		while (1) {
			int computer, you;
			do {
				computer = rand() % 3;
				do {
					cout << "请出手, 0(石头), 1(剪刀), 2(布)：";
					cin >> you;
				} while (you < 0 || you>2);//如果输入有误，从新输入
				switch (you - computer) {
				case 0:
					cout << "平手" << endl;
					break;
				case 1: case -2:					
					cout << "你输了!" << endl;					
					break;
				case -1: case 2:					
					cout << "你赢了!" << endl;
				}
			} while (computer == you);//双方出法相同，继续出
			cout << "还要玩吗？Y/N:";
			char play;
			cin >> play;
			if (play == 'N' || play == 'n') break;
		}
		return 0;
	}

	//例3.9 百钱买百鸡问题
	{
		int max_rst = 10, max_hen;
		max_rst = 100 / 5;
		max_hen = 100 / 3;
		for (int i = 0; i < max_rst; ++i) {
			for (int j = 0; j < max_hen; ++j) {
				int k = 100 - i - j;
				if (k % 3) continue;
				if (5 * i + 3 * j + k / 3 == 100) {
					cout << "公鸡：" << i << " 母鸡：" << j << " 小鸡：" << k << endl;
				}
			}
		}
	}

}