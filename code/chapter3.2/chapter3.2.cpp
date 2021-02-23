
#include<iostream>
#include<cmath>
using namespace std;

int main() {

	{//3.2.1节
		if (int i = 10) {
			/*...*/
		}
	}

	{//3.2.1节
		int n;
		cout << "请输入一个整数： " << endl;
		cin >> n;
		if (n % 2 == 0) //n被2整除
			if (n % 3 == 0) //n被3整除
				cout << "n是6的倍数";
			else //n被2整除但不能被3整除
				cout << "n是2的倍数不是3的倍数";
	}

	{//3.2.1节
		int n;
		cout << "请输入一个整数： " << endl;
		cin >> n;
		if (n % 2 == 0) {
			if (n % 3 == 0)
				cout << "n是6的倍数";
		}
		else //n不能被2整除
			cout << "n不是2的倍数";
	}

	{//3.2.1节
		int n;
		cout << "请输入一个整数： " << endl;
		cin >> n;
		if (n % 2 == 0) {
			if (n % 3 == 0) {
				cout << "n是6的倍数";
			}
		}
		else {
			cout << "n不是2的倍数";
		}
	}

	//例3.1 判断一个整数是否大于0且是3的倍数
	{
		int n;
		cout << "请输入整数n:";
		cin >> n;
		if (n > 0 && n % 3 == 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	//例3.2 将百分制的学生成绩转换成五级制
	{
		int score;
		cout << "请输入一个分数:";
		cin >> score;

		switch (score / 10) {
		case 9:case 10:
			cout << "A" << endl;
			break;
		case 8:
			cout << "B" << endl;
			break;
		case 7:
			cout << "C" << endl;
			break;
		case 6:
			cout << "D" << endl;
			break;
		default:
			cout << "F" << endl;
			break;
		}
	}

	//例3.3 求解一元二次方程的根
	{
		double a, b, c;
		cout << "请输入a(a!=0),b,c:";
		cin >> a >> b >> c;
		if (a != 0) { //方程
			double delta = b * b - 4 * a*c;
			if (delta > 0) {
				double x1, x2;
				delta = sqrt(delta);
				x1 = (-b + delta) / (2 * a);
				x2 = (-b - delta) / (2 * a);
				cout << "方程有两个实根,分别为：" << x1 << ", " << x2 << endl;
			}
			else if (delta < 0) {
				cout << "方程无实根" << endl;
			}
			else {
				cout << "方程有两个相同的实根：" << -b / (2 * a) << endl;
			}
		}
		else {
			cout << "a不能为0" << endl;
		}

	}
}