#pragma once
#include <iostream>
using namespace std;

////����n�Ľ׳�n!
//unsigned long long mul(int n)//�ݹ�
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
//	//printf("%ld\n",ret);//�����ݽϴ�ʱ��printf��ʽ������ܳ���
//	cout<<ret<<endl;
//
//	unsigned long long ret1 = mul1(32);
//	//printf("%ld\n",ret);//�����ݽϴ�ʱ��printf��ʽ������ܳ���
//	cout<<ret1<<endl;
//}


////����1��+ 2��+����+ 10��
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
////�۰����
//int BinarySearch(int* a,size_t n,int key)//���������������
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

////��д������Ϸ
//#include <time.h>
//void Guess()
//{
//	int start = 1;
//	while(start)
//	{
//		int input = 0;
//
//		printf("���������ѡ��(1�����������Ϸ 2���˳���Ϸ):>");
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
//					printf("��������Ҫ�µ����ݣ�");
//					scanf("%d",&input);
//					if (input == random)
//					{
//						printf("�¶��ˣ�\n");
//						break;
//					}
//					else if (input < random)
//					{
//						printf("��С�ˣ�\n");
//					}
//					else
//					{
//						printf("�´��ˣ�\n");
//					}
//				}
//			}
//			break;
//		case 0:
//			exit(EXIT_FAILURE);
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	}
//}


////���ַ�������ȡ���ַ����������Ӵ��ĳ���
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


////��һ���������У�2/1+3/2+5/3+8/5+13/8+��������������ǰ20��ĺ�
//void Sum()
//{
//	int i = 0;
//	double sum = 0.0;
//	double deno = 1;//��ĸ
//	double mole = 2;//����
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


////һ�����100���������£�ÿ����غ�����ԭ�߶ȵ�һ�룬�����£��ٷ�����
////���10�����ʱ�������������ף���10�η�����ߡ�
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


//���ӳ���:��һ��ժ�����ɸ����ӣ���������һ�룬�������һ����
//�Ժ�ÿ�춼��ʣ�����ӵ�һ���ٶ�һ��������ʮ������Ե�ʱ��
//ֻʣ��һ�������ˣ����һ��һ��ժ�˶������ӡ�
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