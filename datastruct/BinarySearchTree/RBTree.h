#pragma once

enum Color
{
	RED,
	BLACK
};

template <typename K,typename V>
struct RBTreeNode
{
	Color _col;
	K _key;
	V _value;
	
	RBTreeNode<K,V>* _left;
	RBTreeNode<K,V>* _right;
	RBTreeNode<K,V>* _parent;
	
	RBTreeNode(const K& key,const V& value)
		:_col(RED)
		,_key(key)
		,_value(value)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};

template <typename K,typename V>
class RBTree
{
public:
	typedef RBTreeNode<K,V> Node;
	RBTree()
		:_root(NULL)
	{}
	~RBTree()
	{
		if (_root)
		{
			Destroy(_root);
			_root = NULL;
		}
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
	bool Insert(const K& key,const V& value)
	{
		if (NULL == _root)
		{
			_root = new Node(key,value);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = NULL;
		//���ҽڵ������ʺ�λ��
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

		//��Ҫ����Ľڵ����丸�׽ڵ�������
		cur = new Node(key,value);
		if (cur->_key < parent->_key)
		{
		    parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;
		
		//��֤���׽ڵ���游�ڵ����
		while(parent && parent->_col == RED)
		{
			//����������游�ڵ�,����pΪ���׽ڵ㣬gΪ�游�ڵ㣬uΪ����ڵ�
			Node* grandfather = parent->_parent;
			Node* uncle = NULL;
			//�������游�����ӣ�����Ϊ�游���Һ���
			if (parent == grandfather->_left)
			{
				uncle = grandfather->_right;

				//���1��curΪ�죬pΪ�죬gΪ�ڣ�u������Ϊ��
				//��p,u��Ϊ�ڣ�g��Ϊ�죬Ȼ���g����cur���������ϵ�����
				if (uncle && uncle->_col == RED)
				{
					//ֱ�ӱ�ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				//���2/���3��curΪ�죬pΪ�죬gΪ�ڣ�u������/uΪ�ڣ�
				else
				{
					//���2��pΪg�����ӣ�curΪp�����ӣ�
					//���������ת
					if (cur == parent->_right)
					{
						//�Ը��ڵ�Ϊ���������
						RotateL(parent);
						//�������ӹ�ϵ   
						swap(cur,parent);
					} 
					//���3��pΪg�����ӣ�curΪp���Һ��ӣ�
					//�����p������ת,
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			} 
			//�������游���Һ��ӣ�����Ϊ�游������
			else
			{
				uncle = grandfather->_left;

				//���1��curΪ�죬pΪ�죬gΪ�ڣ�u������Ϊ��
				//��p,u��Ϊ�ڣ�g��Ϊ�죬Ȼ���g����cur���������ϵ�����
				if (uncle && uncle->_col == RED)
				{
					//ֱ�ӱ�ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				//���2/���3��curΪ�죬pΪ�죬gΪ�ڣ�u������/uΪ�ڣ�
				else
				{
					//���2��pΪg���Һ��ӣ�curΪp���Һ��ӣ�
					//���������ת��p��g��ɫ--p��ڣ�g���
					if (cur == parent->_left)
					{
						//���游�ڵ�Ϊ���������
						RotateR(parent);
						//�������ӹ�ϵ
						swap(cur,parent);
					}
					//���3��pΪg���Һ��ӣ�curΪp�����ӣ�
					//�����p������ת,
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		
		Node* ppNode = parent->_parent;
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
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}
		subR->_left = parent;
		parent->_parent = subR;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		
		Node* ppNode = parent->_parent;
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
		subL->_right = parent;
		parent->_parent = subL;
	}

	bool IsBalance()
	{
		Node *cur = _root;
		size_t blacknum = 0;	//��ɫ�ڵ���Ŀ
		size_t count = 0;//����·����ɫ�ڵ���Ŀ

		while(cur)
		{
			if(cur->_col == BLACK)
			{
				++count;
			}
			cur = cur->_left;
		}
		return _CheckColorAndBlackNum(_root,blacknum,count);
	}
	bool _CheckColorAndBlackNum(Node *root,size_t blacknum,size_t count)
	{
		if(root == NULL)
		{
			return true;
		}
		if(root->_col == BLACK)
		{
			//����ڽڵ���Ŀ
			++blacknum;
		}
		if(root->_col == RED && root->_parent->_col == RED)//����������ڵ�
		{
			return false;
		}
		if(root->_left == NULL && root->_right == NULL && blacknum != count)
		{
			//һ��·������,��·����ɫ�ڵ���Ŀ������·����Ŀ��ͬ
			return false;
		}
		return  _CheckColorAndBlackNum(root->_left,blacknum,count)
			  &&_CheckColorAndBlackNum(root->_right,blacknum,count);
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
protected:
	Node* _root;
};

void TestRBTree()
{
	int arr1[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int arr[] = {2,4,5,3,6,9,1,0,7,8};
	RBTree<int,int> rb;
	for(size_t i = 0; i< sizeof(arr)/sizeof(arr[0]) ;++i)
	{
		rb.Insert(arr[i],-1);
		cout<<arr[i]<<" "<<rb.IsBalance()<<endl;
	}

	cout<<rb.Find(5)<<endl;
	cout<<rb.Find(50)<<endl;
	cout<<rb.Find(1)<<endl;

	rb.InOrder();
}


