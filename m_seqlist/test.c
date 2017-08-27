#define _CRT_SECURE_NO_WARNINGS 1
#include"m_seqlist.h"

void menu()
{
	printf("0.exit*************1.print_SeqList*****\n");
	printf("2.pushback*********3.pophback**********\n");
	printf("4.pushfront********5.popfront**********\n");
	printf("6.insert***********7.erase*************\n");
	printf("8.find*************9.remmove***********\n");
	printf("10.remmove_all*****11.empty************\n");
	printf("12.size************13.bubble_sort******\n");
	printf("14.select_sort*****15.binary_search****\n");
	printf("16.clear*******************************\n");
}
int main()
{
   int input = 1;
   SeqList seqlist;
   init_seqlist(&seqlist);
   while(1)
   {
	   menu();
	   printf("��������Ҫ�����Ĳ˵�ѡ�");
       scanf("%d",&input);
	   switch(input)
	   {
	   case PRINT_SEQLIST:
		   print_seqlist(&seqlist);
		   break;
	   case PUSHBACK:
		   {
			   Datatype x = 0;
			   printf("��������Ҫ�����Ԫ��:");
			   scanf("%d",&x);
			   pushback(&seqlist,x);
		   }
		   break;
	   case POPBACK:
		   popback(&seqlist);
		   break;
	   case PUSHFRONT:
			{
				Datatype x = 0;
				printf("��������Ҫ�����Ԫ��:");
				scanf("%d",&x);
				pushfront(&seqlist,x);
			}
		   break;
	   case POPFRONT:
		   popfront(&seqlist);
		   break;
	   case INSERT:
		   {
			   Datatype x = 0;
			   int pos = 0;
			   printf("��������Ҫ�����Ԫ��:");
			   scanf("%d",&x);
			   printf("��������Ҫ�����λ��:");
			   scanf("%d",&pos);
			   insert(&seqlist,pos,x);
		   }
		   break;
	   case ERASE:
		   {
			   int pos = 0;
			   printf("��������Ҫ���������λ��:");
			   scanf("%d",&pos);
			   erase(&seqlist,pos);
		   }
		   break;
	   case FIND:
		   {
			   int ret = 0;
			   Datatype x = 0;
			   printf("��������Ҫ���ҵ�Ԫ��:");
			   scanf("%d",&x);
			   ret=find(&seqlist,x);
			   if(ret!=-1)
				   printf("��Ҫ���ҵ�Ԫ�ص�һ�γ��ֵ��±�Ϊ:%d\n",ret);
			   else
				   printf("��Ҫ���ҵ�Ԫ�ز�����\n");
		   }
		   break;
	   case REMMOVE:
		   {
			   Datatype x = 0;
			   printf("��������Ҫɾ����Ԫ��:");
			   scanf("%d",&x);
			   remmove(&seqlist,x);
		   }
		   break;
	   case REMMOVE_ALL:
		   {
			   Datatype x = 0;
			   printf("��������Ҫɾ����Ԫ��:");
			   scanf("%d",&x);
			   remmove_all(&seqlist,x);
		   }
		   break;
	   case EMPTY:
		   empty(&seqlist);
		   break;
	   case SIZE:
		   {
		       int ret = size(&seqlist);
			   printf("˳����й���%d��Ԫ��\n",ret);
		   }
		   break;
	   case BUBBLE_SORT:
		   bubble_sort(&seqlist);
		   break;
	   case SELECT_SORT:
		   select_sort(&seqlist);
		   break;
	   case BINARY_SEARCH:
		   {
			   int ret = 0;
			   Datatype x = 0;
			   printf("��������Ҫ���ҵ�Ԫ��:");
			   scanf("%d",&x);
			   //ret = binary_search(&seqlist,x);
			   ret = binary_search(&seqlist,0,seqlist.size-1,x);
			   if(ret == -1)
			       printf("û�ҵ�Ҫ����Ԫ��\n");
			   else
				   printf("����Ԫ�ص��±�Ϊ:%d\n",ret);
		   }
           break;
	   case CLEAR:
		   clear(&seqlist);
		   break;
	   case 0:
		   destroy(&seqlist);
		   exit(0);
		   break;
	   default:
		   printf("������������������\n");
		   break;
	   }
   }
  
   system("pause");
   return 0;
}
