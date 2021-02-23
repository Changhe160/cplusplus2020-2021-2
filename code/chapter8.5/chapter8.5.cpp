// BinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣

#include"BinaryTree.h"

struct visit
{
	template<typename T>
	void operator()(T &n) {
		cout << n.data() << " ";
	}
};

template<typename T>
void visit_(T &n) {
	cout << n << " ";
}

int main(){
	
	//���������
	//const int N = 16;
	//int keys[] = { 54,18,66,54,87,36,12,54,81,15,76,57,6,40,99,85,99 };
	int keys[] = { 8,3,10,1,6,14,4,7,13 };
	cout << " ���룺";
	BinaryTree<int> bstree;
	for (auto i:keys)
		if (Node<int> *n=bstree.insert(i) )
			cout << n->data() << "  ";
	cout << endl;

	//cout << bstree << endl;
	bstree.inOrder( bstree.root(), visit_<int>);

	visit fun;
	cout << endl;
	cout << "Inorder: ";
	bstree.inOrder(fun, bstree.root());
	cout << endl;
	cout << "Preorder: ";
	bstree.preOrder(fun, bstree.root());

	cout << endl;
	cout << "Postorder: ";
	bstree.postOrder(fun, bstree.root());

	//ɾ��Ԫ��
	while (!bstree.empty())
	{
		int val;
		cin >> val;
		bstree.remove(bstree.search(val));
		cout << bstree << endl;
		bstree.inOrder(fun, bstree.root());
		cout << endl;
	}

	cout << " ��������Ϊ��" << endl;
	
	system("pause");
	
	return 0;


}

