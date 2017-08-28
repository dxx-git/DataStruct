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
	T _value;//节点的值
	TreeNode<T>* _lchild;//左孩子
	TreeNode<T>* _rchild;//右孩子
};

template <class T>
class BinaryTree
{
public:
	typedef TreeNode<T> Node;
	BinaryTree()//无参构造函数
		:_root(NULL)
	{}
	BinaryTree(const T* a,size_t size,const T& invalid)//构造函数
	{
		assert(a);
		size_t index = 0;
		_root = CreatTree(a,size,invalid,index);
	}
	BinaryTree(const BinaryTree<T>& b)//拷贝构造
	{
		_root = Copy(b._root);
	}
	//现代写法的赋值运算符重载1
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
	////现代写法的赋值运算符重载2
	//BinaryTree& operator=(BinaryTree<T> b)
	//{
	//	swap(b._root,_root);
	//	return *this;
	//}
	~BinaryTree()//析构
	{
		if (NULL != _root)
		{
			Destroy(_root);
			_root = NULL;
		}
	}

	void PreOrder()//先序遍历打印树的各个节点
	{
		cout<<"先序遍历:";
		preorderR(_root);
		cout<<endl;
	}
	void InOrder()//中序遍历打印树的各个节点
	{
		cout<<"中序遍历:";
		inorderR(_root);
		cout<<endl;
	}
	void PostOrder()//后序遍历打印树的各个节点
	{
		cout<<"后序遍历:";
		postorderR(_root);
		cout<<endl;
	}
	void LevelOrder()//层序遍历打印树的各个节点
	{
		cout<<"层序遍历:";
		levelorder(_root);
		cout<<endl;
	}
	size_t Size()//求树中的节点个数
	{
		cout<<"size:";
		return size(_root);
	}
	size_t Depth()//求树的深度
	{
		cout<<"depth:";
		return depth(_root);
	}
	size_t GetLeafSize()
	{
		cout<<"leaf_size:";
		return getleafsize(_root);
	}
	size_t GetKLevelSize(size_t k)//树中第k层的节点个数
	{
		cout<<k<<"_level_size:";
		return getklevelsize(_root,k);
	}
protected:
	//按照先序遍历递归建树
	Node* CreatTree(const T* a,size_t size,const T& invalid,size_t& index)//注意index的传值方式
	{
		assert(a);
		Node* root = NULL;
		if (a[index] != invalid && index < size)//按先序遍历建树
		{
			root = new Node(a[index]);
			root->_lchild = CreatTree(a,size,invalid,++index);
			root->_rchild = CreatTree(a,size,invalid,++index);
		}
		return root;
	}
	//拷贝对象
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
	//释放空间
	void Destroy(Node*& root)
	{
		if(root)//用后序遍历方式释放空间
		{
			Destroy(root->_rchild);
			Destroy(root->_lchild);
			delete root;
			root = NULL;
		}
	}
	void preorderR(Node* root)//先序遍历打印树的各个节点
	{
		Node* cur = root;
		stack<Node*> s;
		while (!s.empty() || cur)//只要当前节点和栈不同时为空，就说明树没遍历完
		{
			while(cur)//先序遍历，遇到树根节点直接访问数据并将其压栈
			{
				cout<<cur->_value<<" ";
				s.push(cur);
				cur = cur->_lchild;
			}

			Node* top = s.top();//取出栈顶元素，到此说明此节点以及其左子树已经访问过了
			s.pop();

			cur = top->_rchild;//以子问题的方式去访问右子树
		}
		cout<<endl;
	}
	void inorderR(Node* root)//中序遍历打印树的各个节点
	{
		Node* cur = root;
		stack<Node*> s;
		while(!s.empty() || cur)//只要当前节点和栈不同时为空，就说明树没遍历完
		{
			while(cur)//中序遍历，遇到树根节点直接将其压栈
			{
				s.push(cur);
				cur = cur->_lchild;
			}

			Node* top = s.top();//取出栈顶元素，到此说明此节点的左子树已经访问过了
			cout<<top->_value<<" ";//访问栈顶元素（即根节点）
			s.pop();

			cur = top->_rchild;//以子问题的方式去访问右子树
		}
		cout<<endl;
	}
	void postorderR(Node* root)//后序遍历打印树的各个节点
	{
		Node* cur = root;
		Node* prev = NULL;//上一个访问过的数据
		stack<Node*> s;
		while(!s.empty() || cur)//只要当前节点和栈不同时为空，就说明树没遍历完
		{
			//后序遍历，遇到树根节点直接将其压栈
			while(cur)
			{
				s.push(cur);
				cur = cur->_lchild;
			}

			Node* top = s.top();//取栈顶元素，但不一定能访问
			
			//当节点右子树为空或已经访问过时对其直接进行访问
			if (top->_rchild==NULL || top->_rchild==prev)
			{
				cout<<top->_value<<" ";
				prev = top;//将prev更新为已经访问的节点
				s.pop();
			}
			else//以子问题的方式去访问右子树
			{
				cur = top->_rchild;
			}
	   }
		cout<<endl;
	}
	
	void levelorder(Node* root)//层序遍历打印树的各个节点
	{
		queue<Node*> q;
		if (root)
		{
			q.push(root);//将根节点插进队列
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
	size_t size(Node* root)//求树中的节点个数
	{
		size_t count = 0;
		if (NULL == root)
		{
			count = 0;
		}
		else
		{
			//当前节点 = 左子树节点 + 右子树节点 + 1
			count = size(root->_lchild) + size(root->_rchild)+ 1;
		}
		return count;
	}
	size_t depth(Node* root)//求树的深度
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
	size_t getleafsize(Node* root)//求叶节点的个数
	{
		if (NULL == root)//空树
		{
			return 0;
		}
		if (NULL == root->_lchild && NULL == root->_rchild)//左叶节点右节点均为空，即
		{
			return 1;
		}
		else//左子树的叶节点+右子树的叶节点
		{
			return getleafsize(root->_lchild)+getleafsize(root->_rchild);
		}
	}
	size_t getklevelsize(Node* root,size_t k)//树中第k层的节点个数
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
	Node* _root;//根节点
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