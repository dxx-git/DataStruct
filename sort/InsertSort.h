//#pragma  once
//#include <assert.h>
//
////用仿函数同时实现升序降序功能
//template <class T>
//struct  Less//升序
//{
//	bool operator()(const T& l,const T& r)
//	{
//		return l < r;
//	}
//};
//template <class T>
//struct  Greater//降序
//{
//	bool operator()(const T& l,const T& r)
//	{
//		return l > r;
//	}
//};
//
//template <class T>
//void PrintArray(const T* a,size_t n)//打印数组
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}
//
//template <class T ,class Compare>
//void ShellSort(T* a,size_t n)//希尔排序
//{
//	assert(a);
//	int gap = n;//gap为所给增量
//	while(gap > 1)
//	{
//		//实验证明，gap=gap/3是比较优的，+1则是为了最后一次对全体数据进行插入排序
//		gap = gap/3 + 1;
//		for (size_t i = gap; i < n; ++i)
//		{
//			int end = i - gap;
//			T tmp = a[i];
//
//			while(end >= 0)
//			{
//				if (Compare()(tmp,a[end]))
//				{
//					a[end+gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end+gap] = tmp;
//		}
//	}
//}
//
//void TestShellSort()
//{
//	int a[] = {2,5,4,9,3,6,8,7,1,0};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//
//	ShellSort<int,Less<int>>(a,sz);
//	PrintArray(a,sz);
//	ShellSort<int,Greater<int>>(a,sz);
//	PrintArray(a,sz);
//}
//
//template <class T ,class Compare>
//void InsertSort(T* a,size_t n)
//{
//	assert(a);
//
//	for (size_t i = 1; i < n; ++i)
//	{
//		int end = i-1;//有序区间的最后一个下标
//		T tmp = a[i];//用临时变量保存无序区间的第一个数据，也是即将插入有序区间的数
//
//		while(end >= 0)
//		{
//			if (Compare()(tmp,a[end]))//利用仿函数实现比较器
//			{
//				a[end+1] = a[end];//为tmp挪出合适的位置插入
//				--end;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end+1] = tmp;//将tmp插入有序区间的合适位置
//	}
//}
//
//void TestInsertSort()
//{
//	int a[] = {2,5,4,9,3,6,8,7,1,0};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//
//	InsertSort<int,Less<int>>(a,sz);//升序测试
//	PrintArray(a,sz);
//	InsertSort<int,Greater<int>>(a,sz);//降序测试
//	PrintArray(a,sz);
//}
