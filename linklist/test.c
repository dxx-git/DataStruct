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
		printf("请输入你的选择:");
		scanf("%d",&input);
		switch(input)
		{
		    case PUSHBACK:
				{
				    DataType x = 0;
					printf("请输入你要插入的数据:");
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
					printf("请输入你要插入的数据:");
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
					printf("请输入你要查找的数据:");
					scanf("%d",&x);
					position = Find(pNode,x);
					if(NULL == position)
						printf("没找到所找元素\n");
				}
				break;
			case INSERT:
				{
					DataType x = 0;
					PNode ppos = position;
					printf("请输入你要插入的数据:");
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
					printf("请输入你要删除的数据:");
					scanf("%d",&x);
					Remmove(&pNode,x);
				}
				break;
			case REMMOVE_ALL:
				{
				    DataType x = 0;
					printf("请输入你要删除的数据:");
					scanf("%d",&x);
					RemmoveAll(&pNode,x);
				}
				break;
			case EMPTY:
				{
				    int ret = Empty(pNode);
				    if(ret == 0)
					    printf("链表为空\n");
				    else
					    printf("链表不为空\n");
				}
				break;
			case SIZE:
				{
				    int sz = Size(pNode);
				    printf("单链表一共有%d个元素\n",sz);
				}
				break;
			case EXIT:
				Destroy(&pNode);
					break;
			default:
				printf("参数选择错误\n");
				break;
		}
	}
    system("pause");
	return 0;
}