#define _CRT_SECURE_NO_WARNINGS 1
#include"linklist.h"

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
void Print_LinkList(PNode pHead)
{
	PNode CurNode = pHead;
	while(CurNode)
	{
		printf("%d->",CurNode->data);
		CurNode = CurNode->next;
	}
	printf("over\n");
}

PNode EndNode(PNode *pHead)//返回最后一个节点
{
	PNode CurNode = *pHead;
    assert(pHead);
	while(CurNode->next)
	{
		CurNode = CurNode->next;
	}
	return CurNode;
}
void ReversePrint(PNode pHead)//逆序打印链表
{
	PNode CurNode = pHead;
    if(NULL == pHead)
		return;
	else
	{
		if(CurNode)
		{
			ReversePrint(CurNode->next);
			printf("%d ",CurNode->data);
		}
		printf("\n");
	}
}
void DeleteNotTail(PNode pos)//删除无头非尾节点
{
    if(NULL == pos || NULL == pos->next)
		return;
	else
	{
		PNode DelNode = pos->next;
		pos->data = DelNode->data;
		pos->next = DelNode->next;
		free(DelNode);
	}
}
void InsertNotHead(PNode *pHead,PNode pos,DataType data)//在链表的非头位置插入节点
{
	assert(pHead);
	if((NULL == pos) || NULL == (*pHead) || pos == *pHead)
		return;
	else//在pos之后插入
	{
		PNode newNode = BuyNode(data);
		newNode->next = pos->next;
		pos->next = newNode;
	}
}
PNode JosephCircle(PNode *pHead,int m)//约瑟夫环
{
	int count = m;
    PNode CurNode = NULL;
	PNode PreNode = NULL;
	assert(pHead);
	if(NULL == *pHead)
		return NULL;
	else
	{
	    CurNode = EndNode(pHead);//将CurNode赋值为最后一个节点
		CurNode->next = *pHead;//构成环
		CurNode = *pHead;
		while(CurNode->next != CurNode)
		{
			count = m;
			while(--count)
			{
				PreNode = CurNode;
				CurNode = CurNode->next;
			}
			PreNode->next = CurNode->next;
			free(CurNode);
			CurNode = PreNode->next;
		}
		return CurNode;
	}
}
PNode FindMidNode(PNode pHead)//查找一个单链表的中间节点
{
    PNode pFast = pHead;
	PNode pSlow = pHead;
	//while(pFast && pFast->next)//如果元素个数为偶数，则返回后面的中间值
	//{
	//	pFast = pFast->next->next;
	//	pSlow = pSlow->next;
	//}
	while(pFast->next && pFast->next->next)//如果元素个数为偶数，则返回前面的中间值
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}
PNode FindLastKNode(PNode pHead,int k)//查找链表的倒数第k个节点
{
    PNode pFast = pHead;
	PNode pSlow = pHead;
	if(NULL == pHead || k == 0)
		return NULL;
	else
	{
		while(--k)
		{
			pFast = pFast->next;
		}
		while(pFast->next)
		{
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		return pSlow;
	}
}
void Destroy(PNode* pHead)// 销毁链表
{
	PNode CurNode = *pHead;
    assert(pHead);
	while(CurNode)
	{
	    PNode DelNode = CurNode;
		CurNode = CurNode->next;
		free(DelNode);
		DelNode = NULL;
	}
	*pHead = NULL;
}

PNode Reserse_LinkList(PNode *pHead)//逆置单链表
{
	//方法1：利用三个指针实现
	PNode PreNode = NULL;
	PNode CurNode = NULL;
	PNode NextNode = NULL;
	assert(pHead);
	if(NULL == *pHead || NULL == (*pHead)->next)
		return NULL;
	else
	{ 
		PreNode = *pHead;
		CurNode = PreNode->next;
		NextNode = CurNode->next;
		(*pHead)->next = NULL;
		while(NextNode->next)
		{
			NextNode = CurNode->next;
			CurNode->next = PreNode;
			PreNode = CurNode;
			CurNode = NextNode;
		}
		NextNode->next = PreNode;//将最后一个元素连接上
		return NextNode;
	}	
}
void Bubbleort(PNode pHead)//冒泡排序
{
	int flag = 0;
    PNode CurNode = NULL;
	PNode TailNode = NULL;
	assert(pHead);
	if(NULL == pHead || NULL == (pHead)->next)
		return;
	CurNode = pHead;
	while(TailNode != pHead)//升序
	{
		flag = 0;
		CurNode = pHead;
		while(CurNode->next != TailNode)
		{
		    if(CurNode->data > CurNode->next->data)
			{
				DataType temp = CurNode->data;
				CurNode->data = CurNode->next->data;
				CurNode->next->data = temp;
				flag = 1;
			}
			CurNode = CurNode->next;
		}
		TailNode = CurNode;
		if(flag == 0)
			break;
	}
}
PNode MergeOrder_LinkList(PNode pList1,PNode pList2)//合并两个有序链表，合并后仍有序
{
	PNode p1 = pList1;
	PNode p2 = pList2;
	PNode NewNode = NULL;
	PNode pNewHead = NewNode;
	if(NULL == pList2)
		return pList1;
	if(NULL == pList1)
		return pList2;
	else
	{
		if(p1->data < p2->data)
		{
			NewNode = p1;
			p1 = p1->next;
		}
		else
		{
			NewNode = p2;
			p2 = p2->next;
		}
		pNewHead = NewNode;
	    while(p1 && p2)//假设都为升序
		{
			if(p1->data < p2->data)
			{
				NewNode->next = p1;
				NewNode = p1;
				p1 = p1->next;
			}
			else
			{
				NewNode->next = p2;
				NewNode = p2;
				p2 = p2->next;
			}
		}
		if(NULL == p1)
		{
			NewNode->next = p2;
		}
		if(NULL == p2)
		{
			NewNode->next = p1;
		}
		return pNewHead;
	}
}
int CheckCross(PNode pList1,PNode pList2)//判断链表是否相交
{
	PNode p1 = pList1;
	PNode p2 = pList2;
    if(NULL == pList2 || NULL == pList1)
		return 0;
	while(p1->next)
	{
		p1 = p1->next;
	}
	while(p2->next)
	{
		p2 = p2->next;
	}
	if(p1 == p2)
		return 1;
	else
		return 0;
}
PNode Cross(PNode pList1,PNode pList2)//求两个链表相交的交点
{
	int count1 = 0;
	int count2 = 0;
	PNode p1 = pList1;
	PNode p2 = pList2;
	if(NULL == pList2 || NULL == pList1)
		return 0;
	while(p1->next)
	{
		p1 = p1->next;
		count1++;
	}
	while(p2->next)
	{
		p2 = p2->next;
		count2++;
	}
	p1 = pList1;
	p2 = pList2;
	if(count1 - count2 >= 0)
	{
	    int temp = count1 - count2;
		while(temp--)
		{
			p1 = p1->next;
		}
	}
	else
	{
		int temp = count2 - count1;
		while(temp--)
		{
			p2 = p2->next;
		}
	}
	while(p1->next)
	{
		if(p1 == p2)
			break;
		else
		{
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if(p1 == p2)
	    return p1;
	else 
		return NULL;
}

PNode CheckCircle(PNode pHead)//判断链表是否带环
{
	PNode pFast = NULL;
	PNode pSlow = NULL;
	if (NULL == pHead)
	{
		return NULL;
	}
	pFast = pHead;
	pSlow = pHead;
	while(pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		if(pFast == pSlow)
			break;
	}
	if(pFast == pSlow && pFast != pHead)
	    return pFast;
	else
		return NULL;
}
int GetCircleLength(PNode pMeetNode)//如果带环，求环的长度
{
	int len = 1;
	PNode CurNode = pMeetNode;
	if(NULL == pMeetNode)
		return 0;
	while(CurNode->next != pMeetNode)
	{
		CurNode = CurNode->next;
		len++;
	}
	return len;
}
PNode GetInterNode(PNode pHead,PNode pMeetNode)//获取环的入口点
{
	PNode pH = pHead;
	PNode pM = pMeetNode;
	if(NULL == pHead || NULL == pMeetNode)
		return NULL;
	while(pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pM;
}
int CheckCrossWithCircle(PNode pHead1,PNode pHead2)//判断链表是否相交(有可能带环)
{
	PNode pMeetNode1 = NULL;
	PNode pMeetNode2 = NULL;
	if(NULL == pHead1 || NULL == pHead2)
		return 0;
	pMeetNode1 = CheckCircle(pHead1);
	pMeetNode2 = CheckCircle(pHead2);
	if(NULL == pMeetNode1 && NULL == pMeetNode2)//两个链表都不带环
	{
		PNode p1 = pHead1;
		PNode p2 = pHead2;
		while(p1->next)
		{
			p1 = p1->next;
		}
		while(p2->next)
		{
			p2 = p2->next;
		}
		if(p1 == p2)
			return 1;
		else
			return 0;
	}
	else if((NULL == pMeetNode1 && pMeetNode2) || 
		(NULL == pMeetNode2 && pMeetNode1))//一个带环一个不带环
		return 0;
	else//两个都带环
	{
		PNode pM1 = pMeetNode1;
		PNode pM2 = pMeetNode2;
		while(pM1 != pM1->next)
		{
			pM1 = pM1->next;
			if(pM1 == pM2)
				break;
		}
		if (pM1 == pM2)
		    return 2;
		else
			return 0;
	}
}
PNode UnionSet(Node *list1,Node *list2)//求两个已排序单链表中相同的数据----打印出来
{
	PNode p1 = list1;
	PNode p2 = list2;
	PNode p3 = NULL;
	PNode newHead = p3;
	if(NULL == list1 || NULL == list2)
		return NULL;
	while(!p3)
	{
		if(p1->data == p2->data)
		{
			p3 = p1;
			newHead = p3;
			while(p1->data == p1->next->data)
			{
				p1 = p1->next;
			}
			p1 = p1->next;
			while(p2->data == p2->next->data)
			{
				p2 = p2->next;
			}
			p2 = p2->next;
		}
		else if(p1->data < p2->data)
			p1 = p1->next;
		else
			p2 = p2->next;
	}
	
	while(p1 && p2)//假设均是升序
	{
		if(p1->data == p2->data)
		{
			    p3->next = p1;
			    p3 = p3->next;
				if(!p1->next || !p2->next)
					break;
				while(p1->data == p1->next->data)
				{
					p1 = p1->next;
				}
				p1 = p1->next;
				while(p2->data == p2->next->data)
				{
					p2 = p2->next;
				}
				p2 = p2->next;
		}
			else if(p1->data < p2->data)
				p1 = p1->next;
			else
				p2 = p2->next;
	}
	p3->next = NULL;
	return newHead;
}

void ParityRearrangement(PNode *pHead)//将所有奇节点放在偶数节点的前面
{
	int flag = 0;
	PNode CurNode = NULL;
	PNode NextNode = NULL;
	PNode TailNode = NULL;
	assert(pHead);
	if(NULL == *pHead || NULL == (*pHead)->next)//链表无元素或只有一个元素，直接返回
		return;
	else if(NULL == (*pHead)->next->next)//链表有两个元素,直接交换
	{
		CurNode = *pHead;
		NextNode = CurNode->next;
		NextNode->next = CurNode;
		NextNode->next->next = NULL;
		*pHead = NextNode;
	}
	else//链表有多个元素
	{
		CurNode = *pHead;
		while(TailNode != *pHead)
		{
			flag = 0;
			CurNode = *pHead;
			while(CurNode->next != TailNode)
			{
				if((CurNode->data%2 == 0) && (CurNode->next->data%2 == 1))
				{
					DataType temp = CurNode->data;
					CurNode->data = CurNode->next->data;
					CurNode->next->data = temp;
					flag = 1;
				}
				CurNode = CurNode->next;
			}
			TailNode = CurNode;
			if(flag == 0)
				break;
		}
	}
}
void ReverseNode(PNode *pHead)//将所有奇数节点反转，将所有偶数节点反转
{
	PNode CurNode = NULL;
	PNode PreNode = NULL;
	PNode TailNode = NULL;
	PNode OldNumber = NULL;//奇数节点
	PNode EvenNumber = NULL;//偶数节点
	assert(pHead);
	CurNode = *pHead;
	if(NULL == *pHead || NULL == (*pHead)->next || NULL == (*pHead)->next->next)
		return;
	PreNode = BuyNode(CurNode->data);
	TailNode = PreNode;
	while(CurNode  && ((CurNode->next->data%2) == 1))//反转奇数节点
	{
		CurNode = CurNode->next;
		OldNumber = BuyNode(CurNode->data);
		OldNumber->next = PreNode;
		PreNode = OldNumber;
		if(NULL == CurNode->next)
			break;
	}
	*pHead = PreNode;
	CurNode = CurNode->next;
	PreNode = BuyNode(CurNode->data);
	while(CurNode && ((CurNode->next->data%2) == 0))//反转偶数节点
	{
		CurNode = CurNode->next;
		EvenNumber = BuyNode(CurNode->data);
		EvenNumber->next = PreNode;
		PreNode = EvenNumber;
		if(NULL == CurNode->next)
			break;
	}
	TailNode->next = PreNode;
}