#define _CRT_SECURE_NO_WARNINGS 1
#include"m_seqlist.h"

void init_seqlist(pseq seq)
{
    assert(seq);
	seq->arr = (Datatype *)malloc(3*sizeof(Datatype));//起初先分配3个空间
	if(NULL == seq->arr)
	{
	    printf("out of memory.\n");
		exit(1);
	}
	else
	{
	    memset(seq->arr,0,3*sizeof(Datatype));
		seq->size = 0;
		seq->capacity = 3;
	}
}

void check_capacity(pseq seq)
{
	Datatype *temp = NULL;
	assert(seq);
	if(seq->size >= seq->capacity)//说明容量不够了，需要扩容
	{
		temp = (Datatype *)realloc(seq->arr,(3+seq->capacity*2)*sizeof(Datatype));
		if(NULL == temp)
		{
			printf("out of memory.\n");
			exit(1);
		}
		else
		{
		    seq->arr = temp;
			seq->capacity += 3+seq->capacity*2;
		}
	}
}

void print_seqlist(pseq seq)
{
    int i = 0;
	assert(seq);
	for(i=0; i<seq->size; i++)
	{
		printf("%d->",seq->arr[i]);
	}
	printf("end\n");
}
void pushback(pseq seq,Datatype x)
{
	assert(seq);
    check_capacity(seq);
	seq->arr[seq->size++] = x;
	printf("插入成功\n");
}
void popback(pseq seq)
{
	assert(seq);
	if(seq->size==0)
		printf("顺序表已空\n");
	else
	{
		//方法1：
	    seq->size--;//将最后一个元素删除即可

		////方法2:调用擦除函数实现
		//erase(seq,seq->size-1);
	    printf("删除成功\n");
	}
}
void pushfront(pseq seq,Datatype x)
{
	int i = 0;
	assert(seq);
	check_capacity(seq);
	 //   //方法1(如果顺序表的元素与顺序无关)
		//seq->arr[seq->size]=seq->arr[0];//将首元素保存到最后位置
		//seq->arr[0]=x;
		//seq->size++;

		////方法2:调用插入函数
		//insert(seq,0,x);

		////方法3:
		//int i = 0;
		//for(i=seq->size; i>0; i--)//移动元素
		//{ 
		//	seq->arr[i] = seq->arr[i-1];
		//}
		//seq->arr[0] = x;//插入元素
		//seq->size++;

		//方法4:
	for(i=seq->size-1; i>=0; i--)//移动元素
	{ 
		seq->arr[i+1] = seq->arr[i];
	}
	seq->arr[0] = x;//插入元素
	seq->size++;
	printf("插入成功\n");
}
void popfront(pseq seq)
{
	assert(seq);
	if(seq->size == 0)
		printf("顺序表已空\n");
	else
	{
		//   //方法1(如果顺序表的元素与顺序无关)
		//seq->arr[0]=seq->arr[seq->size-1];//将首元素保存到最后
		//seq->size--;

		////方法2：直接调用擦除函数
		//erase(seq,0);

		////方法3:
		//int i = 0;
		//for(i=0; i<seq->size-1; i++)//移动元素
		//{ 
		//	seq->arr[i] = seq->arr[i+1];
		//}
		//seq->size--;

		//方法4:
		int i = 0;
		for(i = 1; i<seq->size; i++)//移动元素
		{ 
			seq->arr[i-1] = seq->arr[i];
		}
		seq->size--;
	}   
	printf("删除成功\n");
}
void insert(pseq seq,int pos,Datatype x)
{
	int i = 0;
	assert(seq);
	check_capacity(seq);
		////方法1:
	 //   int i = 0;
		//for(i=seq->size; i>pos; i--)
		//{
		//	seq->arr[i] = seq->arr[i-1];
		//}
		//seq->arr[pos] = x;
		//seq->size++;

		//方法2:
		for(i=seq->size-1; i>=pos; i--)
		{
			seq->arr[i+1] = seq->arr[i];
		}
		seq->arr[pos] = x;
		seq->size++;
	printf("插入成功\n");
}
void erase(pseq seq,int pos)
{
	assert(seq);
	if(seq->size==0)
		printf("顺序表已空\n");
	else
	{
	    int i = 0;
		for(i=pos; i<seq->size-1; i++)
		{
			seq->arr[i] = seq->arr[i+1];
		}
		seq->size--;
		printf("擦除成功\n");
	}
}
int find(pseq seq,Datatype x)
{
	int i = 0;
	assert(seq);
	for(i=0; i<seq->size; i++)
	{
		if(seq->arr[i] == x)
			return i;//返回首次出现位置的下标
	}
	return -1;
}
void remmove(pseq seq,Datatype x)
{
	assert(seq);
	if(seq->size==0)
		printf("顺序表已空\n");
	else
	{
		int i = 0;
	    for(i=0; i<seq->size; i++)
		{
			if(seq->arr[i]==x)
			{
				int j = 0;
				for(j=i; j<seq->size; j++)//移动元素
				{
					seq->arr[j]=seq->arr[j+1];
				}
			}
		}
		seq->size--;
		printf("删除成功\n");
	}

}
void remmove_all(pseq seq,Datatype x)
{
	assert(seq);
	if(seq->size==0)
		printf("顺序表已空\n");
	else
	{
	 //   //方法1:找一个删一个
		//int i = 0;
		//int count = 0;
		//for(i=0; i<seq->size; ++i)
		//{
		//	if(seq->arr[i] == x)
		//	{
		//		int j = 0;
		//		for(j=i; j<seq->size; j++)//移动元素
		//		{
		//			seq->arr[j]=seq->arr[j+1];
		//		}
		//		seq->size--;
		//	}
		//}

		//方法2：
		int i = 0;
		int count = 0;
		assert(seq);
		for(i=0; i<seq->size; i++)
		{
			seq->arr[i-count]=seq->arr[i];
			if(seq->arr[i] == x)
				count++;
		}
		seq->size-=count;
	}
		printf("删除成功\n");
}
void empty(pseq seq)
{
	assert(seq);
    if(seq->size == 0)
		printf("顺序表为空\n");
	else
		printf("顺序表不为空\n");
}

int size(pseq seq)
{
    assert(seq);
	return seq->size;
}
void bubble_sort(pseq seq)
{
 //   //普通写法
	//int i = 0;
	//int flag = 0;
	//assert(seq);
	//for(i=0; i<seq->size-1; i++)
	//{
	//    int j = 0;
	//	flag = 0;
	//	for(j=0; j<seq->size-1-i; j++)
	//	{
	//		if(seq->arr[j]>seq->arr[j+1])//升序
	//		{
	//			Datatype temp = seq->arr[j];
	//			seq->arr[j] = seq->arr[j+1];
	//			seq->arr[j+1] = temp;
	//			flag = 1;
	//		}
	//	}
	//	if(flag == 0)
	//		break;
	//}

	//自由选择升序或排序
	int option = 0;
	int i = 0;
	int flag = 0;
	assert(seq);
	printf("请输入你的选择:(0.升序  1.降序)");
	scanf("%d",&option);
	for(i=0; i<seq->size-1; i++)
	{
	    int j = 0;
		flag = 0;
		for(j=0; j<seq->size-1-i; j++)
		{
			if(option == 0)
			{
			    if(seq->arr[j]>seq->arr[j+1])//升序
				{
					Datatype temp = seq->arr[j];
					seq->arr[j] = seq->arr[j+1];
					seq->arr[j+1] = temp;
					flag = 1;
				}
			}
			else if(option == 1)
			{
			    if(seq->arr[j]<seq->arr[j+1])//降序
				{
					Datatype temp = seq->arr[j];
					seq->arr[j] = seq->arr[j+1];
					seq->arr[j+1] = temp;
					flag = 1;
				}
			}
		}
		if(flag == 0)
			break;
	}
	printf("排序成功\n");
}

void select_sort(pseq seq)
{
	;
}

//int binary_search(pseq seq,Datatype x)//假设顺序表已经按升序排列好
//{
//	int left = 0;
//	int right = 0;
//	int mid = 0;
//	assert(seq);
//	////方法1，前闭后闭区间
//	/*right = seq->size-1;
//	while(left <= right)
//	{
//	    mid = left + ((right - left)>>1);
//		if(seq->arr[mid] > x)
//			right = mid-1;
//		else if(seq->arr[mid] < x)
//			left = mid+1;
//		else
//			return mid;
//	}
//	return -1;*/
//
//	////方法2:前闭后开区间
//	//right = seq->size;
//	//while(left < right)
//	//{
//	//    mid = (left & right)+((left ^ right)>>1);
//	//	if(seq->arr[mid] > x)
//	//		right = mid;
//	//	else if(seq->arr[mid] < x)
//	//		left = mid+1;
//	//	else
//	//		return mid;
//	//}
//	//return -1;
//}
//方法3:递归实现
int binary_search(pseq seq,int left,int right,Datatype x)//假设顺序表已经按升序排列好
{
    int mid = 0;
	assert(seq);
    if(left > right)
		return -1;
	mid = left + ((right - left)>>1);
	if(seq->arr[mid] > x)
		return binary_search(seq,left,mid-1,x);
	else if(seq->arr[mid] < x)
		return binary_search(seq,mid+1,right,x);
	else
		return mid;
}

void clear(pseq seq)
{
	assert(seq);
	seq->size = 0;
}
void destroy(pseq seq)
{
	assert(seq);
	free(seq->arr);
	seq->arr = NULL;
}