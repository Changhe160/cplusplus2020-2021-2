#include <iostream>
using namespace std;

int sum = 10;

extern int g_val;
static int gs_val = 20;

//5.2.2 �ֲ�����
int fun() {
	int a = 0; //aΪ�ֲ��Զ�����
	static int b = 0; //bΪ�ֲ���̬����
	return ++b + ++a;
}

int main() {

//5.2.2 �ֲ�����
for (int i = 0; i < 3; ++i) {
	cout << fun() << endl;
}

//5.2.3 ȫ�ֶ���
{
	int sum = 1; //����ֲ�����
	std::cout << sum << std::endl; //���ʾֲ�����sum����ӡ���1
	std::cout << ::sum << std::endl; //����ȫ�ֶ���sum����ӡ���10
	cout << g_val + gs_val;
}
}