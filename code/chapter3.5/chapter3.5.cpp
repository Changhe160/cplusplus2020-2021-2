#include <cstdlib>
#include <iostream>
#include <ctime>
#include<cmath>

using namespace std;

int main() {

	//��3.7 ����sin(x)��[0:2pi]�ڵ�����
	{
		double step = 0.2;//x���ӵĲ���
		double x = 0;//x��0��ʼ
		while (x < 6.28) {//��һ�����ڵ�����
			int val = 30 * (sin(x) + 1);//����sin(x)���Ŀո���
			for (int i = 0; i < val; ++i) {//�������пո�
				cout << " ";
			}
			cout << "*" << endl;//����Ӧ��λ�ô�ӡ*
			x += step;//������һ��x
		}
	}

	//��3.8 ʯͷ��������Ϸ
	{
		srand(time(0));
		while (1) {
			int computer, you;
			do {
				computer = rand() % 3;
				do {
					cout << "�����, 0(ʯͷ), 1(����), 2(��)��";
					cin >> you;
				} while (you < 0 || you>2);//����������󣬴�������
				switch (you - computer) {
				case 0:
					cout << "ƽ��" << endl;
					break;
				case 1: case -2:					
					cout << "������!" << endl;					
					break;
				case -1: case 2:					
					cout << "��Ӯ��!" << endl;
				}
			} while (computer == you);//˫��������ͬ��������
			cout << "��Ҫ����Y/N:";
			char play;
			cin >> play;
			if (play == 'N' || play == 'n') break;
		}
		return 0;
	}

	//��3.9 ��Ǯ��ټ�����
	{
		int max_rst = 10, max_hen;
		max_rst = 100 / 5;
		max_hen = 100 / 3;
		for (int i = 0; i < max_rst; ++i) {
			for (int j = 0; j < max_hen; ++j) {
				int k = 100 - i - j;
				if (k % 3) continue;
				if (5 * i + 3 * j + k / 3 == 100) {
					cout << "������" << i << " ĸ����" << j << " С����" << k << endl;
				}
			}
		}
	}

}