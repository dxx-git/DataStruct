#define _CRT_SECURE_NO_WARNINGS 1
#include"linklist.h"

//void test1()
//{
//	PNode pHead = NULL;
//    PNode pNode = NULL;
//	Init_LinkList(&pNode);
//	PushBack(&pNode,1);
//	PushBack(&pNode,2);
//	PushBack(&pNode,3);
//	PushBack(&pNode,4);
//	PushBack(&pNode,5);
//	Print_LinkList(pNode);
//	ReversePrint(pNode);
//	DeleteNotTail(Find(pNode,1));
//	DeleteNotTail(Find(pNode,2));
//	DeleteNotTail(Find(pNode,3));
//	DeleteNotTail(Find(pNode,4));
//	Print_LinkList(pNode);
//	InsertNotHead(&pNode,Find(pNode,4),5);
//	Print_LinkList(pNode);
//	pHead = JosephCircle(&pNode,3);
//	pHead->next = NULL;
//	Print_LinkList(pHead);
//	Destroy(&pHead);
//}
//void test2()
//{
//    PNode pNode = NULL;
//	PNode pRet = NULL;
//	Init_LinkList(&pNode);
//	PushBack(&pNode,1);
//	PushBack(&pNode,2);
//	PushBack(&pNode,3);
//	PushBack(&pNode,4);
//	//PushBack(&pNode,5);
//	Print_LinkList(pNode);
//	pRet = FindMidNode(pNode);
//	printf("pNode的中间节点为:%d\n",pRet->data);
//	Destroy(&pNode);
//}
//void test3()
//{
//    PNode pNode = NULL;
//	PNode pRet = NULL;
//	Init_LinkList(&pNode);
//	PushBack(&pNode,1);
//	PushBack(&pNode,2);
//	PushBack(&pNode,3);
//	PushBack(&pNode,4);
//	PushBack(&pNode,5);
//	Print_LinkList(pNode);
//	pRet = FindLastKNode(pNode,2);
//	printf("pNode的倒数第k个节点为:%d\n",pRet->data);
//	Destroy(&pNode);
//}

void test4()
{
	PNode pNode = NULL;
	PNode pRet = NULL;
	Init_LinkList(&pNode);
	PushBack(&pNode,2);
	PushBack(&pNode,5);
	PushBack(&pNode,1);
	PushBack(&pNode,4);
	PushBack(&pNode,3);
	Print_LinkList(pNode);
	pRet = Reserse_LinkList(&pNode);
	Print_LinkList(pRet);
	Bubbleort(pRet);
	Print_LinkList(pRet);
	Destroy(&pNode);
}

//void test5()
//{
//	PNode pNode1 = NULL;
//	PNode pNode2 = NULL;
//	PNode pRet = NULL;
//	Init_LinkList(&pNode1);
//	Init_LinkList(&pNode2);
//	PushBack(&pNode1,1);
//	PushBack(&pNode1,3);
//	PushBack(&pNode1,5);
//	PushBack(&pNode2,2);
//	PushBack(&pNode2,4);
//	PushBack(&pNode2,6);
//	pRet = MergeOrder_LinkList(pNode1,pNode2);
//	Print_LinkList(pRet);
//	Destroy(&pRet);
//}
//void test6()
//{
//	PNode pNode1 = NULL;
//	PNode pNode2 = NULL;
//	PNode pRet = NULL;
//	PNode tmp1 = NULL; 
//	PNode tmp2 = NULL;
//	int ret = 0;
//	Init_LinkList(&pNode1);
//	Init_LinkList(&pNode2);
//	PushBack(&pNode1,1);
//	PushBack(&pNode1,2);
//	PushBack(&pNode1,3);
//	PushBack(&pNode1,4);
//	PushBack(&pNode2,5);
//	tmp1 = Find(pNode1,3);
//	tmp2 = EndNode(&pNode2);
//	tmp2->next = tmp1;
//	ret = CheckCross(pNode1,pNode2);
//	if(ret == 1)
//		printf("两个链表有交点\n");
//	else
//		printf("两个链表无交点\n");
//	pRet = Cross(pNode1,pNode2);
//	Print_LinkList(pRet);
//	Destroy(&pRet);
//}
//void test7()
//{
//	PNode pNode = NULL;
//	PNode pMeetNode = NULL;
//	PNode tmp1 = NULL;
//	PNode tmp2 = NULL;
//	PNode pInterNode = NULL;
//	int length = 0;
//	Init_LinkList(&pNode);
//	PushBack(&pNode,1);
//	PushBack(&pNode,2);
//	PushBack(&pNode,3);
//	PushBack(&pNode,4);
//	PushBack(&pNode,5);
//	tmp1 = Find(pNode,3);
//	tmp2 = EndNode(&pNode);
//	tmp2->next = tmp1;
//	pMeetNode = CheckCircle(pNode);
//	if(pMeetNode == NULL)
//		printf("链表不带环\n");
//	else
//		printf("链表带环，且相遇节点为%d\n",pMeetNode->data);
//	length = GetCircleLength(pMeetNode);
//	printf("环的长度为%d\n",length);
//	pInterNode = GetInterNode(pNode,pMeetNode);
//	if(pInterNode == NULL)
//		printf("链表不带环\n");
//	else
//		printf("链表带环，且相遇节点为%d\n",pInterNode->data);
//	free(pNode);//注意带环的链表不能再用自拟的Destroy函数销毁
//}
//void test8()
//{
//	PNode pNode1 = NULL;
//	PNode pNode2 = NULL;
//	PNode pRet = NULL;
//	PNode tmp1 = NULL; 
//	PNode tmp2 = NULL;
//	int ret = 0;
//	Init_LinkList(&pNode1);
//	Init_LinkList(&pNode2);
//	
//	////两个链表都没环
//	//PushBack(&pNode1,1);
//	//PushBack(&pNode1,2);
//	//PushBack(&pNode1,3);
//	//PushBack(&pNode1,4);
//	//PushBack(&pNode2,5);
//	//tmp1 = Find(pNode1,3);
//	//tmp2 = EndNode(&pNode2);
//	//tmp2->next = tmp1;
//	
//	////一个有环一个没环
//	//PushBack(&pNode1,1);
//	//PushBack(&pNode1,2);
//	//PushBack(&pNode1,3);
//	//PushBack(&pNode1,4);
//	//PushBack(&pNode2,3);
//	//tmp1 = Find(pNode1,3);
//	//tmp2 = EndNode(&pNode1);
//	//tmp2->next = tmp1;
//	//ret = CheckCrossWithCircle(pNode1,pNode2);
//	//if(ret == 1)
//	//	printf("两个链表有交点\n");
//	//else
//	//	printf("两个链表无交点\n");
//
//	//两个都有环
//	PushBack(&pNode1,1);
//	PushBack(&pNode1,2);
//	PushBack(&pNode1,3);
//	PushBack(&pNode1,4);
//	PushBack(&pNode2,5);
//	PushBack(&pNode2,3);
//	PushBack(&pNode2,4);
//	//给pNode1构造环
//	tmp1 = Find(pNode1,3);
//	tmp2 = EndNode(&pNode1);
//	tmp2->next = tmp1;
//	//给pNode2构造环
//	tmp1 = Find(pNode2,3);
//	tmp2 = EndNode(&pNode2);
//	tmp2->next = tmp1;
//	//使其相交
//	tmp1 = Find(pNode1,2);
//	tmp2 = Find(pNode2,3);
//	tmp1->next = tmp2;
//	ret = CheckCrossWithCircle(pNode1,pNode2);
//	if(ret == 1)
//		printf("两个链表都不带环且有交点\n");
//	else if(ret == 2)
//		printf("两个链表都带环且有交点\n");
//	else
//		printf("两个链表无交点\n");
//	free(pNode2);
//	free(pNode1);
//}
//void test9()
//{
//	PNode pNode1 = NULL;
//	PNode pNode2 = NULL;
//	PNode pRet = NULL;
//	Init_LinkList(&pNode1);
//	Init_LinkList(&pNode2);
//	PushBack(&pNode1,1);
//	PushBack(&pNode1,2);
//	PushBack(&pNode1,2);
//	PushBack(&pNode1,4);
//	PushBack(&pNode1,4);
//	PushBack(&pNode1,5);
//
//	PushBack(&pNode2,2);
//	PushBack(&pNode2,4);
//	PushBack(&pNode2,5);
//	PushBack(&pNode2,6);
//	pRet = UnionSet(pNode1,pNode2);
//	Print_LinkList(pRet);
//	Destroy(&pNode1);
//	Destroy(&pNode2);
//}
void test10()
{
	PNode pNode = NULL;
	Init_LinkList(&pNode);
	PushBack(&pNode,1);
	PushBack(&pNode,2);
	PushBack(&pNode,3);
	PushBack(&pNode,4);
	PushBack(&pNode,5);
	PushBack(&pNode,6);
	ParityRearrangement(&pNode);
	ReverseNode(&pNode);
	Print_LinkList(pNode);
	Destroy(&pNode);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	test10();
    system("pause");
	return 0;
}