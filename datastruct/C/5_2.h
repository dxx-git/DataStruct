#pragma once
#include <iostream>
using namespace std;

/*��һ������������ʽ���ж���λΪ1*/
int CountBits1(unsigned value)//�������ڸ���
{
	int count = 0;
	while(value)
	{
		if (value%2 != 0)//�����һλ�ǲ���1����1��++
			++count;
		value /= 2;//ȥ�����һλ
	}
	return count;
}
int CountBits2(unsigned value)//�������ڸ���
{
	int count = 0;
	while(value)
	{
		if (value%2 != 0)//�����һλ�ǲ���1����1��++
			++count;
		value >>= 1;//ȥ�����һλ���ȳ�����Ч
	}
	return count;
}
int CountBits3(unsigned value)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (((value>>i)&1) == 1)
			++count;
	}
	return count;
}
int CountBits4(unsigned value)//�������ڸ���
{
	int count = 0;
	while(value)
	{
		++count;
		value &= (value-1);//ȥ�����һλ1
	}
	return count;
}
void TestCountBits()
{
	cout<<CountBits1(0)<<endl;
	cout<<CountBits1(10)<<endl;
	cout<<CountBits1(8)<<endl;
	cout<<CountBits1(15)<<endl;

	cout<<CountBits2(0)<<endl;
	cout<<CountBits2(10)<<endl;
	cout<<CountBits2(8)<<endl;
	cout<<CountBits2(15)<<endl;

	cout<<CountBits3(0)<<endl;
	cout<<CountBits3(-1)<<endl;
	cout<<CountBits3(8)<<endl;
	cout<<CountBits3(15)<<endl;

	cout<<CountBits4(0)<<endl;
	cout<<CountBits4(-1)<<endl;
	cout<<CountBits4(8)<<endl;
	cout<<CountBits4(15)<<endl;
}

#include <Windows.h>
void ProgressBar()
{
	int i = 0;
	char bar[102];
	bar[0] = 0;
	const char* lable = "|/-\\";
	while(i <= 100)
	{
		printf("[%-100s][%d%%][%c]\r",bar,i,lable[i%4]);
		fflush(stdout);
		bar[i] = '*';
		i++;
		bar[i] = 0;
		Sleep(100);
	}
	printf("\n");
}

/*����������*/
void Swap1(int* a,int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Swap2(int* a,int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void Swap3(int* a,int* b)
{
	*a = *a * *b;
	*b = *a / *b;
	*a = *a / *b;
}