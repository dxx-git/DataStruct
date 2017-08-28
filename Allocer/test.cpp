#include <iostream>
#include "STL_malloc_alloc.h"
#include "STL_default_alloc.h"
using namespace std;

template <class T,class Alloc>
class SimpleAlloc
{
public:
	//�൱��new
	static T* Allocate()
	{
		T* ret = (T*)Alloc::Allocate(sizeof(T));
		//��λnew���ʽ�����ù��캯��
		new(ret)T();
		return ret;
	}

	//�൱��new[]
	static T* Allocate(size_t n)
	{
		T* ret = (T*)Alloc::Allocate(sizeof(T)*n);
		//��λnew���ʽ�����ε��ù��캯��
		for (size_t i = 0; i < n; ++i)
		{
			new(ret+i)T();
		}
		return ret;
	}

	////�൱��delete
	//static void Deallocate(T* p)
	//{
	//	//������������
	//	p->~T();
	//	//�ͷſռ�
	//	Alloc::Deallocate(p);
	//}

	//�൱��delete[]
	static void Deallocate(T* p,size_t n)
	{
		//���ε�����������
		for (size_t i = 0; i < n; ++i)
		{
			(p+i)->~T();
		}
		//�ͷſռ�
		Alloc::Deallocate(p,n);
	}
};

////����һ���ռ�������
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

//���Զ����ռ�������
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