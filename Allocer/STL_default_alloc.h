#pragma once

enum {ALIGN = 8};                      //小型区块的上调边界
enum {MAX_BYTES = 128};                //小型区块的上限
enum {NFREELISTS = MAX_BYTES/ALIGN};    //free-list个数

//二级空间配置器
template <bool threads,int ints>
class __DefaultAllocTemplate
{
private:
	//将bytes调至ALIGN(8)的倍数
	static size_t RoundUp(size_t bytes)
	{
		return ((bytes+ALIGN-1) & ~(ALIGN-1));
	}
public:
	union Obj//FreeLists的节点构造
	{
		Obj* FreeListLink;
		char ClientData[1];/* The client sees this. */
	};
private:
	static Obj* volatile FreeList[NFREELISTS];//16个free-lists

	//根据块大小，决定使用第n号free-list,n从0开始
	static size_t FreeListIndex(size_t bytes)
	{
		return ((bytes+ALIGN-1)/ALIGN-1);
	}

	//返回一个大小为n的对象，并可能加入大小为n的其他区块到free-list
	static void* Refill(size_t n);

	//配置一块大空间，可容纳nobjs个大小为size的区块
	//如果空间不够，nobjs可能会被改小
	static char *ChunkAlloc(size_t size, int &nobjs);

	// Chunk allocation state.
	static char* StartFree;
	static char* EndFree;
	static size_t HeapSize;

public:
	//空间配置函数
	static void* Allocate(size_t n)//n>0
	{
		Obj* volatile* MyFreeList;
		Obj* result;

		//申请的字节数>128就调用一级空间配置器
		if (n > MAX_BYTES)
		{
			return (__MallocAlloc::Allocate(n));
		}

		//寻找自由链表的适当位置
		MyFreeList = FreeList + FreeListIndex(n);
		result = *MyFreeList;

		//没找到可用的free-list，重新填充free-list
		if (0 == result)
		{
			void* tmp = Refill(RoundUp(n));
			return tmp;
		}

		//区块从free-list中拔出，调整free-list
		*MyFreeList = result->FreeListLink;
		return result;
	}


	//空间释放函数
	static void Deallocate(void* p, size_t n)//n != 0   deiete
	{
		Obj* q = (Obj*)p;
		Obj* volatile* MyFreeList;

		//如果n>128,则调用一级空间配置器
		if (n > MAX_BYTES)
		{
			__MallocAlloc::Deallocate(p,n);
		}

		//寻找free-list的适合位置
		MyFreeList = FreeList + FreeListIndex(n);
		
		//将释放的内存块重新挂到自由链表的适当位置
		q->FreeListLink = *MyFreeList;
		*MyFreeList = q;
	}

	//重新分配内存
	static void* Reallocate(void *p, size_t oldSz, size_t newSz)
	{
		void* result;
		size_t CopySize;//要拷贝的字节数

		//如果原先开辟的字节数和新字节数均>128,则直接调用系统的realloc()进行重置空间
		if (oldSz > MAX_BYTES && newSz > MAX_BYTES)
		{
			return realloc(p,newSz);
		}

		//如果新字节与旧字节向上调整到8的倍数后相等，则空间不用变，可以直接返回
		if (RoundUp(oldSz) == RoundUp(newSz)) 
		{
			return(p);
		}

		//申请新空间
		result = Allocate(newSz);

		//新字节>旧字节，则要将旧字节的所有内容进行拷贝
		if (newSz > oldSz)
		{
			CopySize = oldSz;
		}
		//只需要拷贝一部分内容
		else
		{
			CopySize = newSz;
		}
		//调用内存拷贝函数进行拷贝
		memcpy(result, p, CopySize);

		//将原有的空间释放
		Deallocate(p, oldSz);
		return(result);
	}
};

template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::StartFree = 0;//内存池的起始指针

template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::EndFree = 0;//内存池的末尾指针

template <bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::HeapSize = 0;//记录已经向系统申请的内存字节
 
template <bool threads, int inst>
typename __DefaultAllocTemplate<threads,inst>::Obj* volatile//前面加typename表示后面是类型
__DefaultAllocTemplate<threads,inst>::FreeList[NFREELISTS] = {0};//自由链表


//重新填充free-list：返回一个大小为n的对象，有时会为free-list增加节点
//假设n已适当上调至8的倍数
template <bool threads, int inst>
void* __DefaultAllocTemplate<threads,inst>::Refill(size_t n)//n表示要申请的字节数
{
	int nobjs = 20;//默认每次申请20块空间

	//调用ChunkAlloc(),尝试取nobjs个区块作为free=list的新结点
	char* chunk = ChunkAlloc(n,nobjs);
	
	//只申请到一个对象的大小，直接返回
	if (1 == nobjs)
	{
		return chunk;
	}
	//至少申请到两个对象的大小
	Obj* result,* cur;
	result = (Obj*)chunk;//将申请到的第一个对象作为返回值
	size_t index = FreeListIndex(n);

	//将剩下的区块挂入自由链表
	cur = (Obj*)(chunk+n);
	FreeList[index] = cur;//将第二块内存挂入自由链表

	//将剩余的n-2个对象挂进自由链表
	for (size_t i = 2; i < n; ++i)
	{
		cur->FreeListLink = (Obj*)(chunk+n*i);
		cur = cur->FreeListLink;
	}
	//将挂对象链表的末端置空
	cur->FreeListLink = NULL;

	return result;
}

//从内存池中申请大块内存给free-list用
//假设size已适当上调至8的倍数
template <bool threads, int inst>
char* __DefaultAllocTemplate<threads,inst>::ChunkAlloc(size_t size, int &nobjs)
{
	char* result;
	size_t TotalBytes = size * nobjs;      //本次需要申请的总字节数
	size_t LeftBytes = EndFree - StartFree;//内存池剩余的总字节数

	//内存池的内存足够分配：皆大欢喜
	if (LeftBytes >= TotalBytes)
	{
		result = StartFree;
		StartFree += TotalBytes;
		return result;
	}

	//内存池剩余内存不够分配nobjs个对象但是至少够分配一个对象:尽力而为
	else if (LeftBytes > size)
	{
		nobjs = LeftBytes / size;
		result = StartFree;
		StartFree += nobjs*size;
		return result;
	}

	//内存池剩余字节连一个对象都不够分配：倾其所有，绞尽脑汁
	else
	{
		//此时内存池中剩余的字节数一定是8的倍数，BytesToGet内存池要开辟的新容量
		size_t BytesToGet = 2 * TotalBytes + RoundUp(HeapSize>>4);//>>4相当于除16

		//如果内存池还有一些零头，先将其分配给free-list
		if (LeftBytes > 0)
		{
			//寻找适当位置的free-list
			Obj* volatile* MyFreeList = FreeList + FreeListIndex(LeftBytes);

			//调整free-list，将内存池的零头内存挂入自由链表
			((Obj*)StartFree)->FreeListLink = *MyFreeList;
			*MyFreeList = (Obj*)StartFree;
		}

		//配置heap空间，用来补充内存池
		StartFree = (char*)malloc(BytesToGet);

		//heap空间不足，malloc失败
		if (0 == StartFree)
		{
			Obj* volatile* MyFreeList,*p;
			//到更大的自由链表中去找是否有空间可分配
			for (int i = size; i <= MAX_BYTES; i += ALIGN)
			{
				MyFreeList = FreeList + FreeListIndex(i);
				p = *MyFreeList;
				//free-list还有未使用的区块
				if (NULL != p)
				{
					//调整free-list以释放出未使用的区块
					*MyFreeList = p->FreeListLink;
					StartFree = (char*)p;
					EndFree = StartFree + i;

					//递归调用自己，为了修正nobjs,同时实现代码复用，重新分配大块内存
					return ChunkAlloc(size,nobjs);

					//注意：任何残余零头终将被编入适当的free-list中备用
				}
			}
			//山穷水尽，到处都没内存可用了
			EndFree = 0;
			//调用一级空间配置器，看看内存不足的句柄函数是否能挽救
			StartFree = (char*)__MallocAlloc::Allocate(BytesToGet);
			//要么解救成功，要么抛异常或调用释放内存机制时崩溃
		}
		//申请成功，更新HeapSize(记录总共向系统申请了多少内存)，更新EndFree
		HeapSize += BytesToGet;
		EndFree = StartFree + BytesToGet;

		//递归调用自己，为了修正nobjs,同时实现代码复用，重新分配大块内存
		return ChunkAlloc(size,nobjs);
	}
}

typedef __DefaultAllocTemplate<false, 0> __DefaultAlloc;