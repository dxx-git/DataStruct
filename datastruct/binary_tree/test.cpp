#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
using namespace std;

template <class T>
struct TreeNode
{
	TreeNode(const T& value = T())
		:_value(value)
		,_lchild(0)
		,_rchild(0)
	{}
	T _value;//�ڵ��ֵ
	TreeNode<T>* _lchild;//����
	TreeNode<T>* _rchild;//�Һ���
};

template <class T>
class BinaryTree
{
public:
	typedef TreeNode<T> Node;
	BinaryTree()//�޲ι��캯��
		:_root(NULL)
	{}
	BinaryTree(const T* a,size_t size,const T& invalid)//���캯��
	{
		assert(a);
		size_t index = 0;
		_root = CreatTree(a,size,invalid,index);
	}
	BinaryTree(const BinaryTree<T>& b)//��������
	{
		_root = Copy(b._root);
	}
	//�ִ�д���ĸ�ֵ���������1
	BinaryTree& operator=(const BinaryTree<T>& b)
	{
		if (this != &b)
		{
			Node* tmp = Copy(b._root);
			Destroy(_root) ;
			_root = tmp;
			//swap(_root,tmp);
		}
		return *this;
	}
	////�ִ�д���ĸ�ֵ���������2
	//BinaryTree& operator=(BinaryTree<T> b)
	//{
	//	swap(b._root,_root);
	//	return *this;
	//}
	~BinaryTree()//����
	{
		if (NULL != _root)
		{
			Destroy(_root);
			_root = NULL;
		}
	}

	void PreOrder()//���������ӡ���ĸ����ڵ�
	{
		cout<<"�������:";
		preorderR(_root);
		cout<<endl;
	}
	void InOrder()//���������ӡ���ĸ����ڵ�
	{
		cout<<"�������:";
		inorderR(_root);
		cout<<endl;
	}
	void PostOrder()//���������ӡ���ĸ����ڵ�
	{
		cout<<"�������:";
		postorderR(_root);
		cout<<endl;
	}
	void LevelOrder()//���������ӡ���ĸ����ڵ�
	{
		cout<<"�������:";
		levelorder(_root);
		cout<<endl;
	}
	size_t Size()//�����еĽڵ����
	{
		cout<<"size:";
		return size(_root);
	}
	size_t Depth()//���������
	{
		cout<<"depth:";
		return depth(_root);
	}
	size_t GetLeafSize()
	{
		cout<<"leaf_size:";
		return getleafsize(_root);
	}
	size_t GetKLevelSize(size_t k)//���е�k��Ľڵ����
	{
		cout<<k<<"_level_size:";
		return getklevelsize(_root,k);
	}
protected:
	//������������ݹ齨��
	Node* CreatTree(const T* a,size_t size,const T& invalid,size_t& index)//ע��index�Ĵ�ֵ��ʽ
	{
		assert(a);
		Node* root = NULL;
		if (a[index] != invalid && index < size)//�������������
		{
			root = new Node(a[index]);
			root->_lchild = CreatTree(a,size,invalid,++index);
			root->_rchild = CreatTree(a,size,invalid,++index);
		}
		return root;
	}
	//��������
	Node* Copy(Node* root)
	{
		Node* tmp = NULL;

		if(root)
		{
			tmp = new Node(root->_value);
			tmp->_lchild = Copy(root->_lchild);
			tmp->_rchild = Copy(root->_rchild);
		}
		return tmp;
	}
	//�ͷſռ�
	void Destroy(Node*& root)
	{
		if(root)//�ú��������ʽ�ͷſռ�
		{
			Destroy(root->_rchild);
			Destroy(root->_lchild);
			delete root;
			root = NULL;
		}
	}
	void preorderR(Node* root)//���������ӡ���ĸ����ڵ�
	{
		Node* cur = root;
		stack<Node*> s;
		while (!s.empty() || cur)//ֻҪ��ǰ�ڵ��ջ��ͬʱΪ�գ���˵����û������
		{
			while(cur)//������������������ڵ�ֱ�ӷ������ݲ�����ѹջ
			{
				cout<<cur->_value<<" ";
				s.push(cur);
				cur = cur->_lchild;
			}

			Node* top = s.top();//ȡ��ջ��Ԫ�أ�����˵���˽ڵ��Լ����������Ѿ����ʹ���
			s.pop();

			cur = top->_rchild;//��������ķ�ʽȥ����������
		}
		cout<<endl;
	}
	void inorderR(Node* root)//���������ӡ���ĸ����ڵ�
	{
		Node* cur = root;
		stack<Node*> s;
		while(!s.empty() || cur)//ֻҪ��ǰ�ڵ��ջ��ͬʱΪ�գ���˵����û������
		{
			while(cur)//������������������ڵ�ֱ�ӽ���ѹջ
			{
				s.push(cur);
				cur = cur->_lchild;
			}

			Node* top = s.top();//ȡ��ջ��Ԫ�أ�����˵���˽ڵ���������Ѿ����ʹ���
			cout<<top->_value<<" ";//����ջ��Ԫ�أ������ڵ㣩
			s.pop();

			cur = top->_rchild;//��������ķ�ʽȥ����������
		}
		cout<<endl;
	}
	void postorderR(Node* root)//���������ӡ���ĸ����ڵ�
	{
		Node* cur = root;
		Node* prev = NULL;//��һ�����ʹ�������
		stack<Node*> s;
		while(!s.empty() || cur)//ֻҪ��ǰ�ڵ��ջ��ͬʱΪ�գ���˵����û������
		{
			//������������������ڵ�ֱ�ӽ���ѹջ
			while(cur)
			{
				s.push(cur);
				cur = cur->_lchild;
			}

			Node* top = s.top();//ȡջ��Ԫ�أ�����һ���ܷ���
			
			//���ڵ�������Ϊ�ջ��Ѿ����ʹ�ʱ����ֱ�ӽ��з���
			if (top->_rchild==NULL || top->_rchild==prev)
			{
				cout<<top->_value<<" ";
				prev = top;//��prev����Ϊ�Ѿ����ʵĽڵ�
				s.pop();
			}
			else//��������ķ�ʽȥ����������
			{
				cur = top->_rchild;
			}
	   }
		cout<<endl;
	}
	
	void levelorder(Node* root)//���������ӡ���ĸ����ڵ�
	{
		queue<Node*> q;
		if (root)
		{
			q.push(root);//�����ڵ�������
		}
		while(!q.empty())
		{
			Node* front = q.front();
			q.pop();
			cout<<front->_value<<" ";
			if (front->_lchild)
			{
				q.push(front->_lchild);
			}
			if (front->_rchild)
			{
				q.push(front->_rchild);
			}
		}
	}
	size_t size(Node* root)//�����еĽڵ����
	{
		size_t count = 0;
		if (NULL == root)
		{
			count = 0;
		}
		else
		{
			//��ǰ�ڵ� = �������ڵ� + �������ڵ� + 1
			count = size(root->_lchild) + size(root->_rchild)+ 1;
		}
		return count;
	}
	size_t depth(Node* root)//���������
	{
		if (NULL == root)
		{
			return 0;
		}
		else
		{
			return depth(root->_lchild)>depth(root->_rchild)?
				(depth(root->_lchild)+1):(depth(root->_rchild)+1);
		}
	}
	size_t getleafsize(Node* root)//��Ҷ�ڵ�ĸ���
	{
		if (NULL == root)//����
		{
			return 0;
		}
		if (NULL == root->_lchild && NULL == root->_rchild)//��Ҷ�ڵ��ҽڵ��Ϊ�գ���
		{
			return 1;
		}
		else//��������Ҷ�ڵ�+��������Ҷ�ڵ�
		{
			return getleafsize(root->_lchild)+getleafsize(root->_rchild);
		}
	}
	size_t getklevelsize(Node* root,size_t k)//���е�k��Ľڵ����
	{
		assert(k>0);

		size_t count = 0;
		if (NULL == root)
		{
			return 0;
		}
		if (k == 1)
		{
			count++;
		}
		else
		{
			count =  getklevelsize(root->_lchild,k-1)
				+ getklevelsize(root->_rchild,k-1);
		}
		return count;
	}
protected:
	Node* _root;//���ڵ�
};

void TestBinaryTree()
{
	int arr[] = {1, 2, 3, '#', '#', 4, '#' , '#', 5, 6,'#','#','#'};
	size_t size = sizeof(arr)/sizeof(arr[0]);
	BinaryTree<int> bt(arr,size,'#');
	BinaryTree<int> b1(bt);
	BinaryTree<int> b2;
	b2 = bt;
	b2.PreOrder();
	b2.InOrder();
	b2.PostOrder();
	b2.LevelOrder();
	cout<<b2.Size()<<endl;
	cout<<b2.Depth()<<endl;
	cout<<b2.GetLeafSize()<<endl;
	cout<<b2.GetKLevelSize(1)<<endl;
	cout<<b2.GetKLevelSize(2)<<endl;
	cout<<b2.GetKLevelSize(3)<<endl;
}



#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
using namespace std;
//#include "binary_tree_thread.h"

int main()
{
	TestBinaryTree();
	//TestBinaryTreeThd();
	system("pause");
	return 0;
}