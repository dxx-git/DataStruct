#include <iostream>
using namespace std;
#include "binary_search_tree.h"
#include "RBTree.h"
//
//template <class K>
//struct BinarySearchTreeNode
//{
//	K _key;//�ڵ�Ĺؼ���
//	BinarySearchTreeNode<K>* _left;//�ڵ������
//	BinarySearchTreeNode<K>* _right;//�ڵ���Һ���
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
//	bool Insert(const K& k)//�������������������в���ڵ�
//	{
//		if (NULL == _root)
//		{
//			_root = new Node(k);
//			return true;
//		}
//		Node* cur = _root;
//		Node* parent = NULL;
//		//Ѱ�Ҳ���ڵ�ĺ���λ��
//		while (cur)
//		{
//			//Ҫ����ڵ�Ĺؼ���С�ڵ�ǰ�ڵ�Ĺؼ��룬��ǰ�ڵ��������Ѱ��
//			if (k < cur->_key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			//Ҫ����ڵ�Ĺؼ�����ڵ�ǰ�ڵ�Ĺؼ��룬��ǰ�ڵ��������Ѱ��
//			else if (k > cur->_key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			//Ҫ����ڵ�Ĺؼ�����ڵ�ǰ�ڵ�Ĺؼ��룬������ȷλ�ã�ֱ�ӷ���
//			else
//			{
//				return false;
//			}
//		}
//		//���ҵ�����λ���Ժ��жϲ��븸�׽ڵ����߻����ұ�
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
//	bool Remove(const K& k)//������ɾ��������������ĳ�ڵ�
//	{
//		//����
//		if (NULL == _root)
//		{
//			return false;
//		}
//		Node* cur = _root;
//		Node* parent = NULL;
//		Node* del = NULL;
//		//Ѱ��Ҫɾ���Ľڵ�λ��
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
//			//�ҵ���Ҫɾ���Ľڵ������������������Ϊ�ա�������Ϊ�ա�������������Ϊ��
//			else
//			{
//				del = cur;
//				//������Ϊ��
//				if (NULL == cur->_left)
//				{
//					//ע���жϸ��ڵ��Ƿ�Ϊ�գ���Ϊ�գ���Ҫɾ���Ľڵ�Ϊ���ڵ�
//					if (NULL == parent)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						//�жϵ�ǰ�ڵ��Ǹ��ڵ�����ӻ����Һ���
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
//				//������Ϊ��
//				else if (NULL == cur->_right)
//				{
//					//ע���жϸ��ڵ��Ƿ�Ϊ�գ���Ϊ�գ���Ҫɾ���Ľڵ�Ϊ���ڵ�
//					if (NULL == parent)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						//�жϵ�ǰ�ڵ��Ǹ��ڵ�����ӻ����Һ���
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
//				//������������Ϊ��
//				else
//				{
//					parent = cur;
//					//��������������ڵ�
//					Node* subleft = cur->_right;
//					while (subleft->_left)
//					{
//						parent = subleft;
//						subleft = subleft->_left;
//					}
//					//��Ҫɾ���ڵ�Ĺؼ��븳ֵΪ��������������ڵ�Ĺؼ���
//					cur->_key = subleft->_key;
//					//��������������ڵ㸳��Ҫɾ���Ľڵ�
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
//	const Node* Find(const K& k)//�������������������в��ҽڵ�
//	{
//		Node* cur = _root;
//		//��ʼ��������
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
//	void InOrder()//�����������������
//	{
//		_InOrder(_root);
//		cout<<endl;
//	}
//	bool InsertR(const K& k)//�ݹ��������������в���ڵ�
//	{
//		return _InsertR(_root,k);
//	}
//	bool RemoveR(const K& k)//�ݹ�ɾ��������������ĳ�ڵ�
//	{
//		return _RemoveR(_root,k);
//	}
//	const Node* FindR(const K& k)//�ݹ��������������в��ҽڵ�
//	{
//		return _FindR(_root,k);
//	}
//protected:
//	bool _InsertR(Node*& root,const K& k)
//	{
//		//����
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
//				//������Ϊ��
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
//				//������Ϊ��
//				else if (NULL == cur->_right)
//				{
//					if (NULL == parent)
//					{
//						root = cur->_left;
//					}
//					cur = cur->_left;
//				}
//				//������������������Ϊ�գ��滻��ɾ���ڵ�
//				//(��Ҫɾ���Ľڵ�ֵ��ֵΪ�������������ҽڵ��������������ڵ�,ɾ����������ҽڵ�)
//				else
//				{
//					parent = cur;
//					Node* subleft = cur->_right;//������������ڵ�
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
//	const Node* _FindR(Node*& root,const K& k)//�ݹ���Ҷ�����������
//	{
//		//����
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
//	////����������
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
//	//�ݹ����
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