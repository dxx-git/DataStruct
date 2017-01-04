#pragma once

enum PointTag
{
   LINK,//子树
   THREAD,//线索
};

template <class T>
struct BinaryTreeThdNode
{
	BinaryTreeThdNode(const T& x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		,_leftTag(LINK)
		,_rightTag(LINK)
	{}
	
    T _data;//节点数据
	BinaryTreeThdNode<T>* _left;//当前节点的左孩子
    BinaryTreeThdNode<T>* _right;//当前节点的右孩子
	BinaryTreeThdNode<T>* _parent;//当亲节点的双亲

	PointTag _leftTag;//当前节点的左孩子线索标志
	PointTag _rightTag;//当前节点的右孩子线索标志
};

template <class T,class Ref,class Ptr>
struct BinaryTreeIterator
{
	typedef BinaryTreeThdNode<T> Node;
	typedef BinaryTreeIterator<T,Ref,Ptr> Self;

	BinaryTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
	    return &(operator*());
	}
	Self& operator++()
	{
		_node = _Next(_node);
		return *this;
	}
	Self operator++(int)
	{
		Self tmp(*this);
		_node = _Next(_node);
		return tmp;
	}
	Self& operator--()
	{
		_node = _Prev(_node);
		return *this;
	}
	Self operator--(int)
	{
		Self tmp(*this);
		_node = _Prev(_node);
		return tmp;
	}
	bool operator!=(const Self& s)const
	{
		return _node != s._node;
	}
	bool operator==(const Self& s)const
	{
		return _node == s._node;
	}
protected:
	Node* _Next(Node* node)//找中序遍历的下一个节点
	{
		assert(node);
		if (node->_rightTag == THREAD)
		{
			return node->_right;
		}
		else
		{
			Node* cur = node->_right;
			while (cur && cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			return cur;
		}
	}
	Node* _Prev(Node* node)//找中序遍历的前一个节点
	{
		if (node->_leftTag == THREAD)
		{
			return node->_left;
		}
		else
		{
			Node* cur = node->_left;
			while (cur && cur->_rightTag == LINK)
			{
				cur = cur->_right;
			}
			return cur;
		}
	}
protected:
	Node* _node;
};

template <class T>
class BinaryTreeThd
{
public:
	typedef BinaryTreeThdNode<T> Node;
	typedef BinaryTreeIterator<T,T&,T*> Iterator;
	typedef BinaryTreeIterator<const T,const T&,const T*> ConstIterator;

	Iterator Begin()
	{
		Node* cur = _node;
		while(cur->_leftTag == LINK)
		{
			cur = cur->_left;
		}
		return Iterator(cur);
	}
	Iterator End()
	{
		return NULL;
	}
public:
	BinaryTreeThd()//无参构造函数
		:_node(NULL)
	{}

	BinaryTreeThd(T* a,size_t n,const T& invalid)//构造函数
	{
		size_t index = 0;
		Node* parent = NULL;
		_node = _CreatBinaryTreeThd(a,n,invalid,index,parent);
	}
	void PrveOrderThread()//前序遍历的线索化
	{
		Node* prev = NULL;
		_PrveOrderThreading(_node,prev);
	}
	void PrevOrderThd()//通过线索化前序遍历二叉树
	{
		Node* cur = _node;
		while (cur)
		{
			while(cur->_leftTag == LINK)
			{
				cout<<cur->_data<<" ";//访问当前节点
				cur = cur->_left;
			}

			cout<<cur->_data<<" ";//访问最左节点

			//访问整棵树的右子树(下面的方法也可以)
			cur = cur->_right;


			//访问当前节点的右子树
			//while (cur && cur->_rightTag == THREAD//当前节点的右指针为线索
			//{
			//	cur = cur->_right;
			//	if(cur)
			//	{
			//		cout<<cur->_data<<" ";
			//	}
			//}
			////子问题，右是子树，子问题处理
			//if (cur)//cur->_rightTag == LINK(当前节点的右指针为子树）
			//{
			//	cur = cur->_right;
			//}
		}
		cout<<endl;
	}
	void InOrderThread()//中序遍历的线索化
	{
		Node* prev = NULL;
		_InOrderThreading(_node,prev);
	}
	void InOrderThd()//通过线索化中序遍历二叉树
	{
		Node* cur = _node;
		while (cur)
		{
			while(cur->_leftTag == LINK)//寻找最左节点
			{
				cur = cur->_left;
			}

			cout<<cur->_data<<" ";//访问最左节点

			while (cur && cur->_rightTag == THREAD)//当前节点的右指针为线索
			{
				cur = cur->_right;
				if(cur)
				{
					cout<<cur->_data<<" ";
				}
			}
			//子问题，右是子树，子问题处理
			if (cur)//cur->_rightTag == LINK(当前节点的右指针为子树）
			{
				cur = cur->_right;
			}
		}
		cout<<endl;
	}
	void PostOrderThead()//后序遍历的线索化
	{
		Node* prev = NULL;
		_PostOrderTheading(_node,prev);
	}
	void PostOrderThd()//通过线索化后序遍历二叉树
	{
		Node* cur = _node;
		Node* prev = NULL;
		while (cur)
		{
			//寻找最左节点
			while(cur->_left != prev && cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}//cur==_node或NULL结束循环

			//访问后继
			while (cur && cur->_rightTag == THREAD)//当前节点的右指针为线索
			{
				cout<<cur->_data<<" ";
				prev = cur;
				cur = cur->_right;
			}

			if (cur == _node)//判断节点是否指向了根节点
			{
				cout<<cur->_data<<endl;
				return;
			}

			while (cur && cur->_right == prev)
			{
				cout<<cur->_data<<" ";
				prev = cur;
				cur = cur->_parent;//向上一层走
			}
			if (cur && cur->_rightTag == LINK)//cur->_rightTag == LINK(当前节点的右指针为子树）
			{
				cur = cur->_right;
			}
		}
	}
	
protected:
	//按照先序遍历创建二叉树
	Node* _CreatBinaryTreeThd(const T* a,size_t n,const T& invalid,size_t& index,Node*& parent)
	{
		Node* root = NULL;
	    if (a[index] != invalid && index < n)
	    {
			root = new Node(a[index]);
			root->_parent = parent;

			root->_left = _CreatBinaryTreeThd(a,n,invalid,++index,root);
			root->_right = _CreatBinaryTreeThd(a,n,invalid,++index,root);
	    }
		return root;
	}

	void _PrveOrderThreading(Node* cur,Node*& prev)//前序遍历的线索化
	{
		if (NULL == cur)
		{
			return;
		}

		//线索化根节点
		if (NULL == cur->_left)//找到最左节点，
		{
			cur->_left = prev;       //将其左指针指向该节点的直接前驱节点
			cur->_leftTag = THREAD;  //将其标志位置为THEAD
		}
		if (prev && NULL == prev->_right)//找到最右节点，
		{
			prev->_right = cur;       //将其右指针指向该节点的直接后继节点
			prev->_rightTag = THREAD; //将其标志位置为THEAD
		}
		prev = cur;    //前一个节点后移为当前节点

		//线索化左子树
		if (cur->_leftTag == LINK)  //防止栈溢出
		{
			_PrveOrderThreading(cur->_left,prev);
		}

		//线索化右子树
		if (cur->_rightTag == LINK)  //防止栈溢出
		{
			_PrveOrderThreading(cur->_right,prev);
		}
	}

	void _InOrderThreading(Node* cur,Node*& prev)//中序遍历的线索化
	{
		if (NULL == cur)
		{
			return;
		}
		//线索化左子树
		if (cur->_leftTag == LINK)
		{
			_InOrderThreading(cur->_left,prev);
		}

		//线索化根节点
		if (NULL == cur->_left)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}
		if (prev && NULL == prev->_right)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}
		prev = cur;

		//线索化右子树
		if (cur->_rightTag == LINK)
		{
			_InOrderThreading(cur->_right,prev);
		}
	}

	void _PostOrderTheading(Node* cur,Node*& prev)//后序遍历的线索化
	{
		if (NULL == cur)
		{
			return;
		}
		//线索化左子树
		if (cur->_leftTag == LINK)  //防止栈溢出
		{
			_PostOrderTheading(cur->_left,prev);
		}

		//线索化右子树
		if (cur->_rightTag == LINK)  //防止栈溢出
		{
			_PostOrderTheading(cur->_right,prev);
		}

		//线索化根节点
		if (NULL == cur->_left)//找到最左节点，
		{
			cur->_left = prev;       //将其左指针指向该节点的直接前驱节点
			cur->_leftTag = THREAD;  //将其标志位置为THEAD
		}
		if (prev && NULL == prev->_right)//找到最右节点，
		{
			prev->_right = cur;       //将其右指针指向该节点的直接后继节点
			prev->_rightTag = THREAD; //将其标志位置为THEAD
		}
		prev = cur;    //前一个节点后移为当前节点
	}
protected:
	Node* _node;
};

void TestBinaryTreeThd()
{
	int array [10] = {1, 2, 3, '#', '#', 4, '#' , '#', 5, 6};
	size_t size = sizeof(array)/sizeof(array[0]);
	BinaryTreeThd<int> bt(array,size,'#');
	bt.InOrderThread();
	bt.InOrderThd();

	size_t size1 = sizeof(array)/sizeof(array[0]);
	BinaryTreeThd<int> bt1(array,size1,'#');
	bt1.PrveOrderThread();
	bt1.PrevOrderThd();

	size_t size2 = sizeof(array)/sizeof(array[0]);
	BinaryTreeThd<int> bt2(array,size2,'#');
	bt2.PostOrderThead();
	bt2.PostOrderThd();

	BinaryTreeThd<int>::Iterator it = bt.Begin();//注意这里我写的迭代器只是针对中序遍历
	while (it != bt.End())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}