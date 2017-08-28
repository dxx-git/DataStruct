#pragma once

typedef void(*MallocAlloc)(); //将函数指针void(*)()设置为MallocAlloc
//一级空间配置器
template <int inst>
class __MallocAllocTemplate
{
private:
	//以下函数用来处理内存不足的情况
	static void *OOM_Malloc(size_t);//内存分配失败以后处理的句柄handler类型

	static void *OOM_Realloc(void *, size_t);//内存分配失败以后处理的句柄handler类型

	static void (* __MallocAllocOomHandler)();//函数指针，内存不足时候的处理机制

public:
	//申请空间
	static void* Allocate(size_t n)
	{
		//一级空间配置器直接使用malloc开辟空间
		void* result = malloc(n);

		//如果内存不够时，改用OOM_Malloc()
		if (NULL == result)
		{
			OOM_Malloc(n);
		}
		return result;
	}

	//释放内存delete[]
	static void Deallocate(void* p,size_t /* n */)
	{
		free(p);//一级空间配置器释放空间直接调用free()
	}

	//释放内存delete
	static void Deallocate(void* p)
	{
		free(p);//一级空间配置器释放空间直接调用free()
	}

	//重新分配内存
	static void* ReAllocate(void* p,size_t newSize)
	{
		//一级空间配置器直接使用realloc()开辟空间
		void* result = realloc(p,newSize);

		//如果内存不够时，改用OOM_Realloc()
		if (NULL == result)
		{
			OOM_Realloc(p,newSize);
		}
		return result;
	}

	//内存分配失败的句柄函数，返回值与参数均为函数指针
	static MallocAlloc set_malloc_handler(MallocAlloc f)
	{
		MallocAlloc old = __MallocAllocOomHandler;
		//将内存分配失败的句柄设为f
		//(让它指向一个内存失败了，让系统去释放其他地方空间的函数)
		__MallocAllocOomHandler = f;
		return (old);
	}
};

//申请内存(malloc失败时调用本函数,调用handler释放内存后,继续通过malloc申请内存)
template <int inst>
void* __MallocAllocTemplate<inst>::OOM_Malloc(size_t n)
{
	MallocAlloc MyMallocHandler;//定义一个函数指针
	void* result = NULL;

	//不断尝试释放、配置，再释放、再配置……
	while (1)
	{
		MyMallocHandler = __MallocAllocOomHandler;
		if (0 == MyMallocHandler)//没有设置内存不足处理机制
		{
			cout<<"out of memory!\n";//抛异常
			exit(-1);
		}
		(*MyMallocHandler)();//调用内存不足处理函数，申请其他地方释放的内存
		result = malloc(n); //再次尝试申请内存
		if (result)
		{
			return (result);//申请成功时，返回这块内存的地址
		}
	}
	return result;
}

//申请内存(realloc失败时调用本函数,调用handler释放内存后,继续通过realloc申请内存)
template <int inst>
void* __MallocAllocTemplate<inst>::OOM_Realloc(void* p,size_t newSize)
{
	MallocAlloc MyAllocHandler;//定义一个函数指针
	void* result = NULL;

	//不断尝试释放、配置，再释放、再配置……
	while(1)
	{
		MyMallocHandler = __MallocAllocOomHandler;
		if (0 == MyMallocHandler)//没有设置内存不足处理机制
		{
			_THROW_BAD_ALLOC;//抛异常
		}
		(*MyMallocHandler)();//调用内存不足处理函数，申请其他地方释放的内存
		result = realloc(p,newSize);
		if (result)
		{
			return (result);
		}
	}
	return result;
}

//分配内存失败处理函数的句柄函数指针
template <int inst>
void (*__MallocAllocTemplate<inst>::__MallocAllocOomHandler)() = 0;//默认不设置内存不足的处理机制

//将参数inst指定为0
typedef __MallocAllocTemplate<0> __MallocAlloc;