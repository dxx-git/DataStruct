#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

int GetMaxDigit(int* a,size_t n)//�õ��������ֵ��λ��
{
	int digit = 1;
	int base = 10;

	for (size_t i = 0; i < n; ++i)
	{
		//ÿ���뼸λ������С���ݣ�10��100��1000���������бȽϣ�
		//�ŵ�����ͬλ��������ֻͳ��һ��
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
	int digit = GetMaxDigit(a,n);//ͳ��λ��
	int* tmp = new int[n];//������ʱ����

	while(digit--)
	{
		int count[10] = {0};
		//ͳ��ĳλ��ͬ�����ݳ��ִ���
		for (size_t i = 0; i < n; ++i)
		{
			int index = a[i]/base %10;
			count[index]++;
		}

		int start[10] = {0};
		//ͳ�Ƹ�λ��ͬ����������a�г��ֵ�λ��
		for (size_t i = 1; i < n; ++i)
		{
			start[i] = count[i-1] + start[i-1];
		}

		memset(tmp,0,sizeof(int)*n);//Ϊtmp�����ʼ��
		//��Ͱ���ռ����ݣ���С����
		for (size_t i = 0; i < n; ++i)
		{
			int index = a[i]/base %10;
			tmp[start[index]++] = a[i];
		}

		//�����ݿ���ԭ����
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