//#pragma  once
//#include <assert.h>
//
////�÷º���ͬʱʵ����������
//template <class T>
//struct  Less//����
//{
//	bool operator()(const T& l,const T& r)
//	{
//		return l < r;
//	}
//};
//template <class T>
//struct  Greater//����
//{
//	bool operator()(const T& l,const T& r)
//	{
//		return l > r;
//	}
//};
//
//template <class T>
//void PrintArray(const T* a,size_t n)//��ӡ����
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}
//
//template <class T ,class Compare>
//void ShellSort(T* a,size_t n)//ϣ������
//{
//	assert(a);
//	int gap = n;//gapΪ��������
//	while(gap > 1)
//	{
//		//ʵ��֤����gap=gap/3�ǱȽ��ŵģ�+1����Ϊ�����һ�ζ�ȫ�����ݽ��в�������
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
//		int end = i-1;//������������һ���±�
//		T tmp = a[i];//����ʱ����������������ĵ�һ�����ݣ�Ҳ�Ǽ������������������
//
//		while(end >= 0)
//		{
//			if (Compare()(tmp,a[end]))//���÷º���ʵ�ֱȽ���
//			{
//				a[end+1] = a[end];//ΪtmpŲ�����ʵ�λ�ò���
//				--end;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end+1] = tmp;//��tmp������������ĺ���λ��
//	}
//}
//
//void TestInsertSort()
//{
//	int a[] = {2,5,4,9,3,6,8,7,1,0};
//	size_t sz = sizeof(a)/sizeof(a[0]);
//
//	InsertSort<int,Less<int>>(a,sz);//�������
//	PrintArray(a,sz);
//	InsertSort<int,Greater<int>>(a,sz);//�������
//	PrintArray(a,sz);
//}
