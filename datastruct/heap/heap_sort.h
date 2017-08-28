//#pragma  once
//
////升序
//template <class T>
//struct SortUp
//{
//	bool operator()(const T&l,const T& r)
//	{
//		return l<r;
//	}
//};
//
////降序
//template <class T>
//struct SortDown
//{
//	bool operator()(const T&l,const T& r)
//	{
//		return l>r;
//	}
//};
////用仿函数实现升序还是降序，提高代码的复用性
//
//
//template <class T,class Sort = SortUp<T>>//默认是升序
//class HeapSort
//{
//public:
//	void HSort(T* a,size_t n)
//	{
//		assert(a);
//		for (int i = (n-2)/2; i>=0; --i)
//		{
//			AdjustDown(a,n,i);
//		}
//		size_t end = n - 1;
//		while(end > 0)
//		{
//			swap(a[0],a[end]);
//			AdjustDown(a,end,0);
//			--end;
//		}
//	}
//	void SortDisplay(T* a,size_t n)
//	{
//		for (size_t i = 0; i<n; i++)
//		{
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
//	}
//	void AdjustDown(T* a,size_t n,size_t root)//向下调整
//	{
//		Sort sort;
//		size_t parent = root;
//		size_t child = parent*2+1;
//
//		while(child < n)
//		{
//			//找左右孩子里面大的那一个
//			if (child+1 < n && sort(a[child+1],a[child]))
//			{
//				++child;
//			}
//
//			//如果孩子大于父亲，则交换，继续向下调整,否则结束
//			if (sort(a[child] , a[parent]))
//			{
//				swap(a[child],a[parent]);
//				parent = child;
//				child = parent*2+1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	void GetTopK(T* a,int n,const int k)//求最大的前k个数据
//	{
//		assert(n>k && a);
//		T* heap = new T[k];
//		//将数组a中的数据拷贝到堆数组中
//		for (int i = 0; i < k; i++)
//		{
//			heap[i] = a[i];
//		}
//		//建堆
//		for (int i = (k-2)/2; i>=0; --i)
//		{
//			AdjustDown(heap,k,i);//小堆
//		}
//		//选择最大的前k个数据
//		for (int i = k; i < n; ++i)
//		{
//			if (a[i] > heap[0])
//			{
//				heap[0] = a[i];
//			}
//			AdjustDown(heap,k,0);
//		}
//		cout<<"最大的前k个数据是:"<<endl;
//		for (int i = 0 ; i < k; i++)
//		{
//			cout<<heap[i]<<" ";
//		}
//		cout<<endl;
//	}
//};
//
//
//void Testheapsort()
//{
//	int a [] = {10, 11, 13, 12, 16, 18, 15, 17, 14, 19};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//	HeapSort<int,SortUp<int>> hp;
//	hp.GetTopK(a,sz,5);
//	hp.HSort(a,sz);
//	hp.SortDisplay(a,sz);
//
//	HeapSort<int,SortDown<int>> hp1;
//	hp1.HSort(a,sz);
//	hp1.SortDisplay(a,sz);
//}