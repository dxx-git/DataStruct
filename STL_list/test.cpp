//#include <iostream>
//#include <list>
//#include <algorithm>
//using namespace std;
//
////��������ʹ��
//void ListTest()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//	l1.push_back(5);
//	//���������
//	list<int>::iterator it1 = l1.begin(); 
//	while(it1 != l1.end())
//	{
//		cout<<*it1<<" ";
//		it1++;
//	}
//	cout<<endl;
//	
//	//���������
//	list<int>::reverse_iterator it2 = l1.rbegin();
//	while(it2 != l1.rend())
//	{
//		cout<<*it2<<" ";
//		it2++;
//	}
//	cout<<endl;
//	
//	//max_size():���͵����ֵ/ÿ��Ԫ�ص��ֽ���
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
//	//insert:��ָ��λ�õ�����֮ǰ����
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
//	//erase:����ָ��λ�õ�Ԫ��(����list��û��find�ӿڣ�������Ҫ�����㷨ͷ�ļ�)
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
//	//������ʧЧ
//	list<int>::iterator it5 = l1.begin();
//	//if (it5 != l1.end())
//	//{
//	//	l1.erase(it5);//�ͷ�֮��it5ָ������ռ�
//	//}
//	//it5++;//������ռ�++�����³������
//	
//	//���������1���ȼӼӣ���ɾ��   
//	if (it5 != l1.end())
//	{
//		it5++;
//		l1.erase(it5);
//	}
//	//2�����÷���ֵ������иĽ�
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
//	//remove:ɾ��ֵĳ�ض�ֵ��Ԫ��
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




//ģ��list(��ͷ����˫��ѭ������)
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
//typedef ListIterator<T,T&,T*> Iterator;//��ͨ������
//typedef ListIterator<T,const T&, const T*> ConstIterator;//const������ 

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
	Self& operator++()//ǰ��++
	{
		_node = _node->_pnext;
		return *this;
	}
	Self operator++(int)//����++
	{
		Self tmp(*this);
		_node = _node->_pnext;
		return tmp;
	}
	Self& operator--()//ǰ��--
	{
		_node = _node->_prev;
		return *this;
	}
	Self operator--(int)//����--
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
	 typedef ListIterator<T,T&,T*> Iterator;//��ͨ������
	 typedef ListIterator<T,const T&, const T*> ConstIterator;//const������

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

	template <typename InputIterator>//ģ�����е�ģ�庯��
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

		return Iterator(next);//������һ���ڵ㣬��ֹ������ʧЧ
	}
	Iterator Begin()
	{
		//return Iterator(_head->_next);
		return _head->_pnext; //�Զ�������ʽ����ת��:
		//���캯���Ϳ�������ͬһ����ʹ�ã�������������Զ��Ż�,ֻ����һ��
	}

	Iterator End()
	{
		//return Iterator(_head);
		return _head;//�Զ�������ʽ����ת��
		//���캯���Ϳ�������ͬһ����ʹ�ã�������������Զ��Ż�,ֻ����һ��
	}

	ConstIterator Begin() const
	{
		//return ConstIterator(_head->_next);
		return _head->_pnext;//�Զ�������ʽ����ת��
		//���캯���Ϳ�������ͬһ����ʹ�ã�������������Զ��Ż�,ֻ����һ��
	}

	ConstIterator End() const
	{
		//return ConstIterator(_head);
		return _head;//�Զ�������ʽ����ת��
		//���캯���Ϳ�������ͬһ����ʹ�ã�������������Զ��Ż�,ֻ����һ��
	}
private:
	Node* BuyNode(const T& data)
	{
		return new Node(data);
	}
protected:
	Node* _head;//ָ��ͷ����ָ��
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



