#include <iostream>
#include <assert.h>
using namespace std;

//template <typename T>
//class Stack
//{
//public:
//	Stack()
//		:_data(NULL)
//		,_size(0)
//		,_capacity(0)
//	{}
//
//	Stack(const Stack& s)
//		:_data(new T[s._capacity])
//		,_size(s._size)
//		,_capacity(s._capacity)
//	{
//		for(int i = 0; i<s._size; i++)
//		{
//			_data[i] = s._data[i];
//		}
//	}
//
//	Stack& operator=(const Stack& s)
//	{
//		if(this != &s)
//		{
//			Stack<T> temp(s);
//			delete []_data;//释放旧空间
//			_data = temp._data;//指向新空间
//
//			_capacity = s._capacity;
//			_size = s._size;
//		}
//		return *this;
//	}
//
//	~Stack()
//	{
//		if(NULL != _data)
//		{
//			delete []_data;
//			_data = NULL;
//			_size = 0;
//			_capacity = 0;
//		}
//	}
//
//	T Top()
//	{
//		assert(_data);
//		return _data[_size-1];
//	}
//
//	void Push(T data)
//	{
//		CheckCapacity();
//		_data[_size++] = data;
//	}
//
//	void Pop()
//	{
//		assert(_data);
//		_size--;//懒删除，不改变数据，只改变size标识
//	}
//
//	bool Empty()
//	{
//		return _size==0;
//	}
//
//	size_t Size()
//	{
//		return _size;
//	}
//private:
//	void CheckCapacity()
//	{
//		if(_size >= _capacity)
//		{
//			T NewCapacity = _capacity * 2 + 3;
//			T* temp = new T[NewCapacity];
//			//memcpy(temp,_data,_size * sizeof(Stack));
//			for(int i = 0; i<_size; i++)
//			{
//				temp[i] = _data[i];
//			}
//
//			delete []_data;
//			_data = temp;
//			_capacity = NewCapacity;
//		}
//	}
//protected:
//	T *_data;
//	T _capacity;
//	int _size;
//};
//
//void TestStack()
//{
//	Stack<int> s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	s1.Push(5);
//	Stack<int> s2(s1);
//	s2.Pop();
//	s2.Pop();
//	s2.Pop();
//	Stack<int> s3;
//	s3 = s2;
//	cout<<"s1.top:"<<s1.Top()<<endl;
//	cout<<"s2.top"<<s2.Top()<<endl;
//	cout<<"s3.size:"<<s3.Size()<<endl;
//	while(!s1.Empty())
//	{
//		cout<<s1.Size()<<" ";
//		s1.Pop();
//	}
//	cout<<endl;
//}
//int main()
//{
//	TestStack();
//	system("pause");
//	return 0;
//}





//template <typename T>
//struct QNode
//{
//	QNode(T data)
//		:_pNext(NULL)
//		,_data(data)
//	{}
//	T _data;
//	struct QNode* _pNext;
//};
//
//template <typename T>
//class Queue
//{
//public:
//	Queue()
//		:_Front(NULL)
//        ,_Tail(NULL)
//		,_size(0)
//	{}
//
//	Queue(const Queue& q)
//		:_Front(NULL)
//		,_Tail(NULL)
//		,_size(0)//Push()里面会自动加_size
//	{
//		QNode<T>* Cur = q._Front;
//		while(NULL != Cur)
//		{
//            Push(Cur->_data);
//			Cur = Cur->_pNext;
//		}
//	}
//
//	Queue& operator=(const Queue& q)
//	{
//		if(_Front != q._Front)//排除自己给自己赋值
//		{
//			QNode<T>* Cur = q._Front;
//			while(Cur)
//			{
//				Push(Cur->_data);
//				Cur = Cur->_pNext;
//			}
//		}
//		return *this;
//	}
//
//	~Queue()
//	{
//		if(!Empty())
//		{
//			Clear();
//			_Front = NULL;
//			_Tail = NULL;
//			_size = 0;
//		}
//	}
//	void Push(T data)
//	{
//		if(NULL == _Front)
//		{
//			_Front = _Tail = new QNode<T>(data);
//		}
//		else
//		{
//			_Tail->_pNext = new QNode<T>(data);
//			_Tail = _Tail->_pNext;
//		}
//		_size++;
//	}
//	void Pop()
//	{
//		assert(_Front);//队列中没有节点
//		QNode<T>* Del = _Front;
//		if(NULL == _Front->_pNext)//队列只有一个节点
//		{
//			Del = _Front;
//			_Front = _Tail = NULL;
//			delete Del;
//			Del = NULL;
//		}
//		else
//		{
//			Del = _Front;
//			_Front = Del->_pNext;
//			delete Del;
//			Del = NULL;
//		}
//		_size--;
//	}
//	bool Empty()
//	{
//		return _size==0;
//	}
//	void Clear()
//	{
//		QNode<T>* Cur = _Front;
//		QNode<T>* Del = _Front;
//		while(Cur)
//		{
//			Del = Cur;
//			Cur = Cur->_pNext;
//			delete Del;
//			Del = NULL;
//		}
//	}
//	size_t Size()const
//	{
//		return _size;
//	}
//	T& Front()
//	{
//		assert(_Front);
//		return _Front->_data;
//	}
//	T& Back()
//	{
//		assert(_Tail);
//		return _Tail->_data;
//	}
//    const T& Front()const
//	{
//		assert(_Front);
//		return _Front->_data;
//	}
//	const T& Back()const
//	{
//		assert(_Tail);
//		return _Tail->_data;
//	}
//protected:
//	QNode<T>* _Front;//队首指针
//	QNode<T>* _Tail;//队尾指针
//	size_t _size;//记录当前队列有几个节点
//};
//
//
//void TestQueue()
//{
//	Queue<int> s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	s1.Push(5);
//
//	Queue<int> s2(s1);
//	s2.Pop();
//	s2.Pop();
//	s2.Pop();
//	Queue<int> s3;
//	s3 = s2;
//	cout<<"s3.size:"<<s3.Size()<<endl;
//	cout<<"s1.front;"<<s1.Front()<<endl;
//	cout<<"s1.back;"<<s1.Back()<<endl;
//	while(!s1.Empty())
//	{
//		cout<<s1.Front()<<" ";
//		s1.Pop();
//	}
//	cout<<endl;
//}
//int main()
//{
//	TestQueue();
//	system("pause");
//	return 0;
//}


//#include <stack>
//
//enum Type
//{
//	OP_SYMBOL,
//	OP_NUM,
//	ADD,
//	SUB,
//	MUL,
//	DIV,
//};
//
//struct Cell
//{
//	Type _type;
//	int _value;
//};
//
//int RPN(Cell* rpn,size_t n)
//{
//	assert(rpn);
//	stack<int> s;
//	for (size_t i = 0; i<n; i++)
//	{
//		if (rpn[i]._type == OP_NUM)
//		{
//			s.push(rpn[i]._value);
//		}
//		else if (rpn[i]._type == OP_SYMBOL)
//		{
//			int right = s.top();
//			s.pop();
//			int left = s.top();
//			s.pop();
//
//			switch(rpn[i]._value)
//			{
//			case ADD:
//				s.push(left + right);
//				break;
//			case SUB:
//				s.push(left - right);
//				break;
//			case MUL:
//				s.push(left * right);
//				break;
//			case DIV:
//				//assert(right == 0);
//				s.push(left / right);
//				break;
//			default:
//				//assert(false);
//				throw std::invalid_argument("表达式错误！");
//			}
//		}
//		else
//		{
//			assert(false);
//		}
//	}
//	return s.top();
//}
//
//void TestRPN()
//{
//	//eg:12 * (3 + 4) - 6 + 8/2
//	Cell rpn[] = {{OP_NUM,12},{OP_NUM,3},{OP_NUM,4},
//	{OP_SYMBOL,ADD},{OP_SYMBOL,MUL},{OP_NUM,6},{OP_SYMBOL,SUB},
//	{OP_NUM,8},{OP_NUM,2},{OP_SYMBOL,DIV},{OP_SYMBOL,ADD}};
//	cout<<"12 * (3+4) - 6 + 8/2 = "<<RPN(rpn,sizeof(rpn)/sizeof(rpn[0]))<<endl;
//}
//int main()
//{
//	try
//	{
//		TestRPN();
//	}
//	catch (exception& e)
//	{
//		//多态
//		cout<<e.what()<<endl;
//	}
//	system("pause");
//	return 0;
//}