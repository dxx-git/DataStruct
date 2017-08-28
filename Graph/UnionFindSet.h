#include <iostream>
#include <vector>
#include <set> 
using namespace std;

class UnionFindSet
{
public:
	UnionFindSet(size_t n)
	{
		_ufs.resize(n,-1);
	}
	int FindRoot(int x)
	{
		while (_ufs[x] >= 0)
		{
			x = _ufs[x];
		}
		return x;
	}
	void Union(int x1,int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2)
		{
			return;
		}
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
	}
	bool IsInSet(int x1,int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}
protected:
	vector<int> _ufs;
};

void TestUnionFindSet()
{
	UnionFindSet uf(10);
	uf.Union(0,6);
	uf.Union(6,7);
	uf.Union(0,8);
	uf.Union(1,4);
	uf.Union(1,9);
	uf.Union(2,3);
	uf.Union(3,5);
}

