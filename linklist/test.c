#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"

void menu()
{
    printf("1.PushBack******************2.PopBack\n");
	printf("3.PushFront*****************4.PopFront\n");
	printf("5.Find**********************6.Insert\n");
	printf("7.Print_LinkList************8.Erase\n");
	printf("9.Remove********************10.RemoveAll\n");
	printf("11.Empty********************12.Size\n");
	printf("0.exit******************************\n");
}
int main()
{
	PNode pNode;
	PNode position = NULL;
	int input = 1;
	Init_LinkList(&pNode);
	while(input)
	{
	    menu();
		printf("���������ѡ��:");
		scanf("%d",&input);
		switch(input)
		{
		    case PUSHBACK:
				{
				    DataType x = 0;
					printf("��������Ҫ���������:");
					scanf("%d",&x);
					PushBack(&pNode,x);
					ReversePrint(pNode);
				}
				break;
			case POPBACK:
				PopBack(&pNode);
				break;
			case PUSHFRONT:
				{
				    DataType x = 0;
					printf("��������Ҫ���������:");
					scanf("%d",&x);
					PushFront(&pNode,x);
				}
				break;
			case POPFRONT:
				PopFront(&pNode);
				break;
			case FIND:
				{
				    DataType x = 0;
					printf("��������Ҫ���ҵ�����:");
					scanf("%d",&x);
					position = Find(pNode,x);
					if(NULL == position)
						printf("û�ҵ�����Ԫ��\n");
				}
				break;
			case INSERT:
				{
					DataType x = 0;
					PNode ppos = position;
					printf("��������Ҫ���������:");
					scanf("%d",&x);
					Insert(ppos,x);
				}
				break;
			case PRINT:
				Print_LinkList(&pNode);
				break;
			case ERASE:
				{
					PNode ppos = position;
					Erase(&pNode,ppos);
				}
				break;
			case REMMOVE:
				{
					DataType x = 0;
					printf("��������Ҫɾ��������:");
					scanf("%d",&x);
					Remmove(&pNode,x);
				}
				break;
			case REMMOVE_ALL:
				{
				    DataType x = 0;
					printf("��������Ҫɾ��������:");
					scanf("%d",&x);
					RemmoveAll(&pNode,x);
				}
				break;
			case EMPTY:
				{
				    int ret = Empty(pNode);
				    if(ret == 0)
					    printf("����Ϊ��\n");
				    else
					    printf("����Ϊ��\n");
				}
				break;
			case SIZE:
				{
				    int sz = Size(pNode);
				    printf("������һ����%d��Ԫ��\n",sz);
				}
				break;
			case EXIT:
				Destroy(&pNode);
					break;
			default:
				printf("����ѡ�����\n");
				break;
		}
	}
    system("pause");
	return 0;
}