#pragma  once
#include <string>

 
typedef long long LongType;
//
struct CharInfo 
{
	char _ch;//字符
	LongType _count;//字符出现的次数
	string _code;//哈弗曼编码
};

template <class T>
//文件压缩
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
	void Compress(const char* filename)//压缩文件
	{
		//1.统计字符出现的次数
		FILE* fout = fopen("huffman.txt","w");
		assert(fout);
		
		char ch = fgetc(fout);

		while (ch != EOF)
		{
			_infos[ch]._count++;
			ch = fgetc(fout);
		}
		
		//2.建HuffmanTree
		HuffmanTree <CharInfo> tree(_infos,256);

		//3.生成哈夫曼编码
		GetHuffmanTreeCode(tree);	
	}
	void UnCompress(const char* filename)//解压缩
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
	T _weight;//权值
	HuffmanTreeNode<T>* _left;//左孩子
	HuffmanTreeNode<T>* _right;//右孩子
	HuffmanTreeNode<T>* _parent;//双亲
	
	HuffmanTreeNode(const T& x)
		:_weight(x)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};

//哈夫曼树
template <class T>
class HuffmanTree
{
public:
	typedef HuffmanTreeNode<T> Node;
	HuffmanTree()
		:_root(NULL)
	{}
	HuffmanTree(T* a,size_t n)//不过滤没出现的字符
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
			bool operator()(Node* l,Node* r)//比较的是节点的权值
			{
				return l->_weight < r->_weight;
			}
		};

		Heap<Node*,Compare> hp;//建小堆

		//选数据(创建节点并放入堆中)
		for (size_t i = 0; i<n; ++i)
		{
			hp.Push(new Node(a[i]));
		}
		//取出两个最小的节点作为左右孩子并创建其父节点
		while (hp.Size > 1)//堆中只剩一个数据，说明只剩下根节点了
		{
			Node* left = hp.Top();//取堆中最小的数据
			hp.Pop();
			Node* right = hp.Top();//取堆中次小的数据
			hp.pop();
			Node* parent = new Node(left->_weight + right->_weight);
			//连上节点之间的关系
			left->_parent = parent;
			right->_parent = parent;
			parent->_left = left;
			parent->_right = right;
			//将双亲节点重新扔回堆中
			hp.Push(parent);
		}
		_root = hp.Top();//将堆中最大的数据作为根节点
		hp.Pop();
		return _root;
	}
	Node* _CreatHuffmanTree(T* a,size_t n,const T& invalid)//invalid过滤掉没出现的字符
	{
		struct Compare
		{
			bool operator()(Node* l,Node* r)//比较的是节点的权值
			{
				return l->_weight < r->_weight;
			}
		};

		Heap <Node*,Compare> hp;//建小堆

		//选数据(创建节点并放入堆中)
		for (size_t i = 0; i<n; ++i)
		{
			if (a[i] != invalid)
			{
				hp.Push(new Node(a[i]));
			}
		}
		//取出两个最小的节点作为左右孩子并创建其父节点
		while (hp.Size > 1)//堆中只剩一个数据，说明只剩下根节点了
		{
			Node* left = hp.Top();//取堆中最小的数据
			hp.Pop();
			Node* right = hp.Top();//取堆中次小的数据
			hp.pop();
			Node* parent = new Node(left->_weight + right->_weight);
			//连上节点之间的关系
			left->_parent = parent;
			right->_parent = parent;
			parent->_left = left;
			parent->_right = right;
			//将双亲节点重新扔回堆中
			hp.Push(parent);
		}
		_root = hp.Top();//将堆中最大的数据作为根节点
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
	HuffmanTree(const T& hf);//防拷贝
	HuffmanTree& operator=(HuffmanTree& hf);
};

void TestHuffmanTree()
{
	int a[4] = {1,2,3,4};
	HuffmanTree<int> hf(a,4);
}