#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

int GetMaxDigit(int* a,size_t n)//得到数组最大值的位数
{
	int digit = 1;
	int base = 10;

	for (size_t i = 0; i < n; ++i)
	{
		//每次与几位数的最小数据（10、100、1000……）进行比较，
		//优点是相同位数的数据只统计一次
		while(a[i] >= base)
		{
			++digit;
			base *= 10;
		}
	}
	
	return digit;
}

void LSDSort(int* a,size_t n)
{
	assert(a);
	int base = 1;
	int digit = GetMaxDigit(a,n);//统计位数
	int* tmp = new int[n];//开辟临时数组

	while(digit--)
	{
		int count[10] = {0};
		//统计某位相同的数据出现次数
		for (size_t i = 0; i < n; ++i)
		{
			int index = a[i]/base %10;
			count[index]++;
		}

		int start[10] = {0};
		//统计个位相同的数在数组a中出现的位置
		for (size_t i = 1; i < n; ++i)
		{
			start[i] = count[i-1] + start[i-1];
		}

		memset(tmp,0,sizeof(int)*n);//为tmp数组初始化
		//从桶中收集数据（从小到大）
		for (size_t i = 0; i < n; ++i)
		{
			int index = a[i]/base %10;
			tmp[start[index]++] = a[i];
		}

		//将数据拷回原数组
		memcpy(a,tmp,sizeof(int)*n);
		base *= 10;
	}
	delete []tmp;
}

void PrintArray(int* a,size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void TestLDSort()
{
	int a[] = {73,20,93,43,55,14,28,65,39,81};
	size_t sz = sizeof(a)/sizeof(a[0]);

	LSDSort(a,sz);
	PrintArray(a,sz);
}