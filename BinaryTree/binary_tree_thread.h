#pragma once

enum PointTag
{
   LINK,//����
   THREAD,//����
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
	
    T _data;//�ڵ�����
	BinaryTreeThdNode<T>* _left;//��ǰ�ڵ������
    BinaryTreeThdNode<T>* _right;//��ǰ�ڵ���Һ���
	BinaryTreeThdNode<T>* _parent;//���׽ڵ��˫��

	PointTag _leftTag;//��ǰ�ڵ������������־
	PointTag _rightTag;//��ǰ�ڵ���Һ���������־
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
	Node* _Next(Node* node)//�������������һ���ڵ�
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
	Node* _Prev(Node* node)//�����������ǰһ���ڵ�
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
	BinaryTreeThd()//�޲ι��캯��
		:_node(NULL)
	{}

	BinaryTreeThd(T* a,size_t n,const T& invalid)//���캯��
	{
		size_t index = 0;
		Node* parent = NULL;
		_node = _CreatBinaryTreeThd(a,n,invalid,index,parent);
	}
	void PrveOrderThread()//ǰ�������������
	{
		Node* prev = NULL;
		_PrveOrderThreading(_node,prev);
	}
	void PrevOrderThd()//ͨ��������ǰ�����������
	{
		Node* cur = _node;
		while (cur)
		{
			while(cur->_leftTag == LINK)
			{
				cout<<cur->_data<<" ";//���ʵ�ǰ�ڵ�
				cur = cur->_left;
			}

			cout<<cur->_data<<" ";//��������ڵ�

			//������������������(����ķ���Ҳ����)
			cur = cur->_right;


			//���ʵ�ǰ�ڵ��������
			//while (cur && cur->_rightTag == THREAD//��ǰ�ڵ����ָ��Ϊ����
			//{
			//	cur = cur->_right;
			//	if(cur)
			//	{
			//		cout<<cur->_data<<" ";
			//	}
			//}
			////�����⣬���������������⴦��
			//if (cur)//cur->_rightTag == LINK(��ǰ�ڵ����ָ��Ϊ������
			//{
			//	cur = cur->_right;
			//}
		}
		cout<<endl;
	}
	void InOrderThread()//���������������
	{
		Node* prev = NULL;
		_InOrderThreading(_node,prev);
	}
	void InOrderThd()//ͨ���������������������
	{
		Node* cur = _node;
		while (cur)
		{
			while(cur->_leftTag == LINK)//Ѱ������ڵ�
			{
				cur = cur->_left;
			}

			cout<<cur->_data<<" ";//��������ڵ�

			while (cur && cur->_rightTag == THREAD)//��ǰ�ڵ����ָ��Ϊ����
			{
				cur = cur->_right;
				if(cur)
				{
					cout<<cur->_data<<" ";
				}
			}
			//�����⣬���������������⴦��
			if (cur)//cur->_rightTag == LINK(��ǰ�ڵ����ָ��Ϊ������
			{
				cur = cur->_right;
			}
		}
		cout<<endl;
	}
	void PostOrderThead()//���������������
	{
		Node* prev = NULL;
		_PostOrderTheading(_node,prev);
	}
	void PostOrderThd()//ͨ���������������������
	{
		Node* cur = _node;
		Node* prev = NULL;
		while (cur)
		{
			//Ѱ������ڵ�
			while(cur->_left != prev && cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}//cur==_node��NULL����ѭ��

			//���ʺ��
			while (cur && cur->_rightTag == THREAD)//��ǰ�ڵ����ָ��Ϊ����
			{
				cout<<cur->_data<<" ";
				prev = cur;
				cur = cur->_right;
			}

			if (cur == _node)//�жϽڵ��Ƿ�ָ���˸��ڵ�
			{
				cout<<cur->_data<<endl;
				return;
			}

			while (cur && cur->_right == prev)
			{
				cout<<cur->_data<<" ";
				prev = cur;
				cur = cur->_parent;//����һ����
			}
			if (cur && cur->_rightTag == LINK)//cur->_rightTag == LINK(��ǰ�ڵ����ָ��Ϊ������
			{
				cur = cur->_right;
			}
		}
	}
	
protected:
	//���������������������
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

	void _PrveOrderThreading(Node* cur,Node*& prev)//ǰ�������������
	{
		if (NULL == cur)
		{
			return;
		}

		//���������ڵ�
		if (NULL == cur->_left)//�ҵ�����ڵ㣬
		{
			cur->_left = prev;       //������ָ��ָ��ýڵ��ֱ��ǰ���ڵ�
			cur->_leftTag = THREAD;  //�����־λ��ΪTHEAD
		}
		if (prev && NULL == prev->_right)//�ҵ����ҽڵ㣬
		{
			prev->_right = cur;       //������ָ��ָ��ýڵ��ֱ�Ӻ�̽ڵ�
			prev->_rightTag = THREAD; //�����־λ��ΪTHEAD
		}
		prev = cur;    //ǰһ���ڵ����Ϊ��ǰ�ڵ�

		//������������
		if (cur->_leftTag == LINK)  //��ֹջ���
		{
			_PrveOrderThreading(cur->_left,prev);
		}

		//������������
		if (cur->_rightTag == LINK)  //��ֹջ���
		{
			_PrveOrderThreading(cur->_right,prev);
		}
	}

	void _InOrderThreading(Node* cur,Node*& prev)//���������������
	{
		if (NULL == cur)
		{
			return;
		}
		//������������
		if (cur->_leftTag == LINK)
		{
			_InOrderThreading(cur->_left,prev);
		}

		//���������ڵ�
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

		//������������
		if (cur->_rightTag == LINK)
		{
			_InOrderThreading(cur->_right,prev);
		}
	}

	void _PostOrderTheading(Node* cur,Node*& prev)//���������������
	{
		if (NULL == cur)
		{
			return;
		}
		//������������
		if (cur->_leftTag == LINK)  //��ֹջ���
		{
			_PostOrderTheading(cur->_left,prev);
		}

		//������������
		if (cur->_rightTag == LINK)  //��ֹջ���
		{
			_PostOrderTheading(cur->_right,prev);
		}

		//���������ڵ�
		if (NULL == cur->_left)//�ҵ�����ڵ㣬
		{
			cur->_left = prev;       //������ָ��ָ��ýڵ��ֱ��ǰ���ڵ�
			cur->_leftTag = THREAD;  //�����־λ��ΪTHEAD
		}
		if (prev && NULL == prev->_right)//�ҵ����ҽڵ㣬
		{
			prev->_right = cur;       //������ָ��ָ��ýڵ��ֱ�Ӻ�̽ڵ�
			prev->_rightTag = THREAD; //�����־λ��ΪTHEAD
		}
		prev = cur;    //ǰһ���ڵ����Ϊ��ǰ�ڵ�
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

	BinaryTreeThd<int>::Iterator it = bt.Begin();//ע��������д�ĵ�����ֻ������������
	while (it != bt.End())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}