#pragma once
#include <stdio.h>

////���õı��ϰ��
//void fun()
//{
//	int ch = 0;
//	//��ջ�����
//	while((ch=getchar()) != EOF && ch != '\n')//����֮��س��п�����Ϊ��һ���ַ�
//		putchar(ch);
//	//ˢ�»�����
//	fflush(stdin);//�ö��б�ʾһ�е�Ч��������\�����з���ת��س�������\���治�ܼ��κ������ַ�
//}
//
////forѭ������
//void f()
//{
//	int i,k,x,y;
//	i = 0;
//	for(x=0,y=0;x+y<5;x++,y++);//���ű��ʽ���������ʽ�Ľ��Ϊ���һ�����ʽ�Ľ��
//	for(i=0,k=-1;k=0;i++,k++)//ִ��0��
//		k++;
//	for(;;);//��ѭ��
//	for(i=0;;i++);//��ѭ��    
//}


////��д����ַ��������ƶ������м���
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


////ģ���û���¼������ֻ�ܵ�¼���Σ������ڿɵ�¼�ɹ�������3��ֱ�ӷ��ء�
//#include <string.h>
//void Loading()
//{
//	char correct_mm[15] = {0};
//	char new_mm[15] = {0};
//	int n = 3;
//	int len = 0;
//	printf("��������ȷ����(���Ȳ�����15)��");
//	scanf("%s",correct_mm);
//	len = strlen(correct_mm);
//
//	printf("�������¼����(���Ȳ�����15)��");
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
//			printf("�����������������(���Ȳ�����15)��");
//		}
//	}
//	if (n < 0)
//	{
//		printf("��¼ʧ�ܣ�\n");
//	}
//	else
//	{
//		printf("������ȷ����¼�ɹ���\n");
//	}
//}
//
//void Loading1()//����
//{
//	char psw[10] = "" ;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3 && strcmp(psw, "123456"); ++i)//�жϲ��˵����γɹ�
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





