#pragma  once
#include <string>

 
typedef long long LongType;
//
struct CharInfo 
{
	char _ch;//�ַ�
	LongType _count;//�ַ����ֵĴ���
	string _code;//����������
};

template <class T>
//�ļ�ѹ��
class FileCompress
{ 
public:
	FileCompress()
	{
		size_t ch = 0;
		for (size_t i = 0; i < 256; ++i)
		{
			_infos[ch]._ch = i;
			_infos[ch]._count = 0;
		}
	}
	void Compress(const char* filename)//ѹ���ļ�
	{
		//1.ͳ���ַ����ֵĴ���
		FILE* fout = fopen("huffman.txt","w");
		assert(fout);
		
		char ch = fgetc(fout);

		while (ch != EOF)
		{
			_infos[ch]._count++;
			ch = fgetc(fout);
		}
		
		//2.��HuffmanTree
		HuffmanTree <CharInfo> tree(_infos,256);

		//3.���ɹ���������
		GetHuffmanTreeCode(tree);	
	}
	void UnCompress(const char* filename)//��ѹ��
	{

	} 

	void GetHuffmanTreeCode(HuffmanTreeNode<CharInfo>* root)
	{
		if (NULL == root)
		{
			return;
		}
		if (NULL == root->_left && NULL == root->_right)
		{
			HuffmanTreeNode<CharInfo>* cur = root;
			HuffmanTreeNode<CharInfo>* parent  = cur->_parent;

			string& code = _infos[root->_weight._ch]._code;
			
			while (parent)
			{
				if (cur == parent->_left)
				{
					code.push_back('0');
				}
				else
				{
					code.push_back('1');
				}
				cur = parent;
				parent = cur->_parent;
			}
			reverse(code.begin(),code.end());
				return;
		}
		GetHuffmanTreeCode(cur->_left);
		GetHuffmanTreeCode(cur->_right);
	}

protected:
	CharInfo _infos[256];
};


template <typename T>
struct HuffmanTreeNode
{
	T _weight;//Ȩֵ
	HuffmanTreeNode<T>* _left;//����
	HuffmanTreeNode<T>* _right;//�Һ���
	HuffmanTreeNode<T>* _parent;//˫��
	
	HuffmanTreeNode(const T& x)
		:_weight(x)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};

//��������
template <class T>
class HuffmanTree
{
public:
	typedef HuffmanTreeNode<T> Node;
	HuffmanTree()
		:_root(NULL)
	{}
	HuffmanTree(T* a,size_t n)//������û���ֵ��ַ�
	{
		_root = _CreatHuffmanTree(a,n);
	}
	HuffmanTree(T* a,size_t n,const T& invalid)
	{
		_root = _CreatHuffmanTree(a,n,invalid);
	}
	~HuffmanTree()
	{
		if (NULL == _root)
		{
			return;
		}
		_Destroy(_root);
		_root = NULL;
	}
protected:
	Node* _CreatHuffmanTree(T* a,size_t n)
	{
		struct Compare
		{
			bool operator()(Node* l,Node* r)//�Ƚϵ��ǽڵ��Ȩֵ
			{
				return l->_weight < r->_weight;
			}
		};

		Heap<Node*,Compare> hp;//��С��

		//ѡ����(�����ڵ㲢�������)
		for (size_t i = 0; i<n; ++i)
		{
			hp.Push(new Node(a[i]));
		}
		//ȡ��������С�Ľڵ���Ϊ���Һ��Ӳ������丸�ڵ�
		while (hp.Size > 1)//����ֻʣһ�����ݣ�˵��ֻʣ�¸��ڵ���
		{
			Node* left = hp.Top();//ȡ������С������
			hp.Pop();
			Node* right = hp.Top();//ȡ���д�С������
			hp.pop();
			Node* parent = new Node(left->_weight + right->_weight);
			//���Ͻڵ�֮��Ĺ�ϵ
			left->_parent = parent;
			right->_parent = parent;
			parent->_left = left;
			parent->_right = right;
			//��˫�׽ڵ������ӻض���
			hp.Push(parent);
		}
		_root = hp.Top();//����������������Ϊ���ڵ�
		hp.Pop();
		return _root;
	}
	Node* _CreatHuffmanTree(T* a,size_t n,const T& invalid)//invalid���˵�û���ֵ��ַ�
	{
		struct Compare
		{
			bool operator()(Node* l,Node* r)//�Ƚϵ��ǽڵ��Ȩֵ
			{
				return l->_weight < r->_weight;
			}
		};

		Heap <Node*,Compare> hp;//��С��

		//ѡ����(�����ڵ㲢�������)
		for (size_t i = 0; i<n; ++i)
		{
			if (a[i] != invalid)
			{
				hp.Push(new Node(a[i]));
			}
		}
		//ȡ��������С�Ľڵ���Ϊ���Һ��Ӳ������丸�ڵ�
		while (hp.Size > 1)//����ֻʣһ�����ݣ�˵��ֻʣ�¸��ڵ���
		{
			Node* left = hp.Top();//ȡ������С������
			hp.Pop();
			Node* right = hp.Top();//ȡ���д�С������
			hp.pop();
			Node* parent = new Node(left->_weight + right->_weight);
			//���Ͻڵ�֮��Ĺ�ϵ
			left->_parent = parent;
			right->_parent = parent;
			parent->_left = left;
			parent->_right = right;
			//��˫�׽ڵ������ӻض���
			hp.Push(parent);
		}
		_root = hp.Top();//����������������Ϊ���ڵ�
		hp.Pop();
		return _root;
	}
	void _Destroy(Node* root)
	{
		if (NULL == root)
		{
			return;
		}
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
		root = NULL;
	}

protected:
	Node* _root;
	HuffmanTree(const T& hf);//������
	HuffmanTree& operator=(HuffmanTree& hf);
};

void TestHuffmanTree()
{
	int a[4] = {1,2,3,4};
	HuffmanTree<int> hf(a,4);
}