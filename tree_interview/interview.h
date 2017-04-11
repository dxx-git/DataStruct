#pragma  once
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
struct TreeNode
{
	T _data;              //节点的数据
	TreeNode<T>* _left;    //节点的左指针
	TreeNode<T>* _right;   //节点的右指针

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

	BinaryTree()                               //无参构造函数
		:_root(NULL)
	{}
	BinaryTree(T* a,size_t n,const T& invalid)   //构造函数
		:_root(NULL)
	{
		assert(a);
		size_t index = 0;
		_root = _CreatTree(a,n,index,invalid);
	}
	~BinaryTree()      //析构函数
	{
		if (_root)
		{
			_Destroy(_root);
			_root = NULL;
		}
	}
	bool Find(const T& data)      //判断一个值为的节点是否在当前二叉树中
	{
		return _Find(_root,data);
	}
	Node* sameAncester(Node* n1,Node* n2)      //求两个节点的最近公共祖先
	{
		//return _sameAncester1(_root,n1,n2);
		return _sameAncester2(_root,n1,n2);
	}
protected:
	Node* _CreatTree(T* a,size_t n,size_t& index,const T& invalid)    //建树
	{
		Node* root = NULL;
		if (a[index] != invalid && index < n)
		{
			//以递归的方式前序创建二叉树
			root = new Node(a[index]);
			root->_left = _CreatTree(a,n,++index,invalid);
			root->_right = _CreatTree(a,n,++index,invalid);
		}
		return root;
	}
	void _Destroy(Node* root)     //毁树
	{
		if (root)
		{
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
			root = NULL;
		}
	}
	bool _Find(Node* root,const T& data)    //查找指定数据的节点
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
	Node* _sameAncester1(Node*& root,Node* n1,Node* n2)//求两个节点的最近公共祖先(时间复杂度：O(N^2))
	{
		assert(n1 && n2);
		//保证两个节点都在当前树中,且当前树不为空
		if (root && Find(n1->_data) && Find(n2->_data))
		{
			//其中一个节点为根节点，直接返回根节点
			if (root->_data == n1->_data || root->_data == n2->_data)
			{
				return root;
			}
			//两个节点：1、都在左子树 2、都在右子树 3、一个在左子树，一个在右子树
			else
			{
				Node* cur = root;
				//在当前树的左子树去找n1和n2节点，如果没找到就一定在右子树
				bool tmp1 = _Find(cur->_left,n1->_data);
				bool tmp2 = _Find(cur->_left,n2->_data);
				//n1和n2都在左子树
				if (tmp1 && tmp2)
				{
					return _sameAncester1(cur->_left,n1,n2);
				}
				//n1和n2都在右子树
				else if(!tmp1 && !tmp2)
				{
					return _sameAncester1(cur->_right,n1,n2);
				}
				//n1与n2一个在左子树一个在右子树
				else
				{
					return root;
				}
			}
		}
		return NULL;
	}
	bool _GetPath2(Node* root,Node* cur,stack<Node*>& s)//在根为root的树中查找节点cur的路径
	{
		if (NULL == root || NULL == cur)//树为空
		    return false;
		s.push(root);    //将当前节点入栈
		
		if (cur->_data == root->_data)  //找到路径
		{
			return true;
		}
		if (_GetPath2(root->_left,cur,s))//在左子树中找路径
		{
			return true;
		}
		if (_GetPath2(root->_right,cur,s))//在右子树中找路径
		{
			return true;
		}
		s.pop();
		return false;
	}
	Node* _sameAncester2(Node*& root,Node* n1,Node* n2)//求两个节点的最近公共祖先(时间复杂度：O(N))
	{
		//树为空
		if (NULL == root)
		{
			return NULL;
		}
		stack<Node*> s1;
		stack<Node*> s2;
		//用栈s1和s2分别保存节点n1和节点n2的路径
		_GetPath2(root,n1,s1);
		_GetPath2(root,n2,s2);
		//将多余的路径删除
		while (s1.size() > s2.size())
		{
			s1.pop();
		}
		while(s1.size() < s2.size())
		{
			s2.pop();
		}
		//找s1与s2中不同的节点
		while(s1.top() != s2.top())
		{
			s1.pop();
			s2.pop();
		}
		return s1.top();
	}
private:
	Node* _root;    //根节点
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

	cout<<bt1.sameAncester(new TreeNode<int>(3),new TreeNode<int>(8))->_data<<endl;//不同子树
	cout<<bt1.sameAncester(new TreeNode<int>(3),new TreeNode<int>(2))->_data<<endl;//左边
	cout<<bt1.sameAncester(new TreeNode<int>(8),new TreeNode<int>(7))->_data<<endl;//右边
	cout<<bt1.sameAncester(new TreeNode<int>(1),new TreeNode<int>(3))->_data<<endl;//其中一个是根

}