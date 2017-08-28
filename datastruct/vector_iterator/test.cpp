//#include <iostream>
//#include <vector>
//using namespace std;
// 
//template <typename T,typename Ref,typename Ptr>
//struct VectorIterator
//{
//	typedef VectorIterator<T,Ref,Ptr> Self;
//	
//	VectorIterator(const Ptr p)
//		:_ptr(p)
//	{}
//	VectorIterator()
//	{}
//
//	bool operator==(const Ptr p)
//	{
//		return _ptr == p;
//	}
//	bool operator!=(const Ptr r)
//	{
//		return _ptr != r;
//	}
//	Ref operator*()
//	{
//		return *_ptr;
//	}
//	Ptr operator->()
//	{
//		return &_ptr;
//	}
//	Self& operator++()//前置++
//	{ 
//		++_ptr;
//		return *this;
//	}
//	Self operator++(int)//后置++
//	{
//		T* tmp(_ptr);
//		_ptr++;
//		return tmp;
//	}
//	Self& operator--()//前置--
//	{
//		--_ptr;
//		return *this;
//	}
//	Self operator--(int)//后置--
//	{
//		T* tmp(_ptr);
//		_ptr--;
//		return tmp;
//	}
//protected:
//	T* _ptr;//数据
//};
//
//template <typename T>
//class Vector//顺序表
//{
//public:
//	typedef VectorIterator<T,T&,T*> Iterator;
//	typedef VectorIterator<const T,const T&,const T*> ConstIterator;
//public:
//	Vector(const T& data)
//		:_data(data)
//		,_size(0)
//		,_capacity(0)
//	{}
//	Vector()
//	{}
//	T& Begin()const
//	{
//		assert(_size==0);
//		return _data[0];
//	}
//	T& Back()const
//	{
//		return _data[];
//	}
//	void PrintVector()
//	{
//		Vector<int>::Iterator it1 = _data.Begin();
//		while(it1 != _data.End())
//		{
//			cout<<*it1<<" ";
//			it1++;
//		}
//	}
//	void PrintConstVector()
//	{
//		Vector<int>::ConstIterator it1 = _data.Begin();
//		while(it1 != _data.End())
//		{
//			cout<<*it1<<" ";
//			it1++;
//		}
//	}
//protected:
//	T* _data;
//	size_t _size;
//	size_t _capacity;
//};
//
//
//void TestVector()
//{
//	vector<int> v1;
//	v1.begin();
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.PrintVector();
//	cout<<endl;
//	cout<<"size:"<<v1.size()<<endl;
//	cout<<"capacity:"<<v1.capacity()<<endl;
//
//}
//
//int main()
//{
//	TestVector();
//	system("pause");
//	return 0;
//}




#include <iostream>
#include <assert.h>
using namespace std;

//类型萃取
struct TrueType
{
	bool Get()
	{
		return true;
	}
};
struct FalseType
{
	bool Get()
	{
		return false;
	}
};

template <class Tp>
struct TypeTraits
{
	typedef FalseType IsPODType;
};

template<>
struct TypeTraits<bool>//bool类型的特化
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<short>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<long>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<char>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<long long>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<unsigned int>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<unsigned char>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<unsigned short>
{
	typedef TrueType IsPODType;
};



//Vector模拟
template <typename T>
class Vector
{
public:
	typedef T* Iterator;
	typedef const T* ConstIterator;
	//construcor
	Vector()
		:_start(0)
		,_last(0)
		,_endofstorage(0)
	{}
	//普通版本的拷贝构造
	Vector(const Vector<T>& v)
   		:_start(new T[v.Size()])
	{
		_last = _start + v.Size();
		_endofstorage = _start + v.Capacity();
		//类型萃取
		if (TypeTraits<T>::IsPODType().Get())
		{
			//内置类型
			memcpy(_start,v._start,v.Size()*sizeof(T));
		}
		else
		{
			//自定义类型
			for(size_t i = 0; i<v.Size(); i++)
			{
				_start[i] = v._start[i];
			}
		}
	}
	////简洁版的拷贝构造函数
	//Vector(const Vector<T>& v)
	//	:_start(NULL)
	//{
	//	T* tmp(v._start);
	//	swap(_start,tmp);
	//	_last = _start + v.Size();
	//	_endofstorage = _start + v.Capacity();
	//}

	//普通版本的赋值运算符重载
	Vector& operator=(const Vector<T>& v)
	{
		if (_start != v._start)
		{
			T* tmp = new T[v.Capacity()];
			//类型萃取
			if (TypeTraits<T>::IsPODType().Get())
			{
				//内置类型
				memcpy(tmp,v._start,v.Size()*sizeof(T));
			}
			else
			{
				//自定义类型
				for(size_t i = 0; i<v.Size(); i++)
				{
					tmp[i] = v._start[i];
				}
			}
			delete []_start;
			_start = tmp;
			_last = _start + v.Size();
			_endofstorage = _start + v.Capacity();
		}
		return *this;
	}
	////简洁版的赋值运算符重载<1>
	//Vector& operator=(const Vector<T>& v)
	//{
	//	if (_start != v._start)//排除自己给自己赋值
	//	{
	//		Vector<T> tmp(v);//创建临时变量，辅助交换
	//		swap(_start,tmp._start);
	//		_last = _start + v.Size();
	//		_endofstorage = _start + v.Capacity();
	//	}
	//	return *this;
	//}
	//简洁版的赋值运算符重载<2>
	//Vector& operator=(Vector<T> v)
	//{
	//	size_t size = v.Size();//先保存元素个数
	//	size_t capacity = v.Capacity();//保存容量
	//	swap(_start,v._start);//直接交换
	//	_last = _start + size;
	//	_endofstorage = _start + capacity;
	//	return *this;
	//}

	~Vector()
	{
		if(_start)
		{
			delete []_start;
			_start = NULL;
		}
	}

	//Iterator
	Iterator Begin()
	{
		assert(_start);
		return _start;
	}
	ConstIterator Begin()const
	{
		assert(_start);
		return _start;
	}
	Iterator End()
	{
		assert(_last);
		return _last;
	}
	ConstIterator End()const
	{
		assert(_last);
		return _last;
	}

	//capacity
	size_t Size()const
	{
		return (_last - _start);
	}
	size_t Capacity()const
	{
		return (_endofstorage - _start);
	}
	bool Empty()
	{
		return Size()==0;
	}
	void Resize(size_t sz)
	{
		if (Size() > sz)
		{
			_last = _start + sz;
		}
		else if(Size() == sz)
		{
			;
		}
		else
		{
			size_t size = Size();
			_last = _start + sz;
			CheckCapacity();
			for (size_t i = size; i<sz; i++)
			{
				_start[i] = 0;//设默认值为0
			}
		}
	}
	void Reserve(size_t sz)
	{
		if (Capacity() > sz)
		{
			_endofstorage = _start + sz;
		}
		else if(Capacity() == sz)
		{
			;
		}
		else
		{
			_endofstorage = _start + sz;
			CheckCapacity();
		}
	}

	//Element access
	T& operator[](size_t index)
	{
		assert(index>=0 && index<Size());
		return _start[index];
	}
	T Front()
	{
		assert(_start);
		return *Begin();
	}
	const T Front()const
	{
		assert(_start);
		return *Begin();
	}
	T Back()
	{
		assert(_last);
		return *(_last - 1);
	}
	const T Back()const
	{
		assert(_last);
		return *(_last - 1);
	}

	//modifities
	void PushBack(const T& x)
	{
		CheckCapacity();
		Insert(_last,x);
	}
	void PopBack()
	{
		assert(_start != _last);
		Erase(_last-1);
	}
	Iterator Find(const T& data)
	{
		Vector<T>::Iterator it = Begin();
		while(it != End())
		{
			if(*it == data)
				break;
			it++;
		}
		return it;
	}
	Iterator Insert(Iterator pos, const T& x )
	{
		assert(pos>=_start && pos<=_last);
		CheckCapacity();
        if (pos == _start)//容器中无元素
		{
			*_start = x;
		}
		else if(pos == _last)//尾插
		{
			*_last = x;
		}
		else
		{
			size_t tmp = _last - pos;
			size_t i = 0;
			for (i = Size(); i >= tmp; i--)//将后面的元素向后移
			{
				_start[i] = _start[i-1];
			}
			_start[i] = x;
		}
		_last++;
		
		return  pos;
	}
	Iterator Erase(Iterator pos)
	{
		assert(_start != _last);
		if (pos == _last-1)//尾删
		{
			;
		}
		else
		{
			size_t tmp = pos - _start;
			for (size_t i = tmp; i < Size()-1; i++)//将pos后面的元素向前移
			{
				_start[i] = _start[i+1];
			}
		}
		_last--;
		return pos+1;
	}
	void Clear()//只清数据，不清空间
	{
		assert(_start != _last);
		_last = _start;
	}
	void Swap(Vector<T>& v)
	{
		Vector<T> tmp(v);

		v = *this;
		*this = tmp;
	}
private:
	void CheckCapacity()//检查容量
	{
		if(Size() >= Capacity())//说明需要扩容
		{
			size_t size = Size();
			size_t capacity = Capacity()*2 +3;
			Iterator tmp = new T[capacity];
			//类型萃取
			if (TypeTraits<T>::IsPODType().Get())
			{
				//内置类型
				memcpy(tmp,_start,size*sizeof(T));
			}
			else
			{
				//自定义类型
				for(size_t i = 0; i<size; i++)
				{
					tmp[i] = _start[i];
				}
			}

			delete []_start;
			_start = tmp;
			_last = _start + size;
			_endofstorage = _start + capacity;
		}
	}

protected:
	Iterator _start;//存放第一个元素的位置
	Iterator _last;//最后一个元素的下一个位置
	Iterator _endofstorage;//已开辟容量的下一个位置
};

template <typename T>
void PrintVector(Vector<T>& v)
{
	Vector<int>::Iterator it1 = v.Begin();
	while(it1 != v.End())
	{
		cout<<*it1<<" ";
		it1++;
	}
	cout<<endl;
}
template <typename T>
void PrintConstVector(Vector<T>& v)
{
	Vector<int>::ConstIterator it1 = v.Begin();
	while(it1 != v.End())
	{
		cout<<*it1<<" ";
		it1++;
	}
	cout<<endl;
}

void TestVector()
{
	Vector<int> v1;
	cout<<"v1.Size():"<<v1.Size()<<endl;
	cout<<"v1.Capacity():"<<v1.Capacity()<<endl;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	cout<<"v1.Size():"<<v1.Size()<<endl;
	cout<<"v1.Capacity():"<<v1.Capacity()<<endl;
	PrintVector(v1);
	Vector<int> v2(v1);
	PrintVector(v2);
	Vector<int> v3;
	v3 = v2;
	PrintVector(v3);

	v3.Resize(10);//>size
	PrintVector(v3);
	v3.Resize(3);//<size
	PrintVector(v3);
	v3.Reserve(5);//>capacity
	cout<<v3.Capacity()<<endl;
	v3.Reserve(0);//<capacity
	cout<<v3.Capacity()<<endl;

	cout<<v2.Front()<<endl;
	cout<<v2.Back()<<endl;
	PrintVector(v2);
	v2.PopBack();
	PrintVector(v2);
	v2.Insert(v2.Find(2),6);
	PrintVector(v2);
	v2.Erase(v2.Find(1));
	PrintVector(v2);

	v2.Clear();//只清数据，不清空间
	cout<<"v2.Size():"<<v2.Size()<<endl;
	cout<<"v2.Capacity():"<<v2.Capacity()<<endl;
	v2.Swap(v1);
	PrintVector(v2);
}

int main()
{
	TestVector();
	system("pause");
	return 0;
}