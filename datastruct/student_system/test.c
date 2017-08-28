#define _CRT_SECURE_NO_WARNINGS
//添加头文件
#include<stdio.h>
#include<string.h>

#define STUDENT_COUNT 1//宏定义
//输入主函数
int main(void)
{
	int i,j;
	//定义学生数组

	char names[STUDENT_COUNT][50];
	char xingbie[STUDENT_COUNT];
	int number[STUDENT_COUNT];
	int phonenumber[STUDENT_COUNT];
	char danwei[STUDENT_COUNT];
	int mail[STUDENT_COUNT]; 
	int n;//当前学生人数
	int temp;//定义一个辅助变量
	char name[STUDENT_COUNT][50];//定义一个待查变量
	int k;//定义一个变量用于储存names[i]的下标
	int choice = 1;//定义用户输入
	printf("系统菜单\n");
	printf("*************************************\n");
	printf("欢迎使用学生通信信息管理系统\n");
	printf("[1] 输入所有学生信息\n");
	printf("[2] 输出所有学生信息\n");
	printf("[3] 按电话号码查找某个学生信息\n");
	printf("[4] 按姓名查找某个学生信息\n");
	printf("[5] 按姓名修改某个学生信息\n");
	printf("[6] 按电话号码修改某个学生信息\n");
	printf("[7] 按姓名删除某个学生信息\n");
	printf("[8] 按电话号码删除某个学生信息\n");
	printf("[0] 退出程序\n");
	printf("**************************************\n");
	while(choice)
	{
		printf("请输入您的选择（0-8）:");

		scanf("%d",&choice);

		if(choice==0)//判定
		{
			break;//结束最近的循环
		}
		//显示菜单
		switch(choice)
		{
		case 1://输入所有学生的信息
			for(n=0;n<STUDENT_COUNT;n++)
			{
				printf("请输入第%d学生信息(姓名，性别，学号，电话号码，单位，邮址)\n",n+1);
				scanf("%s%s%d%d%s%d",&names[n],&xingbie[n],&number[n],&phonenumber[n],&danwei[n],&mail[n]);
			}
			break;
		case 2://输出所有学生信息
			//打印表头
			printf("请输入%d学生信息(姓名，性别，学号，电话号码，单位，邮址)\n",n+1);
			printf("------------------------------------------------------\n");
			for(i=0;i<n;i++)
			{
				//打印信息\n
				printf("%s%s%d%d%s%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("------------------------------------------------------\n");
			}
			break;
		case 3://按电话号码查找某个学生信息
			printf("请输入待查学生电话：\n");
			scanf("%d",&j);
			k=-1;
			//学号查找
			for(i=0;i<n;i++)
			{
				if(j==phonenumber[i])
				{
					k=i;
					break;
				}
			}
			if(k==-1)
			{
				printf("对不起，没有该学生信息");
			}
			else
			{
				//先打印表头
				printf("请输入第%d学生信息(姓名，性别，学号，电话号码，单位，邮址)\n",n+1);
				printf("-----------------------------------------------------------\n");
				//后打印学生信息
				printf("\n15%s\t15%s\t15%d\t15%d\t15%s\t15%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("----------------------------------------------------------\n");
			}
			break;
		case 4://按姓名查找某个学生信息
			printf("请输入待查学生名字\n");
			scanf("%s",&name);
			k=-1;//重置变量K，便于多次查找
			for(i=0;i<n;++i)
			{
				if(strcmp(name[i],names[i])==0)//姓名的比较
				{
					k=i;
					break;
				}
			}
			if(k==-1)
			{
				printf("对不起，没有该学生的信息：\n");
			}
			else
			{
				//先打印表头
				printf("请输入第%d学生信息(姓名，学号，性别，电话号码，单位，邮址)\n",n+1);
				printf("-----------------------------------------------------------\n");
				//后打印学生信息
				printf("\n15%s\t15%s\t15%d\t15%d\t15%s\t15%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("----------------------------------------------------------\n");
			}
			break;
		case 5://按姓名修改某个学生信息
			printf("请输入要修改学生的姓名：");
			scanf("%s",&name);
			k=-1;
			for(i=0;i<n;++i)
			{
				if(strcmp(name[i],names[i])==0)
				{
					k=i;
					printf("请输入要修改的信息：\n");
					printf("姓名\n");
					scanf("%15s",names[i]);
					printf("学号\n");
					scanf("%d",&number[i]);
					printf("性别\n");
					scanf("%s",&xingbie[i]);
					printf("电话号码\n");
					scanf("%d",&phonenumber[i]);
					printf("单位\n");
					scanf("%s",&danwei[i]);
					printf("邮址\n");
					scanf("%d",&mail[i]);

					break;
				}
			}
			if(k==-1)
			{
				printf("对不起，没有该学生");
			}


			break;
		case 6:// 按学号修改某个学生信息
			printf("请输入要修改学生的电话号码：");
			scanf("%d",&temp);
			k=-2;
			for(i=0;i<n;++i)
			{
				if(temp==phonenumber[i])
				{
					k=i;
					printf("请输入要修改的信息：\n");
					printf("姓名\n");
					scanf("%15s",names[i]);
					printf("学号\n");
					scanf("%d",&number[i]);
					printf("性别\n");
					scanf("%s",&xingbie[i]);
					printf("电话号码\n");
					scanf("%d",&phonenumber[i]);
					printf("单位\n");
					scanf("%s",&danwei[i]);
					printf("邮址\n");
					scanf("%d",&mail[i]);
					break;		
				}
			}
			if(k==-2)
			{
				printf("对不起，没有该学生");
			}
			break;
		case 7://按姓名删除某个学生信息
			k=-3;
			printf("请输入要删除学生的姓名：");
			scanf("%s",&name);
			for(i=0;i<n;++i)
			{
				if(strcmp(name[i],names[i])==0)
				{
					k=i;
					for(j=i;j<=n-i-1;++j,++i)
					{
						strcpy(names[i],names[i+1]);//姓名
						number[i]=number[i+1];//学号
						xingbie[i]=xingbie[i+1];//性别
						phonenumber[i]=phonenumber[i+1];//电话号码
						danwei[i]=danwei[i+1];//单位
						mail[i]=mail[i+1];//邮址
						printf("删除成功");		
					}	
				}
			}
			n=n-1;
			printf("请输入第%d学生信息(名字，性别，学号，电话号码，单位，邮址)\n",n+1);
			printf("-------------------------------------\n");
			for(i=0;i<n;++i)
			{
				printf("\n15%s\t15%s\t15%d\t15%d\t15%s\t15%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("-------------------------------------\n");		
			}
			if
				(k==-3)
			{
				printf("删除失败");
			}



			break;
		case 8://按电话号码删除某个学生信息
			k=-4;

			printf("请输入要删除学生的电话号码");
			scanf("%d",&temp);


			for(i=0;i<n;++i)
			{
				if(temp==phonenumber[i])
				{
					k=i;
					for(j=i;j<=n-i-1;++j,++i)
					{

						strcpy(names[i],names[i+1]);//姓名
						number[i]=number[i+1];//学号
						xingbie[i]=xingbie[i+1];//性别
						phonenumber[i]=phonenumber[i+1];//电话号码
						danwei[i]=danwei[i+1];//单位
						mail[i]=mail[i+1];//邮址
						printf("删除成功");
					}							
				}
			}
			n=n-1;
			printf("请输入第%d学生信息(名字，性别，学号，电话号码，单位，邮址)\n",n+1);
			printf("-------------------------------------\n");
			for(i=0;i<n;++i)
			{
				printf("\n15%s\t15%s\t15%d\t15%d\t15%s\t15%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("-------------------------------------\n");
			}
			printf("\n");

			if
				(k==-4)
			{
				printf("对不起，没有该学生\n");
			}

			break;
		default:;
		}
	}
	printf("程序结束，谢谢使用：");
	return 0;			

}

