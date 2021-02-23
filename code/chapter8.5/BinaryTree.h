#ifndef BINARYTREE_H
#define BINARYTREE_H

#include"Node.h"
#include<vector>
#include<iostream>
using namespace std;

template<typename T>
ostream &operator<< (ostream &cout, const BinaryTree<T> &value);

template<typename T>
class BinaryTree{
public:
	BinaryTree() = default;
	BinaryTree(const BinaryTree &value) = delete;
	BinaryTree& operator=(const BinaryTree &value) = delete;
	~BinaryTree() {	destroy(m_root); }
	bool empty() const { return m_root == nullptr; }
	int size() const { return size(m_root); }
	Node<T>* root() const { return m_root; }
	Node<T>* insert(const T &value) { return insert_(m_root, value); }
	Node<T>* search(const T &value)const;
	
	template<typename FUN>
	void preOrder(FUN &fun, Node<T> *p) const;
	template<typename FUN>
	void inOrder(FUN &fun, Node<T> *p);
	void inOrder( Node<T> *p, void(*visit)(T &));

	template<typename FUN>
	void postOrder(FUN &fun, Node<T> *p) const;
	void destroy(Node<T>* p);
	friend ostream &operator<< <T> (ostream &cout, const BinaryTree<T> &value);

	
	void remove(Node<T> *p);
	Node<T>* parent(Node<T> *node) const;


private:
	int size(Node<T> *p) const;
	Node<T>* search_(Node<T> *p, const T &value) const;
	Node<T>* insert_(Node<T>* &p, const T &value);
	
	Node<T>* parent(Node<T> *p, Node<T> *node) const;
	Node<T>* minChild(Node<T> *p) const;

private:
	Node<T> *m_root = nullptr;
};

template<typename T>
inline Node<T>* BinaryTree<T>::search(const T &value)const{
	return search_(m_root, value);
}

template<typename T>
Node<T>* BinaryTree<T>::parent(Node<T>* node) const{
	if (m_root == nullptr || node == nullptr || node == m_root)
		return nullptr;
	return parent(m_root, node);
}

template<typename T>
template<typename FUN>
void BinaryTree<T>::preOrder(FUN &fun, Node<T> *p) const{
	if (p != nullptr)
	{
		fun(*p);
		preOrder(fun, p->m_left);
		preOrder(fun, p->m_right);
	}
}

template<typename T>
template<typename FUN>
void BinaryTree<T>::inOrder(FUN &visit, Node<T> *p) {
	if (p != nullptr)
	{
		inOrder(visit, p->m_left);
		visit(*p);
		inOrder(visit, p->m_right);
	}
}
template<typename T>
void BinaryTree<T>::inOrder( Node<T> *p, void(*visit)(T&)) {
	if (p != nullptr)
	{
		inOrder( p->m_left, visit);
		visit(p->m_data);
		inOrder(p->m_right, visit);
	}
}

template<typename T>
template<typename FUN>
void BinaryTree<T>::postOrder(FUN &fun, Node<T> *p) const {
	if (p != nullptr)
	{
		postOrder(fun, p->m_left);
		postOrder(fun, p->m_right);
		fun(*p);
	}
}

template<typename T>
void BinaryTree<T>::destroy(Node<T>* p){
	if (p != nullptr)
	{
		destroy(p->m_left);
		destroy(p->m_right);
		delete p;
	}
}

template<typename T>
ostream &operator<< (ostream &os, const BinaryTree<T> &value){
	os << " 层次遍历二叉树：";
	vector<Node<T> *> que;
	Node<T> *p = value.m_root;
	while (p != nullptr)
	{
		os << p->data() << " ";
		if (p->left() != nullptr)
			que.push_back(p->left());
		if (p->right() != nullptr)
			que.push_back(p->right());
		if (!que.empty())
		{
			p = que.front();
			que.erase(que.begin());
		}
		else
			p = nullptr;
	}
	return os;
}

template<typename T>
void BinaryTree<T>::remove(Node<T> *p){
	if (p == nullptr)//二分查找返回空，表示无此元素
		cout << " 无此元素" << endl;
	else{
		cout << " 删除元素" << p->m_data << endl;
		if (p->m_left == nullptr && p->m_right == nullptr)//删除叶子节点
		{
			auto p_parent = parent(p);
			if (p_parent != nullptr)//当叶子节点不是最后二叉树的最后一个结点时
			{
				if (p_parent->m_left == p)
					p_parent->m_left = nullptr;
				else
					p_parent->m_right = nullptr;
				delete p;
			}
			else//当叶子节点是最后二叉树的最后一个结点时
			{
				m_root = nullptr;
				delete p;
			}
		}
		else if (p->m_right == nullptr)//当删除节点无右子树时
		{
			auto p_m_left = p->m_left;
			p->m_data = p_m_left->m_data;
			p->m_left = p_m_left->m_left;
			p->m_right = p_m_left->m_right;
			delete p_m_left;
		}
		else//当删除结点有右子树时
		{
			auto p_minchild = minChild(p->m_right);
			auto p_mc_parent = parent(p_minchild);
			p->m_data = p_minchild->m_data;
			if (p == p_mc_parent)
				p->m_right = p_minchild->m_right;
			else
				p_mc_parent->m_left = p_minchild->m_right;
			delete p_minchild;
		}
	}
}

template<typename T>
int BinaryTree<T>::size(Node<T> *p) const{
	if (p == nullptr)
		return 0;
	else
		return 1 + size(p->m_left) + size(p->m_right);
}

template<typename T>
Node<T>* BinaryTree<T>::search_(Node<T> *p, const T &value)const{
	while (p != nullptr && p->m_data != value)
	{
		if (value < p->m_data)
			p = p->m_left;
		else
			p = p->m_right;
	}
	return p;
}

template<typename T>
Node<T>* BinaryTree<T>::insert_(Node<T>* &p, const T &value){
	if (p == nullptr) {
		return p = new (std::nothrow) Node<T>(value);
	}else if (value < p->m_data)
		return insert_(p->m_left, value);
	else
		return insert_(p->m_right, value);
}

template<typename T>
Node<T>* BinaryTree<T>::parent(Node<T> *p, Node<T> *node)const{
	//std::pair<Node<T>*, bool> result(nullptr, false);;
	Node<T>* result = nullptr;
	if (p != nullptr)
	{
		if (p->m_left == node || p->m_right == node)
			return p;
		result = parent(p->m_left, node);
		if (result == nullptr)
			result = parent(p->m_right, node);
	}
	return result;
}

template<typename T>
Node<T>* BinaryTree<T>::minChild(Node<T> *p) const{
	if (p != nullptr)
	{
		if (p->m_left != nullptr)
			return minChild(p->m_left);
		return p;
	}
	return nullptr;
}

#endif // BINARYTREE_H