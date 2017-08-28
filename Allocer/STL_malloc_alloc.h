#pragma once

typedef void(*MallocAlloc)(); //������ָ��void(*)()����ΪMallocAlloc
//һ���ռ�������
template <int inst>
class __MallocAllocTemplate
{
private:
	//���º������������ڴ治������
	static void *OOM_Malloc(size_t);//�ڴ����ʧ���Ժ���ľ��handler����

	static void *OOM_Realloc(void *, size_t);//�ڴ����ʧ���Ժ���ľ��handler����

	static void (* __MallocAllocOomHandler)();//����ָ�룬�ڴ治��ʱ��Ĵ������

public:
	//����ռ�
	static void* Allocate(size_t n)
	{
		//һ���ռ�������ֱ��ʹ��malloc���ٿռ�
		void* result = malloc(n);

		//����ڴ治��ʱ������OOM_Malloc()
		if (NULL == result)
		{
			OOM_Malloc(n);
		}
		return result;
	}

	//�ͷ��ڴ�delete[]
	static void Deallocate(void* p,size_t /* n */)
	{
		free(p);//һ���ռ��������ͷſռ�ֱ�ӵ���free()
	}

	//�ͷ��ڴ�delete
	static void Deallocate(void* p)
	{
		free(p);//һ���ռ��������ͷſռ�ֱ�ӵ���free()
	}

	//���·����ڴ�
	static void* ReAllocate(void* p,size_t newSize)
	{
		//һ���ռ�������ֱ��ʹ��realloc()���ٿռ�
		void* result = realloc(p,newSize);

		//����ڴ治��ʱ������OOM_Realloc()
		if (NULL == result)
		{
			OOM_Realloc(p,newSize);
		}
		return result;
	}

	//�ڴ����ʧ�ܵľ������������ֵ�������Ϊ����ָ��
	static MallocAlloc set_malloc_handler(MallocAlloc f)
	{
		MallocAlloc old = __MallocAllocOomHandler;
		//���ڴ����ʧ�ܵľ����Ϊf
		//(����ָ��һ���ڴ�ʧ���ˣ���ϵͳȥ�ͷ������ط��ռ�ĺ���)
		__MallocAllocOomHandler = f;
		return (old);
	}
};

//�����ڴ�(mallocʧ��ʱ���ñ�����,����handler�ͷ��ڴ��,����ͨ��malloc�����ڴ�)
template <int inst>
void* __MallocAllocTemplate<inst>::OOM_Malloc(size_t n)
{
	MallocAlloc MyMallocHandler;//����һ������ָ��
	void* result = NULL;

	//���ϳ����ͷš����ã����ͷš������á���
	while (1)
	{
		MyMallocHandler = __MallocAllocOomHandler;
		if (0 == MyMallocHandler)//û�������ڴ治�㴦�����
		{
			cout<<"out of memory!\n";//���쳣
			exit(-1);
		}
		(*MyMallocHandler)();//�����ڴ治�㴦���������������ط��ͷŵ��ڴ�
		result = malloc(n); //�ٴγ��������ڴ�
		if (result)
		{
			return (result);//����ɹ�ʱ����������ڴ�ĵ�ַ
		}
	}
	return result;
}

//�����ڴ�(reallocʧ��ʱ���ñ�����,����handler�ͷ��ڴ��,����ͨ��realloc�����ڴ�)
template <int inst>
void* __MallocAllocTemplate<inst>::OOM_Realloc(void* p,size_t newSize)
{
	MallocAlloc MyAllocHandler;//����һ������ָ��
	void* result = NULL;

	//���ϳ����ͷš����ã����ͷš������á���
	while(1)
	{
		MyMallocHandler = __MallocAllocOomHandler;
		if (0 == MyMallocHandler)//û�������ڴ治�㴦�����
		{
			_THROW_BAD_ALLOC;//���쳣
		}
		(*MyMallocHandler)();//�����ڴ治�㴦���������������ط��ͷŵ��ڴ�
		result = realloc(p,newSize);
		if (result)
		{
			return (result);
		}
	}
	return result;
}

//�����ڴ�ʧ�ܴ������ľ������ָ��
template <int inst>
void (*__MallocAllocTemplate<inst>::__MallocAllocOomHandler)() = 0;//Ĭ�ϲ������ڴ治��Ĵ������

//������instָ��Ϊ0
typedef __MallocAllocTemplate<0> __MallocAlloc;