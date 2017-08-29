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
	void PrevOrder()  //ǰ�����
	{
		_PrevOrder(_root);
		cout<<"null"<<endl;
	}
	bool Find(const T& data)      //�ж�һ��ֵΪ�Ľڵ��Ƿ��ڵ�ǰ��������
	{
		return _Find(_root,data);
	}
	Node* sameAncester(Node* n1,Node* n2)      //�������ڵ�������������
	{
		//return _sameAncester1(_root,n1,n2);
		//return _sameAncester2(_root,n1,n2);
		return _sameAncester3(_root,n1,n2);
	}
	int Depth()   //������������
	{
		return _Depth(_root);
	}
	int RemoteDistance()   //�����������Զ�������ڵ�ľ���
	{
		int tmp = 0;
		return _RemoteDistance1(_root,tmp);
	}
	Node* Rebuild(T* prevOrder,T* inOrder,int n) //����ǰ�����к����������ؽ�������
	{
		assert(prevOrder && inOrder);

		int prevIndex = 0;   //ָ��ǰ������ָ����±�
		int inBegin = 0;     //�������е���λ�õ��±�
		int inEnd = n-1;     //�������е�ĩλ�õ��±�(������)

		_root = _Rebuild(prevOrder,prevIndex,inOrder,inBegin,inEnd,n);
		return _root;
	}
	bool IsCompleteBT()//�ж�һ�����Ƿ�����ȫ������
	{
		bool flag = true;//�ж�һ�������Ƿ�Ϊһ����ȫ�������ı��
		queue<Node*> q;  //���ö��н��в������
		q.push(_root);

		while(!q.empty())
		{
			Node* front = q.front();//������׽ڵ�
			q.pop();               //������Ԫ�س���
			
			/*�������Ԫ�ص�����Ϊ�գ�����־��Ϊfalse,����������\
			 \����Ľڵ㻹��������˵��������ȫ������*/
			if (NULL == front->_left)
			{
				flag = false;
			}
			else
			{
				/*���flagΪ�٣�˵��֮ǰ�Ѿ��нڵ�ĺ���Ϊ�գ�����ǰ\
				\�ڵ�����Ӳ�Ϊ�գ�˵��������ȫ������*/
				if (flag == false)
				{
					return false;
				}
				q.push(front->_left);//�������̽��
			}

			/*�������Ԫ�ص�����Ϊ�գ�����־��Ϊfalse,����������\
			 \����Ľڵ㻹��������˵��������ȫ������*/
			if (NULL == front->_right)
			{
				flag = false;
			}
			else
			{
				/*���flagΪ�٣�˵��֮ǰ�Ѿ��нڵ�ĺ���Ϊ�գ�����ǰ\
				\�ڵ���Һ��Ӳ�Ϊ�գ�˵��������ȫ������*/
				if (flag == false)
				{
					return false;
				}
				q.push(front->_right);//�������̽��
			}
		}
		return true;//���ߵ�����˵��һ������ȫ������
	}
	void GetMirrorTree()//��������ľ���
	{
		_GetMirrorTree(_root);
	}
	void MakeSearchToList()/*������������ת����һ�������˫������\
							Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��*/
	{
		Node* cur = _root;
		//Ѱ������ڵ�
		while (cur->_left)
		{
			cur = cur->_left;
		}
		
		Node* prev = NULL;
		_MakeSearchToList1(_root,prev);
		//_MakeSearchToList2(_root);
		
		while(cur)//��ӡ����(���Ľṹ����֮����������ѭ��)
		{
			cout<<cur->_data<<"<->";
			cur = cur->_right;
		}
		cout<<"null";
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
	void _PrevOrder(Node* root)
	{
		if (NULL == root)
		{
			return;
		}

		cout<<root->_data<<"->";//��ӡ��ǰ�ڵ�
		_PrevOrder(root->_left);//�ݹ����������
		_PrevOrder(root->_right);//�ݹ����������
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
	bool _GetPath3(Node* root,Node* cur,vector<Node*>& v)
	{
		if (NULL == root || NULL == cur)//��Ϊ��
			return false;
		v.push_back(root);
	
		if (cur->_data == root->_data)  //�ҵ�·��
		{
			return true;
		}
		else
		{
			bool ret = false;
			if (root->_left && !ret)//������������·��
			{
				ret = _GetPath3(root->_left,cur,v);
			}
			if (root->_right && !ret)//������������·��
			{
				ret = _GetPath3(root->_right,cur,v);
			}
			if (ret == false && v.size() != 0)//���������ȷ·���ϵĽڵ㣬��ȥ���ýڵ�
			{
				v.pop_back();
			}
			return ret;
		}
	}
	Node* _sameAncester3(Node*& root,Node* n1,Node* n2)
	{
		//��Ϊ��
		if (NULL == root)
		{
			return NULL;
		}

		//��������
		vector<Node*> v1;
		vector<Node*> v2;
		
		//������v1��v2�ֱ𱣴�ڵ�n1�ͽڵ�n2��·��
		_GetPath3(root,n1,v1);
		_GetPath3(root,n2,v2);
		
		////����������
		////����ָ����ҽڵ�ĵ�����ָ��
		//vector<Node*>::iterator it1 = --v1.end();
		//vector<Node*>::iterator it2 = --v2.end();
		////�������·���ڵ�ɾ����
		//while(v1.size() > v2.size())
		//{
		//	--it1;          //��Ӧ�ĵ�����Ҫ��ǰ��
		//	v1.pop_back();
		//}
		//while(v2.size() > v1.size())
		//{
		//	--it2;          //��Ӧ�ĵ�����Ҫ��ǰ��
		//	v2.pop_back();
		//}

		////��v1��v2�в�ͬ�Ľڵ�
		//while(it1 >= v1.begin() && it2 >= v2.begin())
		//{
		//	if (*it1 == *it2)
		//	{
		//		return *it1;
		//	}
		//	--it1;
		//	--it2;
		//}

		//����������
		//����ָ����ҽڵ�ĵ�����ָ��
		vector<Node*>::iterator it1 = v1.begin();
		vector<Node*>::iterator it2 = v2.begin();
		//��v1��v2�в�ͬ�Ľڵ�
		while(it1 != v1.end() && it2 != v2.end())
		{
			if (*it1 != *it2)//�ҵ���һ������ͬ�Ľڵ㣬����ǰһ���ڵ�
			{
				return *(--it1);
			}
			++it1;
			++it2;
		}
		//����������������磺v1:1->2->3    v2:1->2
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
		int tmp = _Depth(root->_left)+_Depth(root->_right);//�ݹ�ȥ��ÿ����������Զ����
		
		if (distance < tmp)//��ȫ�ֱ�������ÿ����������Զ���룬�����ϸ���
		{
			distance = tmp;
		}
		return distance;
	}
	Node* _Rebuild(T* prevOrder,int& prevIndex,T* inOrder,int inBegin,int inEnd,int n)
	{
		Node* root = NULL;
		if (prevIndex < n)//��ǰ�����е��±�<nʱ�Ŵ����½��
		{
			root = new Node(prevOrder[prevIndex]);
		}
		if (NULL == root)//�ݹ�ķ�������
		{
			return NULL;
		}

		if (inBegin == inEnd)//Ҫ�ؽ�����ֻ��һ���ڵ�
		{
			return root;
		}
		else
		{
			//�������������ҵ�ǰ�������еĸ�
			int i = inBegin;
			for ( ; i <= inEnd; ++i)
			{
				if (prevOrder[prevIndex] == inOrder[i])
					break;
			}

			if (i > inEnd)//˵������������û�ҵ�ǰ�������еĸ����������в�ƥ��
			{
				throw invalid_argument("�������в�ƥ�䣡");//ֱ�����쳣
			}
			
			//�����ڵ���Ϊ�ָ��ߣ��������Ϊ���������֣��ֱ�ݹ��ؽ���������
			root->_left = _Rebuild(prevOrder,++prevIndex,inOrder,inBegin,i-1,n);
			root->_right = _Rebuild(prevOrder,++prevIndex,inOrder,i+1,inEnd,n);

			return root;
		}
	}
	void _GetMirrorTree(Node* root)//��������ľ���
	{
		if (NULL == root)
		{
			return;
		}
		swap(root->_left,root->_right);//������������
		_GetMirrorTree(root->_left); //�ݹ����������
		_GetMirrorTree(root->_right);//�ݹ����������
	}
	void _MakeSearchToList1(Node* root,Node*& prev)
	{
		if (NULL == root)//�����ǰ��Ϊ�գ���ֱ�ӷ���
			return;

		_MakeSearchToList1(root->_left,prev);//�ݹ�������
		
		//����ת��
		root->_left = prev;//root��һ��ָ������ڵ�
		if (prev)//�����һ���ڵ㲻Ϊ�գ��ͽ���һ���ڵ����ָ��ָ��ǰ�ڵ�root
		{
			prev->_right = root;
		}
		prev = root;//���±�����һ���ڵ�

		_MakeSearchToList1(root->_right,prev);//�ݹ�������
	}
	void _InOrderList(Node* root,queue<Node*>& q)//��������������Ľڵ��뵽������
	{
		if (NULL == root)
			return;
		_InOrderList(root->_left,q);//�ݹ�������
		q.push(root);              //����ǰ�ڵ����
		_InOrderList(root->_right,q);//�ݹ�������
	}
	void _MakeSearchToList2(Node* root)
	{
		if (NULL == root)//�����ǰ��Ϊ����ֱ�ӷ���
			return;

		queue<Node*> q;
		_InOrderList(root,q);//������������������push������q��
		
		Node* head = q.front();//�����׽ڵ㣨��������������ڵ㣩��������
		q.pop();

		head->_left = NULL;//�����׽ڵ����ָ���ÿ�
		Node* prev = head;//��prev���浱ǰ�ڵ�
		
		while(!q.empty())//�����в���ʱ����ѭ��
		{
			Node* front = q.front();//��ȡ���׽ڵ�
			q.pop();               //�����׽ڵ����
			
			prev->_right = front;   //��ǰһ���ڵ����ָ��ָ����׽ڵ�
			front->_left = prev;    //�����׽ڵ����ָ��ָ����һ���ڵ�

			front->_right = NULL;   //�����׽ڵ����ָ���ÿ�
			prev = front;          //���±�����һ���ڵ�
		}
	}
private:
	Node* _root;               //���ڵ�
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

	//cout<<bt1.sameAncester(new TreeNode<int>(3),new TreeNode<int>(8))->_data<<endl;//��ͬ����
	//cout<<bt1.sameAncester(new TreeNode<int>(3),new TreeNode<int>(2))->_data<<endl;//���
	//cout<<bt1.sameAncester(new TreeNode<int>(8),new TreeNode<int>(7))->_data<<endl;//�ұ�
	//cout<<bt1.sameAncester(new TreeNode<int>(1),new TreeNode<int>(3))->_data<<endl;//����һ���Ǹ�

	/*cout<<"bt1->depth:"<<bt1.Depth()<<endl;
	cout<<"bt1->depth:"<<bt2.Depth()<<endl;
	cout<<"bt1->remoteDistance:"<<bt1.RemoteDistance()<<endl;
	cout<<"bt2->remoteDistance:"<<bt2.RemoteDistance()<<endl;*/

	//bt1.PrevOrder();
	//int prev[] = {1,2,3,4,5,6};//ǰ������
	//int in[] = {3,2,4,1,6,5};//��������
	//int size = sizeof(prev)/sizeof(prev[0]);
	//BinaryTree<int> bt3;
	//bt3.Rebuild(prev,in,size);
	//bt3.PrevOrder();

	cout<<"bt1:IsCompleteBT?"<<bt1.IsCompleteBT()<<endl;
	cout<<"bt2:IsCompleteBT?"<<bt2.IsCompleteBT()<<endl;
	
	bt1.GetMirrorTree();
	bt1.PrevOrder();
	bt1.GetMirrorTree();

	//int a3 [] = {5, 3, 2, '#', '#', 4, '#' , '#', 7, 6};//����һ�ö���������
	//size_t n3 = sizeof(a3)/sizeof(a3[0]);
	//BinaryTree<int> bt3(a3,n3,'#');
	//bt3.MakeSearchToList();
}