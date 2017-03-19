//#pragma  once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//void BubbleSort(int* a,size_t n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		for (size_t j = 0; j < n-1-i; ++j)
//		{
//			if (a[j] > a[j+1])
//			{
//				swap(a[j],a[j+1]);
//			}
//		}
//	}
//}
//
////冒泡排序优化
//void BubbleSort1(int* a,size_t n)
//{
//	size_t flag = 0;
//	for (size_t i = 0; i < n; ++i)
//	{
//		flag = 0;
//		for (size_t j = 0; j < n-1-i; ++j)
//		{
//			if (a[j] > a[j+1])
//			{
//				swap(a[j],a[j+1]);
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//
//void PrintArray(const int* a,const size_t n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}
//
//void TestBubbleSort()
//{
//	int a[] = {2,5,4,9,3,6,8,7,1,0};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//
//	BubbleSort(a,sz);
//	//BubbleSort1(a,sz);
//	PrintArray(a,sz);
//}
//
//
////快排优化1：三数取中法
//int GetMidIndex(int* a,int left,int right)
//{
//	int mid = left + ((right - left) >> 1);
//
//	if (a[left] < a[mid])
//	{
//		if (a[mid] < a[right])
//		{
//			return mid;
//		}
//		else if (a[left] < a[right])
//		{
//			return right;
//		}
//		else
//		{
//			return left;
//		}
//	}
//	else//a[left]>=a[mid]
//	{
//		if (a[mid] > a[right])
//		{
//			return mid;
//		}
//		else if (a[left] > a[right])
//		{
//			return right;
//		}
//		else
//		{
//			return left;
//		}
//	}
//}
//
////左右指针法
//int PartSort1(int* a,int left,int right)
//{
//	int mid = GetMidIndex(a,left,right);
//	swap(a[mid],a[right]);
//
//	int key = right;//利用key作为基准值的下标
//
//	while (left < right)
//	{
//		//左指针向右找第一个比key大的数
//		while (left < right && a[left] <= a[key])
//		{
//			++left;
//		}
//		//右指针向左扎找第一个比key的数
//		while (left < right && a[right] >= a[key])
//		{
//			--right;
//		}
//		//交换左右指针所指的值
//		if (a[left] != a[right])
//		{
//			std::swap(a[left],a[right]);
//		}
//	}
//	//将key值放到正确位置上
//	swap(a[left],a[key]);
//
//	return left;
//}
//
//
////挖坑法
//int PartSort2(int*a,int left,int right)
//{
//	int mid = GetMidIndex(a,left,right);
//	swap(a[mid],a[right]);
//
//	int key = a[right];//将区间最右侧数据基准值
//	int blank = right;//首次将坑设置到key处
//
//	while (left < right)
//	{
//		//左指针向右找比key大的数据
//		while (left < right && a[left] <= key)
//		{
//			++left;
//		}
//		a[blank] = a[left];//用找到的数据填坑
//		blank = left;//更新坑所在位置
//
//		//右指针想左找比key小的数据
//		while (left < right && a[right] >= key)
//		{
//			--right;
//		}
//		a[blank] = a[right];//用找到的数据填坑
//		blank = right;//更新坑
//	}
//	a[blank] = key;//最后用key值填坑
//	return blank;
//}
//
////3,前后指针法
//int PartSort3(int* a,int left,int right)
//{
//	int mid = GetMidIndex(a,left,right);
//	swap(a[mid],a[right]);
//
//	int key = right;//key保存基准值的下标
//	int cur = left;
//	int prev = cur - 1;
//
//	while (cur != right)
//	{
//		if (a[cur] < a[key] && a[++prev] != a[cur])
//		{
//			swap(a[cur],a[prev]);
//		}
//		++cur;
//	}
//	swap(a[++prev],a[cur]);
//	return prev;
//}
////快排优化2：小区间优化
//void InsertSort(int* a,size_t n)//升序
//{
//	int end = 0;
//	for (size_t i = 1; i < n; ++i)
//	{
//		int tmp = a[i];
//		end = i - 1;
//
//		while(end >= 0)
//		{
//			if (a[end] > tmp)
//			{
//				a[end+1] = a[end];
//				--end;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end+1] = tmp;
//	}
//}
//void QuickSort(int* a,int left,int right)
//{
//	assert(a);
//	if (left < right)
//	{
//		int kiv = PartSort1(a,left,right);
//		int kiv = PartSort2(a,left,right);
//		int kiv = PartSort3(a,left,right);
//
//		//快排优化2：小区间优化
//		if (right - left < 2)//数据较少直接用插入排序更优
//		                     （13可能更合适，写2为了方便测试）
//		{
//			InsertSort((a + left),(right - left +1));
//		}
//		else//数据量大则选用快排
//		{
//			QuickSort(a,left,kiv-1);
//			QuickSort(a,kiv+1,right);
//		}
//	}
//}
//
//#include <stack>
////快排优化3：非递归实现
//void QuickSortNoneR(int* a,int left,int right)
//{
//	assert(a);
//	stack<int> s;//创建一个栈
//	s.push(right);
//	s.push(left);
//
//	while(!s.empty())
//	{
//		int start = s.top();//先取左边界
//		s.pop();
//		int end = s.top();//再取右边界
//		s.pop();
//		//int div = PartSort1(a,start,end);
//		//int div = PartSort2(a,start,end);
//		int div = PartSort3(a,start,end);
//
//		if (start < div-1)
//		{
//			s.push(div - 1);
//			s.push(start);
//		}
//		if (end > div+1)
//		{
//			s.push(end);
//			s.push(div + 1);
//		}
//	}
//}
//
//
//void TestQuickSort()
//{
//	int a1[] = {2,0,4,9,3,6,8,7,1,5};
//	int a[] = {2,8,4,6,5,1};
//
//	size_t sz = sizeof(a)/sizeof(a[0]);
//
//	QuickSort(a,0,sz-1);
//	//QuickSortNoneR(a,0,sz-1);
//
//	PrintArray(a,sz);
//}