#include"List.h"

int main() {

	//8.3.6
	SList<int> l; //����һ���������Ԫ�ص�����l
	int val;
	while (cin >> val) {	//����10 20 30��������
		l.push_back(val);	//����β�嵽����l��
	}
	cout << l << endl;	//��ӡ���10 20 30
	Node<int> *pos = l.find(20); //����Ԫ��20���ڵĽ��ָ��
	l.insert(pos, 25);	//Ԫ��20�������Ԫ��Ϊ25���½��
	cout << l << endl;	//��ӡ���10 20 25 30
	l.erase(25);		//ɾ��Ԫ��25
	cout << l << endl;	//��ӡ���10 20 30
}