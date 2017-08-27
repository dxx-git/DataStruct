#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
	struct Node *next;
}*PNode,Node;

void Init_LinkList(PNode *pHead);//初始化
PNode BuyNode(DataType data);//创建新节点
void PushBack(PNode *pHead,DataType data);//尾插
void Print_LinkList(PNode pHead);//打印
PNode Find(PNode pHead,DataType data);//查找值为data的节点位置
//***********************************************
PNode EndNode(PNode *pHead);//返回最后一个节点
void ReversePrint(PNode pHead);//逆序打印链表
void DeleteNotTail(PNode pos);//删除无头非尾节点
void InsertNotHead(PNode *pHead,PNode pos,DataType data);//在链表的非头位置插入节点
PNode JosephCircle(PNode *pHead,int m);//约瑟夫环
PNode FindMidNode(PNode pHead);//查找一个单链表的中间节点
PNode FindLastKNode(PNode pHead,int k);//查找链表的倒数第k个节点
void Destroy(PNode* pHead);// 销毁链表
//************************************************
PNode Reserse_LinkList(PNode *pHead);//逆置单链表
void Bubbleort(PNode pHead);//冒泡排序
PNode MergeOrder_LinkList(PNode pList1,PNode pList2);//合并两个有序链表，合并后仍有序
int CheckCross(PNode pList1,PNode pList2);//判断链表是否相交(假设不带环)
PNode Cross(PNode pList1,PNode pList2);//求两个链表相交的交点(P假设不带环)
//*************************************************
PNode CheckCircle(PNode pHead);//判断链表是否带环
int GetCircleLength(PNode pMeetNode);//如果带环，求环的长度
PNode GetInterNode(PNode pHead,PNode pMeetNode);//获取环的入口点
int CheckCrossWithCircle(PNode pHead1,PNode pHead2);//判断链表是否相交(有可能带环)
PNode UnionSet(Node *list1,Node *list2);//求两个已排序单链表中相同的数据----打印出来
//**************************************************
void ParityRearrangement(PNode *pHead);//将所有奇节点放在偶数节点的前面
void ReverseNode(PNode *pHead);//将所有奇数节点反转，将所有偶数节点反转



