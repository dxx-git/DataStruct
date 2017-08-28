//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <assert.h>
//#include <stack>
//using namespace std;
//
//const int N = 10;//����ȫ�ֱ����Թ��Ĵ�С�������Թ�����Ϊ�����Σ�������ȣ�
//
//struct Pos
//{
//	int Row;
//	int Col;
//};
////void GetMaze(int (*maze)[N])//��ȡ�Թ�
////void GetMaze(int **maze)//��ȡ�Թ�(��Ҫ��̬���ٿռ�)
////void GetMaze(int maze[][N])//��ȡ�Թ�
//void GetMaze(int *maze)//��ȡ�Թ�
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
//void PrintMaze(int *maze)//��ӡ�Թ�
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
//bool CheckIsAccess(int* maze,Pos path)//��������Ƿ�Ϸ�
//{
//	if(    (path.Row >= 0) && (path.Row < N) 
//		&& (path.Col >= 0) && (path.Col < N)
//		&& (maze[path.Row*N + path.Col]) == 0)
//		return true;
//	else
//		return false;
//}
//void GetMazePath(int* maze,Pos entry,stack<Pos>& s)//��ͨ·
//{
//	assert(maze);
//	Pos cur = entry;
//	maze[cur.Row*N+cur.Col] = 2;//����ͨ����������Ϊ2
//	s.push(entry);
//	Pos next = cur;
//	
//	//̽�����������ĸ������Ƿ��ͨ
//	while(!s.empty())
//	{
//		if(s.top().Row == N-1)
//		{
//			cout<<"�ҵ�ͨ·"<<endl;
//			return;
//		}
//		//��
//		next = s.top();
//		next.Row -= 1;
//		if(CheckIsAccess(maze,next))
//		{
//			s.push(next);
//			maze[next.Row*N+next.Col] = 2;
//			continue;
//		}
//		//��
//		next = s.top();
//		next.Col += 1;
//		if(CheckIsAccess(maze,next))
//		{
//			s.push(next);
//			maze[next.Row*N+next.Col] = 2;
//			continue;
//		}
//		//��
//		next = s.top();
//		next.Row += 1;
//		if(CheckIsAccess(maze,next))
//		{
//			s.push(next);
//			maze[next.Row*N+next.Col] = 2;
//			continue;
//		}
//		//��
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
//		//����
//		next = s.top();
//		s.pop();
//		maze[next.Row*N+next.Col] = 3;
//	}
//	cout<<"���Թ���ͨ·"<<endl;
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
////�ݹ�ʵ��
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <assert.h>
//#include <stack>
//using namespace std;
//
//const int N = 10;//����ȫ�ֱ����Թ��Ĵ�С�������Թ�����Ϊ�����Σ�������ȣ�
//
//struct Pos
//{
//	int Row;
//	int Col;
//};
//
////void GetMaze(int (*maze)[N])//��ȡ�Թ�
////void GetMaze(int **maze)//��ȡ�Թ�(��Ҫ��̬���ٿռ�)
////void GetMaze(int maze[][N])//��ȡ�Թ�
//void GetMaze(int *maze)//��ȡ�Թ�
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
//void PrintMaze(int *maze)//��ӡ�Թ�
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
//bool CheckIsAccess(int* maze,Pos path)//��������Ƿ�Ϸ�
//{
//	if(    (path.Row >= 0) && (path.Row < N) 
//		&& (path.Col >= 0) && (path.Col < N)
//		&& (maze[path.Row*N + path.Col]) == 0)
//		return true;
//	else
//		return false;
//}
//void GetMazePath(int* maze,Pos entry,stack<Pos>& s)//��ͨ·
//{
//	assert(maze);
//	Pos next = entry;
//	maze[next.Row*N+next.Col] = 2;//����ͨ����������Ϊ2
//	s.push(entry);
//
//
//	//̽�����������ĸ������Ƿ��ͨ
//	if(entry.Row == N-1)
//	{
//		cout<<"�ҵ�ͨ·"<<endl;
//		return;
//	}
//	//��
//	next = entry;
//	next.Row -= 1;
//	if(CheckIsAccess(maze,next))
//	{
//		GetMazePath(maze,next,s);
//	}
//	//��
//	next = entry;
//	next.Col += 1;
//	if(CheckIsAccess(maze,next))
//	{
//		GetMazePath(maze,next,s);
//	}
//	//��
//	next = entry;
//	next.Row += 1;
//	if(CheckIsAccess(maze,next))
//	{
//		GetMazePath(maze,next,s);
//	}
//	//��
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

const int N = 10;//����ȫ�ֱ����Թ��Ĵ�С�������Թ�����Ϊ�����Σ�������ȣ�

struct Pos
{
	int Row;
	int Col;
};

//void GetMaze(int (*maze)[N])//��ȡ�Թ�
//void GetMaze(int **maze)//��ȡ�Թ�(��Ҫ��̬���ٿռ�)
//void GetMaze(int maze[][N])//��ȡ�Թ�
void GetMaze(int *maze)//��ȡ�Թ�
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
void PrintMaze(int *maze)//��ӡ�Թ�
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
bool CheckIsAccess(int* maze,Pos cur,Pos next)//��������Ƿ�Ϸ�
{
	//��һ������Ƿ�
	if(    (next.Row < 0) || (next.Row >= N) 
		|| (next.Col < 0) || (next.Col >= N))
	{
		return false;
	}
	//��һ������Ϸ�
	if(maze[next.Row*N + next.Col] == 0)
	{
		return true;
	}
	//��һ����������ǰ�߹�������
	if(maze[next.Row*N + next.Col] > maze[cur.Row*N + cur.Col]+1)
	{
		return true;
	}
	return false;
}
void GetMazeMinPath(int* maze,Pos entry,stack<Pos>& path,stack<Pos>& min)//��ͨ·
{
	assert(maze);
	path.push(entry);
	Pos cur = entry;
	Pos next = cur;

	//�ҵ�ͨ·

	if(cur.Col == N-1)
	{
		if(min.empty() || path.size()<min.size())
		{
			min = path;
			//cout<<"�ҵ�ͨ·"<<endl;
		}
		path.pop();
		return;
	}
	//̽�����������ĸ������Ƿ��ͨ
	//��
	next = cur;
	next.Row -= 1;
	if(CheckIsAccess(maze,cur,next))
	{
		maze[next.Row*N+next.Col] = maze[cur.Row*N+cur.Col] + 1;
		GetMazeMinPath(maze,next,path,min);
	}
	//��
	next = cur;
	next.Col += 1;
	if(CheckIsAccess(maze,cur,next))
	{
		maze[next.Row*N+next.Col] = maze[cur.Row*N+cur.Col] + 1;
		GetMazeMinPath(maze,next,path,min);
	}
	//��
	next = cur;
	next.Row += 1;
	if(CheckIsAccess(maze,cur,next))
	{
		maze[next.Row*N+next.Col] = maze[cur.Row*N+cur.Col] + 1;
		GetMazeMinPath(maze,next,path,min);
	}
	//��
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
	maze[2][0] = 2; //���Թ���ڸ�ֵΪ2
	PrintMaze((int*)maze);
	cout<<endl<<endl;
	GetMazeMinPath((int*)maze,entry,path,minpath);
	PrintMaze((int*)maze);
	system("pause");
	return 0;
}


  

    
   


