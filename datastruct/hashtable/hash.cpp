#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "hash_bucket.h"
#include "bit_map.h"
#include "BloomFilter.h"
using namespace std;
//
//enum Status
//{
//	EMPTY,
//	DELETE,
//	EXIST,
//};
//
//
////·Âº¯Êý
//template <class K>
//struct __HashFunc
//{
//	size_t operator()(const K& key)
//	{
//		return key;
//	}
//};
////º¯ÊýÌØ»¯
//template <>
//struct __HashFunc<string>
//{
//	size_t BKDRHash(const char* str)
//	{
//		register size_t hash = 0;
//		while(*str)
//		{
//			hash = hash * 131 + *str;
//			++str;
//		}
//		return hash;
//	}
//	size_t operator()(const string& s)
//	{
//		return BKDRHash(s.c_str());
//	}
//};
//
//template <class K,class V>
//struct HashTableNode
//{
//	K _key;
//	V _value;
//	Status _status;
//
//	HashTableNode(const K& key = K(),const V& value = V())
//		:_key(key)
//		,_value(value)
//		,_status(EMPTY)
//	{}
//};
//
//template <typename K,typename V,typename HashFunc = __HashFunc<K>>
//class HashTable
//{
//	typedef HashTableNode<K,V> Node;
//public:
//	HashTable(const size_t size = 10)
//		:_tables()
//		,_size(0)
//	{
//		_tables.resize(size);
//	}
//	~HashTable()
//	{}
//
//	size_t _HashFunc(const K& key)
//	{
//		__HashFunc<K> hf;
//		return hf(key) % _tables.size();
//	}
//
//	pair<Node*,bool> Insert(const K& key,const V& value)
//	{
//		_CheckCapacity();
//		size_t index = _HashFunc(key);
//
//	Node* ret = Find(key);
//	if (ret)
//	{
//		return make_pair(ret,false);
//	}
//
//		while(_tables[index]._status == EXIST)
//		{
//			//·ÀÈßÓà
//			if (key == _tables[index]._key)
//			{
//				return make_pair(&_tables[index],false);
//			}
//			++index;//ÏßÐÔÌ½²â
//			if (index == _tables.size())
//			{
//				index = 0;
//			}
//		}
//
//		_tables[index]._key = key;
//		_tables[index]._status = EXIST;
//		_tables[index]._value = value;
//
//		++_size;
//		return make_pair(&_tables[index],true);
//	}
//
//	////¶þ´ÎÌ½²â
//	//pair<Node*,bool> Insert(const K& key,const V& value)
//	//{
//	//	_CheckCapacity();
//	//	size_t index = _HashFunc(key);
//	//	size_t i = 0;
//	//	size_t first = index;
//
//	//	Node* ret = Find(key);
//	//	if (ret)
//	//	{
//	//		return make_pair(ret,false);
//	//	}
//	//	while(_tables[index]._status == EXIST)
//	//	{
//	//		//·ÀÈßÓà
//	//		if (key == _tables[index]._key)
//	//		{
//	//			return make_pair(&_tables[index],false);
//	//		}
//	//		++i;
//	//		index = first + i*i;
//	//		index %= _tables.size();
//	//	}
//
//	//	_tables[index]._key = key;
//	//	_tables[index]._status = EXIST;
//	//	_tables[index]._value = value;
//
//	//	++_size;
//	//	return make_pair(&_tables[index],true);
//	//}
//	
//	bool Remove(const K& key)
//	{
//		assert(_size != 0);
//        Node* del = Find(key);
//
//		if (NULL == del)
//		{
//			cout<<"Ã»ÕÒµ½ÒªÉ¾³ýµÄÔªËØ£¬É¾³ýÊ§°Ü"<<endl;
//			return false;
//		} 
//		else
//		{
//			del->_status = DELETE;
//			cout<<"É¾³ý³É¹¦"<<endl;
//			return true;
//		}
//	}
//
//	Node* Find(const K& key)
//	{
//		size_t index = 0;
//		while (index < _tables.size())
//		{
//			if (_tables[index]._key == key && _tables[index]._status == EXIST)
//		   {
//			   return &_tables[index];
//		   } 
//
//		   ++index;
//		}
//		return NULL;
//	}
//	void Swap(HashTable<K,V,HashFunc> h)
//	{
//		swap(h._tables,_tables);
//		swap(h._size,_size);
//	}
//
//	void _CheckCapacity()
//	{
//		//¹þÏ£±íÎª¿Õ
//		if(_tables.empty())
//		{
//			_tables.resize(GetPrime(_tables.size()));
//			return;
//		}
//		if (_size*10 / _tables.size() >= 7)
//		{
//			size_t newSize = GetPrime(_tables.size());
//			HashTable<K,V,HashFunc> tmp(newSize);
//			for (size_t i = 0; i < _tables.size(); ++i)
//			{
//				if (_tables[i]._status == EXIST)
//				{
//					tmp.Insert(_tables[i]._key,_tables[i]._value);
//				}
//			}
//			Swap(tmp);
//		}
//	}
//	//Ê¹ÓÃËØÊý±í¶ÔÆë×ö¹þÏ£±íµÄÈÝÁ¿£¬½µµÍ¹þÏ£³åÍ»
//	size_t GetPrime(size_t num)
//	{
//		const int _PrimeSize= 28;
//
//		static const unsigned long _PrimeList[_PrimeSize] =
//		{
//			53ul, 97ul, 193ul, 389ul, 769ul,
//			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
//			49157ul, 98317ul, 196613ul, 393241ul,786433ul,
//			1572869ul, 3145739ul, 6291469ul, 12582917ul,25165843ul,
//			50331653ul, 100663319ul, 201326611ul, 402653189ul,
//			805306457ul,1610612741ul, 3221225473ul, 4294967291ul
//		};
//
//		for (size_t i = 0; i<_PrimeSize; ++i)
//		{
//			if (num < _PrimeList[i])
//			{
//				return _PrimeList[i];
//			}
//		}
//
//		return _PrimeList[_PrimeSize-1];
//	}
//	
//protected:
//	vector<Node> _tables;
//	size_t _size;
//};
//
//void TestHash()
//{
//	/*HashTable<int,int> hash;
//	hash.Insert(89,0);
//	hash.Insert(18,0);
//	hash.Insert(49,0);
//	hash.Insert(58,0);
//	hash.Insert(3,0);
//	hash.Insert(4,0);
//	hash.Insert(90,0);
//	hash.Insert(56,0);
//	hash.Insert(78,0);
//	hash.Insert(48,0);
//	hash.Insert(19,0);
//
//	hash.Find(18);
//	hash.Find(9);
//	hash.Find(49);
//
//	hash.Remove(89);
//	hash.Remove(9);
//	hash.Remove(58);*/
//
//	HashTable<string,string> ha;
//	ha.Insert("left","×ó±ß");
//	ha.Insert("dictionary","×Öµä");
//	ha.Insert("Apple","Æ»¹û");
//	ha.Insert("banana","Ïã½¶");
//	ha.Insert("sort","ÅÅÐò");
//
//
//}
//
int main()
{
	//TestHash();
	//TestHashBucket();
	//TestBitMap();
	TestBloomBitMap();
	system("pause");
	return 0;
}