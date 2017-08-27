#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"

void Init_LinkList(PNode *pHead)
{
    assert(pHead);
	*pHead = NULL;
}
PNode BuyNode(DataType data)
{
	PNode newNode = NULL;
	newNode = (PNode)malloc(sizeof(Node));
	if(NULL == newNode)
	{
	    printf("out of memory.\n");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}
void PushBack(PNode *pHead,DataType data)
{
    assert(pHead);
	if(NULL == *pHead)//�����޽ڵ�
	{
		*pHead = BuyNode(data);
	}
	else//�ж���ڵ�
	{
		PNode CurNode = *pHead;
		while(CurNode->next)
		{
			CurNode = CurNode->next;
		}
		CurNode->next = BuyNode(data);
	}
}
void PopBack(PNode *pHead)
{
    assert(pHead);
	if(NULL == *pHead)//�����޽ڵ�
	{
		return;
	}
	else if(NULL == (*pHead)->next)//����ֻ��һ���ڵ�
	{
		PNode DelNode = *pHead;
		free(DelNode);
		DelNode = NULL;
		*pHead = NULL;
	}
	else//�ж���ڵ�
	{
		PNode CurNode = *pHead;
		////����1:
		//PNode PreNode = *pHead;
		//while(CurNode->next)//�ҵ����һ���ڵ�
		//{
		//	PreNode = CurNode;
		//	CurNode = CurNode->next;
		//}
		//free(CurNode);
		//CurNode = NULL;
		//PreNode->next = NULL;

		//����2:
		while(CurNode->next->next)//�ҵ������ڶ����ڵ�
		{
			CurNode = CurNode->next;
		}
		free(CurNode->next);
		CurNode->next = NULL;
	}
}
void PushFront(PNode *pHead,DataType data)
{
	PNode PreNode = NULL;
	PNode newNode = BuyNode(data);
    assert(pHead);
	PreNode = *pHead;
	newNode->next = PreNode;
	*pHead= newNode;
}
void PopFront(PNode *pHead)
{
	PNode PreNode = *pHead;
    PNode DelNode = *pHead;
	assert(pHead);
	if(NULL ==(*pHead))
		return;
	else if(NULL ==(*pHead)->next)
	{
	    *pHead = NULL;
		free(DelNode);
	    DelNode = NULL;
	}
	else
	{
	    *pHead = DelNode->next;
	    free(DelNode);
	    DelNode = NULL;
	}
}
PNode Find(PNode pHead,DataType data)
{
	PNode CurNode = pHead;
    assert(pHead);
	while(CurNode)
	{
		if(CurNode->data == data)
			break;
		else
		CurNode = CurNode->next;
	}
	return CurNode;
}
void Insert(PNode pos,DataType data)//������λ�õĺ������
{
    PNode newNode = BuyNode(data);
    PNode PreNode = pos;
	newNode->next = pos->next;
	PreNode->next = newNode;
}
void Print_LinkList(PNode *pHead)
{
	PNode CurNode = *pHead;
    assert(pHead);
	while(CurNode)
	{
		printf("%d->",CurNode->data);
		CurNode = CurNode->next;
	}
	printf("over\n");
}
void Erase(PNode* pHead, PNode pos)// ɾ������Posλ�õ�Ԫ��
{
	PNode CurNode = *pHead;
    assert(pHead);
	if(NULL == CurNode)//������Ԫ��
		return;
	else if(NULL == CurNode->next)//ֻ��һ��Ԫ��
	{
		if(CurNode == pos)
		{
		    free(CurNode);
			*pHead = NULL;
		}
		else
		{ 
			return;
		}
	}
	else
	{
	    PNode PreNode = *pHead;
		if(*pHead == pos)//��һ��Ԫ�ؼ�Ϊpos
		{
			CurNode = CurNode->next;
			PreNode = CurNode;
			free(pos);
		    pos = NULL;
			*pHead = PreNode;
			return;
		}
		while((CurNode != pos) && CurNode)
		{
			PreNode= CurNode;
			CurNode = CurNode->next;
		}
		if(CurNode == NULL)
		{
		     printf("û�ҵ���Ҫɾ����λ��\n");
			 return;
		}
		else
		{
		    PreNode->next = CurNode->next;
		    free(pos);
		    pos = NULL;
		}
	}
}
void Remmove(PNode* pHead, DataType data)// ɾ�������е�һ��ֵΪdata��Ԫ��
{
	PNode CurNode = *pHead;
    assert(pHead);
	if(NULL == CurNode)
		return;
	else
	{
	     PNode PreNode = *pHead;
		while(CurNode->data != data)
		{
			PreNode = CurNode;
			CurNode = CurNode->next;
		}
		if(CurNode == NULL)
		{
		     printf("û�ҵ���Ҫɾ����λ��\n");
			 return;
		}
		else
		{
		    PreNode->next = CurNode->next;
		    free(CurNode);
		    CurNode = NULL;
		}
	}
}
void RemmoveAll(PNode* pHead, DataType data)// ɾ������������ֵΪData��Ԫ��
{
	PNode CurNode = *pHead;
	PNode PreNode = *pHead;
    assert(pHead);
	if(NULL == CurNode)//������Ԫ��
		return;
	while(*pHead)//�жϵ�һ��Ԫ��
	{
	    if(NULL == CurNode->next)//ֻ��һ��Ԫ��
		{
			if(CurNode->data == data)
			{
				free(CurNode);
				*pHead = NULL;
				return;
			}
		}
		else if((*pHead)->data == data)//�ж��Ԫ�أ��ҵ�һ��Ԫ�ص�ֵΪdata
		{
			*pHead = CurNode->next;
			free(CurNode);
			CurNode = *pHead;
		}
		else
			break;
	}
	CurNode = CurNode->next;
	PreNode = *pHead;
    while(CurNode)
	{
		if(CurNode->data == data)
		{
			PreNode->next = CurNode->next;
			free(CurNode);
			CurNode = PreNode;
		}
		PreNode = CurNode;
		CurNode = CurNode->next;
	}
}
void Destroy(PNode* pHead)// ��������
{
	PNode CurNode = *pHead;
    assert(pHead);
	while(CurNode->next)
	{
	    PNode DelNode = CurNode;
		CurNode = CurNode->next;
		free(DelNode);
		DelNode = NULL;
	}
	*pHead = NULL;
}
int Empty(PNode pHead)// �����Ƿ�Ϊ��
{
    assert(pHead);
	if(NULL == pHead)
		return 0;
	else
		return 1;
}
int Size(PNode pHead)// �������н��ĸ���
{
	PNode CurNode = pHead;
	DataType num = 0;
    assert(pHead);
	while(CurNode)
	{
	    num++;
		CurNode = CurNode->next;
	}
	return num;
}

