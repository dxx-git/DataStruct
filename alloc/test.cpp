#include <iostream>
#include "STL_malloc_alloc.h"
#include "STL_default_alloc.h"
using namespace std;

template <class T,class Alloc>
class SimpleAlloc
{
public:
	//相当于new
	static T* Allocate()
	{
		T* ret = (T*)Alloc::Allocate(sizeof(T));
		//定位new表达式，调用构造函数
		new(ret)T();
		return ret;
	}

	//相当于new[]
	static T* Allocate(size_t n)
	{
		T* ret = (T*)Alloc::Allocate(sizeof(T)*n);
		//定位new表达式，依次调用构造函数
		for (size_t i = 0; i < n; ++i)
		{
			new(ret+i)T();
		}
		return ret;
	}

	////相当于delete
	//static void Deallocate(T* p)
	//{
	//	//调用析构函数
	//	p->~T();
	//	//释放空间
	//	Alloc::Deallocate(p);
	//}

	//相当于delete[]
	static void Deallocate(T* p,size_t n)
	{
		//依次调用析构函数
		for (size_t i = 0; i < n; ++i)
		{
			(p+i)->~T();
		}
		//释放空间
		Alloc::Deallocate(p,n);
	}
};

////测试一级空间配置器
//void TestAlloc1()
//{
//	typedef __MallocAllocTemplate<0> MallocAlloc;
//	SimpleAlloc<int,MallocAlloc> sa1;
//
//	int* p1 = sa1.Allocate();//new
//	sa1.Deallocate(p1);     //delete
//
//	int* p2 = sa1.Allocate(10);  //new[]
//	sa1.Deallocate(p2); //delete[]
//
//}

//测试二级空间配置器
void TestAlloc2()
{
	typedef __DefaultAllocTemplate<false,0> DefaultAlloc;
	SimpleAlloc<int,DefaultAlloc> sa2;

	int* p1 = sa2.Allocate();//new
	sa2.Deallocate(p1,sizeof(int));     //delete
}

int main()
{
	//TestAlloc1();
	TestAlloc2();
	system("pause");
	return 0;
}