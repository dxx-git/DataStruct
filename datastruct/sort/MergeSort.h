//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//void Merge(int* a,int* tmp,int left,int mid,int right)
//{
//	int begin1 = left;   //左区间的左边界
//	int end1 = mid;      //左区间的右边界
//	int begin2 = mid + 1;//右区间的左边界
//	int end2 = right;    //右区间的右边界
//
//	int index = left;//中间数组的下标
//	while(begin1 <= end1 && begin2 <= end2)
//	{
//		//将左右区间中较小的值放入中间数组
//		if (a[begin1] <= a[begin2])
//		{
//			tmp[index++] = a[begin1++];
//		} 
//		else
//		{
//			tmp[index++] = a[begin2++];
//		}
//	}
//	//如果左区间还有数据，直接放到中间数组后边
//	while(begin1 <= end1)
//	{
//		tmp[index++] = a[begin1++];
//	}
//	//如果右区间还有数据，直接放到中间数组后边
//	while(begin2 <= end2)
//	{
//		tmp[index++] = a[begin2++];
//	}
//	//将中间数组的值考回原数组
//	memcpy(a,tmp,index*sizeof(int));
//	/*for (int i = left; i < index; ++i)
//	{
//		a[i] = tmp[i];
//	}*/
//}
//void _MerSort(int* a,int* tmp,int left,int right)
//{
//	//当区间只有一个数或没有数据时递归返回
//	if (left >= right)
//		return;
//	
//	int mid = left + ((right - left)>>1);//划分左右区间的中间值
//
//	_MerSort(a,tmp,left,mid);   //递归左边区间，使之有序
//	_MerSort(a,tmp,mid+1,right);//递归右边区间，使之有序
//
//	Merge(a,tmp,left,mid,right);//对左右两个有序区间进行归并
//}
//void MergeSort(int* a,size_t n)//归并排序
//{
//	assert(a);
//	int* tmp = new int[n];//中间数组
//
//	_MerSort(a,tmp,0,n-1);
//	delete[]tmp;
//}
//
////非递归
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
