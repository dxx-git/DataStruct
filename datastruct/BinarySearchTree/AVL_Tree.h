#pragma once

template <class K,class V>
struct AVLTreeNode
{
	K _key;//节点的关键码
	V _value;//节点的数据值

	int _bf;//节点的平衡因子

	AVLTreeNode<K,V> _left;
	AVLTreeNode<K,V> _right;
	AVLTreeNode<K,V> _parent;

	AVLTreeNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		,_bf(0)
		_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};

template <class K,class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K,V> Node;
	AVLTree()
		:_root(NULL)
	{}
	~AVLTree()
	{
		if (_root)
		{
			Destroy(_root);
			_root = NULL;
		}
	}
	bool Insert(const K& key,const V& value)
	{
		if (NULL == _root)
		{
			_root = new Node(key,value);
			//调整平衡因子
		}
		
		Node* cur = _root;
		Node* parent = cur;
		while(cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key,value);
		if (parent->_key < key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		return true;
	}
	bool Remove(const K& key)
	{

	}
	Node* Find(const K& key)
	{
		if (NULL == _root)
		{
			return false;
		}
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return false;
	}
	void Destroy(Node* root)
	{
		if (root)
		{
			delete root;
			root = NULL;
		}
	}
	void RotateL(Node* parent)//左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		if (NULL == ppNode)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = =subR;
			}
			subR->_parent = ppNode;
		}
		
		//更新平衡因子
		subR->_bf = parent->_bf = 0;
	}
	void RotateR(Node* parent)//右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (NULL == ppNode)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
		//更新平衡因子
		parent->_bf = subL->_bf = 0;
	}

protected:
	Node* _root;
};