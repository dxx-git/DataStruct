#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <queue>
#include "UnionFindSet.h"
using namespace std;

template <class V,class W>
class GraphMatrix
{
public:
	GraphMatrix(V* vertexs,size_t n,const W& invalid = W(),bool isDirected = false)//Ĭ��������ͼ
		:_vertexs(vertexs,vertexs+n)
		,_isDirected(isDirected)
	{
		_matrix = new W*[n];//Ϊ�ڽӾ��󿪱ٿռ�
		for (size_t i = 0; i < n; ++i)
		{
			_matrix[i] = new W[n];

			for (size_t j = 0; j < n; ++j)
			{
				_matrix[i][j] = invalid;
			}
		}
	}

	~GraphMatrix()
	{
		if (NULL != _matrix)
		{
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				delete []_matrix[i];
			}
		}
		_matrix = NULL;
	}
	int GetVertexIndex(const V& v)//��ȡ������±�
	{
		for (size_t i = 0; i < _vertexs.size(); ++i)
		{
			if (_vertexs[i] == v)
			{
				return i;
			}
		}
		assert(false);
		return -1; 
	}
	void AddEdge(const V& v1,const V& v2,const W& w)
	{
		int src = GetVertexIndex(v1);
		int dest = GetVertexIndex(v2);

		_matrix[src][dest] = w;
		if (_isDirected == false)
		{
			_matrix[dest][src] = w;
		}
	}
protected:
	vector<V> _vertexs;//���㼯��
	W** _matrix;     //�ڽӾ��󣨱ߵļ��ϣ�

	bool _isDirected; //����ͼ��������ͼ
};

void TestGraphMatrix()
{
	string city[] = {"����", "����", "�Ӱ�", "μ��", "����"};
	GraphMatrix<string,double> g1(city, sizeof(city)/sizeof(city[0]));//����ͼ
	//GraphMatrix<string,double> g1(city, sizeof(city)/sizeof(city[0]),0,true);//����ͼ

	g1.AddEdge("����", "����", 100.5);
	g1.AddEdge("����", "μ��", 19.5);
	g1.AddEdge("����", "�Ӱ�", 50.5);
	g1.AddEdge("����", "����", 5.5);
}


template<class W>
struct LinkEdge//��
{
	W _weight;//Ȩ��
	LinkEdge<W>* _next;
	
	size_t _src;//ԭ�±�
	size_t _dest;//Ŀ���±�

	LinkEdge(size_t src = 0,size_t dest = 0,const W& w = W())
		:_weight(w)
		,_next(NULL)
		,_src(src)
		,_dest(dest)
	{}
};

template<class V,class W>
class GraphNearLink
{
	typedef LinkEdge<W> Edge;
public:
	GraphNearLink()
	{}
	GraphNearLink(V* vertexs,size_t n,const W& w = W(),bool isDirected = false)
	{
		_Vertexs.resize(n);
		_Vertexs.assign(vertexs,vertexs+n);

		_nearlink.resize(n,NULL);
	}

	int GetVertexIndex(const V& v)
	{
		for (size_t i = 0; i < _Vertexs.size(); ++i)
		{
			if (_Vertexs[i] == v)
			{
				return i;
			}
		}
		assert(false);
		return -1;
	}
	void _AddEdge(size_t src,size_t dest,const W& w)
	{
		//ͷ�巨
		Edge* edge = new Edge(src,dest,w);

		edge->_next = _nearlink[src];
		_nearlink[src] = edge;
	}
	void AddEdge(const V& v1,const V& v2,const W& w)
	{
		size_t src = GetVertexIndex(v1);
		size_t dest = GetVertexIndex(v2);

		_AddEdge(src,dest,w);
		if (_isDirected == false)//����ͼ
		{
			_AddEdge(dest,src,w);
		}
	}
	void DFS(const V& src) // ͼ��������ȱ������ݹ� 
	{
		int startIndex = GetVertexIndex(src);

		//�ظ����й��캯������ʼ��������Ϊ�ظ�n�θ�����ֵ
		vector<bool> visited(_Vertexs.size(),false);

		cout<<_Vertexs[startIndex]<<":"<<startIndex<<"->";

		visited[startIndex] = true;
		_DFS(startIndex,visited);

		cout<<"NULL"<<endl;
	}

	void BFS(const V& src) //ͼ�Ĺ�����ȱ���������
	{
		queue<int> q;
		int index = GetVertexIndex(src);
		q.push(index);

		vector<bool> visited(_Vertexs.size(),false);

		while(!q.empty())
		{
			int front = q.front();

			if (visited[front] == false)
			{
				cout<<_Vertexs[front]<<":"<<front<<"->";
				visited[front] = true;

				Edge* cur = _nearlink[front];
				while(cur)
				{
					int dest = cur->_dest;
					if (visited[dest] == false)
					{
						q.push(dest);
					}
					cur = cur->_next;
				}
			}
			q.pop();
		}
		cout<<"NULL"<<endl;
	}
	bool Kruskal(GraphNearLink<V,W>& minTree)//��С������
	{
		minTree._isDirected = _isDirected;
		minTree._Vertexs = _Vertexs;
		minTree._nearlink.resize(_Vertexs.size(),NULL);

		struct Com
		{
			bool operator()(Edge* l,Edge* r)
			{
				return l->_weight < r->_weight;
			}
		};

		priority_queue<Edge*, vector<Edge*>, Com> pq;
		for (size_t i = 0; i < _Vertexs.size(); ++i)
		{
			Edge* cur = _nearlink[i];
			while(cur)
			{
				if (cur->_src < cur->_dest)
				{
					pq.push(cur);
				}
				cur = cur->_next;
			}
		}

		//������С������
		size_t count = 0;
		UnionFindSet ufs(_Vertexs.size());
		while (!pq.empty())
		{
			Edge* edge = pq.top();
			pq.pop();
			int src = edge->_src;
			int dst = edge->_dest;
			if (false == ufs.IsInSet(src, dst))
			{
				minTree._AddEdge(src, dst, edge->_weight);
				minTree._AddEdge(dst, src, edge->_weight);
				ufs.Union(src, dst);
				++count;

				if (count == _Vertexs.size()-1)
				{
					return true;
				}
			}
		}

		return false;
	}
protected:
	void _DFS(int src,vector<bool>& visited) // ͼ��������ȱ������ݹ� 
	{
		Edge* cur = _nearlink[src];
		while(cur)
		{
			int dest = cur->_dest;
			if (visited[dest] == false)
			{
				cout<<_Vertexs[dest]<<":"<<dest<<"->";
				visited[dest] = true;

				_DFS(dest,visited);
			}
			cur = cur->_next;
		}
	}
	
protected:
	vector<Edge*> _nearlink;//�ڽӱ�
	vector<V> _Vertexs;    //���㼯��

	bool _isDirected;     //����ͼ������ͼ
};

void TestGraphNearLink()
{
	string city[] = {"����", "����", "�Ӱ�", "μ��", "����"};
	GraphNearLink<string,double> g1(city, sizeof(city)/sizeof(city[0]));//����ͼ
	//GraphNearLink<string,double> g1(city, sizeof(city)/sizeof(city[0]),0,true);//����ͼ

	g1.AddEdge("����", "����", 100.5);
	g1.AddEdge("����", "μ��", 19.5);
	g1.AddEdge("����", "�Ӱ�", 50.5);
	g1.AddEdge("����", "����", 5.5);

	g1.DFS("����");
	g1.BFS("����");

	GraphNearLink<string, double> minTree;
	cout<<"minTree?"<<g1.Kruskal(minTree)<<endl;
}
int main()
{
	//TestGraphMatrix();
	TestGraphNearLink();
	system("pause");
	return 0;
}


