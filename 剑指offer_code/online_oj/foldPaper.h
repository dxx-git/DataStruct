#pragma once
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


class FoldPaper {
public:
	vector<string> foldPaper(int n)  
	{
		vector<string> v;
		pair<int,int> s = calcount(n);
		int down = s.first;   //记录“down”的个数
		int up = s.second;     //记录"up"的个数

		int i = 0;
		for(; i < down; ++i)
		{
			v.push_back("down");
		}
		for(int j = i; j < i+up; ++j)
		{
			v.push_back("up");
		}
		return v;
	}
	pair<int,int> calcount(int n)//计算“down”和“up”的个数
	{
		int down = 0;
		int up = 0;
		if (n == 1)
		{
			return make_pair(1,0);
		}
		up = calcount(n-1).second+calcount(n-1).first;
		down = up + 1;
		return make_pair(down,up);
	}

};


void Test()
{
	int n = 4;
	vector<string> vs;
	FoldPaper fp;
	vs = fp.foldPaper(n);
	/*for (int i = 0; i < vs.size(); ++i)
	{
		printf("%s ",vs[i]);
	}*/
	cout<<endl;
}