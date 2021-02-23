#include"List.h"

int main() {

	//8.3.6
	SList<int> l; //定义一个存放整型元素的链表l
	int val;
	while (cin >> val) {	//输入10 20 30三个数据
		l.push_back(val);	//依次尾插到链表l中
	}
	cout << l << endl;	//打印输出10 20 30
	Node<int> *pos = l.find(20); //查找元素20所在的结点指针
	l.insert(pos, 25);	//元素20后面插入元素为25的新结点
	cout << l << endl;	//打印输出10 20 25 30
	l.erase(25);		//删除元素25
	cout << l << endl;	//打印输出10 20 30
}