//#include <iostream>
//using namespace std;
//
//template <typename T>
//class SymmetricMatrix
//{
//public:
//	SymmetricMatrix(T* arr,size_t n)
//		:_data(new T[n*(n+1)/2])//已知空间大小为n*(n+1)/2
//		,_n(n)
//	{
//		size_t index = 0;
//	    for (size_t i = 0; i < n; i++)
//	    {
//			for (size_t j = 0; j < n; j++)
//			{
//				if (i >= j)//下三角
//				{
//					_data[index] = arr[i*n+j];
//					index++;
//				}
//				else//上三角
//				{
//					break;
//				}
//			}
//	    }
//	}
//	T& Access(size_t i,size_t j)//获取上三角的数据
//	{
//		if (i >= j)//下三角元素
//		{
//			//由对称矩阵可得i>=j, A[i][j] ==_data[i*(i+1)/2+j]
//			return _data[i*(i+1)/2+j];
//		}
//		else//上三角元素
//		{
//			swap(i,j);//行列交换
//			return _data[i*(i+1)/2+j];
//		}
//	}
//	void PrintSymmetricMatrix()
//	{
//		cout<<"SymmetricMatrix:"<<_n<<"行"<<_n<<"列"<<endl;
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
//struct Triple//三元组
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
//class SparseMatrix//稀疏矩阵
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
//				if (arr[i*n+j] != invalid)//说明是有效数据
//				{
//					_a.push_back(Triple<T>(i,j,arr[i*n+j]));
//				}
//			}
//		}
//	}
//	void PrintSparseMatrix()
//	{
//		size_t index = 0;
//		cout<<"SparseMatrix:"<<_m<<"行"<<_n<<"列"<<endl;
//		for (size_t i = 0; i < _m; i++)
//		{
//			for(size_t j = 0; j < _n; j++)
//			{
//				//有效值
//				if (index < _a.size() 
//					&& _a[index]._row == i 
//					&& _a[index]._col == j)
//				{
//					cout<<_a[index]._value<<" ";
//					index++;
//				}
//				else//无效值
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
//	size_t _m;//行
//	size_t _n;//列
//	T _invalid;//无效值
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
struct Triple//三元组
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
class SparseMatrix//稀疏矩阵
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
				if (arr[i*n+j] != invalid)//说明是有效数据
				{
					_a.push_back(Triple<T>(i,j,arr[i*n+j]));
				}
			}
		}
	}
	void PrintSparseMatrix()
	{
		size_t index = 0;
		cout<<"SparseMatrix:"<<_m<<"行"<<_n<<"列"<<endl;
		for (size_t i = 0; i < _m; i++)
		{
			for(size_t j = 0; j < _n; j++)
			{
				//有效值
				if (index < _a.size() 
					&& _a[index]._row == i 
					&& _a[index]._col == j)
				{
					cout<<_a[index]._value<<" ";
					index++;
				}
				else//无效值
				{
					cout<<_invalid<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	SparseMatrix<T> Transport()   //矩阵的转置--普通算法
	{
		SparseMatrix<T> tsm;
		tsm._m = _n;
		tsm._n = _m;
		tsm._a.reserve(_a.size());//开辟有效元素个空间
		for (size_t i = 0;i < _n; ++i)
		{
			//i控制新矩阵的行也就是旧矩阵的列
			size_t index=0;
			while (index < _a.size())
			{
				//index控制原来三元组的元素个数
				if (_a[index]._col == i)
				{
					//遍历原来的三元组如果存在满足对应下标的元素则进入新的三元组.
					Triple<T> tmp(_a[index]._col,_a[index]._row,_a[index]._value);
					tsm._a.push_back(tmp);
				}
				++index;
			}
		}
		return tsm;
	}

	SparseMatrix<T> FastTransport()     //矩阵的转置--快速算法
	{
		SparseMatrix<T> ftsm;
		ftsm._m = _n;    //新矩阵的行就是旧矩阵的列
		ftsm._n = _m;
		ftsm._a.resize(_a.size());

		//count统计新矩阵每一行有效值的个数
		int *count = new int[_n];
		memset(count,0,sizeof(int)*_n);    //将count空间初值赋值为0
		
		for (size_t i = 0; i < _a.size(); ++i)//记录每列有效元素的个数
		{
			int col = _a[i]._col;
			++count[col];
		}
		
		int *start = new int[_n];	//start记录新矩阵的每行第一个元素在三元组的存储下标
		memset(start,0,sizeof(int)*_n);//将start空间初值赋值为0
		
		size_t i = 0;
		start[i] = 0;//第0列的下标为0
		for (i = 1; i < _n; ++i)
		{
			//每列的初始坐标为上一列初始坐标+上一列有效元素的个数
			start[i] = start[i-1] + count[i-1];
		}
		
		//遍历原来的三元组，找到数据就直接放入新三元组的对应的下标处
		for (size_t i = 0; i < _a.size(); ++i)
		{
			int col = _a[i]._col;
			size_t tmp = start[col];
			
			ftsm._a[tmp]._row = _a[i]._col;
			ftsm._a[tmp]._col = _a[i]._row;
			ftsm._a[tmp]._value = _a[i]._value;
			
			++start[col];			//防止同一行的有效数据放入相同位置
		}
		
		delete[]start;
		delete[]count;
		
		return ftsm;
	}


protected:
	vector<Triple<T>> _a;
	size_t _m;//行
	size_t _n;//列
	T _invalid;//无效值
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

