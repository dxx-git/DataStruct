#pragma  once
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include <queue>
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
	void PrevOrder()  //前序遍历
	{
		_PrevOrder(_root);
		cout<<"null"<<endl;
	}
	bool Find(const T& data)      //判断一个值为的节点是否在当前二叉树中
	{
		return _Find(_root,data);
	}
	Node* sameAncester(Node* n1,Node* n2)      //求两个节点的最近公共祖先
	{
		//return _sameAncester1(_root,n1,n2);
		//return _sameAncester2(_root,n1,n2);
		return _sameAncester3(_root,n1,n2);
	}
	int Depth()   //求二叉树的深度
	{
		return _Depth(_root);
	}
	int RemoteDistance()   //求二叉树中最远的两个节点的距离
	{
		int tmp = 0;
		return _RemoteDistance1(_root,tmp);
	}
	Node* Rebuild(T* prevOrder,T* inOrder,int n) //根据前序序列和中序序列重建二叉树
	{
		assert(prevOrder && inOrder);

		int prevIndex = 0;   //指向前序序列指针的下标
		int inBegin = 0;     //中序序列的首位置的下标
		int inEnd = n-1;     //中序序列的末位置的下标(闭区间)

		_root = _Rebuild(prevOrder,prevIndex,inOrder,inBegin,inEnd,n);
		return _root;
	}
	bool IsCompleteBT()//判断一棵树是否是完全二叉树
	{
		bool flag = true;//判断一棵子树是否为一棵完全二叉树的标记
		queue<Node*> q;  //运用队列进行层序遍历
		q.push(_root);

		while(!q.empty())
		{
			Node* front = q.front();//保存队首节点
			q.pop();               //将队首元素出队
			
			/*如果队首元素的左树为空，将标志置为false,如果层序遍历\
			 \后面的节点还有子树，说明不是完全二叉树*/
			if (NULL == front->_left)
			{
				flag = false;
			}
			else
			{
				/*如果flag为假，说明之前已经有节点的孩子为空，又因当前\
				\节点的左孩子不为空，说明不是完全二叉树*/
				if (flag == false)
				{
					return false;
				}
				q.push(front->_left);//继续向后探索
			}

			/*如果队首元素的右树为空，将标志置为false,如果层序遍历\
			 \后面的节点还有子树，说明不是完全二叉树*/
			if (NULL == front->_right)
			{
				flag = false;
			}
			else
			{
				/*如果flag为假，说明之前已经有节点的孩子为空，又因当前\
				\节点的右孩子不为空，说明不是完全二叉树*/
				if (flag == false)
				{
					return false;
				}
				q.push(front->_right);//继续向后探索
			}
		}
		return true;//能走到这里说明一定是完全二叉树
	}
	void GetMirrorTree()//求二叉树的镜像
	{
		_GetMirrorTree(_root);
	}
	void MakeSearchToList()/*将二叉搜索树转换成一个排序的双向链表。\
							要求不能创建任何新的结点，只能调整树中结点指针的指向。*/
	{
		Node* cur = _root;
		//寻找最左节点
		while (cur->_left)
		{
			cur = cur->_left;
		}
		
		Node* prev = NULL;
		_MakeSearchToList1(_root,prev);
		//_MakeSearchToList2(_root);
		
		while(cur)//打印链表(树的结构变了之后析构会死循环)
		{
			cout<<cur->_data<<"<->";
			cur = cur->_right;
		}
		cout<<"null";
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
	void _PrevOrder(Node* root)
	{
		if (NULL == root)
		{
			return;
		}

		cout<<root->_data<<"->";//打印当前节点
		_PrevOrder(root->_left);//递归遍历左子树
		_PrevOrder(root->_right);//递归遍历右子树
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
	bool _GetPath3(Node* root,Node* cur,vector<Node*>& v)
	{
		if (NULL == root || NULL == cur)//树为空
			return false;
		v.push_back(root);
	
		if (cur->_data == root->_data)  //找到路径
		{
			return true;
		}
		else
		{
			bool ret = false;
			if (root->_left && !ret)//在左子树中找路径
			{
				ret = _GetPath3(root->_left,cur,v);
			}
			if (root->_right && !ret)//在右子树中找路径
			{
				ret = _GetPath3(root->_right,cur,v);
			}
			if (ret == false && v.size() != 0)//如果不是正确路径上的节点，就去除该节点
			{
				v.pop_back();
			}
			return ret;
		}
	}
	Node* _sameAncester3(Node*& root,Node* n1,Node* n2)
	{
		//树为空
		if (NULL == root)
		{
			return NULL;
		}

		//定义容器
		vector<Node*> v1;
		vector<Node*> v2;
		
		//用容器v1和v2分别保存节点n1和节点n2的路径
		_GetPath3(root,n1,v1);
		_GetPath3(root,n2,v2);
		
		////从下往上找
		////定义指向查找节点的迭代器指针
		//vector<Node*>::iterator it1 = --v1.end();
		//vector<Node*>::iterator it2 = --v2.end();
		////将多余的路径节点删除掉
		//while(v1.size() > v2.size())
		//{
		//	--it1;          //相应的迭代器要向前移
		//	v1.pop_back();
		//}
		//while(v2.size() > v1.size())
		//{
		//	--it2;          //相应的迭代器要向前移
		//	v2.pop_back();
		//}

		////找v1与v2中不同的节点
		//while(it1 >= v1.begin() && it2 >= v2.begin())
		//{
		//	if (*it1 == *it2)
		//	{
		//		return *it1;
		//	}
		//	--it1;
		//	--it2;
		//}

		//从上往下找
		//定义指向查找节点的迭代器指针
		vector<Node*>::iterator it1 = v1.begin();
		vector<Node*>::iterator it2 = v2.begin();
		//找v1与v2中不同的节点
		while(it1 != v1.end() && it2 != v2.end())
		{
			if (*it1 != *it2)//找到第一个不相同的节点，返回前一个节点
			{
				return *(--it1);
			}
			++it1;
			++it2;
		}
		//处理特殊情况，例如：v1:1->2->3    v2:1->2
		if (it1 == v1.end() || it2 == v2.end())
			return *(--it1);

	    return NULL;
	}
	int _Depth(Node* root)
	{
		if (NULL == root)
		{
			return 0;
		}
		return _Depth(root->_left)>_Depth(root->_right)?_Depth(root->_left)+1:_Depth(root->_right)+1;
	}
	int _RemoteDistance1(Node* root,int& distance)
	{
		if (NULL == root)
		{
			return 0;
		}
		int tmp = _Depth(root->_left)+_Depth(root->_right);//递归去求每棵子树的最远距离
		
		if (distance < tmp)//用全局变量保存每棵子树的最远距离，并不断更新
		{
			distance = tmp;
		}
		return distance;
	}
	Node* _Rebuild(T* prevOrder,int& prevIndex,T* inOrder,int inBegin,int inEnd,int n)
	{
		Node* root = NULL;
		if (prevIndex < n)//当前序序列的下标<n时才创建新结点
		{
			root = new Node(prevOrder[prevIndex]);
		}
		if (NULL == root)//递归的返回条件
		{
			return NULL;
		}

		if (inBegin == inEnd)//要重建树中只有一个节点
		{
			return root;
		}
		else
		{
			//在中序序列中找到前序序列中的根
			int i = inBegin;
			for ( ; i <= inEnd; ++i)
			{
				if (prevOrder[prevIndex] == inOrder[i])
					break;
			}

			if (i > inEnd)//说明中序序列中没找到前序序列中的根，所给序列不匹配
			{
				throw invalid_argument("所给序列不匹配！");//直接抛异常
			}
			
			//将根节点作为分割线，将区间分为左右两部分，分别递归重建左右子树
			root->_left = _Rebuild(prevOrder,++prevIndex,inOrder,inBegin,i-1,n);
			root->_right = _Rebuild(prevOrder,++prevIndex,inOrder,i+1,inEnd,n);

			return root;
		}
	}
	void _GetMirrorTree(Node* root)//求二叉树的镜像
	{
		if (NULL == root)
		{
			return;
		}
		swap(root->_left,root->_right);//交换左右子树
		_GetMirrorTree(root->_left); //递归遍历左子树
		_GetMirrorTree(root->_right);//递归遍历右子树
	}
	void _MakeSearchToList1(Node* root,Node*& prev)
	{
		if (NULL == root)//如果当前树为空，则直接返回
			return;

		_MakeSearchToList1(root->_left,prev);//递归左子树
		
		//进行转换
		root->_left = prev;//root第一次指向最左节点
		if (prev)//如果上一个节点不为空，就将上一个节点的右指针指向当前节点root
		{
			prev->_right = root;
		}
		prev = root;//更新保存上一个节点

		_MakeSearchToList1(root->_right,prev);//递归右子树
	}
	void _InOrderList(Node* root,queue<Node*>& q)//将树的中序遍历的节点入到队列中
	{
		if (NULL == root)
			return;
		_InOrderList(root->_left,q);//递归左子树
		q.push(root);              //将当前节点入队
		_InOrderList(root->_right,q);//递归右子树
	}
	void _MakeSearchToList2(Node* root)
	{
		if (NULL == root)//如果当前树为空则直接返回
			return;

		queue<Node*> q;
		_InOrderList(root,q);//将所给树的中序序列push到队列q中
		
		Node* head = q.front();//将队首节点（即所给树的最左节点）保存起来
		q.pop();

		head->_left = NULL;//将队首节点的左指针置空
		Node* prev = head;//用prev保存当前节点
		
		while(!q.empty())//当队列不空时进入循环
		{
			Node* front = q.front();//获取队首节点
			q.pop();               //将队首节点出队
			
			prev->_right = front;   //将前一个节点的右指针指向队首节点
			front->_left = prev;    //将队首节点的左指针指向上一个节点

			front->_right = NULL;   //将队首节点的右指针置空
			prev = front;          //更新保存上一个节点
		}
	}
private:
	Node* _root;               //根节点
};


void Test()
{
	int a1[] = {1,2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#',8};
	int a2 [10] = {1, 2, 3, '#', '#', 4, '#' , '#', 5, 6};
	size_t n1 = sizeof(a1)/sizeof(a1[0]);
	size_t n2 = sizeof(a2)/sizeof(a2[0]);

	BinaryTree<int> bt1(a1,n1,'#');
	BinaryTree<int> bt2(a2,n2,'#');
	//cout<<"2:"<<bt1.Find(2)<<endl;
	//cout<<"9:"<<bt1.Find(9)<<endl;
	//cout<<"7:"<<bt2.Find(7)<<endl;
	//cout<<"6:"<<bt2.Find(6)<<endl;

	//cout<<bt1.sameAncester(new TreeNode<int>(3),new TreeNode<int>(8))->_data<<endl;//不同子树
	//cout<<bt1.sameAncester(new TreeNode<int>(3),new TreeNode<int>(2))->_data<<endl;//左边
	//cout<<bt1.sameAncester(new TreeNode<int>(8),new TreeNode<int>(7))->_data<<endl;//右边
	//cout<<bt1.sameAncester(new TreeNode<int>(1),new TreeNode<int>(3))->_data<<endl;//其中一个是根

	/*cout<<"bt1->depth:"<<bt1.Depth()<<endl;
	cout<<"bt1->depth:"<<bt2.Depth()<<endl;
	cout<<"bt1->remoteDistance:"<<bt1.RemoteDistance()<<endl;
	cout<<"bt2->remoteDistance:"<<bt2.RemoteDistance()<<endl;*/

	//bt1.PrevOrder();
	//int prev[] = {1,2,3,4,5,6};//前序序列
	//int in[] = {3,2,4,1,6,5};//中序序列
	//int size = sizeof(prev)/sizeof(prev[0]);
	//BinaryTree<int> bt3;
	//bt3.Rebuild(prev,in,size);
	//bt3.PrevOrder();

	cout<<"bt1:IsCompleteBT?"<<bt1.IsCompleteBT()<<endl;
	cout<<"bt2:IsCompleteBT?"<<bt2.IsCompleteBT()<<endl;
	
	bt1.GetMirrorTree();
	bt1.PrevOrder();
	bt1.GetMirrorTree();

	//int a3 [] = {5, 3, 2, '#', '#', 4, '#' , '#', 7, 6};//构造一棵二叉搜索树
	//size_t n3 = sizeof(a3)/sizeof(a3[0]);
	//BinaryTree<int> bt3(a3,n3,'#');
	//bt3.MakeSearchToList();
}