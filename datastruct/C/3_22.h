#pragma once
#include <stdio.h>

////良好的编程习惯
//void fun()
//{
//	int ch = 0;
//	//清空缓冲区
//	while((ch=getchar()) != EOF && ch != '\n')//输完之后回车有可能作为下一个字符
//		putchar(ch);
//	//刷新缓冲区
//	fflush(stdin);//用多行表示一行的效果可以用\（续行符）转义回车，并且\后面不能加任何语句或字符
//}
//
////for循环变种
//void f()
//{
//	int i,k,x,y;
//	i = 0;
//	for(x=0,y=0;x+y<5;x++,y++);//逗号表达式，整个表达式的结果为最后一个表达式的结果
//	for(i=0,k=-1;k=0;i++,k++)//执行0次
//		k++;
//	for(;;);//死循环
//	for(i=0;;i++);//死循环    
//}


////编写多个字符从两端移动，向中间汇聚
//#include <string.h>
//#include <Windows.h>
//void move(char* str)
//{
//	int i = 0;
//	int len = strlen(str);
//	int start = 0;
//	int end = len-1;
//	char* target = (char*)malloc(len+1);
//	memset(target,'*',len);
//	target[len] = '\0';
//
//	printf("%s\n",target);
//	while(start <= end)
//	{
//		target[start] = str[start];
//		target[end] = str[end];
//		start++;
//		end--;
//
//		Sleep(1000);
//		printf("%s\n",target);
//	}
//	free(target);
//}
//
//void move1()
//{
//	char target[80] = "####################" ;
//	char src[] = "welcome to bit-tech!" ;
//	int i, j;
//	printf( "%s\n", target);
//	for (i = 0, j = strlen(src)-1; i <= j; i++, j--)
//	{
//		target[i] = src[i];
//		target[j] = src[j];
//		Sleep(1000);
//		printf( "%s\n", target);
//	}
//}


////模拟用户登录场景，只能登录三次，三次内可登录成功，超过3次直接返回。
//#include <string.h>
//void Loading()
//{
//	char correct_mm[15] = {0};
//	char new_mm[15] = {0};
//	int n = 3;
//	int len = 0;
//	printf("请输入正确密码(长度不超过15)：");
//	scanf("%s",correct_mm);
//	len = strlen(correct_mm);
//
//	printf("请输入登录密码(长度不超过15)：");
//	while(n--)
//	{
//		int new_len = 0;
//		scanf("%s",new_mm);
//		new_len = strlen(new_mm);
//		if (len == new_len)
//		{
//			if (strcmp(new_mm,correct_mm)==0)
//			{
//				break;
//			}
//		}
//		if (n > 0)
//		{
//			printf("密码错误，请重新输入(长度不超过15)：");
//		}
//	}
//	if (n < 0)
//	{
//		printf("登录失败！\n");
//	}
//	else
//	{
//		printf("密码正确，登录成功！\n");
//	}
//}
//
//void Loading1()//错误
//{
//	char psw[10] = "" ;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3 && strcmp(psw, "123456"); ++i)//判断不了第三次成功
//	{
//		printf( "please input:");
//		gets(psw);
//	}
//	if (i == 3)
//		printf( "log failure\n");
//	else
//		printf( "log in\n");
//}
//
//void Loading2()
//{
//	char psw[10] = "" ;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3 ; ++i)
//	{
//		printf( "please input:");
//		gets(psw);
//		if (strcmp(psw, "password" ) == 0)
//			break;
//	}
//	if (i == 3)
//		printf( "log failure\n");
//	else
//		printf( "log in\n");
//}





