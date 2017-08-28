#include <iostream>
using namespace std;
#include "binary_search_tree.h"
#include "RBTree.h"
//
//template <class K>
//struct BinarySearchTreeNode
//{
//	K _key;//节点的关键码
//	BinarySearchTreeNode<K>* _left;//节点的左孩子
//	BinarySearchTreeNode<K>* _right;//节点的右孩子
//
//	BinarySearchTreeNode(const K& key)
//		:_key(key)
//		,_left(NULL)
//		,_right(NULL)
//	{}
//};
//
//template <class K>
//class BSTree
//{
//public:
//	typedef BinarySearchTreeNode<K> Node;
//	BSTree()
//		:_root(NULL)
//	{}
//	~BSTree()
//	{
//		if (_root != NULL)
//		{
//			_Destroy(_root);
//			_root = NULL;
//		}
//	}
//
//	bool Insert(const K& k)//迭代法在搜索二叉树中插入节点
//	{
//		if (NULL == _root)
//		{
//			_root = new Node(k);
//			return true;
//		}
//		Node* cur = _root;
//		Node* parent = NULL;
//		//寻找插入节点的合适位置
//		while (cur)
//		{
//			//要插入节点的关键码小于当前节点的关键码，向当前节点的左子树寻找
//			if (k < cur->_key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			//要插入节点的关键码大于当前节点的关键码，向当前节点的右子树寻找
//			else if (k > cur->_key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			//要插入节点的关键码等于当前节点的关键码，则无正确位置，直接返回
//			else
//			{
//				return false;
//			}
//		}
//		//在找到插入位置以后，判断插入父亲节点的左边还是右边
//		if (parent->_key > k)
//		{
//			parent->_left = new Node(k);
//		}
//		else
//		{
//			parent->_right = new Node(k);
//		}
//		return true;
//	}
//	bool Remove(const K& k)//迭代法删除搜索二叉树的某节点
//	{
//		//空树
//		if (NULL == _root)
//		{
//			return false;
//		}
//		Node* cur = _root;
//		Node* parent = NULL;
//		Node* del = NULL;
//		//寻找要删除的节点位置
//		while (cur)
//		{
//			if (cur->_key < k)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > k)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			//找到所要删除的节点后分三种情况，左子树为空、右子树为空、左右子树都不为空
//			else
//			{
//				del = cur;
//				//左子树为空
//				if (NULL == cur->_left)
//				{
//					//注意判断父节点是否为空，若为空，则要删除的节点为根节点
//					if (NULL == parent)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						//判断当前节点是父节点的左孩子还是右孩子
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//					}
//				}
//				//右子树为空
//				else if (NULL == cur->_right)
//				{
//					//注意判断父节点是否为空，若为空，则要删除的节点为根节点
//					if (NULL == parent)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						//判断当前节点是父节点的左孩子还是右孩子
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_left;
//						}
//						else
//						{
//							parent->_right = cur->_left;
//						}
//					}
//				}
//				//左右子树都不为空
//				else
//				{
//					parent = cur;
//					//找右子树的最左节点
//					Node* subleft = cur->_right;
//					while (subleft->_left)
//					{
//						parent = subleft;
//						subleft = subleft->_left;
//					}
//					//将要删除节点的关键码赋值为其右子树的最左节点的关键码
//					cur->_key = subleft->_key;
//					//将右子树的最左节点赋给要删除的节点
//					del = subleft;
//					if (parent->_left == subleft)
//					{
//						parent->_left = subleft->_right;
//					}
//					else
//					{
//						parent->_right = subleft->_left;
//					}
//				}
//				delete del;
//				return true;
//			}
//		}
//	}
//	const Node* Find(const K& k)//迭代法在搜索二叉树中查找节点
//	{
//		Node* cur = _root;
//		//开始遍历查找
//		while (cur)
//		{
//			if (cur->_key > k)
//			{
//				cur = cur->_left;
//			}
//			else if(cur->_key < k)
//			{
//				cur = cur->_right;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//		return NULL;
//	}
//	
//	void InOrder()//中序遍历搜索二叉树
//	{
//		_InOrder(_root);
//		cout<<endl;
//	}
//	bool InsertR(const K& k)//递归在搜索二叉树中插入节点
//	{
//		return _InsertR(_root,k);
//	}
//	bool RemoveR(const K& k)//递归删除搜索二叉树的某节点
//	{
//		return _RemoveR(_root,k);
//	}
//	const Node* FindR(const K& k)//递归在搜索二叉树中查找节点
//	{
//		return _FindR(_root,k);
//	}
//protected:
//	bool _InsertR(Node*& root,const K& k)
//	{
//		//空树
//		if (NULL == root)
//		{
//			root = new Node(k);
//			return true;
//		}
//		if (root->_key > k)
//		{
//			return _InsertR(root->_left,k);
//		}
//		else if (root->_key < k)
//		{
//			return _InsertR(root->_right,k);
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool _RemoveR(Node*& root,const K& k)
//	{
//		if (NULL == root)
//		{
//			return false;
//		}
//		Node* cur = root;
//		Node* parent = NULL;
//		Node* del = NULL;
//		while(cur)
//		{
//			if (cur->_key > k)
//			{
//				return _RemoveR(cur->_left,k);
//			}
//			else if (cur->_key < k)
//			{
//				return _RemoveR(cur->_right,k);
//			}
//			else
//			{
//				del = cur;
//				//左子树为空
//				if (NULL == cur->_left)
//				{
//					if (NULL == parent)
//					{
//						root = cur->_right;
//					}
//					else
//					{
//						cur = cur->_right;
//					}
//				}
//				//右子树为空
//				else if (NULL == cur->_right)
//				{
//					if (NULL == parent)
//					{
//						root = cur->_left;
//					}
//					cur = cur->_left;
//				}
//				//左子树和右子树都不为空，替换法删除节点
//				//(将要删除的节点值赋值为其左子树的最右节点或右子树的最左节点,删除最左或最右节点)
//				else
//				{
//					parent = cur;
//					Node* subleft = cur->_right;//右子树的最左节点
//					while (subleft->_left)
//					{
//						parent = subleft;
//						subleft = subleft->_left;
//					}
//					cur->_key = subleft->_key;
//					del = subleft;
//					if (parent->_left == subleft)
//					{
//						parent->_left = subleft->_right;
//					}
//					else
//					{
//						parent->_right = subleft->_left;
//					}
//				}
//				delete del;
//				return true;
//			}
//		}
//		return false;
//	}
//	const Node* _FindR(Node*& root,const K& k)//递归查找二叉搜索树的
//	{
//		//空树
//		if (NULL == root)
//		{
//			return NULL;
//		}
//		
//		Node* cur = root;
//		while (cur)
//		{
//			if (cur->_key > k)
//			{
//				return _FindR(cur->_left,k);
//			}
//			else if (cur->_key < k)
//			{
//				return _FindR(cur->_right,k);
//			}
//			else
//			{
//				return cur;
//			}
//		}
//		return false;
//	}
//	void _InOrder(Node* root)
//	{
//		if (root == NULL)
//		{
//			return;
//		}
//		
//		_InOrder(root->_left);
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//	}
//	void _Destroy(Node* root)
//	{
//		if (NULL == root)
//		{
//			return;
//		}
//		_Destroy(root->_left);
//		_Destroy(root->_right);
//		delete root;
//	}
//protected:
//	Node* _root;
//};
//
//void TestBSTree()
//{
//	////迭代法测试
//	//BSTree<int> bs;
//	//bs.Insert(5);
//	//bs.Insert(3);
//	//bs.Insert(4);
//	//bs.Insert(1);
//	//bs.Insert(7);
//	//bs.Insert(8);
//	//bs.Insert(5);
//	//bs.Insert(2);
// //   bs.Insert(6);
//	//bs.Insert(0);
//	//bs.Insert(9);
//	//
//	//cout<<bs.Find(5)->_key<<endl;
//	//cout<<bs.Find(6)->_key<<endl;
// //   bs.Find(20);
//
//	//bs.Remove(1);
//	//bs.InOrder();
//	//bs.Remove(5);
//	//bs.InOrder();
//	//bs.Remove(3);
//	//bs.InOrder();
//	//bs.Remove(6);
//	//bs.InOrder();
//	//bs.Remove(2);
//	//bs.InOrder();
//
//	//递归测试
//	BSTree<int> bs1;
//	bs1.InsertR(5);
//	bs1.InsertR(3);
//	bs1.InsertR(4);
//	bs1.InsertR(1);
//	bs1.InsertR(7);
//	bs1.InsertR(8);
//	bs1.InsertR(5);
//	bs1.InsertR(2);
//	bs1.InsertR(6);
//	bs1.InsertR(0);
//	bs1.InsertR(9);
//	bs1.InOrder();
//
//	cout<<bs1.FindR(5)->_key<<endl;
//	cout<<bs1.FindR(6)->_key<<endl;
//	bs1.FindR(20);
//
//	bs1.RemoveR(1);
//	bs1.InOrder();
//	bs1.RemoveR(5);
//	bs1.InOrder();
//	bs1.RemoveR(3);
//	bs1.InOrder();
//	bs1.RemoveR(6);
//	bs1.InOrder();
//	bs1.RemoveR(2);
//	bs1.InOrder();
//	bs1.RemoveR(0);
//	bs1.InOrder();
//	bs1.RemoveR(4);
//	bs1.InOrder();
//	bs1.RemoveR(7);
//	bs1.InOrder();
//}

int main()
{
	//TestBSTree();
	//Test();
	TestRBTree();
	system("pause");
	return 0;
}