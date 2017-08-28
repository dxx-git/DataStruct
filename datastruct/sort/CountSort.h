//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//void PrintArray(int* a,size_t n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}
//
//
//void CountSort(int* a,size_t n)
//{
//	//���Ҵ��������е����ֵ
//	int max = a[0];
//	for (size_t i = 0; i < n-1; ++i)
//	{
//		if (max < a[i+1])
//		{
//			max = a[i+1];
//		}
//	}
//
//	//������ʱ��������ͳ�����ݳ��ִ���
//	int* tmp = new int[max+1];
//	//����ʱ�����ֵ��Ϊ0
//	memset(tmp,0,sizeof(int)*(max+1));
//	//ͳ�����ݳ��ִ���
//	for (size_t i = 0; i < n; ++i)
//	{
//		tmp[a[i]]++;
//	}
//
//	//�����ݿ���ԭ����
//	int index = 0;
//	for (int i = 0; i <= max; ++i)
//	{
//		while(tmp[i]--)
//		{
//			a[index] = i;
//			++index;
//		}
//	}
//	delete []tmp;
//}
//
////����������Ż�
//void CountSort1(int* a,size_t n)
//{
//	//�ҵ����������е����ֵ����Сֵ
//	int max = a[0];
//	int min = a[0];
//	for (size_t i = 0; i < n-1; ++i)
//	{
//		if (max < a[i+1])
//		{
//			max = a[i+1];
//		}
//		if (min > a[i+1])
//		{
//			min = a[i+1];
//		}
//	}
//
//	//�����ʵ��ռ������
//	int range = max - min + 1;
//	int* tmp = new int[range];
//	memset(tmp,0,sizeof(int)*(range));
//	for (size_t i = 0; i < n; ++i)
//	{
//		tmp[a[i]-min]++;
//	}
//
//	//�����ݿ���ԭ����
//	int index = 0;
//	for (int i = 0; i < range; ++i)
//	{
//		while(tmp[i]--)
//		{
//			a[index] = i+min;
//			++index;
//		}
//	}
//	delete []tmp;
//}
//
//void TestCountSort()
//{
//	int a[] = {2,5,4,9,3,6,8,7,1,0};
//	int a1[] = {73,20,93,43,55,14,28,65,39,81};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//	size_t sz1 = sizeof(a1)/sizeof(a1[0]);
//
//	CountSort(a,sz);
//	CountSort1(a1,sz1);
//	PrintArray(a,sz);
//	PrintArray(a1,sz1);
//}