#pragma once
#include <iostream>
#include <string>
#include "bit_map.h"
#include "string_hash.h"
using namespace std;

//布隆过滤器
struct __HashFunc1
{ 
	size_t operator()(const std::string& s)
	{
		return BKDRHash(s.c_str());
	}
};
struct __HashFunc2
{
	size_t operator()(const std::string& s)
	{
		return SDBMHash(s.c_str());
	}
};
struct __HashFunc3
{
	size_t operator()(const std::string& s)
	{
		return RSHash(s.c_str());
	}
};
struct __HashFunc4
{
	size_t operator()(const std::string& s)
	{
		return JSHash(s.c_str());
	}
};
struct __HashFunc5
{
	size_t operator()(const std::string& s)
	{
		return APHash(s.c_str());
	}
};


//template<class K = string,
//class HashFunc1 = __HashFunc1,
//class HashFunc2 = __HashFunc2,
//class HashFunc3 = __HashFunc3,
//class HashFunc4 = __HashFunc4,
//class HashFunc5 = __HashFunc5
//>
//class BloomFilter
//{
//public:
//	BloomFilter(size_t N = 1024)
//		:_bm(N * 10)
//		,_size(N * 10)
//	{}
//	void Set(const K& key)
//	{
//		size_t hash1 = HashFunc1()(key) % _size;
//		size_t hash2 = HashFunc2()(key) % _size;
//		size_t hash3 = HashFunc3()(key) % _size;
//		size_t hash4 = HashFunc4()(key) % _size;
//		size_t hash5 = HashFunc5()(key) % _size;
//
//		_bm.Set(hash1);
//		_bm.Set(hash2);
//		_bm.Set(hash3);
//		_bm.Set(hash4);
//		_bm.Set(hash5);
//
//		cout<<hash1<<":"<<hash2<<":"<<hash3<<":"<<hash4<<":"<<hash5<<endl;
//	}
//	//void ReSet(const K& key);//不支持
//	bool Test(const K& key)
//	{
//		size_t hash1 = HashFunc1()(key) % _size;
//		if (_bm.Test(hash1) == false)
//			return false;
//		
//		size_t hash2 = HashFunc2()(key) % _size;
//		if (_bm.Test(hash2) == false)
//			return false;
//
//		size_t hash3 = HashFunc3()(key) % _size;
//		if (_bm.Test(hash3) == false)
//			return false;
//
//		size_t hash4 = HashFunc4()(key) % _size;
//		if (_bm.Test(hash4) == false)
//			return false;
//
//		size_t hash5 = HashFunc5()(key) % _size;
//		if (_bm.Test(hash5) == false)
//			return false;
//
//		return true;
//	}
//protected:
//	BitMap _bm;
//	size_t _size;
//};

//带删除功能的布隆过滤器（引用计数）
template<class K = string,
class HashFunc1 = __HashFunc1,
class HashFunc2 = __HashFunc2,
class HashFunc3 = __HashFunc3,
class HashFunc4 = __HashFunc4,
class HashFunc5 = __HashFunc5
>
class RefBloomFilter
{
public:
	RefBloomFilter(size_t N = 1024)
		:_size(N * 10)
	{
		_refbm.resize(_size);
	}
	void Set(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % _size;
		size_t hash2 = HashFunc2()(key) % _size;
		size_t hash3 = HashFunc3()(key) % _size;
		size_t hash4 = HashFunc4()(key) % _size;
		size_t hash5 = HashFunc5()(key) % _size;

		_refbm[hash1]++;
		_refbm[hash2]++;
		_refbm[hash3]++;
		_refbm[hash4]++;
		_refbm[hash5]++;

		cout<<hash1<<":"<<hash2<<":"<<hash3<<":"<<hash4<<":"<<hash5<<endl;
	}
	void ReSet(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % _size;
		size_t hash2 = HashFunc2()(key) % _size;
		size_t hash3 = HashFunc3()(key) % _size;
		size_t hash4 = HashFunc4()(key) % _size;
		size_t hash5 = HashFunc5()(key) % _size;

		_refbm[hash1]--;
		_refbm[hash2]--;
		_refbm[hash3]--;
		_refbm[hash4]--;
		_refbm[hash5]--;
	}
	bool Test(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % _size;
		if (_refbm[hash1] <= 0)
			return false;

		size_t hash2 = HashFunc2()(key) % _size;
		if (_refbm[hash2] <= 0)
			return false;

		size_t hash3 = HashFunc3()(key) % _size;
		if (_refbm[hash3] <= 0)
			return false;

		size_t hash4 = HashFunc4()(key) % _size;
		if (_refbm[hash4] <= 0)
			return false;

		size_t hash5 = HashFunc5()(key) % _size;
		if (_refbm[hash5] <= 0)
			return false;

		return true;
	}
protected:
	vector<size_t> _refbm;
	size_t _size;
};


void TestBloomBitMap()
{
	/*BloomFilter<> bm(1024);
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html");
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528154.html");
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528155.html");
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528156.html");
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528157.html");

	cout<<bm.Test("http://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/-clq/archive/2012/05/31/2528158.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/-clq/archive/2012/05/31/2528154.html")<<endl;*/

	RefBloomFilter<> bm(1024);
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html");
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528154.html");
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528155.html");
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528156.html");
	bm.Set("http://www.cnblogs.com/-clq/archive/2012/05/31/2528157.html");

	cout<<bm.Test("http://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/-clq/archive/2012/05/31/2528158.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/-clq/archive/2012/05/31/2528154.html")<<endl;
}