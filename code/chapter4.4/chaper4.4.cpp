
#include <iostream>  
#include <string>  
using namespace std;

int main() {
	
	//4.4.1
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int *p = arr;					//arr��ת����arr[0]�ĵ�ַ
		{
			int *p = &arr[0];
		}
		cout << arr << "," << &arr[0];	//�����ǵ�ϵͳ�£����:010FF774,010FF774
		auto pa = arr;		//pa Ϊint *���ͣ���Ȼ��һ��ָ��
		cout << *pa;		//���arr[0]��ֵ1
		decltype(arr) ar2;	//ar2 Ϊ���5����������һά����
		int a2d[3][5];
		int(*p2d)[5] = a2d; //ָ��a2d �ĵ�һ��Ԫ��
		{
			int(*p2d)[5] = &a2d[0]; //a2d ��һ��Ԫ�صĵ�ַ
		}
		{
			int *p2d[5];
		}
		{
			int * const p = &arr[0]; //arr�������Ϊconst ָ��p
			cout << sizeof(arr) << " " << sizeof(p);
		}
	}

	//4.4.2
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int *p = arr;		//pָ������arr
		int *p2 = p + 3;	//����p�����3��Ԫ�صĵ�ַ����&arr[3]
		int *p3 = p++;		//p����һ��λ�ã�p3 ָ��pԭ����λ��&arr[0]
		int *p4 = ++p;		//p ��������һ��λ�ã�p4 ��pָ��ͬһ��λ��&arr[2]
		p2 = &arr[0];		//��ȷ��ָ���һ��Ԫ�أ��ȼ���p2 = arr;
		p2 = &arr[5];		//��ȷ��ָ��βԪ�غ����һ��λ�ã��ȼ���p2 = arr + 5;
		{
			int *p = arr;			//p ָ������arr
			int val = *(p + 2) + 1; //�ȼ���int val = arr[2] + 1;
			int val2 = p[2];		//�ȼ���int val2 = arr[2];
		}
		{
			int a2d[3][5];
			int(*p2d)[5] = a2d;
			p2d[1][1] = 1;
			*(*(p2d + 1) + 1) = 1; *(*(a2d + 1) + 1) = 1;
			*(p2d[1] + 1) = 1; *(a2d[1] + 1) = 1;
		}
		{
			int a2d[3][5] = { { 1 },{ 1 },{ 1 } };
			for (auto p = a2d; p < a2d + 3; ++p) {	//p������Ϊint (*)[5]
				for (auto q = *p; q < *p + 5; ++q) {//q������Ϊint *
					cout << *q << " ";
				}
				cout << endl;
			}

			for (auto p = &a2d[0][0]; p < a2d[0] + 15; ++p) {
				if ((p - a2d[0]) % 5 == 0)	//a2d[0]�ȼ���&a2d[0][0]
					cout << endl;			//ÿ��ӡ5��Ԫ�غ���
				cout << *p << " ";
			}
		}
	}
}