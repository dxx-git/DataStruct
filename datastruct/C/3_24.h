#pragma once
#include <iostream>
using namespace std;

////计算n的阶乘n!
//unsigned long long mul(int n)//递归
//{
//	unsigned long long tmp = 0;
//	if (n == 1)
//	{
//		return 1;
//	}
//	tmp = n * mul(n-1); 
//	return tmp;
//}
//
//unsigned long long mul1(int n)
//{
//	unsigned long long tmp = n;
//	while(n > 1)
//	{
//		tmp *= (n-1);
//		--n;
//	}
//	return tmp;
//}
//
//void Testmul()
//{
//	unsigned long long ret = mul(32);
//	//printf("%ld\n",ret);//当数据较大时，printf格式输出可能出错
//	cout<<ret<<endl;
//
//	unsigned long long ret1 = mul1(32);
//	//printf("%ld\n",ret);//当数据较大时，printf格式输出可能出错
//	cout<<ret1<<endl;
//}


////计算1！+ 2！+……+ 10！
//void cal()
//{
//	int sum = 0;
//	int n = 10;
//	int tmp = n;
//
//	while(n > 1)
//	{
//		tmp *= (n - 1);
//		--n;
//		sum += tmp;
//	}
//	printf("%d\n",sum);
//}
//
////折半查找
//int BinarySearch(int* a,size_t n,int key)//假设数组是升序的
//{
//	int left = 0;
//	int right = n - 1;
//	//int mid = (right + left)/2;
//	//int mid =  ((left & right) + (left | right)) >>1;
//	int mid = left + ((right - left)>>1);
//
//	while(left <= right)
//	{
//		//mid = (right + left)/2;
//		//mid = ((left & right) + (left | right)) >>1;
//		mid = left + ((right - left)>>1);
//		if (key > a[mid])
//		{
//			left = mid + 1;
//		}
//		else if (key < a[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//void TestBinarySearch()
//{
//	int array[] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(array)/sizeof(array[0]);
//
//	cout<<BinarySearch(array,sz,1)<<endl;
//	cout<<BinarySearch(array,sz,10)<<endl;
//	cout<<BinarySearch(array,sz,5)<<endl;
//	cout<<BinarySearch(array,sz,6)<<endl;
//	cout<<BinarySearch(array,sz,8)<<endl;
//	cout<<BinarySearch(array,sz,20)<<endl;
//}

////编写猜字游戏
//#include <time.h>
//void Guess()
//{
//	int start = 1;
//	while(start)
//	{
//		int input = 0;
//
//		printf("请输入你的选择(1、进入猜字游戏 2、退出游戏):>");
//		scanf("%d",&start);
//		
//		switch(start)
//		{
//		case 1:
//			{
//				srand(time(NULL));
//				int random = rand() % 10;
//				while(1)
//				{
//					printf("请输入你要猜的数据：");
//					scanf("%d",&input);
//					if (input == random)
//					{
//						printf("猜对了！\n");
//						break;
//					}
//					else if (input < random)
//					{
//						printf("猜小了！\n");
//					}
//					else
//					{
//						printf("猜大了！\n");
//					}
//				}
//			}
//			break;
//		case 0:
//			exit(EXIT_FAILURE);
//		default:
//			printf("选择错误！\n");
//			break;
//		}
//	}
//}


////从字符串中提取子字符串，返回子串的长度
//int substr(char dst[], char src[],int start, int len)
//{
//	char* tmp = src;
//	int length = len - start;
//	int i = 0;
//	while(start--)
//	{
//		++tmp;
//	}
//	for(i = 0; i < length; ++i)
//	{
//		dst[i] = *tmp++;
//	}
//	dst[i] = '\0';
//	return length;
//}
//void TestSubstr()
//{
//	char src[] = {"abcdrfghijklmn"};
//	int len = sizeof(src)/sizeof(src[0]);
//	char *dst = new char[len];
//	cout<<substr(dst,src,4,len)<<endl;
//	delete []dst;
//}


////有一个分数序列：2/1+3/2+5/3+8/5+13/8+…，求出这个序列前20项的和
//void Sum()
//{
//	int i = 0;
//	double sum = 0.0;
//	double deno = 1;//分母
//	double mole = 2;//分子
//	double num1 = 1;
//	double num2 = 2;
//
//	for(i = 0; i < 20; ++i)
//	{
//		sum += mole/deno;
//
//		deno = mole;
//		mole = num1 + num2;
//		num1 = num2;
//		num2 = mole;
//	}
//	printf("%f\n",sum);
//}


////一个球从100高自由落下，每次落地后反跳回原高度的一半，再落下，再反弹。
////求第10次落地时，共经过多少米，第10次反弹多高。
//void Heigh()
//{
//	double high = 100.0;
//	int count = 10;
//	double sum = high;
//
//	while(count--)
//	{
//		high /= 2;
//		sum += 2*high;
//	}
//	printf("sum:%f\n",sum-2*high);
//	printf("high:%f\n",high);
//}


//猴子吃桃:第一天摘下若干个桃子，当即吃了一半，还多吃了一个，
//以后每天都吃剩余桃子的一半再多一个，到第十天再想吃的时候，
//只剩下一个桃子了，求第一天一共摘了多少桃子。
//void Peach()
//{
//	int peach = 1;
//	int day = 9;
//	
//	while(day--)
//	{
//		peach = (peach+1)*2;
//	}
//	printf("%d\n",peach);
//}