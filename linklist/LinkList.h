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
void Init_LinkList(PNode *pHead);//��ʼ��
PNode BuyNode(DataType data);//�����½ڵ�
void PushBack(PNode *pHead,DataType data);//β��
void PopBack(PNode *pHead);//βɾ
void PushFront(PNode *pHead,DataType data);//ͷ��
void PopFront(PNode *pHead);//ͷɾ
PNode Find(PNode pHead,DataType data);//����ֵΪdata�Ľڵ�λ��
void Insert(PNode pos,DataType data);//�ʵ�λ�ò���
void Print_LinkList(PNode *pHead);//��ӡ
void Erase(PNode* pHead, PNode pos);// ɾ������Posλ�õ�Ԫ��
void Remmove(PNode* pHead, DataType data);// ɾ�������е�һ��ֵΪdata��Ԫ��
void RemmoveAll(PNode* pHead, DataType data);// ɾ������������ֵΪData��Ԫ��
void Destroy(PNode* pHead);// ��������
int Empty(PNode pHead);// �����Ƿ�Ϊ��
int Size(PNode pHead);// �������н��ĸ���
