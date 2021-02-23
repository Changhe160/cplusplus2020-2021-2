
#include<iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	{//3.3.3节
		int sum = 0;
		for (int i = 1; i <= 100; ++i) {
			sum += i; //1到i的累加和放到sum中
		}
	}

	{//3.3.3节
		int sum = 0;
		for (int i = 1, j = 100; i < j; ++i, --j) {
			sum += i + j;
		}
	}

	//例3.4 迭代法求pi的近似值
	{
		double sum = 0, x = 1;
		int i = 1;
		while (x > 1.0E-10) {
			sum += x;
			++i;
			x *= (i - 1.) / (2 * i - 1);
		}
		cout << "pi=" << fixed << setprecision(10) << 2 * sum << endl;
	}


	//例3.5 输入一段文本统计数字字符的个数
	{
		int cnt = 0;
		char digit;
		do {
			digit = cin.get();
			if (digit >= '0'&&digit <= '9') ++cnt;
		} while (digit != EOF);

		cout << "数字字符个数为： " << cnt << endl;
	}

	//例3.6 猜数字游戏
	{
		srand(time(0)); // use current time as seed for random generator
		int target = rand() % 100;
		int guess;
		cout << "请猜0-100之内的数" << endl;
		do {
			cin >> guess;
			if (guess < target) {
				cout << "猜小了" << endl;
			}
			else if (guess > target) {
				cout << "猜大了" << endl;
			}
			else {
				cout << "恭喜！ 猜对了！" << endl;
			}
		} while (guess != target);
	}

}