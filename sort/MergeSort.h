//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//void Merge(int* a,int* tmp,int left,int mid,int right)
//{
//	int begin1 = left;   //���������߽�
//	int end1 = mid;      //��������ұ߽�
//	int begin2 = mid + 1;//���������߽�
//	int end2 = right;    //��������ұ߽�
//
//	int index = left;//�м�������±�
//	while(begin1 <= end1 && begin2 <= end2)
//	{
//		//�����������н�С��ֵ�����м�����
//		if (a[begin1] <= a[begin2])
//		{
//			tmp[index++] = a[begin1++];
//		} 
//		else
//		{
//			tmp[index++] = a[begin2++];
//		}
//	}
//	//��������仹�����ݣ�ֱ�ӷŵ��м�������
//	while(begin1 <= end1)
//	{
//		tmp[index++] = a[begin1++];
//	}
//	//��������仹�����ݣ�ֱ�ӷŵ��м�������
//	while(begin2 <= end2)
//	{
//		tmp[index++] = a[begin2++];
//	}
//	//���м������ֵ����ԭ����
//	memcpy(a,tmp,index*sizeof(int));
//	/*for (int i = left; i < index; ++i)
//	{
//		a[i] = tmp[i];
//	}*/
//}
//void _MerSort(int* a,int* tmp,int left,int right)
//{
//	//������ֻ��һ������û������ʱ�ݹ鷵��
//	if (left >= right)
//		return;
//	
//	int mid = left + ((right - left)>>1);//��������������м�ֵ
//
//	_MerSort(a,tmp,left,mid);   //�ݹ�������䣬ʹ֮����
//	_MerSort(a,tmp,mid+1,right);//�ݹ��ұ����䣬ʹ֮����
//
//	Merge(a,tmp,left,mid,right);//��������������������й鲢
//}
//void MergeSort(int* a,size_t n)//�鲢����
//{
//	assert(a);
//	int* tmp = new int[n];//�м�����
//
//	_MerSort(a,tmp,0,n-1);
//	delete[]tmp;
//}
//
////�ǵݹ�
//void Merge_sort(int *a, int length)
//{  
//	int i, begin1, end1, begin2, end2, index;  
//	int *tmp = new int[length];  
//
//	for (i = 1; i < length; i *= 2) 
//	{
//		for (begin1 = 0; begin1 < length - i; begin1 = end2)
//		{   
//			begin2 = end1 = begin1 + i;  
//			end2 = end1 + i;  
//
//			if (end2 > length)  
//				end2 = length;  
//
//			index = 0;  
//			while (begin1 < end1 && begin2 < end2)  
//				tmp[index++] = a[begin1] > a[begin2] ? a[begin2++] : a[begin1++];  
//
//			while (begin1 < end1)  
//				a[--begin2] = a[--end1];  
//
//			while (index > 0)  
//				a[--begin2] = tmp[--index];  
//		}  
//	}
//	delete []tmp;
//}  
//
//void PrintArray(int* a,size_t n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}
//void TestMergeSort()
//{
//	int a[] = {2,5,4,9,3,6,8,7,1,0};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//
//	Merge_sort(a,sz);
//	//MergeSort(a,sz);
//	PrintArray(a,sz);
//}
