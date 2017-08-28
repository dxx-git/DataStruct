#include <iostream>
#include <vector>
#include <cassert>
#include "heap_sort.h"
#include "huffmantree.h"
using namespace std;
//
////建小堆
template <class T>
struct Less
{
	bool operator()(const T&l,const T& r)
	{
		return l<r;
	}
};

//建大堆
template <class T>
struct Greater
{
	bool operator()(const T&l,const T& r)
	{
		return l>r;
	}
};
//用仿函数实现建大堆还是小堆，提高代码的复用性
template <class T,class Compare = Greater<T>>//默认建大堆
class Heap
{
public:
	Heap()
		:_a(NULL)
	{}
	Heap(T* a,size_t n)
		:_a(a,a+n)//方法一：相当于调用系统中vector的构造函数
	{
		/*
		//方法二：
		_a.reserve(n);//开辟n快空间
		for (size_t i = 0; i < n; i++)
		{
			_a.push_back(a[i]);//for循环插入数据
		}
		*/
		for (int i = (_a.size()-2)/2; i>=0; --i)
		{
			_AdjustDown(i);
		}
	}
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size()-1);
	}
	void Pop()
	{
		assert(!_a.empty());
		swap(_a[0],_a[_a.size()-1]);
		_a.pop_back();
		_AdjustDown(0);
	}
	size_t Size()
	{
		return _a.size();
	}
	bool Empty()
	{
		return _a.empty();
	}
	const T& Top()const
	{
		assert(!_a.empty());
		return _a[0];
	}
	void Display()
	{
		for (size_t i = 0; i<_a.size(); i++)
		{
			cout<<_a[i]<<" ";
		}
		cout<<endl;
	}
	
protected:
	void _AdjustDown(size_t root)//向下调整
	{
		Compare com;
		size_t parent = root;
		size_t child = parent*2+1;

		while(child < _a.size())
		{
			//找左右孩子里面大的那一个
			if (child+1 < _a.size() && com(_a[child+1],_a[child]))
			{
				++child;
			}

			//如果孩子大于父亲，则交换，继续向下调整,否则结束
			if (com(_a[child] , _a[parent]))
			{
				swap(_a[child],_a[parent]);
				parent = child;
				child = parent*2+1;
			}
			else
			{
				break;
			}
		}
	}
	void _AdjustUp(size_t child)
	{
		size_t parent = (child - 1)/2;
		Compare com; 

		while(child > 0)
		{
			//如果孩子小于父亲，则交换，继续向下调整,否则结束
			if (com(_a[child],_a[parent]))
			{
				swap(_a[child],_a[parent]);
				child = parent;
				parent = (child - 1)/2;
			}
			else
			{
				break;
			}
		}
	}
protected:
	vector<T> _a; 
};
//
//
//template <class T,class Compare = Greater<T>>
//class PriorrityQueue
//{
//public:
//	PriorrityQueue(T* a, size_t size)
//		:_p(a,size)
//	{}
//	void Push(const T& x)
//	{
//		_p.Push(x);
//	}
//	void Pop()
//	{
//		assert(!_p.Empty());
//		_p.Pop();
//	}
//	size_t Size()
//	{
//		return _p.Size();
//	}
//	bool Empty()
//	{
//		return _p.Empty();
//	}
//	const T& Top()const
//	{
//		return _p.Top();
//	}
//	void Display()
//	{
//		_p.Display();
//	}
//	
//protected:
//	Heap<T,Compare> _p;
//};
//
//void TestPriorityQueue()
//{
//	int a [] = {10, 11, 13, 12, 16, 18, 15, 17, 14, 19};
//	size_t size = sizeof(a)/sizeof(a[0]);
//	PriorrityQueue<int,Greater<int>> pq(a,size);
//	pq.Display();
//	cout<<pq.Size()<<endl;
//	pq.Top();
//	pq.Push(20);
//	pq.Display();
//	cout<<pq.Size()<<endl;
//	pq.Top();
//	pq.Pop();
//	pq.Display();
//}
//
//void TestHeap()
//{
//	int a [] = {10, 11, 13, 12, 16, 18, 15, 17, 14, 19};
//	size_t size = sizeof(a)/sizeof(a[0]);
//	Heap<int,Greater<int>> hp(a,size);
//	hp.Display();
//	cout<<hp.Size()<<endl;
//	hp.Top();
//	hp.Push(20);
//	hp.Display();
//	cout<<hp.Size()<<endl;
//	hp.Top();
//	hp.Pop();
//	hp.Display();
//
//}
//
int main()
{
	//TestHeap();
	//TestPriorityQueue();
	//Testheapsort();
	TestHuffmanTree();
	system("pause");
	return 0;
}