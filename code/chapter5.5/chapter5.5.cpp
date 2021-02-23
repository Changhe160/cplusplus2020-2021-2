#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//5.5.1 ��������
const int& getMax(const int &a, const int &b) {
	return a > b ? a : b;
}
const int& getMax(const int &a, const int &b, const int &c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
const string& getMax(const string &a, const string &b) {
	return a > b ? a : b;
}
//5.5.2 Ĭ�ϲ���
void turnoff(int time = 21) {}
//void turnoff(int time = getTime());
void print(int a, int b, int c = 3);			//��ȷ�����ֲ�������Ĭ��ֵ
//void print(int a, int b = 2, int c);			//�������Ҳ����û��Ĭ��ֵ
//void print(int a = 1, int b = 2, int c = 3);	//��ȷ�����в�������Ĭ��ֵ
void print(int a, int b = 2);		//��ȷ������ʱΪ�β�bָ��Ĭ��ֵ
/*void print(int a, int b = 2) {	//�����β�b��Ĭ��ֵ�Ѿ�ָ��
	cout << a << "," << b << endl;
}*/

//5.5.4 constexpr����
const int num = 30;
const int getNumber() { return 10; }
constexpr int f() { return 10; }
constexpr int getNumber(int i) { return i; }

//��5.2 swap����
inline void swap(int & x, int &y) {
	int z(x);
	x = y;
	y = z;
}

int main() {

	enum class stoplight
	{
		red, green, yellow

	};

	stoplight l = stoplight::red;
	switch (l) {
	case stoplight::red:
		cout << "stop!" << endl;
		break;
	case stoplight::green:
		cout << "pass carefully" << endl;
		break;
	case stoplight::yellow:
		cout << "slow down" << endl;
		break;
	default:
		cout << "light broken, call 110" << endl;
		break;
	}

	//5.5.1 ��������
	{
		getMax(7, 8); //���õ�һ�����غ���
		getMax("C++", "Programming"); //���õ��������غ���
	}
	//5.5.2 Ĭ�ϲ���
	{
		turnoff();		//ʡ��ʵ�Σ��β�ʹ��Ĭ��ֵ����21��ر��ֻ�
		turnoff(22);	//����ʵ�Σ��βν���ʵ��ֵ����22��ر��ֻ�
	}
	//5.5.4 constexpr����
	{
		const int numStudent = getNumber();
		//int arr[numStudent];
		int stu1[getNumber(10)];		//��ȷ��getNumber(10)�ǳ������ʽ
		int num = 10;
		//int stu2[getNumber(num)];		//��������ʱ����ȷ��num��ֵ
	}

	//��5.2 ð������
		srand(0);
		vector<int> score(10);
		for (auto &i : score)
			i = rand() % 100;
		for (int i = 0; i < score.size() - 1; ++i) {
			for (int j = score.size() - 1; j > i; --j) {//ÿһ��ð�ݹ��̽���С����������
				if (score[j] < score[j - 1])			//���ڵ��������Ƚϣ���������ð��
					swap(score[j], score[j - 1]);
			}
		}
		for (auto &i : score)
			cout << i << endl;

		return 0;
}
