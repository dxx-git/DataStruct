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

enum OP
{
	EXIT,
    PUSHBACK,
	POPBACK,
	PUSHFRONT,
	POPFRONT,
	FIND,
	INSERT,
	PRINT,
	ERASE,
	REMMOVE,
	REMMOVE_ALL,
	EMPTY,
	SIZE
};
void Init_LinkList(PNode *pHead);//初始化
PNode BuyNode(DataType data);//创建新节点
void PushBack(PNode *pHead,DataType data);//尾插
void PopBack(PNode *pHead);//尾删
void PushFront(PNode *pHead,DataType data);//头插
void PopFront(PNode *pHead);//头删
PNode Find(PNode pHead,DataType data);//查找值为data的节点位置
void Insert(PNode pos,DataType data);//适当位置插入
void Print_LinkList(PNode *pHead);//打印
void Erase(PNode* pHead, PNode pos);// 删除链表Pos位置的元素
void Remmove(PNode* pHead, DataType data);// 删除链表中第一个值为data的元素
void RemmoveAll(PNode* pHead, DataType data);// 删除链表中所有值为Data的元素
void Destroy(PNode* pHead);// 销毁链表
int Empty(PNode pHead);// 链表是否为空
int Size(PNode pHead);// 求链表中结点的个数
