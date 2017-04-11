#pragma  once
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
struct TreeNode
{
	T _data;              //�ڵ������
	TreeNode<T>* _left;    //�ڵ����ָ��
	TreeNode<T>* _right;   //�ڵ����ָ��

	TreeNode(const T& data = T())
		:_data(data)
		,_left(NULL)
		,_right(NULL)
	{}
};

template <typename T>
class BinaryTree
{
public:
	typedef TreeNode<T> Node;

	BinaryTree()                               //�޲ι��캯��
		:_root(NULL)
	{}
	BinaryTree(T* a,size_t n,const T& invalid)   //���캯��
		:_root(NULL)
	{
		assert(a);
		size_t index = 0;
		_root = _CreatTree(a,n,index,invalid);
	}
	~BinaryTree()      //��������
	{
		if (_root)
		{
			_Destroy(_root);
			_root = NULL;
		}
	}
	bool Find(const T& data)      //�ж�һ��ֵΪ�Ľڵ��Ƿ��ڵ�ǰ��������
	{
		return _Find(_root,data);
	}
	Node* sameAncester(Node* n1,Node* n2)      //�������ڵ�������������
	{
		//return _sameAncester1(_root,n1,n2);
		return _sameAncester2(_root,n1,n2);
	}
protected:
	Node* _CreatTree(T* a,size_t n,size_t& index,const T& invalid)    //����
	{
		Node* root = NULL;
		if (a[index] != invalid && index < n)
		{
			//�Եݹ�ķ�ʽǰ�򴴽�������
			root = new Node(a[index]);
			root->_left = _CreatTree(a,n,++index,invalid);
			root->_right = _CreatTree(a,n,++index,invalid);
		}
		return root;
	}
	void _Destroy(Node* root)     //����
	{
		if (root)
		{
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
			root = NULL;
		}
	}
	bool _Find(Node* root,const T& data)    //����ָ�����ݵĽڵ�
	{
		if (NULL == root)
		{
			return false;
		}
		else if (root->_data == data)
		{
			return true;
		}
		else
		{
			bool isIn = false;
			if (root->_left && !isIn)
				isIn = _Find(root->_left,data);
			if (root->_right && !isIn)
			    isIn = _Find(root->_right,data);
			return isIn;
		}
	}
	Node* _sameAncester1(Node*& root,Node* n1,Node* n2)//�������ڵ�������������(ʱ�临�Ӷȣ�O(N^2))
	{
		assert(n1 && n2);
		//��֤�����ڵ㶼�ڵ�ǰ����,�ҵ�ǰ����Ϊ��
		if (root && Find(n1->_data) && Find(n2->_data))
		{
			//����һ���ڵ�Ϊ���ڵ㣬ֱ�ӷ��ظ��ڵ�
			if (root->_data == n1->_data || root->_data == n2->_data)
			{
				return root;
			}
			//�����ڵ㣺1������������ 2������������ 3��һ������������һ����������
			else
			{
				Node* cur = root;
				//�ڵ�ǰ����������ȥ��n1��n2�ڵ㣬���û�ҵ���һ����������
				bool tmp1 = _Find(cur->_left,n1->_data);
				bool tmp2 = _Find(cur->_left,n2->_data);
				//n1��n2����������
				if (tmp1 && tmp2)
				{
					return _sameAncester1(cur->_left,n1,n2);
				}
				//n1��n2����������
				else if(!tmp1 && !tmp2)
				{
					return _sameAncester1(cur->_right,n1,n2);
				}
				//n1��n2һ����������һ����������
				else
				{
					return root;
				}
			}
		}
		return NULL;
	}
	bool _GetPath2(Node* root,Node* cur,stack<Node*>& s)//�ڸ�Ϊroot�����в��ҽڵ�cur��·��
	{
		if (NULL == root || NULL == cur)//��Ϊ��
		    return false;
		s.push(root);    //����ǰ�ڵ���ջ
		
		if (cur->_data == root->_data)  //�ҵ�·��
		{
			return true;
		}
		if (_GetPath2(root->_left,cur,s))//������������·��
		{
			return true;
		}
		if (_GetPath2(root->_right,cur,s))//������������·��
		{
			return true;
		}
		s.pop();
		return false;
	}
	Node* _sameAncester2(Node*& root,Node* n1,Node* n2)//�������ڵ�������������(ʱ�临�Ӷȣ�O(N))
	{
		//��Ϊ��
		if (NULL == root)
		{
			return NULL;
		}
		stack<Node*> s1;
		stack<Node*> s2;
		//��ջs1��s2�ֱ𱣴�ڵ�n1�ͽڵ�n2��·��
		_GetPath2(root,n1,s1);
		_GetPath2(root,n2,s2);
		//�������·��ɾ��
		while (s1.size() > s2.size())
		{
			s1.pop();
		}
		while(s1.size() < s2.size())
		{
			s2.pop();
		}
		//��s1��s2�в�ͬ�Ľڵ�
		while(s1.top() != s2.top())
		{
			s1.pop();
			s2.pop();
		}
		return s1.top();
	}
private:
	Node* _root;    //���ڵ�
};


void Test()
{
	int a1[] = {1,2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#',8};
	int a2 [10] = {1, 2, 3, '#', '#', 4, '#' , '#', 5, 6};
	size_t n1 = sizeof(a1)/sizeof(a1[0]);
	size_t n2 = sizeof(a2)/sizeof(a2[0]);

	BinaryTree<int> bt1(a1,n1,'#');
	BinaryTree<int> bt2(a2,n2,'#');
	cout<<"2:"<<bt1.Find(2)<<endl;
	cout<<"9:"<<bt1.Find(9)<<endl;
	cout<<"7:"<<bt2.Find(7)<<endl;
	cout<<"6:"<<bt2.Find(6)<<endl;

	cout<<bt1.sameAncester(new TreeNode<int>(3),new TreeNode<int>(8))->_data<<endl;//��ͬ����
	cout<<bt1.sameAncester(new TreeNode<int>(3),new TreeNode<int>(2))->_data<<endl;//���
	cout<<bt1.sameAncester(new TreeNode<int>(8),new TreeNode<int>(7))->_data<<endl;//�ұ�
	cout<<bt1.sameAncester(new TreeNode<int>(1),new TreeNode<int>(3))->_data<<endl;//����һ���Ǹ�

}