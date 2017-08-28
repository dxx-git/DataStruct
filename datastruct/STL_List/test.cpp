//#include <iostream>
//#include <list>
//#include <algorithm>
//using namespace std;
//
////迭代器的使用
//void ListTest()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//	l1.push_back(5);
//	//正向迭代器
//	list<int>::iterator it1 = l1.begin(); 
//	while(it1 != l1.end())
//	{
//		cout<<*it1<<" ";
//		it1++;
//	}
//	cout<<endl;
//	
//	//反向迭代器
//	list<int>::reverse_iterator it2 = l1.rbegin();
//	while(it2 != l1.rend())
//	{
//		cout<<*it2<<" ";
//		it2++;
//	}
//	cout<<endl;
//	
//	//max_size():整型的最大值/每个元素的字节数
//	unsigned int i;
//
//	cout << "Enter number of elements: ";
//	cin >> i;
//
//	if (i<l1.max_size()) 
//		l1.resize(i);
//	else 
//		cout << "That size exceeds the limit.\n";
//	cout<<l1.size()<<endl;
//
//	//insert:在指定位置的数据之前插入
//	list<int>::iterator it3 = l1.begin();
//	it3++;
//	l1.insert(it3,10);
//	it3 = l1.begin();
//	while(it3 != l1.end())
//	{
//		cout<<*it3<<" ";
//		it3++;
//	}
//	cout<<endl;
//
//	//erase:擦除指定位置的元素(由于list中没有find接口，所以需要引入算法头文件)
//	list<int>::iterator it4 = find(l1.begin(),l1.end(),10);
//	if(it4 != l1.end())
//		l1.erase(it4);
//	it4 = l1.begin();
//	while(it4 != l1.end())
//	{
//		cout<<*it4<<" ";
//		it4++;
//	}
//	cout<<endl;
//
//	//迭代器失效
//	list<int>::iterator it5 = l1.begin();
//	//if (it5 != l1.end())
//	//{
//	//	l1.erase(it5);//释放之后it5指向随机空间
//	//}
//	//it5++;//对随机空间++，导致程序崩溃
//	
//	//解决方法：1、先加加，再删除   
//	if (it5 != l1.end())
//	{
//		it5++;
//		l1.erase(it5);
//	}
//	//2、利用返回值对其进行改进
//	it5 = l1.begin();
//	if (it5 != l1.end())
//	{
//		it5 = l1.erase(it5);
//	}
//	else
//	{
//		it5++;
//	}
//
//	//remove:删除值某特定值的元素
//	l1.remove(4);
//	it5 = l1.begin();
//	while(it5 != l1.end())
//	{
//		cout<<*it5<<" ";
//		it5++;
//	}
//	cout<<endl;
//
//}
//int main()
//{
//	ListTest();
//	system("pause");
//	return 0;
//}




//模拟list(带头结点的双向循环链表)
#pragma  once
#include <iostream>
using namespace std;
#include <Cassert>


template <class T>
struct ListNode
{
	ListNode <T>* _prev;
	ListNode <T>* _pnext;

	T _data;

	ListNode(const T& data)
		:_data(data)
		,_prev(NULL)
		,_pnext(NULL)
	{}
};

// T T& T*
//typedef ListIterator<T,T&,T*> Iterator;//普通迭代器
//typedef ListIterator<T,const T&, const T*> ConstIterator;//const迭代器 

template <class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	ListIterator()
	{}
	ListIterator(Node* node)
		:_node(node)
	{}
	bool operator==(const Self& s)
	{
		return s._node == _node;	
	}
	bool operator!=(const Self& s)
	{
		return s._node != _node;	
	}
	//T& operator*()
	Ref operator*()
	{
		return _node->_data;
	}
	//T* operator->()
	Ptr operator->()
	{
		return &_node->_data;
	}
	Self& operator++()//前置++
	{
		_node = _node->_pnext;
		return *this;
	}
	Self operator++(int)//后置++
	{
		Self tmp(*this);
		_node = _node->_pnext;
		return tmp;
	}
	Self& operator--()//前置--
	{
		_node = _node->_prev;
		return *this;
	}
	Self operator--(int)//后置--
	{
		//Self tmp(*this);
		Self tmp(_node);
		_node = _node->_prev;
		return tmp;
	}
};
template <typename T>
class List
{
public:
     typedef ListNode <T> Node;
	 typedef ListIterator<T,T&,T*> Iterator;//普通迭代器
	 typedef ListIterator<T,const T&, const T*> ConstIterator;//const迭代器

public:
	List()
		:_head(BuyNode(T()))
	{
		_head->_pnext = _head;
		_head->_prev = _head;
	}
	void PushBack(const T& data)
	{
		Node* tail = _head->_prev;
		Node* newnode = BuyNode(data);
	    
		tail->_pnext = newnode;
		newnode->_prev = tail;

		newnode->_pnext = _head;
		_head->_prev = newnode;
	}
	void PopBack()
	{
		Erase(--End());
	}
	void PushFront(const T& data)
	{
		Insert(Begin(),data);
	}
	void PopFront()
	{
		Erase(Begin());
	}

	template <typename InputIterator>//模板类中的模板函数
	void Insert(Iterator pos, InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			Insert(pos, *first);
			++first;
		}
	}
	Iterator Insert(Iterator pos,const T& data)
	{
		assert(pos._node);

		Node* cur = pos._node;
		Node* prev = cur->_prev;

		Node* tmp = new Node(data);

		prev->_pnext = tmp;
		tmp->_prev = prev;

		tmp->_pnext = cur;
		cur->_prev = tmp;

		return tmp;
	}
	Iterator Erase(Iterator pos)
	{
		assert(pos._node && pos._node != _head);

		Node* prev = pos._node->_prev;
		Node* next = pos._node->_next;

		prev->_next = next;
		next->_prev = prev;

		delete pos._node;

		return Iterator(next);//返回下一个节点，防止迭代器失效
	}
	Iterator Begin()
	{
		//return Iterator(_head->_next);
		return _head->_pnext; //自动进行隐式类型转换:
		//构造函数和拷贝构造同一步骤使用，编译器会进行自动优化,只调用一个
	}

	Iterator End()
	{
		//return Iterator(_head);
		return _head;//自动进行隐式类型转换
		//构造函数和拷贝构造同一步骤使用，编译器会进行自动优化,只调用一个
	}

	ConstIterator Begin() const
	{
		//return ConstIterator(_head->_next);
		return _head->_pnext;//自动进行隐式类型转换
		//构造函数和拷贝构造同一步骤使用，编译器会进行自动优化,只调用一个
	}

	ConstIterator End() const
	{
		//return ConstIterator(_head);
		return _head;//自动进行隐式类型转换
		//构造函数和拷贝构造同一步骤使用，编译器会进行自动优化,只调用一个
	}
private:
	Node* BuyNode(const T& data)
	{
		return new Node(data);
	}
protected:
	Node* _head;//指向头结点的指针
};

void PrintListConst(const List<int>& l)
{
	List<int>::ConstIterator it = l.Begin();

	while (it != l.End())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
}

void PrintList(List<int>& l)
{
	List<int>::Iterator it = l.Begin();

	while (it != l.End())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
}

void TestList()
{
	List<int> l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);

	PrintList(l1);

	List<int> l2;
	l2.PushBack(5);
	l2.PushBack(6);
	l2.PushBack(7);

	List<int>::Iterator pos = l1.Begin();
	l1.Insert(pos, l2.Begin(), l2.End());
	PrintListConst(l1);

}
int main()
{
	TestList();
	system("pause");
	return 0;
}



