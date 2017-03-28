#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//仿函数
template <class K>
struct __HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
//函数特化
template <>
struct __HashFunc<string>
{
	size_t BKDRHash(const char* str)
	{
		register size_t hash = 0;
		while(*str)
		{
			hash = hash * 131 + *str;
			++str;
		}
		return hash;
	}
	size_t operator()(const string& s)
	{
		return BKDRHash(s.c_str());
	}
};

template <class K,class V>
struct HashNode
{
	pair<K,V> _kv;
	HashNode<K,V>* _next;
	HashNode(const pair<K,V>& kv)
		:_next(NULL)
		,_kv(kv)
	{}
};

template <class K,class V,class HashFunc = __HashFunc<K>>
class HashBucket;

//迭代器
template <class K,class V,class Ref,class Ptr>
struct __HashTableIterator
{
	typedef HashNode<K,V> Node;
	Node* _node;
	HashBucket<K,V>* _ht;

	typedef __HashTableIterator<K,V,Ref,Ptr> Self;
	__HashTableIterator(Node* node,HashBucket<K,V>* ht)
		:_node(node)
		,_ht(ht)
	{}
	Ref operator*()
	{
		return _node->_kv;
	}
	Ptr operator->()
	{
		return &(operator*());
	}
	Self& operator++()
	{
		_node = _Next(_node);
		return *this;
	}
	Self operator++(int)
	{
		Self tmp(_node,_ht) ;
		_node = _Next(_node);
		return tmp;
	}
	Self& operator--()
	{
		_node = _Prev(_node);
		return *this;
	}
	Self operator--(int)
	{
		Self tmp(_node,_ht);
		_node = _Prev(_node);
		return tmp;
	}
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
	bool operator==(const Self& s)
	{
		return _node == s._node;
	}
protected:
	Node* _Next(Node* node)
	{
		Node* next = node->_next;
		if (next)
		{
			return next;
		} 
		else
		{
			size_t index = _ht->_HashFunc(_node->_kv.first) + 1;
			for (; index < _ht->_tables.size(); ++index)
			{
				next = _ht->_tables[index];
				if (next)
				{
					return next;
				}
			}
			return NULL;
		}
	}
	Node* _Prev(Node* node)
	{
		size_t index = _ht->_HashFunc(_node->_kv.first);
		Node* prev = _ht->_tables[index];

		if (NULL == prev->_next)//当前链表只有一个节点
		{
			for (index = index - 1; index >= 0; --index)
			{
				prev = _ht->_tables[index];
				if (prev)
				{
					Node* cur = prev;
					while(cur->_next)
					{
						cur = cur->_next;
					}
					return cur;
				}
			}
			return NULL;
		} 
		else
		{
			Node* prev = _ht->_tables[index];
			while(prev)
			{
				if (prev->_next->_kv.first == node->_kv.first)
				{
					return prev;
				}
				prev = prev->_next;
			}
			return NULL;
		}
	}
};

template <class K,class V,class HashFunc>
class HashBucket
{
	typedef HashNode<K,V> Node;
public:
	typedef __HashTableIterator<K,V,pair<K,V>&,pair<K,V>*> Iterator;
	typedef __HashTableIterator<K,V,const pair<K,V>&,const pair<K,V>*> ConstIterator;
    
	friend struct Iterator;
	friend struct ConstIterator;
public:
	HashBucket()
		:_size(0)
	{}
	HashBucket(size_t size)
		:_size(0)
	{
		_tables.resize(size);
	}
	~HashBucket()
	{
		Clear();
	}
	pair<Node*,bool> Insert(pair<K,V> kv)
	{
		_CheckCapacity();
		size_t index = _HashFunc(kv.first);

		//查找key值是否已经存在
		Node* cur = _tables[index];
		while (cur)
		{
			//防冗余
			if (cur->_kv.first == kv.first)
			{
				return make_pair(cur,false);
			}
			cur = cur->_next;
		}
		//头插
		Node* tmp = new Node(kv);
		tmp->_next = _tables[index];
		_tables[index] = tmp;

		++_size;
		return make_pair(tmp,true);
	}
	Node* Find(const K& key)
	{
		if (_tables.empty())
		{
			return NULL;
		}
		size_t index = _HashFunc(key);
		Node* cur = _tables[index];
		while(cur)
		{
			if (cur->_kv.first == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}
	bool Remove(const K& key)
	{
		size_t index = _HashFunc(key);
		Node* cur = _tables[index];
		Node* prev = NULL;

		while(cur)
		{
			prev = cur;
			if (cur->_kv.first == key)
			{
				//链表只有一个节点
				if (cur == _tables[index] && NULL == cur->_next)
				{
					delete cur;
					cur = _tables[index] = NULL;
					return true;
				} 
				else
				{
					prev->_next = cur->_next;
					delete cur;
					cur = NULL;
					return true;
				}
			} 
			cur = cur->_next;
		}
		return false;
	}
	//bool Remove(const K& key)//借用find函数进行删除
	//{
	//	if (_tables.empty())
	//	{
	//		return false;
	//	}
	//	size_t index = _HashFunc(key);
	//	Node* cur = _tables[index];
	//	//链表只有一个节点
	//	if (NULL == cur->_next)
	//	{
	//		if (cur->_kv.first == key)
	//		{
	//			delete cur;
	//			cur = _tables[index] = NULL;
	//			return true;
	//		}
	//		return false;
	//	}
	//	else
	//	{
	//		Node* ret = Find(key);

	//		if (ret)
	//		{
	//			swap(_tables[index],cur);
	//			Node* next = _tables[index]->_next;
	//			delete cur;
	//			cur = next;
	//			_tables[index] = next;
	//			return true;
	//		}
	//		return false;
	//	}
	//}
	Iterator Begin()
	{
		for (size_t index = 0; index < _tables.size(); ++index)
		{
			Node* cur = _tables[index];
			if (cur)
			{
				return Iterator(cur,this);
			}
		}
		return Iterator((Node*)NULL,this);
	}
	Iterator End()
	{
		return Iterator((Node*)NULL,this);
	}
	
protected:
	void Clear()
	{
		if (_tables.empty())
		{
			return;
		}
		Node* cur = NULL;
		Node* del = NULL;
		for (size_t i = 0; i < _tables.size(); ++i)
		{
			cur = _tables[i];
			while(cur)
			{
				del = cur;
				cur = cur->_next;
				delete del;
			}
		}
	}
	size_t _HashFunc(const size_t key)
	{
		return key % _tables.size();
	}
	size_t GetNextPrime(size_t num)
	{
		const int _PrimeSize= 28;

		static const unsigned long _PrimeList[_PrimeSize] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul,786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul,25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul,
			805306457ul,1610612741ul, 3221225473ul, 4294967291ul
		};

		for (size_t i = 0; i<_PrimeSize; ++i)
		{
			if (num < _PrimeList[i])
			{
				return _PrimeList[i];
			}
		}

		return _PrimeList[_PrimeSize-1];
	}
	void Swap(HashBucket<K,V,HashFunc> hb)
	{
		swap(_tables,hb._tables);
		swap(_size,hb._size);
	}
	void _CheckCapacity()
	{
		if(_tables.empty())
		{
			_tables.resize(_tables.size());
			return;
		}

		//负载因子达到1进行扩容
		if (_size == _tables.size())
		{
			size_t newSize = GetNextPrime(_tables.size());
			Node* cur = NULL;
			HashBucket<K,V,HashFunc> tmp;
			tmp._tables.resize(newSize);

			for (size_t i = 0; i < _tables.size(); ++i)
			{
				cur = _tables[i];
				while (cur)
				{
					tmp.Insert(cur->_kv);
					cur = cur->_next;
				}
			}
			Swap(tmp);
		}
	}
	
protected:
	vector<Node*> _tables;
	size_t _size;
};



void TestHashBucket()
{
	HashBucket<int,int> hb(10);
	hb.Insert(make_pair(1,1));
	hb.Insert(make_pair(2,2));
	hb.Insert(make_pair(3,3));
	hb.Insert(make_pair(4,4));
	hb.Insert(make_pair(5,5));

	cout<<hb.Find(3)<<endl;
	cout<<hb.Find(7)<<endl;

	hb.Remove(4);
	hb.Remove(1);

	hb.Insert(make_pair(7,7));
	hb.Insert(make_pair(0,0));
	hb.Insert(make_pair(9,9));

	HashBucket<int,int>::Iterator it = hb.Begin();
	HashBucket<int,int>::Iterator it1 = hb.Begin();

	while(it != hb.End())
	{
		it1 = it;
		cout<<it->first<<":"<<it->second<<endl;
		++it;
	}
	
	while(it1 != hb.Begin())
	{
		cout<<it1->first<<":"<<it1->second<<endl;
		//--it1;
		it1--;
	}
}