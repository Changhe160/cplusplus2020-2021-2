#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main(){

	{//3.4.2��
		for (int i = 0; i < 5; ++i) {//��iΪ���������*#��Ϊż��ʱ�����
			if (i % 2) {
				cout << "*";//��ӡ����*��Ȼ���ٴ�ӡ����#
			}
			else {
				continue;//������ǰ��������ת��for��䣬ִ��++i
			}
			cout << "#";
		}
	}

	//��������Ϸ, break, switch, do while
	{
		srand(time(0));
		int target = rand() % 100;
		int guess;
		cout << "���0-100֮�ڵ���" << endl;
		while (1) {
			cin >> guess;
			int val = (guess > target) - (guess < target);
			switch (val) {
			case -1:
				cout << "��С��" << endl;
				break;	//����switch
			case 1:
				cout << "�´���" << endl;
				break;  //����switch
			case 0:
				cout << "��ϲ�� �¶��ˣ�" << endl;
				break;  //����switch
			}
			if (val == 0) {
				break; //����while
			}
		}
	}
}