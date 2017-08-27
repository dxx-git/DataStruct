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
	if(NULL == *pHead)//链表无节点
	{
		*pHead = BuyNode(data);
	}
	else//有多个节点
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
	if(NULL == *pHead)//链表无节点
	{
		return;
	}
	else if(NULL == (*pHead)->next)//链表只有一个节点
	{
		PNode DelNode = *pHead;
		free(DelNode);
		DelNode = NULL;
		*pHead = NULL;
	}
	else//有多个节点
	{
		PNode CurNode = *pHead;
		////方法1:
		//PNode PreNode = *pHead;
		//while(CurNode->next)//找到最后一个节点
		//{
		//	PreNode = CurNode;
		//	CurNode = CurNode->next;
		//}
		//free(CurNode);
		//CurNode = NULL;
		//PreNode->next = NULL;

		//方法2:
		while(CurNode->next->next)//找到倒数第二个节点
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
void Insert(PNode pos,DataType data)//在所给位置的后面插入
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
void Erase(PNode* pHead, PNode pos)// 删除链表Pos位置的元素
{
	PNode CurNode = *pHead;
    assert(pHead);
	if(NULL == CurNode)//链表无元素
		return;
	else if(NULL == CurNode->next)//只有一个元素
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
		if(*pHead == pos)//第一个元素即为pos
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
		     printf("没找到需要删除的位置\n");
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
void Remmove(PNode* pHead, DataType data)// 删除链表中第一个值为data的元素
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
		     printf("没找到需要删除的位置\n");
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
void RemmoveAll(PNode* pHead, DataType data)// 删除链表中所有值为Data的元素
{
	PNode CurNode = *pHead;
	PNode PreNode = *pHead;
    assert(pHead);
	if(NULL == CurNode)//链表无元素
		return;
	while(*pHead)//判断第一个元素
	{
	    if(NULL == CurNode->next)//只有一个元素
		{
			if(CurNode->data == data)
			{
				free(CurNode);
				*pHead = NULL;
				return;
			}
		}
		else if((*pHead)->data == data)//有多个元素，且第一个元素的值为data
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
void Destroy(PNode* pHead)// 销毁链表
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
int Empty(PNode pHead)// 链表是否为空
{
    assert(pHead);
	if(NULL == pHead)
		return 0;
	else
		return 1;
}
int Size(PNode pHead)// 求链表中结点的个数
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

