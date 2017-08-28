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
		//查找节点插入的适合位置
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

		//将要插入的节点与其父亲节点相连接
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
		
		//保证父亲节点和祖父节点存在
		while(parent && parent->_col == RED)
		{
			//定义叔叔和祖父节点,假设p为父亲节点，g为祖父节点，u为叔叔节点
			Node* grandfather = parent->_parent;
			Node* uncle = NULL;
			//父亲是祖父的左孩子，叔叔为祖父的右孩子
			if (parent == grandfather->_left)
			{
				uncle = grandfather->_right;

				//情况1：cur为红，p为红，g为黑，u存在且为红
				//则将p,u改为黑，g改为红，然后把g当成cur，继续向上调整。
				if (uncle && uncle->_col == RED)
				{
					//直接变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				//情况2/情况3：cur为红，p为红，g为黑，u不存在/u为黑：
				else
				{
					//情况2：p为g的左孩子，cur为p的左孩子，
					//则进行左单旋转
					if (cur == parent->_right)
					{
						//以父节点为轴进行左单旋
						RotateL(parent);
						//更正父子关系   
						swap(cur,parent);
					} 
					//情况3：p为g的左孩子，cur为p的右孩子，
					//则针对p做右旋转,
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			} 
			//父亲是祖父的右孩子，叔叔为祖父的左孩子
			else
			{
				uncle = grandfather->_left;

				//情况1：cur为红，p为红，g为黑，u存在且为红
				//则将p,u改为黑，g改为红，然后把g当成cur，继续向上调整。
				if (uncle && uncle->_col == RED)
				{
					//直接变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				//情况2/情况3：cur为红，p为红，g为黑，u不存在/u为黑：
				else
				{
					//情况2：p为g的右孩子，cur为p的右孩子，
					//则进行左单旋转，p、g变色--p变黑，g变红
					if (cur == parent->_left)
					{
						//以祖父节点为轴进行左单旋
						RotateR(parent);
						//更正父子关系
						swap(cur,parent);
					}
					//情况3：p为g的右孩子，cur为p的左孩子，
					//则针对p做左旋转,
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
		size_t blacknum = 0;	//黑色节点数目
		size_t count = 0;//最左路径黑色节点数目

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
			//计算黑节点数目
			++blacknum;
		}
		if(root->_col == RED && root->_parent->_col == RED)//出现连续红节点
		{
			return false;
		}
		if(root->_left == NULL && root->_right == NULL && blacknum != count)
		{
			//一条路径走完,本路径黑色节点数目与其他路径数目不同
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


