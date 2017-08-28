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
//	//查找待排序序列的最大值
//	int max = a[0];
//	for (size_t i = 0; i < n-1; ++i)
//	{
//		if (max < a[i+1])
//		{
//			max = a[i+1];
//		}
//	}
//
//	//开辟临时数组用来统计数据出现次数
//	int* tmp = new int[max+1];
//	//对临时数组初值赋为0
//	memset(tmp,0,sizeof(int)*(max+1));
//	//统计数据出现次数
//	for (size_t i = 0; i < n; ++i)
//	{
//		tmp[a[i]]++;
//	}
//
//	//将数据考回原数组
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
////计数排序的优化
//void CountSort1(int* a,size_t n)
//{
//	//找到待排序序列的最大值和最小值
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
//	//开辟适当空间的数组
//	int range = max - min + 1;
//	int* tmp = new int[range];
//	memset(tmp,0,sizeof(int)*(range));
//	for (size_t i = 0; i < n; ++i)
//	{
//		tmp[a[i]-min]++;
//	}
//
//	//将数据考回原数组
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