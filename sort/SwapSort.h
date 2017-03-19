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
////ð�������Ż�
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
////�����Ż�1������ȡ�з�
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
////����ָ�뷨
//int PartSort1(int* a,int left,int right)
//{
//	int mid = GetMidIndex(a,left,right);
//	swap(a[mid],a[right]);
//
//	int key = right;//����key��Ϊ��׼ֵ���±�
//
//	while (left < right)
//	{
//		//��ָ�������ҵ�һ����key�����
//		while (left < right && a[left] <= a[key])
//		{
//			++left;
//		}
//		//��ָ���������ҵ�һ����key����
//		while (left < right && a[right] >= a[key])
//		{
//			--right;
//		}
//		//��������ָ����ָ��ֵ
//		if (a[left] != a[right])
//		{
//			std::swap(a[left],a[right]);
//		}
//	}
//	//��keyֵ�ŵ���ȷλ����
//	swap(a[left],a[key]);
//
//	return left;
//}
//
//
////�ڿӷ�
//int PartSort2(int*a,int left,int right)
//{
//	int mid = GetMidIndex(a,left,right);
//	swap(a[mid],a[right]);
//
//	int key = a[right];//���������Ҳ����ݻ�׼ֵ
//	int blank = right;//�״ν������õ�key��
//
//	while (left < right)
//	{
//		//��ָ�������ұ�key�������
//		while (left < right && a[left] <= key)
//		{
//			++left;
//		}
//		a[blank] = a[left];//���ҵ����������
//		blank = left;//���¿�����λ��
//
//		//��ָ�������ұ�keyС������
//		while (left < right && a[right] >= key)
//		{
//			--right;
//		}
//		a[blank] = a[right];//���ҵ����������
//		blank = right;//���¿�
//	}
//	a[blank] = key;//�����keyֵ���
//	return blank;
//}
//
////3,ǰ��ָ�뷨
//int PartSort3(int* a,int left,int right)
//{
//	int mid = GetMidIndex(a,left,right);
//	swap(a[mid],a[right]);
//
//	int key = right;//key�����׼ֵ���±�
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
////�����Ż�2��С�����Ż�
//void InsertSort(int* a,size_t n)//����
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
//		//�����Ż�2��С�����Ż�
//		if (right - left < 2)//���ݽ���ֱ���ò����������
//		                     ��13���ܸ����ʣ�д2Ϊ�˷�����ԣ�
//		{
//			InsertSort((a + left),(right - left +1));
//		}
//		else//����������ѡ�ÿ���
//		{
//			QuickSort(a,left,kiv-1);
//			QuickSort(a,kiv+1,right);
//		}
//	}
//}
//
//#include <stack>
////�����Ż�3���ǵݹ�ʵ��
//void QuickSortNoneR(int* a,int left,int right)
//{
//	assert(a);
//	stack<int> s;//����һ��ջ
//	s.push(right);
//	s.push(left);
//
//	while(!s.empty())
//	{
//		int start = s.top();//��ȡ��߽�
//		s.pop();
//		int end = s.top();//��ȡ�ұ߽�
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