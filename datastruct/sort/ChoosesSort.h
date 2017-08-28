//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
////选择排序：选一个数（最大或最小）-->将此数放在正确的位置上-->缩小范围
//void PrintArray(const int* a,const size_t n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}
//
////C语言风格的选择排序
//void SelectSort1(int* a,size_t n)
//{
//	assert(a);
//	for (size_t i = 1; i < n; ++i)
//	{
//		int minIndex = i;//未排序区间最小数据的位置下标
//		int start = i - 1;//未排序区间的第一个数据下标
//
//		//选出第二部分最小的数据
//		for (size_t j = i+1; j < n-1; ++j)//用j = i+1来缩小未排序区间范围
//		{
//			if (a[j+1]<a[minIndex])
//			{
//				swap(a[j+1],a[minIndex]);
//			}
//		}
//		//第二部分最小的数据和第二部分第一个数据进行比较
//		if (a[minIndex] < a[start])
//		{
//			swap(a[start],a[minIndex]);
//		}
//	}
//}
//
////C++风格的选择排序
//void SelectSort2(int* a,size_t n)
//{
//	assert(a);
//	int minIndex = 0;
//	for (size_t i = 0; i < n - 1; ++i)
//	{
//		minIndex = i;      //未排序区间最小数据的位置下标
//		size_t pos = i + 1;//未排序区间的第一个数据下标
//
//		while(pos < n)//选出未排序区间最小的数据
//		{
//			if (a[pos] < a[minIndex])
//			{
//				minIndex = pos;
//			}
//			++pos;
//		}
//		swap(a[i],a[minIndex]);//将所选数据放到正确位置
//	}
//}
//
////选择排序的优化：每次既选出最大的数，也选出最小的数
//void SelectSort3(int* a,size_t n)
//{
//	assert(a);
//	int left = 0;//未排序区间的左下标
//	int right = n - 1;//未排序区间的右下标
//
//	while (left < right)
//	{
//		int minIndex = left;//未排序区间最小数据的位置下标
//		int maxIndex = right;//未排序区间最大数据的位置下标
//
//		//选出最大和最小数据的下标
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
//		//修正：最大值在最小位置或最小值在最大位置
//		swap(a[maxIndex],a[right]);//将最大数据放到区间最右侧
//		if (minIndex == right)
//		{
//			minIndex = maxIndex;
//		}
//		swap(a[minIndex],a[left]);//将最小数据放在区间最左侧
//
//		left++;//缩小区间范围
//		right--;//缩小区间范围
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
////堆调整：将堆的末端子结点作调整，使得子结点永远小于父结点
//void AdjustDown(int* a,size_t n,size_t pos)
//{
//	size_t parent = pos;//父节点的下标
//	size_t child = parent*2 + 1;//左孩子的下标
//	while(child < n)
//	{
//		//选左右孩子中较大的
//		if ((child+1 < n) && (a[child] < a[child+1]))
//		{
//			++child;
//		}
//		if (a[child] > a[parent])//如果孩子节点大于父节点的值，则交换
//		{
//			swap(a[child],a[parent]);
//
//			//向下更新父节点和孩子节点
//			parent = child;
//			child = parent*2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
////默认升序，所以应该建大堆
//void HeapSort(int* a,size_t n)
//{
//	assert(a);
//	//从最后一个非叶子节点开始向下调整
//	for (int i = (n-2)>>1; i >= 0; --i)
//	{
//		AdjustDown(a,n,i);//创建最大堆：将堆所有数据重新排序
//	}
//
//	//缩小范围
//	for (int i = n-1; i > 0; --i)
//	{
//		swap(a[0],a[i]);//堆排序：移除位在第一个数据的根结点
//		AdjustDown(a,i,0);//并做最大堆调整的递归运算
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