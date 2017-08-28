#pragma once

enum {ALIGN = 8};                      //С��������ϵ��߽�
enum {MAX_BYTES = 128};                //С�����������
enum {NFREELISTS = MAX_BYTES/ALIGN};    //free-list����

//�����ռ�������
template <bool threads,int ints>
class __DefaultAllocTemplate
{
private:
	//��bytes����ALIGN(8)�ı���
	static size_t RoundUp(size_t bytes)
	{
		return ((bytes+ALIGN-1) & ~(ALIGN-1));
	}
public:
	union Obj//FreeLists�Ľڵ㹹��
	{
		Obj* FreeListLink;
		char ClientData[1];/* The client sees this. */
	};
private:
	static Obj* volatile FreeList[NFREELISTS];//16��free-lists

	//���ݿ��С������ʹ�õ�n��free-list,n��0��ʼ
	static size_t FreeListIndex(size_t bytes)
	{
		return ((bytes+ALIGN-1)/ALIGN-1);
	}

	//����һ����СΪn�Ķ��󣬲����ܼ����СΪn���������鵽free-list
	static void* Refill(size_t n);

	//����һ���ռ䣬������nobjs����СΪsize������
	//����ռ䲻����nobjs���ܻᱻ��С
	static char *ChunkAlloc(size_t size, int &nobjs);

	// Chunk allocation state.
	static char* StartFree;
	static char* EndFree;
	static size_t HeapSize;

public:
	//�ռ����ú���
	static void* Allocate(size_t n)//n>0
	{
		Obj* volatile* MyFreeList;
		Obj* result;

		//������ֽ���>128�͵���һ���ռ�������
		if (n > MAX_BYTES)
		{
			return (__MallocAlloc::Allocate(n));
		}

		//Ѱ������������ʵ�λ��
		MyFreeList = FreeList + FreeListIndex(n);
		result = *MyFreeList;

		//û�ҵ����õ�free-list���������free-list
		if (0 == result)
		{
			void* tmp = Refill(RoundUp(n));
			return tmp;
		}

		//�����free-list�аγ�������free-list
		*MyFreeList = result->FreeListLink;
		return result;
	}


	//�ռ��ͷź���
	static void Deallocate(void* p, size_t n)//n != 0   deiete
	{
		Obj* q = (Obj*)p;
		Obj* volatile* MyFreeList;

		//���n>128,�����һ���ռ�������
		if (n > MAX_BYTES)
		{
			__MallocAlloc::Deallocate(p,n);
		}

		//Ѱ��free-list���ʺ�λ��
		MyFreeList = FreeList + FreeListIndex(n);
		
		//���ͷŵ��ڴ�����¹ҵ�����������ʵ�λ��
		q->FreeListLink = *MyFreeList;
		*MyFreeList = q;
	}

	//���·����ڴ�
	static void* Reallocate(void *p, size_t oldSz, size_t newSz)
	{
		void* result;
		size_t CopySize;//Ҫ�������ֽ���

		//���ԭ�ȿ��ٵ��ֽ��������ֽ�����>128,��ֱ�ӵ���ϵͳ��realloc()�������ÿռ�
		if (oldSz > MAX_BYTES && newSz > MAX_BYTES)
		{
			return realloc(p,newSz);
		}

		//������ֽ�����ֽ����ϵ�����8�ı�������ȣ���ռ䲻�ñ䣬����ֱ�ӷ���
		if (RoundUp(oldSz) == RoundUp(newSz)) 
		{
			return(p);
		}

		//�����¿ռ�
		result = Allocate(newSz);

		//���ֽ�>���ֽڣ���Ҫ�����ֽڵ��������ݽ��п���
		if (newSz > oldSz)
		{
			CopySize = oldSz;
		}
		//ֻ��Ҫ����һ��������
		else
		{
			CopySize = newSz;
		}
		//�����ڴ濽���������п���
		memcpy(result, p, CopySize);

		//��ԭ�еĿռ��ͷ�
		Deallocate(p, oldSz);
		return(result);
	}
};

template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::StartFree = 0;//�ڴ�ص���ʼָ��

template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::EndFree = 0;//�ڴ�ص�ĩβָ��

template <bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::HeapSize = 0;//��¼�Ѿ���ϵͳ������ڴ��ֽ�
 
template <bool threads, int inst>
typename __DefaultAllocTemplate<threads,inst>::Obj* volatile//ǰ���typename��ʾ����������
__DefaultAllocTemplate<threads,inst>::FreeList[NFREELISTS] = {0};//��������


//�������free-list������һ����СΪn�Ķ�����ʱ��Ϊfree-list���ӽڵ�
//����n���ʵ��ϵ���8�ı���
template <bool threads, int inst>
void* __DefaultAllocTemplate<threads,inst>::Refill(size_t n)//n��ʾҪ������ֽ���
{
	int nobjs = 20;//Ĭ��ÿ������20��ռ�

	//����ChunkAlloc(),����ȡnobjs��������Ϊfree=list���½��
	char* chunk = ChunkAlloc(n,nobjs);
	
	//ֻ���뵽һ������Ĵ�С��ֱ�ӷ���
	if (1 == nobjs)
	{
		return chunk;
	}
	//�������뵽��������Ĵ�С
	Obj* result,* cur;
	result = (Obj*)chunk;//�����뵽�ĵ�һ��������Ϊ����ֵ
	size_t index = FreeListIndex(n);

	//��ʣ�µ����������������
	cur = (Obj*)(chunk+n);
	FreeList[index] = cur;//���ڶ����ڴ������������

	//��ʣ���n-2������ҽ���������
	for (size_t i = 2; i < n; ++i)
	{
		cur->FreeListLink = (Obj*)(chunk+n*i);
		cur = cur->FreeListLink;
	}
	//���Ҷ��������ĩ���ÿ�
	cur->FreeListLink = NULL;

	return result;
}

//���ڴ�����������ڴ��free-list��
//����size���ʵ��ϵ���8�ı���
template <bool threads, int inst>
char* __DefaultAllocTemplate<threads,inst>::ChunkAlloc(size_t size, int &nobjs)
{
	char* result;
	size_t TotalBytes = size * nobjs;      //������Ҫ��������ֽ���
	size_t LeftBytes = EndFree - StartFree;//�ڴ��ʣ������ֽ���

	//�ڴ�ص��ڴ��㹻���䣺�Դ�ϲ
	if (LeftBytes >= TotalBytes)
	{
		result = StartFree;
		StartFree += TotalBytes;
		return result;
	}

	//�ڴ��ʣ���ڴ治������nobjs�����������ٹ�����һ������:������Ϊ
	else if (LeftBytes > size)
	{
		nobjs = LeftBytes / size;
		result = StartFree;
		StartFree += nobjs*size;
		return result;
	}

	//�ڴ��ʣ���ֽ���һ�����󶼲������䣺�������У��ʾ���֭
	else
	{
		//��ʱ�ڴ����ʣ����ֽ���һ����8�ı�����BytesToGet�ڴ��Ҫ���ٵ�������
		size_t BytesToGet = 2 * TotalBytes + RoundUp(HeapSize>>4);//>>4�൱�ڳ�16

		//����ڴ�ػ���һЩ��ͷ���Ƚ�������free-list
		if (LeftBytes > 0)
		{
			//Ѱ���ʵ�λ�õ�free-list
			Obj* volatile* MyFreeList = FreeList + FreeListIndex(LeftBytes);

			//����free-list�����ڴ�ص���ͷ�ڴ������������
			((Obj*)StartFree)->FreeListLink = *MyFreeList;
			*MyFreeList = (Obj*)StartFree;
		}

		//����heap�ռ䣬���������ڴ��
		StartFree = (char*)malloc(BytesToGet);

		//heap�ռ䲻�㣬mallocʧ��
		if (0 == StartFree)
		{
			Obj* volatile* MyFreeList,*p;
			//�����������������ȥ���Ƿ��пռ�ɷ���
			for (int i = size; i <= MAX_BYTES; i += ALIGN)
			{
				MyFreeList = FreeList + FreeListIndex(i);
				p = *MyFreeList;
				//free-list����δʹ�õ�����
				if (NULL != p)
				{
					//����free-list���ͷų�δʹ�õ�����
					*MyFreeList = p->FreeListLink;
					StartFree = (char*)p;
					EndFree = StartFree + i;

					//�ݹ�����Լ���Ϊ������nobjs,ͬʱʵ�ִ��븴�ã����·������ڴ�
					return ChunkAlloc(size,nobjs);

					//ע�⣺�κβ�����ͷ�ս��������ʵ���free-list�б���
				}
			}
			//ɽ��ˮ����������û�ڴ������
			EndFree = 0;
			//����һ���ռ��������������ڴ治��ľ�������Ƿ������
			StartFree = (char*)__MallocAlloc::Allocate(BytesToGet);
			//Ҫô��ȳɹ���Ҫô���쳣������ͷ��ڴ����ʱ����
		}
		//����ɹ�������HeapSize(��¼�ܹ���ϵͳ�����˶����ڴ�)������EndFree
		HeapSize += BytesToGet;
		EndFree = StartFree + BytesToGet;

		//�ݹ�����Լ���Ϊ������nobjs,ͬʱʵ�ִ��븴�ã����·������ڴ�
		return ChunkAlloc(size,nobjs);
	}
}

typedef __DefaultAllocTemplate<false, 0> __DefaultAlloc;