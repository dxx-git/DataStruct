//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
////ѡ������ѡһ������������С��-->������������ȷ��λ����-->��С��Χ
//void PrintArray(const int* a,const size_t n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}
//
////C���Է���ѡ������
//void SelectSort1(int* a,size_t n)
//{
//	assert(a);
//	for (size_t i = 1; i < n; ++i)
//	{
//		int minIndex = i;//δ����������С���ݵ�λ���±�
//		int start = i - 1;//δ��������ĵ�һ�������±�
//
//		//ѡ���ڶ�������С������
//		for (size_t j = i+1; j < n-1; ++j)//��j = i+1����Сδ�������䷶Χ
//		{
//			if (a[j+1]<a[minIndex])
//			{
//				swap(a[j+1],a[minIndex]);
//			}
//		}
//		//�ڶ�������С�����ݺ͵ڶ����ֵ�һ�����ݽ��бȽ�
//		if (a[minIndex] < a[start])
//		{
//			swap(a[start],a[minIndex]);
//		}
//	}
//}
//
////C++����ѡ������
//void SelectSort2(int* a,size_t n)
//{
//	assert(a);
//	int minIndex = 0;
//	for (size_t i = 0; i < n - 1; ++i)
//	{
//		minIndex = i;      //δ����������С���ݵ�λ���±�
//		size_t pos = i + 1;//δ��������ĵ�һ�������±�
//
//		while(pos < n)//ѡ��δ����������С������
//		{
//			if (a[pos] < a[minIndex])
//			{
//				minIndex = pos;
//			}
//			++pos;
//		}
//		swap(a[i],a[minIndex]);//����ѡ���ݷŵ���ȷλ��
//	}
//}
//
////ѡ��������Ż���ÿ�μ�ѡ����������Ҳѡ����С����
//void SelectSort3(int* a,size_t n)
//{
//	assert(a);
//	int left = 0;//δ������������±�
//	int right = n - 1;//δ������������±�
//
//	while (left < right)
//	{
//		int minIndex = left;//δ����������С���ݵ�λ���±�
//		int maxIndex = right;//δ��������������ݵ�λ���±�
//
//		//ѡ��������С���ݵ��±�
//		for (int i = left; i <= right; ++i)
//		{
//			if (a[i] < a[minIndex])
//			{
//				minIndex = i;
//			}
//			if (a[i] > a[maxIndex])
//			{
//				maxIndex = i;
//			}
//		}
//		//���������ֵ����Сλ�û���Сֵ�����λ��
//		swap(a[maxIndex],a[right]);//��������ݷŵ��������Ҳ�
//		if (minIndex == right)
//		{
//			minIndex = maxIndex;
//		}
//		swap(a[minIndex],a[left]);//����С���ݷ������������
//
//		left++;//��С���䷶Χ
//		right--;//��С���䷶Χ
//	}
//}
//
//void TestSelectSort()
//{
//	int a[] = {9,5,4,2,3,6,8,7,1,0};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//
//	//SelectSort1(a,sz);
//	//SelectSort2(a,sz);
//	SelectSort3(a,sz);
//	PrintArray(a,sz);
//}
//
////�ѵ��������ѵ�ĩ���ӽ����������ʹ���ӽ����ԶС�ڸ����
//void AdjustDown(int* a,size_t n,size_t pos)
//{
//	size_t parent = pos;//���ڵ���±�
//	size_t child = parent*2 + 1;//���ӵ��±�
//	while(child < n)
//	{
//		//ѡ���Һ����нϴ��
//		if ((child+1 < n) && (a[child] < a[child+1]))
//		{
//			++child;
//		}
//		if (a[child] > a[parent])//������ӽڵ���ڸ��ڵ��ֵ���򽻻�
//		{
//			swap(a[child],a[parent]);
//
//			//���¸��¸��ڵ�ͺ��ӽڵ�
//			parent = child;
//			child = parent*2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
////Ĭ����������Ӧ�ý����
//void HeapSort(int* a,size_t n)
//{
//	assert(a);
//	//�����һ����Ҷ�ӽڵ㿪ʼ���µ���
//	for (int i = (n-2)>>1; i >= 0; --i)
//	{
//		AdjustDown(a,n,i);//�������ѣ���������������������
//	}
//
//	//��С��Χ
//	for (int i = n-1; i > 0; --i)
//	{
//		swap(a[0],a[i]);//�������Ƴ�λ�ڵ�һ�����ݵĸ����
//		AdjustDown(a,i,0);//�������ѵ����ĵݹ�����
//	}
//}
//
//void TestHeapSort()
//{
//	int a[] = {9,5,4,2,3,6,8,7,1,0};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//
//	HeapSort(a,sz);
//	PrintArray(a,sz);
//}