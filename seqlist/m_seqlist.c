#define _CRT_SECURE_NO_WARNINGS 1
#include"m_seqlist.h"

void init_seqlist(pseq seq)
{
    assert(seq);
	seq->arr = (Datatype *)malloc(3*sizeof(Datatype));//����ȷ���3���ռ�
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
	if(seq->size >= seq->capacity)//˵�����������ˣ���Ҫ����
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
	printf("����ɹ�\n");
}
void popback(pseq seq)
{
	assert(seq);
	if(seq->size==0)
		printf("˳����ѿ�\n");
	else
	{
		//����1��
	    seq->size--;//�����һ��Ԫ��ɾ������

		////����2:���ò�������ʵ��
		//erase(seq,seq->size-1);
	    printf("ɾ���ɹ�\n");
	}
}
void pushfront(pseq seq,Datatype x)
{
	int i = 0;
	assert(seq);
	check_capacity(seq);
	 //   //����1(���˳����Ԫ����˳���޹�)
		//seq->arr[seq->size]=seq->arr[0];//����Ԫ�ر��浽���λ��
		//seq->arr[0]=x;
		//seq->size++;

		////����2:���ò��뺯��
		//insert(seq,0,x);

		////����3:
		//int i = 0;
		//for(i=seq->size; i>0; i--)//�ƶ�Ԫ��
		//{ 
		//	seq->arr[i] = seq->arr[i-1];
		//}
		//seq->arr[0] = x;//����Ԫ��
		//seq->size++;

		//����4:
	for(i=seq->size-1; i>=0; i--)//�ƶ�Ԫ��
	{ 
		seq->arr[i+1] = seq->arr[i];
	}
	seq->arr[0] = x;//����Ԫ��
	seq->size++;
	printf("����ɹ�\n");
}
void popfront(pseq seq)
{
	assert(seq);
	if(seq->size == 0)
		printf("˳����ѿ�\n");
	else
	{
		//   //����1(���˳����Ԫ����˳���޹�)
		//seq->arr[0]=seq->arr[seq->size-1];//����Ԫ�ر��浽���
		//seq->size--;

		////����2��ֱ�ӵ��ò�������
		//erase(seq,0);

		////����3:
		//int i = 0;
		//for(i=0; i<seq->size-1; i++)//�ƶ�Ԫ��
		//{ 
		//	seq->arr[i] = seq->arr[i+1];
		//}
		//seq->size--;

		//����4:
		int i = 0;
		for(i = 1; i<seq->size; i++)//�ƶ�Ԫ��
		{ 
			seq->arr[i-1] = seq->arr[i];
		}
		seq->size--;
	}   
	printf("ɾ���ɹ�\n");
}
void insert(pseq seq,int pos,Datatype x)
{
	int i = 0;
	assert(seq);
	check_capacity(seq);
		////����1:
	 //   int i = 0;
		//for(i=seq->size; i>pos; i--)
		//{
		//	seq->arr[i] = seq->arr[i-1];
		//}
		//seq->arr[pos] = x;
		//seq->size++;

		//����2:
		for(i=seq->size-1; i>=pos; i--)
		{
			seq->arr[i+1] = seq->arr[i];
		}
		seq->arr[pos] = x;
		seq->size++;
	printf("����ɹ�\n");
}
void erase(pseq seq,int pos)
{
	assert(seq);
	if(seq->size==0)
		printf("˳����ѿ�\n");
	else
	{
	    int i = 0;
		for(i=pos; i<seq->size-1; i++)
		{
			seq->arr[i] = seq->arr[i+1];
		}
		seq->size--;
		printf("�����ɹ�\n");
	}
}
int find(pseq seq,Datatype x)
{
	int i = 0;
	assert(seq);
	for(i=0; i<seq->size; i++)
	{
		if(seq->arr[i] == x)
			return i;//�����״γ���λ�õ��±�
	}
	return -1;
}
void remmove(pseq seq,Datatype x)
{
	assert(seq);
	if(seq->size==0)
		printf("˳����ѿ�\n");
	else
	{
		int i = 0;
	    for(i=0; i<seq->size; i++)
		{
			if(seq->arr[i]==x)
			{
				int j = 0;
				for(j=i; j<seq->size; j++)//�ƶ�Ԫ��
				{
					seq->arr[j]=seq->arr[j+1];
				}
			}
		}
		seq->size--;
		printf("ɾ���ɹ�\n");
	}

}
void remmove_all(pseq seq,Datatype x)
{
	assert(seq);
	if(seq->size==0)
		printf("˳����ѿ�\n");
	else
	{
	 //   //����1:��һ��ɾһ��
		//int i = 0;
		//int count = 0;
		//for(i=0; i<seq->size; ++i)
		//{
		//	if(seq->arr[i] == x)
		//	{
		//		int j = 0;
		//		for(j=i; j<seq->size; j++)//�ƶ�Ԫ��
		//		{
		//			seq->arr[j]=seq->arr[j+1];
		//		}
		//		seq->size--;
		//	}
		//}

		//����2��
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
		printf("ɾ���ɹ�\n");
}
void empty(pseq seq)
{
	assert(seq);
    if(seq->size == 0)
		printf("˳���Ϊ��\n");
	else
		printf("˳���Ϊ��\n");
}

int size(pseq seq)
{
    assert(seq);
	return seq->size;
}
void bubble_sort(pseq seq)
{
 //   //��ͨд��
	//int i = 0;
	//int flag = 0;
	//assert(seq);
	//for(i=0; i<seq->size-1; i++)
	//{
	//    int j = 0;
	//	flag = 0;
	//	for(j=0; j<seq->size-1-i; j++)
	//	{
	//		if(seq->arr[j]>seq->arr[j+1])//����
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

	//����ѡ�����������
	int option = 0;
	int i = 0;
	int flag = 0;
	assert(seq);
	printf("���������ѡ��:(0.����  1.����)");
	scanf("%d",&option);
	for(i=0; i<seq->size-1; i++)
	{
	    int j = 0;
		flag = 0;
		for(j=0; j<seq->size-1-i; j++)
		{
			if(option == 0)
			{
			    if(seq->arr[j]>seq->arr[j+1])//����
				{
					Datatype temp = seq->arr[j];
					seq->arr[j] = seq->arr[j+1];
					seq->arr[j+1] = temp;
					flag = 1;
				}
			}
			else if(option == 1)
			{
			    if(seq->arr[j]<seq->arr[j+1])//����
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
	printf("����ɹ�\n");
}

void select_sort(pseq seq)
{
	;
}

//int binary_search(pseq seq,Datatype x)//����˳����Ѿ����������к�
//{
//	int left = 0;
//	int right = 0;
//	int mid = 0;
//	assert(seq);
//	////����1��ǰ�պ������
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
//	////����2:ǰ�պ�����
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
//����3:�ݹ�ʵ��
int binary_search(pseq seq,int left,int right,Datatype x)//����˳����Ѿ����������к�
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