#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void menu()
{
	printf("0.exit*************1.print_SeqList*****\n");
	printf("2.pushback*********3.pophback**********\n");
	printf("4.pushfront********5.popfront**********\n");
	printf("6.insert***********7.erase*************\n");
	printf("8.find*************9.remmove***********\n");
	printf("10.remmove_all*****11.empty************\n");
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
	   case 1:
		   print_seqlist(&seqlist);
		   break;
	   case 2:
		   {
			   Datatype x = 0;
			   printf("��������Ҫ�����Ԫ��:");
			   scanf("%d",&x);
			   pushback(&seqlist,x);
		   }
		   break;
	   case 3:
		   popback(&seqlist);
		   break;
	   case 4:
			{
				Datatype x = 0;
				printf("��������Ҫ�����Ԫ��:");
				scanf("%d",&x);
				pushfront(&seqlist,x);
			}
		   break;
	   case 5:
		   popfront(&seqlist);
		   break;
	   case 6:
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
	   case 7:
		   {
			   int pos = 0;
			   printf("��������Ҫ���������λ��:");
			   scanf("%d",&pos);
			   erase(&seqlist,pos);
		   }
		   break;
	   case 8:
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
	   case 9:
		   {
			   Datatype x = 0;
			   printf("��������Ҫɾ����Ԫ��:");
			   scanf("%d",&x);
			   remmove(&seqlist,x);
		   }
		   break;
	   case 10:
		   {
			   Datatype x = 0;
			   printf("��������Ҫɾ����Ԫ��:");
			   scanf("%d",&x);
			   remmove_all(&seqlist,x);
		   }
		   break;
	   case 11:
		   empty(&seqlist);
		   break;
	   case 0:
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