//#include <iostream>
//using namespace std;
//
//template <typename T>
//class SymmetricMatrix
//{
//public:
//	SymmetricMatrix(T* arr,size_t n)
//		:_data(new T[n*(n+1)/2])//��֪�ռ��СΪn*(n+1)/2
//		,_n(n)
//	{
//		size_t index = 0;
//	    for (size_t i = 0; i < n; i++)
//	    {
//			for (size_t j = 0; j < n; j++)
//			{
//				if (i >= j)//������
//				{
//					_data[index] = arr[i*n+j];
//					index++;
//				}
//				else//������
//				{
//					break;
//				}
//			}
//	    }
//	}
//	T& Access(size_t i,size_t j)//��ȡ�����ǵ�����
//	{
//		if (i >= j)//������Ԫ��
//		{
//			//�ɶԳƾ���ɵ�i>=j, A[i][j] ==_data[i*(i+1)/2+j]
//			return _data[i*(i+1)/2+j];
//		}
//		else//������Ԫ��
//		{
//			swap(i,j);//���н���
//			return _data[i*(i+1)/2+j];
//		}
//	}
//	void PrintSymmetricMatrix()
//	{
//		cout<<"SymmetricMatrix:"<<_n<<"��"<<_n<<"��"<<endl;
//		for (size_t i = 0; i < _n; i++)
//		{
//			for (size_t j = 0; j < _n; j++)
//			{
//				cout<<Access(i,j)<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//	~SymmetricMatrix()
//	{
//		if (NULL != _data)
//		{
//			delete []_data;
//			_data = NULL;
//		}
//	}
//protected:
//	T* _data;
//	size_t _n;
//};
//	
//void TestSymmetricMatrix()
//{
//	int a [5][5]=
//	{
//		{0,1,2,3,4},
//		{1,0,1,2,3},
//		{2,1,0,1,2},
//		{3,2,1,0,1},
//		{4,3,2,1,0},
//	};
//	SymmetricMatrix<int> sy((int*)a,5);
//	sy.PrintSymmetricMatrix();
//}
//int main()
//{
//	TestSymmetricMatrix();
//	system("pause");
//	return 0;
//}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//template <typename T>
//struct Triple//��Ԫ��
//{
//	Triple(size_t row,size_t col,T& value)
//		:_row(row)
//		,_col(col)
//		,_value(value)
//	{}
//	Triple()
//	{}
//	size_t _row;
//	size_t _col;
//	T _value;
//};
//
//template <typename T>
//class SparseMatrix//ϡ�����
//{
//public:
//	SparseMatrix(T* arr,size_t m,size_t n,const T& invalid)
//		:_a(NULL)
//		,_m(m)
//		,_n(n)
//		,_invalid(invalid)
//	{
//		size_t index = 0;
//		for (size_t i = 0; i < m; i++)
//		{
//			for (size_t j = 0; j < n; j++)
//			{
//				if (arr[i*n+j] != invalid)//˵������Ч����
//				{
//					_a.push_back(Triple<T>(i,j,arr[i*n+j]));
//				}
//			}
//		}
//	}
//	void PrintSparseMatrix()
//	{
//		size_t index = 0;
//		cout<<"SparseMatrix:"<<_m<<"��"<<_n<<"��"<<endl;
//		for (size_t i = 0; i < _m; i++)
//		{
//			for(size_t j = 0; j < _n; j++)
//			{
//				//��Чֵ
//				if (index < _a.size() 
//					&& _a[index]._row == i 
//					&& _a[index]._col == j)
//				{
//					cout<<_a[index]._value<<" ";
//					index++;
//				}
//				else//��Чֵ
//				{
//					cout<<_invalid<<" ";
//				}
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//
//protected:
//	vector<Triple<T>> _a;
//	size_t _m;//��
//	size_t _n;//��
//	T _invalid;//��Чֵ
//};
//
//void TestSparseMatrix()
//{
//	int array [6][5] = 
//	{{1, 0, 3, 0, 5},
//	{0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0},
//	{1, 0, 3, 0, 5},
//	{0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0}};
//	SparseMatrix<int> sp((int*)array,6,5,0);
//	sp.PrintSparseMatrix();
//}
//int main()
//{
//	TestSparseMatrix();
//	system("pause");
//	return 0;
//}
//



#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Triple//��Ԫ��
{
	Triple(size_t row = 0,size_t col = 0,T value = T())
		:_row(row)
		,_col(col)
		,_value(value)
	{}

	size_t _row;
	size_t _col;
	T _value;
};

template <typename T>
class SparseMatrix//ϡ�����
{
public:
	SparseMatrix()
		:_a(NULL)
		,_m(0)
		,_n(0)
		,_invalid(T())
	{}
	SparseMatrix(T* arr,size_t m,size_t n,const T& invalid)
		:_a(NULL)
		,_m(m)
		,_n(n)
		,_invalid(invalid)
	{
		size_t index = 0;
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (arr[i*n+j] != invalid)//˵������Ч����
				{
					_a.push_back(Triple<T>(i,j,arr[i*n+j]));
				}
			}
		}
	}
	void PrintSparseMatrix()
	{
		size_t index = 0;
		cout<<"SparseMatrix:"<<_m<<"��"<<_n<<"��"<<endl;
		for (size_t i = 0; i < _m; i++)
		{
			for(size_t j = 0; j < _n; j++)
			{
				//��Чֵ
				if (index < _a.size() 
					&& _a[index]._row == i 
					&& _a[index]._col == j)
				{
					cout<<_a[index]._value<<" ";
					index++;
				}
				else//��Чֵ
				{
					cout<<_invalid<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	SparseMatrix<T> Transport()   //�����ת��--��ͨ�㷨
	{
		SparseMatrix<T> tsm;
		tsm._m = _n;
		tsm._n = _m;
		tsm._a.reserve(_a.size());//������ЧԪ�ظ��ռ�
		for (size_t i = 0;i < _n; ++i)
		{
			//i�����¾������Ҳ���Ǿɾ������
			size_t index=0;
			while (index < _a.size())
			{
				//index����ԭ����Ԫ���Ԫ�ظ���
				if (_a[index]._col == i)
				{
					//����ԭ������Ԫ��������������Ӧ�±��Ԫ��������µ���Ԫ��.
					Triple<T> tmp(_a[index]._col,_a[index]._row,_a[index]._value);
					tsm._a.push_back(tmp);
				}
				++index;
			}
		}
		return tsm;
	}

	SparseMatrix<T> FastTransport()     //�����ת��--�����㷨
	{
		SparseMatrix<T> ftsm;
		ftsm._m = _n;    //�¾�����о��Ǿɾ������
		ftsm._n = _m;
		ftsm._a.resize(_a.size());

		//countͳ���¾���ÿһ����Чֵ�ĸ���
		int *count = new int[_n];
		memset(count,0,sizeof(int)*_n);    //��count�ռ��ֵ��ֵΪ0
		
		for (size_t i = 0; i < _a.size(); ++i)//��¼ÿ����ЧԪ�صĸ���
		{
			int col = _a[i]._col;
			++count[col];
		}
		
		int *start = new int[_n];	//start��¼�¾����ÿ�е�һ��Ԫ������Ԫ��Ĵ洢�±�
		memset(start,0,sizeof(int)*_n);//��start�ռ��ֵ��ֵΪ0
		
		size_t i = 0;
		start[i] = 0;//��0�е��±�Ϊ0
		for (i = 1; i < _n; ++i)
		{
			//ÿ�еĳ�ʼ����Ϊ��һ�г�ʼ����+��һ����ЧԪ�صĸ���
			start[i] = start[i-1] + count[i-1];
		}
		
		//����ԭ������Ԫ�飬�ҵ����ݾ�ֱ�ӷ�������Ԫ��Ķ�Ӧ���±괦
		for (size_t i = 0; i < _a.size(); ++i)
		{
			int col = _a[i]._col;
			size_t tmp = start[col];
			
			ftsm._a[tmp]._row = _a[i]._col;
			ftsm._a[tmp]._col = _a[i]._row;
			ftsm._a[tmp]._value = _a[i]._value;
			
			++start[col];			//��ֹͬһ�е���Ч���ݷ�����ͬλ��
		}
		
		delete[]start;
		delete[]count;
		
		return ftsm;
	}


protected:
	vector<Triple<T>> _a;
	size_t _m;//��
	size_t _n;//��
	T _invalid;//��Чֵ
};

void TestSparseMatrix()
{
	int array [6][5] = 
	{{1, 0, 3, 0, 5},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{2, 0, 4, 0, 6},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0}};
	
	SparseMatrix<int> sp((int*)array,6,5,0);
	sp.PrintSparseMatrix();
	
	SparseMatrix<int> sp1;
	sp1 = sp.Transport();
	sp1.PrintSparseMatrix();

	SparseMatrix<int> sp2;
	sp2 = sp.FastTransport();
	sp2.PrintSparseMatrix();
}
int main()
{
	TestSparseMatrix();
	system("pause");
	return 0;
}

