//#pragma  once
//
////����
//template <class T>
//struct SortUp
//{
//	bool operator()(const T&l,const T& r)
//	{
//		return l<r;
//	}
//};
//
////����
//template <class T>
//struct SortDown
//{
//	bool operator()(const T&l,const T& r)
//	{
//		return l>r;
//	}
//};
////�÷º���ʵ�������ǽ�����ߴ���ĸ�����
//
//
//template <class T,class Sort = SortUp<T>>//Ĭ��������
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
//	void AdjustDown(T* a,size_t n,size_t root)//���µ���
//	{
//		Sort sort;
//		size_t parent = root;
//		size_t child = parent*2+1;
//
//		while(child < n)
//		{
//			//�����Һ�����������һ��
//			if (child+1 < n && sort(a[child+1],a[child]))
//			{
//				++child;
//			}
//
//			//������Ӵ��ڸ��ף��򽻻����������µ���,�������
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
//	void GetTopK(T* a,int n,const int k)//������ǰk������
//	{
//		assert(n>k && a);
//		T* heap = new T[k];
//		//������a�е����ݿ�������������
//		for (int i = 0; i < k; i++)
//		{
//			heap[i] = a[i];
//		}
//		//����
//		for (int i = (k-2)/2; i>=0; --i)
//		{
//			AdjustDown(heap,k,i);//С��
//		}
//		//ѡ������ǰk������
//		for (int i = k; i < n; ++i)
//		{
//			if (a[i] > heap[0])
//			{
//				heap[0] = a[i];
//			}
//			AdjustDown(heap,k,0);
//		}
//		cout<<"����ǰk��������:"<<endl;
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