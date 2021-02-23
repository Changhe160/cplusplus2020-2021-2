#include<iostream>
#include<vector>
using namespace std;

//5.3.1 ֵ����
void Swap(int x, int y) {
	int z(x);
	x = y;
	y = z;
}

void Swap(int *x, int *y) {	//ָ��x��y�ֱ�ָ��ʵ��i ��j
	int z(*x);				//z ����ָ��xָ��Ķ����ֵ��ʵ��i��
	*x = *y;				//�����ò���ʡ��
	*y = z;
}

//5.3.3 const�β�
void f_cval(const int i); //iΪconst����
void f_cptr(const int *i);//iָ��const���͵�ʵ��
void f_cref(const int &i);//iΪconst����ʵ�ε�����
void f_ref(int &i);//�����β�

//5.3.4 �����β� 
void fun(int *p) {}
//void fun(int p[]);	//����ķ�ʽ
//void fun(int p[5]);	//��ָ��������ĳ���
void print(char *str, unsigned size) {
	for (unsigned i = 0; i < size; ++i)
		cout << str[i];
}
void print(char *str) {
	if (str)					//���str����һ����ָ��
		while (*str)			//��ǰָ��ָ��ǿ��ַ�
			cout << *str++;		//�����ǰָ��ָ����ַ���ָ����һ���ַ�
}
void print(char *beg, char * end) {//���beg��end֮���Ԫ�أ�����beg��������endָ���Ԫ�أ�
	while (beg != end)
		cout << *beg++;				//�����ǰָ��ָ����ַ���ָ����һ���ַ�
}
void print(const char *str);
void print(const char *str, unsigned size);
void print(const char *beg, const char * end);
void fun(int(*a2d)[5]) {}		//a2dָ��һ������5��Ԫ�ص�һάʵ������

//��5.1 ���ĺ���
bool is_palindrome(int x) {
	vector<int> digit;
	while (x != 0) {
		digit.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0, j = digit.size() - 1; i < j; ++i, --j) {
		if (digit[i] != digit[j])
			return false;
	}
	return true;
}

int main() {
	
	//5.3 ��������
	{
		int i(4), j(5);
		Swap(i, j);		//����Swap������ʵ��i��j�ֱ��ʼ��Swap�������β�x��y
		cout << "i=" << i << ",j=" << j << endl;//���i=4,j=5
	}
	//5.3.1 ֵ����
	{
		int i(4), j(5);
		Swap(&i, &j);	//��ʵ��i��j�ĵ�ַ���ݸ�Swap����
		cout << "i=" << i << ",j=" << j << endl;//���i=5,j=4
	}
	//5.3.3 const�β�
	{
		const int cx = 1;
		int x = 1;
		//f_ref(41);	//������ֵ���ò��ܰ�����ֵ����
		//f_ref(cx);	//������ֵ���ò��ܰ󶨳���
		//f_ref(x + 1);	//������ֵ���ò��ܰ���ֵ���ʽ
	}
	//5.3.4 �����β�
	{
		int arr[5] = { 1, 2 };
		fun(arr);		//��ȷ��������ת��Ϊ��Ԫ�صĵ�ַ
		fun(&arr[0]);	//��ȷ����ʽ������Ԫ�صĵ�ַ
		{
			char arr[] = "Hello C++";
			print(arr);
		}
		{
			char arr[] = "Hello C++";
			print(begin(arr), end(arr));
		}
		{
			int matrix[4][5] = {};
			fun(matrix); //����matrix��Ԫ�ص�ַ����һ������5��Ԫ�ص�һά����
		}
	}

	//��5.1 �ҳ�10��1000֮�ڵ����л�����
	for (int i = 10; i <= 1000; ++i) {
		if (is_palindrome(i))
			cout << i << endl;
	}
	
}