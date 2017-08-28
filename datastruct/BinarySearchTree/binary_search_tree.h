#pragma once

template <typename K,typename V>
struct BinarySearchNode
{
	K _key;
	V _value;
	BinarySearchNode<K,V>* _left;
	BinarySearchNode<K,V>* _right;
	BinarySearchNode<K,V>* _parent;
	BinarySearchNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};

template <typename K,typename V>
class BinarySearchTree
{
public:
	typedef BinarySearchNode<K,V> Node;
	BinarySearchTree()
		:_root(NULL)
	{}
	~BinarySearchTree()
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
			return true;
		}
		
		Node* parent = NULL;
		Node* cur = _root;
		
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
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
		if (parent->_key > key)
		{
			parent->_left = cur;
		}
		else
		{
	        parent->_right = cur;
		}
		cur->_parent = parent;
		return true;
	}
	bool Remove(const K& key)
	{
		if (NULL == _root)
		{
			return false;
		}

		Node* parent = NULL;
		Node* cur = _root;
		Node* del = NULL;

		while(cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				del = cur;
				
				//右子树为空
				if (cur->_right == NULL)
				{
					if (NULL == cur->_parent)//删除的是根节点
					{
						_root = cur->_left;
					}
					else 
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}

				//左子树为空
				else if (cur->_left == NULL)
				{
					if (NULL == cur->_parent)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}

				//左右子树都不为空
				else
				{
					parent = cur;
					//找右子树的最左节点
					Node* subleft = cur->_right;
					while(subleft->_left)
					{
						parent = subleft;
						subleft = subleft->_left;
					}
					
					cur->_key = subleft->_key;
					del = subleft;
					
					if (parent->_left == subleft)
					{
						parent->_left = subleft->_right;
					}
					else
					{
				 
						parent->_right = subleft->_right;
					}
				}
				delete del;
				return true;
			}
		}
		return false;
	}
	Node* Find(const K& key)
	{
		if (NULL == _root)
		{
			return false;
		}
		
		Node* cur = _root;
		while(cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return NULL;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
	void _InOrder(Node* root)
	{
		if (NULL == root)
		{
			return;
		}
		_InOrder(root->_left);
		cout<<root->_key<<" ";
		_InOrder(root->_right);
	}
	void Destroy(Node* root)
	{
		if (root)
		{
			delete root;
		}
		_Destroy(root->_left);
		_Destroy(root->_right);
	}
protected:
	Node* _root;
};

void Test()
{
	//迭代法测试
	BinarySearchTree<int,int> bs;
	bs.Insert(5,0);
	bs.Insert(3,0);
	bs.Insert(4,0);
	bs.Insert(1,0);
	bs.Insert(7,0);
	bs.Insert(8,0);
	bs.Insert(5,0);
	bs.Insert(2,0);
	bs.Insert(6,0);
	bs.Insert(0,0);
	bs.Insert(9,0);
	
	cout<<bs.Find(5)->_key<<endl;
	cout<<bs.Find(6)->_key<<endl;
	bs.Find(20);

	bs.Remove(1);
	bs.InOrder();
	bs.Remove(5);
	bs.InOrder();
	bs.Remove(3);
	bs.InOrder();
	bs.Remove(6);
	bs.InOrder();
	bs.Remove(2);
	bs.InOrder();
}