#include<iostream>
using namespace std;

int main(){

	{//3.1.1��
		int counter = 0;
		//counter + 1; //һ��û��ʵ������ı��ʽ���
		counter += 1; //һ�����õĸ��ϸ�ֵ���
		; //�����
		counter += 1;; //�ڶ����ֺŲ���Ӱ�������ִ��
	}

	{//3.1.1��
		int counter = 0;
		//while (counter < 10); //һ������ķֺŵ��³�����ѭ��
		++counter;
	}

	//3.1.2��
	{ //���鿪ʼ
		int sum = 0; // ����һ������
					/*...*/
	} //�������

	{//3.1.3��
		int counter = 0, sum = 0;
		while (counter < 10) { //while����������￪ʼ
			++counter;
			sum += counter;
		} //while�������������
	}

}