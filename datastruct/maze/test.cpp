//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <assert.h>
//#include <stack>
//using namespace std;
//
//const int N = 10;//定义全局变量迷宫的大小（假设迷宫整体为正方形，行列相等）
//
//struct Pos
//{
//	int Row;
//	int Col;
//};
////void GetMaze(int (*maze)[N])//读取迷宫
////void GetMaze(int **maze)//读取迷宫(需要动态开辟空间)
////void GetMaze(int maze[][N])//读取迷宫
//void GetMaze(int *maze)//读取迷宫
//{
//	FILE* pf = fopen("MazeMap.txt","r");
//	assert(pf);
//	char value = 0;
//	for(size_t i = 0; i<N; i++)
//	{
//		for (size_t j = 0; j<N;)
//		{
//			value = fgetc(pf);
//			if(value == '0' || value == '1')
//			{
//				maze[i*N+j] = value - '0';
//				j++;
//			}
//			else if(value == EOF)
//			{
//				cout<<"maze error!"<<endl;
//				return;
//			}
//		}
//	}
//	fclose(pf);
//}
//void PrintMaze(int *maze)//打印迷宫
//{
//	for(size_t i = 0; i<N; i++)
//	{
//		for (size_t j = 0; j<N; j++)
//		{
//			cout<<maze[i*N+j]<<' ';
//		}
//		cout<<endl;
//	}
//}
//bool CheckIsAccess(int* maze,Pos path)//检查坐标是否合法
//{
//	if(    (path.Row >= 0) && (path.Row < N) 
//		&& (path.Col >= 0) && (path.Col < N)
//		&& (maze[path.Row*N + path.Col]) == 0)
//		return true;
//	else
//		return false;
//}
//void GetMazePath(int* maze,Pos entry,stack<Pos>& s)//找通路
//{
//	assert(maze);
//	Pos cur = entry;
//	maze[cur.Row*N+cur.Col] = 2;//将可通过的坐标标记为2
//	s.push(entry);
//	Pos next = cur;
//	
//	//探测上下左右四个方向是否可通
//	while(!s.empty())
//	{
//		if(s.top().Row == N-1)
//		{
//			cout<<"找到通路"<<endl;
//			return;
//		}
//		//上
//		next = s.top();
//		next.Row -= 1;
//		if(CheckIsAccess(maze,next))
//		{
//			s.push(next);
//			maze[next.Row*N+next.Col] = 2;
//			continue;
//		}
//		//右
//		next = s.top();
//		next.Col += 1;
//		if(CheckIsAccess(maze,next))
//		{
//			s.push(next);
//			maze[next.Row*N+next.Col] = 2;
//			continue;
//		}
//		//下
//		next = s.top();
//		next.Row += 1;
//		if(CheckIsAccess(maze,next))
//		{
//			s.push(next);
//			maze[next.Row*N+next.Col] = 2;
//			continue;
//		}
//		//左
//		next = s.top();
//		next.Col -= 1;
//		if(CheckIsAccess(maze,next))
//		{
//			s.push(next);
//			maze[next.Row*N+next.Col] = 2;
//			continue;
//		}
//		
//
//		//回溯
//		next = s.top();
//		s.pop();
//		maze[next.Row*N+next.Col] = 3;
//	}
//	cout<<"此迷宫无通路"<<endl;
//}
//
//int main()
//{
//	int maze[N][N];
//	Pos entry = {2,0};
//	stack<Pos> s;
//	GetMaze((int*)maze);
//	GetMazePath((int*)maze,entry,s);
//	PrintMaze((int*)maze);
//	system("pause");
//	return 0;
//}
//
//
//
////递归实现
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <assert.h>
//#include <stack>
//using namespace std;
//
//const int N = 10;//定义全局变量迷宫的大小（假设迷宫整体为正方形，行列相等）
//
//struct Pos
//{
//	int Row;
//	int Col;
//};
//
////void GetMaze(int (*maze)[N])//读取迷宫
////void GetMaze(int **maze)//读取迷宫(需要动态开辟空间)
////void GetMaze(int maze[][N])//读取迷宫
//void GetMaze(int *maze)//读取迷宫
//{
//	FILE* pf = fopen("MazeMap.txt","r");
//	assert(pf);
//	char value = 0;
//	for(size_t i = 0; i<N; i++)
//	{
//		for (size_t j = 0; j<N;)
//		{
//			value = fgetc(pf);
//			if(value == '0' || value == '1')
//			{
//				maze[i*N+j] = value - '0';
//				j++;
//			}
//			else if(value == EOF)
//			{
//				cout<<"maze error!"<<endl;
//				return;
//			}
//		}
//	}
//	fclose(pf);
//}
//void PrintMaze(int *maze)//打印迷宫
//{
//	for(size_t i = 0; i<N; i++)
//	{
//		for (size_t j = 0; j<N; j++)
//		{
//			cout<<maze[i*N+j]<<' ';
//		}
//		cout<<endl;
//	}
//}
//bool CheckIsAccess(int* maze,Pos path)//检查坐标是否合法
//{
//	if(    (path.Row >= 0) && (path.Row < N) 
//		&& (path.Col >= 0) && (path.Col < N)
//		&& (maze[path.Row*N + path.Col]) == 0)
//		return true;
//	else
//		return false;
//}
//void GetMazePath(int* maze,Pos entry,stack<Pos>& s)//找通路
//{
//	assert(maze);
//	Pos next = entry;
//	maze[next.Row*N+next.Col] = 2;//将可通过的坐标标记为2
//	s.push(entry);
//
//
//	//探测上下左右四个方向是否可通
//	if(entry.Row == N-1)
//	{
//		cout<<"找到通路"<<endl;
//		return;
//	}
//	//上
//	next = entry;
//	next.Row -= 1;
//	if(CheckIsAccess(maze,next))
//	{
//		GetMazePath(maze,next,s);
//	}
//	//右
//	next = entry;
//	next.Col += 1;
//	if(CheckIsAccess(maze,next))
//	{
//		GetMazePath(maze,next,s);
//	}
//	//下
//	next = entry;
//	next.Row += 1;
//	if(CheckIsAccess(maze,next))
//	{
//		GetMazePath(maze,next,s);
//	}
//	//左
//	next = entry;
//	next.Col -= 1;
//	if(CheckIsAccess(maze,next))
//	{
//		GetMazePath(maze,next,s);
//	}
//}
//int main()
//{
//	int maze[N][N];
//	Pos entry = {2,0};
//	stack<Pos> s;
//	GetMaze((int*)maze);
//	GetMazePath((int*)maze,entry,s);
//	PrintMaze((int*)maze);
//	system("pause");
//	return 0;
//}
//
//
//


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <assert.h>
#include <stack>
#include<iomanip>

const int N = 10;//定义全局变量迷宫的大小（假设迷宫整体为正方形，行列相等）

struct Pos
{
	int Row;
	int Col;
};

//void GetMaze(int (*maze)[N])//读取迷宫
//void GetMaze(int **maze)//读取迷宫(需要动态开辟空间)
//void GetMaze(int maze[][N])//读取迷宫
void GetMaze(int *maze)//读取迷宫
{
	FILE* pf = fopen("MazeMap.txt","r");
	assert(pf);
	char value = 0;
	for(size_t i = 0; i<N; i++)
	{
		for (size_t j = 0; j<N;)
		{
			value = fgetc(pf);
			if(value == '0' || value == '1')
			{
				maze[i*N+j] = value - '0';
				j++;
			}
			else if(value == EOF)
			{
				cout<<"maze error!"<<endl;
				return;
			}
		}
	}
	fclose(pf);
}
void PrintMaze(int *maze)//打印迷宫
{
	cout<<setw(3);
	for(size_t i = 0; i<N; i++)
	{
		for (size_t j = 0; j<N; j++)
		{
			cout<<maze[i*N+j]<<setw(3);
		}
		cout<<endl;
	}
}
bool CheckIsAccess(int* maze,Pos cur,Pos next)//检查坐标是否合法
{
	//下一个坐标非法
	if(    (next.Row < 0) || (next.Row >= N) 
		|| (next.Col < 0) || (next.Col >= N))
	{
		return false;
	}
	//下一个坐标合法
	if(maze[next.Row*N + next.Col] == 0)
	{
		return true;
	}
	//下一个坐标是以前走过的坐标
	if(maze[next.Row*N + next.Col] > maze[cur.Row*N + cur.Col]+1)
	{
		return true;
	}
	return false;
}
void GetMazeMinPath(int* maze,Pos entry,stack<Pos>& path,stack<Pos>& min)//找通路
{
	assert(maze);
	path.push(entry);
	Pos cur = entry;
	Pos next = cur;

	//找到通路

	if(cur.Col == N-1)
	{
		if(min.empty() || path.size()<min.size())
		{
			min = path;
			//cout<<"找到通路"<<endl;
		}
		path.pop();
		return;
	}
	//探测上下左右四个方向是否可通
	//上
	next = cur;
	next.Row -= 1;
	if(CheckIsAccess(maze,cur,next))
	{
		maze[next.Row*N+next.Col] = maze[cur.Row*N+cur.Col] + 1;
		GetMazeMinPath(maze,next,path,min);
	}
	//右
	next = cur;
	next.Col += 1;
	if(CheckIsAccess(maze,cur,next))
	{
		maze[next.Row*N+next.Col] = maze[cur.Row*N+cur.Col] + 1;
		GetMazeMinPath(maze,next,path,min);
	}
	//下
	next = cur;
	next.Row += 1;
	if(CheckIsAccess(maze,cur,next))
	{
		maze[next.Row*N+next.Col] = maze[cur.Row*N+cur.Col] + 1;
		GetMazeMinPath(maze,next,path,min);
	}
	//左
	next = cur;
	next.Col -= 1;
	if(CheckIsAccess(maze,cur,next))
	{
		maze[next.Row*N+next.Col] = maze[cur.Row*N+cur.Col] + 1;
		GetMazeMinPath(maze,next,path,min);
	}
	path.pop();
}
int main()
{
	int maze[N][N];
	Pos entry = {2,0};
	stack<Pos> path;
	stack<Pos> minpath;
	GetMaze((int*)maze);
	maze[2][0] = 2; //将迷宫入口赋值为2
	PrintMaze((int*)maze);
	cout<<endl<<endl;
	GetMazeMinPath((int*)maze,entry,path,minpath);
	PrintMaze((int*)maze);
	system("pause");
	return 0;
}


  

    
   


