#ifndef NODE_H
#define NODE_H

template<typename T> class BinaryTree;

template<typename T>
class Node
{
	friend class BinaryTree<T>;
private:
	T m_data;
	Node *m_left = nullptr, *m_right = nullptr;
public:
	Node(const Node&) = delete;
	Node& operator=(const Node&) = delete;

	Node(const T &data):m_data(data){}
	T& data() { return m_data; }
	Node* left() { return m_left; }
	Node* right() { return m_right; }
};

#endif // NODE_H