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

PNode EndNode(PNode *pHead)//�������һ���ڵ�
{
	PNode CurNode = *pHead;
    assert(pHead);
	while(CurNode->next)
	{
		CurNode = CurNode->next;
	}
	return CurNode;
}
void ReversePrint(PNode pHead)//�����ӡ����
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
void DeleteNotTail(PNode pos)//ɾ����ͷ��β�ڵ�
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
void InsertNotHead(PNode *pHead,PNode pos,DataType data)//������ķ�ͷλ�ò���ڵ�
{
	assert(pHead);
	if((NULL == pos) || NULL == (*pHead) || pos == *pHead)
		return;
	else//��pos֮�����
	{
		PNode newNode = BuyNode(data);
		newNode->next = pos->next;
		pos->next = newNode;
	}
}
PNode JosephCircle(PNode *pHead,int m)//Լɪ��
{
	int count = m;
    PNode CurNode = NULL;
	PNode PreNode = NULL;
	assert(pHead);
	if(NULL == *pHead)
		return NULL;
	else
	{
	    CurNode = EndNode(pHead);//��CurNode��ֵΪ���һ���ڵ�
		CurNode->next = *pHead;//���ɻ�
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
PNode FindMidNode(PNode pHead)//����һ����������м�ڵ�
{
    PNode pFast = pHead;
	PNode pSlow = pHead;
	//while(pFast && pFast->next)//���Ԫ�ظ���Ϊż�����򷵻غ�����м�ֵ
	//{
	//	pFast = pFast->next->next;
	//	pSlow = pSlow->next;
	//}
	while(pFast->next && pFast->next->next)//���Ԫ�ظ���Ϊż�����򷵻�ǰ����м�ֵ
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}
PNode FindLastKNode(PNode pHead,int k)//��������ĵ�����k���ڵ�
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
void Destroy(PNode* pHead)// ��������
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

PNode Reserse_LinkList(PNode *pHead)//���õ�����
{
	//����1����������ָ��ʵ��
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
		NextNode->next = PreNode;//�����һ��Ԫ��������
		return NextNode;
	}	
}
void Bubbleort(PNode pHead)//ð������
{
	int flag = 0;
    PNode CurNode = NULL;
	PNode TailNode = NULL;
	assert(pHead);
	if(NULL == pHead || NULL == (pHead)->next)
		return;
	CurNode = pHead;
	while(TailNode != pHead)//����
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
PNode MergeOrder_LinkList(PNode pList1,PNode pList2)//�ϲ��������������ϲ���������
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
	    while(p1 && p2)//���趼Ϊ����
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
int CheckCross(PNode pList1,PNode pList2)//�ж������Ƿ��ཻ
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
PNode Cross(PNode pList1,PNode pList2)//�����������ཻ�Ľ���
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

PNode CheckCircle(PNode pHead)//�ж������Ƿ����
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
int GetCircleLength(PNode pMeetNode)//����������󻷵ĳ���
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
PNode GetInterNode(PNode pHead,PNode pMeetNode)//��ȡ������ڵ�
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
int CheckCrossWithCircle(PNode pHead1,PNode pHead2)//�ж������Ƿ��ཻ(�п��ܴ���)
{
	PNode pMeetNode1 = NULL;
	PNode pMeetNode2 = NULL;
	if(NULL == pHead1 || NULL == pHead2)
		return 0;
	pMeetNode1 = CheckCircle(pHead1);
	pMeetNode2 = CheckCircle(pHead2);
	if(NULL == pMeetNode1 && NULL == pMeetNode2)//��������������
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
		(NULL == pMeetNode2 && pMeetNode1))//һ������һ��������
		return 0;
	else//����������
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
PNode UnionSet(Node *list1,Node *list2)//��������������������ͬ������----��ӡ����
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
	
	while(p1 && p2)//�����������
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

void ParityRearrangement(PNode *pHead)//��������ڵ����ż���ڵ��ǰ��
{
	int flag = 0;
	PNode CurNode = NULL;
	PNode NextNode = NULL;
	PNode TailNode = NULL;
	assert(pHead);
	if(NULL == *pHead || NULL == (*pHead)->next)//������Ԫ�ػ�ֻ��һ��Ԫ�أ�ֱ�ӷ���
		return;
	else if(NULL == (*pHead)->next->next)//����������Ԫ��,ֱ�ӽ���
	{
		CurNode = *pHead;
		NextNode = CurNode->next;
		NextNode->next = CurNode;
		NextNode->next->next = NULL;
		*pHead = NextNode;
	}
	else//�����ж��Ԫ��
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
void ReverseNode(PNode *pHead)//�����������ڵ㷴ת��������ż���ڵ㷴ת
{
	PNode CurNode = NULL;
	PNode PreNode = NULL;
	PNode TailNode = NULL;
	PNode OldNumber = NULL;//�����ڵ�
	PNode EvenNumber = NULL;//ż���ڵ�
	assert(pHead);
	CurNode = *pHead;
	if(NULL == *pHead || NULL == (*pHead)->next || NULL == (*pHead)->next->next)
		return;
	PreNode = BuyNode(CurNode->data);
	TailNode = PreNode;
	while(CurNode  && ((CurNode->next->data%2) == 1))//��ת�����ڵ�
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
	while(CurNode && ((CurNode->next->data%2) == 0))//��תż���ڵ�
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