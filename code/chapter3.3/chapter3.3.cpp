
#include<iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	{//3.3.3��
		int sum = 0;
		for (int i = 1; i <= 100; ++i) {
			sum += i; //1��i���ۼӺͷŵ�sum��
		}
	}

	{//3.3.3��
		int sum = 0;
		for (int i = 1, j = 100; i < j; ++i, --j) {
			sum += i + j;
		}
	}

	//��3.4 ��������pi�Ľ���ֵ
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


	//��3.5 ����һ���ı�ͳ�������ַ��ĸ���
	{
		int cnt = 0;
		char digit;
		do {
			digit = cin.get();
			if (digit >= '0'&&digit <= '9') ++cnt;
		} while (digit != EOF);

		cout << "�����ַ�����Ϊ�� " << cnt << endl;
	}

	//��3.6 ��������Ϸ
	{
		srand(time(0)); // use current time as seed for random generator
		int target = rand() % 100;
		int guess;
		cout << "���0-100֮�ڵ���" << endl;
		do {
			cin >> guess;
			if (guess < target) {
				cout << "��С��" << endl;
			}
			else if (guess > target) {
				cout << "�´���" << endl;
			}
			else {
				cout << "��ϲ�� �¶��ˣ�" << endl;
			}
		} while (guess != target);
	}

}