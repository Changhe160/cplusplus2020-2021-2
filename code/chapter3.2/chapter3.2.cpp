
#include<iostream>
#include<cmath>
using namespace std;

int main() {

	{//3.2.1��
		if (int i = 10) {
			/*...*/
		}
	}

	{//3.2.1��
		int n;
		cout << "������һ�������� " << endl;
		cin >> n;
		if (n % 2 == 0) //n��2����
			if (n % 3 == 0) //n��3����
				cout << "n��6�ı���";
			else //n��2���������ܱ�3����
				cout << "n��2�ı�������3�ı���";
	}

	{//3.2.1��
		int n;
		cout << "������һ�������� " << endl;
		cin >> n;
		if (n % 2 == 0) {
			if (n % 3 == 0)
				cout << "n��6�ı���";
		}
		else //n���ܱ�2����
			cout << "n����2�ı���";
	}

	{//3.2.1��
		int n;
		cout << "������һ�������� " << endl;
		cin >> n;
		if (n % 2 == 0) {
			if (n % 3 == 0) {
				cout << "n��6�ı���";
			}
		}
		else {
			cout << "n����2�ı���";
		}
	}

	//��3.1 �ж�һ�������Ƿ����0����3�ı���
	{
		int n;
		cout << "����������n:";
		cin >> n;
		if (n > 0 && n % 3 == 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	//��3.2 ���ٷ��Ƶ�ѧ���ɼ�ת�����弶��
	{
		int score;
		cout << "������һ������:";
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

	//��3.3 ���һԪ���η��̵ĸ�
	{
		double a, b, c;
		cout << "������a(a!=0),b,c:";
		cin >> a >> b >> c;
		if (a != 0) { //����
			double delta = b * b - 4 * a*c;
			if (delta > 0) {
				double x1, x2;
				delta = sqrt(delta);
				x1 = (-b + delta) / (2 * a);
				x2 = (-b - delta) / (2 * a);
				cout << "����������ʵ��,�ֱ�Ϊ��" << x1 << ", " << x2 << endl;
			}
			else if (delta < 0) {
				cout << "������ʵ��" << endl;
			}
			else {
				cout << "������������ͬ��ʵ����" << -b / (2 * a) << endl;
			}
		}
		else {
			cout << "a����Ϊ0" << endl;
		}

	}
}