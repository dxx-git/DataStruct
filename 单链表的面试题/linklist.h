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

void Init_LinkList(PNode *pHead);//��ʼ��
PNode BuyNode(DataType data);//�����½ڵ�
void PushBack(PNode *pHead,DataType data);//β��
void Print_LinkList(PNode pHead);//��ӡ
PNode Find(PNode pHead,DataType data);//����ֵΪdata�Ľڵ�λ��
//***********************************************
PNode EndNode(PNode *pHead);//�������һ���ڵ�
void ReversePrint(PNode pHead);//�����ӡ����
void DeleteNotTail(PNode pos);//ɾ����ͷ��β�ڵ�
void InsertNotHead(PNode *pHead,PNode pos,DataType data);//������ķ�ͷλ�ò���ڵ�
PNode JosephCircle(PNode *pHead,int m);//Լɪ��
PNode FindMidNode(PNode pHead);//����һ����������м�ڵ�
PNode FindLastKNode(PNode pHead,int k);//��������ĵ�����k���ڵ�
void Destroy(PNode* pHead);// ��������
//************************************************
PNode Reserse_LinkList(PNode *pHead);//���õ�����
void Bubbleort(PNode pHead);//ð������
PNode MergeOrder_LinkList(PNode pList1,PNode pList2);//�ϲ��������������ϲ���������
int CheckCross(PNode pList1,PNode pList2);//�ж������Ƿ��ཻ(���費����)
PNode Cross(PNode pList1,PNode pList2);//�����������ཻ�Ľ���(P���費����)
//*************************************************
PNode CheckCircle(PNode pHead);//�ж������Ƿ����
int GetCircleLength(PNode pMeetNode);//����������󻷵ĳ���
PNode GetInterNode(PNode pHead,PNode pMeetNode);//��ȡ������ڵ�
int CheckCrossWithCircle(PNode pHead1,PNode pHead2);//�ж������Ƿ��ཻ(�п��ܴ���)
PNode UnionSet(Node *list1,Node *list2);//��������������������ͬ������----��ӡ����
//**************************************************
void ParityRearrangement(PNode *pHead);//��������ڵ����ż���ڵ��ǰ��
void ReverseNode(PNode *pHead);//�����������ڵ㷴ת��������ż���ڵ㷴ת



