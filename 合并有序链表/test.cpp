#include<iostream>
#include<cassert>
using namespace std;

template<class T>
struct Node
{
	Node(const T data)
	:_data(data)
	, _next(NULL)
	{}

	T _data;
	Node<T>* _next;
};

template<class T>
class List
{
public:
	typedef struct Node<T> Node;
	List()
		:_head(NULL)
	{}
	void Push_back(const T data)
	{
		if (NULL == _head)
			_head = new Node(data);
		else
		{
			Node* cur = _head;
			while (cur->_next)
			{
				cur = cur->_next;
			}
			cur->_next = new Node(data);
		}
	}

	bool Empty()
	{
		if (NULL == _head)
			return true;
		else
			return false;
	}

	int Size()
	{
		int count = 0;
		Node* cur = _head;
		while (cur)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}

	//merge two ordered Lists,default ascending order
	List<int>& merge(List<int> l1, List<int> l2)
	{
		assert(!l1.Empty() && !l2.Empty());
		if (l1.Empty())//l1 is a NULL List
			return l2;
		if (l2.Empty())//l2 is a NULL List
			return l1;

		Node* p1;
		Node* p2;
		p1 = l1._head;
		p2 = l2._head;
		while (p1 && p2)
		{
			if (p1->_data >= p2->_data)
			{
				Push_back(p2->_data);
				p2 = p2->_next;
			}
			else
			{
				Push_back(p1->_data);
				p1 = p1->_next;
			}
		}
		if (NULL == p1)
		{
			while (p2)
			{
				Push_back(p2->_data);
				p2 = p2->_next;
			}
		}
		else
		{
			while (p1)
			{
				Push_back(p1->_data);
				p1 = p1->_next;
			}	
		}
		return *this;
	}

	~List()
	{
		Node* cur = _head;
		Node* del = cur;
		while (cur)
		{
			del = cur;
			cur = cur->_next;
			delete del;
			del = NULL;
		}
		_head = NULL;
	}

	Node* _head;
};

int main()
{
	List<int> l1, l2, l3;
	int i = 0;
	int size = 0;
	Node<int>* p = NULL;
	for (i = 1; i <= 5; i++)
	{
		l1.Push_back(i);
		l2.Push_back(2 * i);
	}

	l3.merge(l1, l2);
	size = l3.Size();
	p = l3._head;
	while (size--)
	{
		cout << p->_data << "->";
		p = p->_next;
	}
	cout << "null" << endl;
	system("pause");
	return 0;
}
