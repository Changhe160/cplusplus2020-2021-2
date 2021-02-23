#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main(){

	{//3.4.2节
		for (int i = 0; i < 5; ++i) {//当i为奇数，输出*#，为偶数时无输出
			if (i % 2) {
				cout << "*";//打印符号*，然后再打印符号#
			}
			else {
				continue;//结束当前迭代，跳转到for语句，执行++i
			}
			cout << "#";
		}
	}

	//猜数字游戏, break, switch, do while
	{
		srand(time(0));
		int target = rand() % 100;
		int guess;
		cout << "请猜0-100之内的数" << endl;
		while (1) {
			cin >> guess;
			int val = (guess > target) - (guess < target);
			switch (val) {
			case -1:
				cout << "猜小了" << endl;
				break;	//跳出switch
			case 1:
				cout << "猜大了" << endl;
				break;  //跳出switch
			case 0:
				cout << "恭喜！ 猜对了！" << endl;
				break;  //跳出switch
			}
			if (val == 0) {
				break; //跳出while
			}
		}
	}
}