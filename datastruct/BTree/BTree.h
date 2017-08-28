#pragma  once

template <class K,class V,int M = 3>
struct BTreeNode
{
	pair<K,V> _kvs[M];       //ֵ������
	BTreeNode<K,V>* _subs[M]; //����������
	BTreeNode<K,V>* _parent;  //����
	
	int _size;             //ֵ(kv)�ĸ���

	BTreeNode()
		:_parent(NULL)
		,_size(0)
	{
		for (int i = 0; i < M+1; ++i)
		{
			_kvs[i].first = K();
			_kvs[i].second = V();

			_subs[i] = NULL;
		}
		_subs[M] = NULL;
	}
};

template <class K,class V,int M = 3>
class BTree
{
	typedef BTreeNode<K,V> Node;
public:
	BTree()
		:_root(NULL)
	{}
	pair<Node*,int> Find(const K& key)
	{
		Node* cur = _root;
		Node* parent = NULL;

		while(cur)
		{
			int i = 0;
			while(i < cur->_size)
			{
				if (cur->_kvs[i].first == key)
				{ 
					return make_pair(cur,i);
				}
				else if (cur->_kvs[i].first > key)
				{
					break;
				}
				else
				{
					++i;
				}
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return make_pair(parent,-1);
	}
	bool Insert(const pair<K,V>& kv)
	{
		//��ǰ��Ϊ������ֱ�Ӳ���ڵ�
		if (NULL == _root)
		{
			_root = new Node;
			_root->_kvs[0] = kv;
			_root->_size = 1;

			return true;
		}
		//�鿴Ҫ����Ľڵ��Ƿ��Ѿ�����
		pair<Node*,int> ret = Find(kv.first);

		if (ret.second != -1)//˵������Ľڵ��Ѿ�����
		{
			return false;
		} 

		Node* cur = ret.first;//˵��Ҫ����Ľڵ㲻����
		pair<K,V> newKV = kv;
		Node* sub = NULL;

		while(1)
		{
			//��curλ�ò���newKV��sub
			_InsertKV(cur,newKV,sub);

			//���curû����˵������ɹ�
			if (cur->_size < M)
			{
				return true;
			}
			
			//����
			int mid = M/2;
			Node* tmp = new Node;
			int j = 0;
			int i = mid + 1;

			for (; i < cur->_size; ++i)
			{
				tmp->_kvs[j] = cur->_kvs[i];//����kv
				tmp->_subs[j] = cur->_subs[i];//���ƺ���

				if (cur->_subs[i])
				{
					cur->_subs[i]->_parent = tmp;
				}

				cur->_kvs[i] = pair<K,V>();
				cur->_subs[i] = NULL;
				tmp->_size++;
				++j;
			}

			//�������һ���Һ���
			tmp->_subs[j] = cur->_subs[i];
			if (cur->_subs[i])
			{
				cur->_subs[i]->_parent = tmp;
			}
			cur->_subs[i] = NULL;

			cur->_size = cur->_size - tmp->_size - 1;

			//������kv��tmp�����ڵ����
			if (NULL == cur->_parent)//curΪ���ڵ�
			{
				_root = new Node;
				_root->_kvs[0] = cur->_kvs[mid];
				cur->_kvs[mid] = pair<K,V>();

				_root->_size = 1;

				_root->_subs[0] = cur;
				_root->_subs[1] = tmp;
				cur->_parent = _root;
				tmp->_parent = _root;

				return true;
			}
			else//û�з��ѵ����ڵ�
			{
				newKV = cur->_kvs[mid];
				sub = tmp;
				cur->_kvs[mid] = pair<K,V>();

				cur = cur->_parent;
			}
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}

protected:
	void _InsertKV(Node* cur,pair<K,V>& newKV,Node* sub)
	{
		int i = cur->_size - 1;

		while(i >= 0)
		{
			//Ҫ�����keyֵ�ȵ�ǰ�ؼ�ֵ��ֱ�Ӳ���
			if (cur->_kvs[i].first < newKV.first)
			{
				break;
			} 
			else
			{
				cur->_kvs[i+1] = cur->_kvs[i];
				cur->_subs[i+2] = cur->_subs[i+1];

				--i;
			}
		}
		cur->_kvs[i+1].first = newKV.first;
		cur->_subs[i+2] = sub;

		if (sub)
			sub->_parent = cur;

		cur->_size++;
	}
	void _InOrder(Node* root)
	{
		if (NULL == root)
		{
			return;
		}
		int i = 0;
		for (; i < root->_size; ++i)
		{
			_InOrder(root->_subs[i]);
			cout<<root->_kvs[i].first<<":"<<root->_kvs[i].second<<endl;
		}
		_InOrder(root->_subs[i]);
	}
protected:
	Node* _root;
};

void TestBtree()
{
	BTree<int, int> t;
	int a[] = {53, 75, 139, 49, 145, 36, 101};
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
	{
		t.Insert(make_pair(a[i], i));
	}

	t.InOrder();
}
