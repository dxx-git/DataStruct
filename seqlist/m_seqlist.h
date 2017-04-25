#ifndef __SEQLIST_H__
#define __SEQLIST_H__
//#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int Datatype;

typedef struct SeqList
{
	Datatype *arr;
	int size;
	int capacity;
}SeqList,*pseq;

enum OP
{
   EXIT,
   PRINT_SEQLIST,
   PUSHBACK,
   POPBACK,
   PUSHFRONT,
   POPFRONT,
   INSERT,
   ERASE,
   FIND,
   REMMOVE,
   REMMOVE_ALL,
   EMPTY,
   SIZE,
   BUBBLE_SORT,
   SELECT_SORT,
   BINARY_SEARCH,
   CLEAR
};
void init_seqlist(pseq seq);
void check_capacity(pseq seq);
void print_seqlist(pseq seq);
void pushback(pseq seq,Datatype x);
void popback(pseq seq);
void pushfront(pseq seq,Datatype x);
void popfront(pseq seq);
void insert(pseq seq,int pos,Datatype x);
void erase(pseq seq,int pos);
int find(pseq seq,Datatype x);
void remmove(pseq seq,Datatype x);
void remmove_all(pseq seq,Datatype x);
void empty(pseq seq);
int size(pseq seq);
void bubble_sort(pseq seq);
void select_sort(pseq seq);
//int binary_search(pseq seq,Datatype x);
int binary_search(pseq seq,int left,int right,Datatype x);
void clear(pseq seq);
void destroy(pseq seq);


#endif //__SEQLIST_H__
