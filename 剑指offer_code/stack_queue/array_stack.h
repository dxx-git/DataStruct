/*用一个数组实现两个栈*/
#pragma once
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;


enum Choose
{
	First,//对第一个栈进行操作
	SECOND,//对第二个栈进行操作
};

//算法一：
/*将数组的两头分别作为两个栈的栈顶指针，插入数据时向中间靠拢，\
\ 指针相遇说明空间已满，则需对数组进行扩容*/
template <class T>
class ArrayStack
{
public:
	ArrayStack()
		:_n(5)//为了方便测试，默认数组只给5个空间
		,_a(new T[_n])
		,_sTop1(0)
		,_sTop2(_n-1)
	{}
	~ArrayStack()
	{
		if (_a)
		{
			delete []_a;
			_a = NULL;
		}
	}

	void Push1(Choose choose,T data)//入栈(参数choose:选择在哪一个栈中进行入栈)
	{
		assert(_a); //预防数组为空
		
		if(_sTop1 > _sTop2)//当两个下标已经交错,说明数组空间已满，需要扩容
			_Dilatation();//扩容函数

		if (choose == First)//在第一个栈中push数据
			_a[_sTop1++] = data;
		else               //在第二个栈中push数据
		    _a[_sTop2--] = data;
	}
	void Pop1(Choose choose)
	{
		if (choose == First)//pop第一个栈中的元素
		{
			if (_sTop1 == 0)//栈为空
			{
				cout<<"stack1 empty!"<<endl;
				return;
			}
			--_sTop1;//将栈顶下标向前移
		}
		else             //pop第二个栈中的元素
		{
			//size_t size2 = _a+n - _a +_sTop2;//保存栈2 的元素个数
			if (_sTop2 == _n)//栈为空
			{
				cout<<"stack2 empty!"<<endl;
				return;
			}
			++_sTop2;//将栈顶下标向后移
		}
	}
protected:
	void _Dilatation()//扩容函数
	{
		size_t n = _n;//保存旧空间的元素个数
		_n *= 2;          //每次以二倍的速度扩容
		T* tmp = new T[_n];//开辟新空间

		//将栈1中旧空间的内容拷贝到新空间中
		for (size_t i = 0; i < _sTop1; ++i)
		{
			tmp[i] = _a[i];
		}

		size_t size2 = n - _sTop2;//保存栈2的元素个数
		_sTop2 += n+1;//将栈2的栈顶指针相应的向后移动增加的字节数

		//将栈2中旧空间的内容拷贝到新空间中
		for (size_t i = _n-1; --size2; --i)
		{
			tmp[i] = _a[--n];//注意循环条件和赋值方式
		}
		delete []_a;//释放旧空间
		swap(_a,tmp);//指向新空间
	}
private:
	size_t _n;
	T* _a;
	size_t _sTop1;//栈1的栈顶下标
	size_t _sTop2;//栈2的栈顶下标
};


//算法二：
/*将数组的中间两个数据位置分别作为两个栈的栈顶指针，插入数据时向两边走，\
\ 其中有一个指针走到边界说明空间已满，则需对数组进行扩容\
\（有极端情况，一个栈满了，另一个栈很空但仍需扩容，空间利用率低）*/


//算法三：
/*将数组的奇偶位置分别作为两个栈的栈顶指针，插入数据时各自向前走，\
\ 其中有一个指针走到右边界说明空间已满，则需对数组进行扩容\
\（有极端情况，一个栈满了，另一个栈很空但仍需扩容，空间利用率低）*/

void TestArrayStack()
{
	ArrayStack<int> as;
	as.Push1(First,1);
	as.Push1(SECOND,5);
	as.Push1(First,2);
	as.Push1(SECOND,6);
	as.Push1(First,3);
	as.Push1(First,4);

	as.Pop1(First);
	as.Pop1(First);
	as.Pop1(First);
	as.Pop1(First);
	as.Pop1(First);
	as.Pop1(SECOND);
	as.Pop1(SECOND);
	as.Pop1(SECOND);
}