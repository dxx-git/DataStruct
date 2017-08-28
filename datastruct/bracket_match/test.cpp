//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char s[5][10];
//	int i = 0;
//
//	int count1 = 0;//记录[]个数
//	int count2 = 0;//记录()个数
//	int tmp[5] = {0};
//
//	for (i = 0; i < 5; ++i)
//	{
//		gets(s[i]);
//	}
//
//	for (i = 0; i < 5; ++i)
//	{
//		int len = strlen(s[i]);
//		if (len%2 == 1)
//		{
//			tmp[i] = 0;
//		}
//		if (*s[i] == ']' || *s[i] == ')')
//		{
//			tmp[i] = 0;
//		}
//		char* str = s[i];
//		while(*str)
//		{
//			if (*s[i] == '[')
//			{
//				count1++;
//			}
//			if (*s[i] == ']')
//			{
//				count1--;
//			}
//
//			if (*s[i] == '(')
//			{
//				count2++;
//			}
//			if (*s[i] == ')')
//			{
//				count2--;
//			}
//			++str;
//		}
//		if (count1==0 && count2==0)
//			tmp[i] = 1;
//		else
//			tmp[i] = 0;
//	}
//	for (i = 0; i < 5; ++i)
//	{
//		if (tmp[i] == 0)
//		{
//			puts("NO");
//		}
//		else
//		{
//			puts("YES");
//		}
//	}
//
//	system("pause");
//	return 0;
//}



#include<cstdio>
#include<cassert>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;

void Test002()
{
	int num = 0;
	cin>>num;
	fflush(stdin);			//清空缓冲区
	queue<bool> result;		//最终结果
	while(num>0)
	{
		int ch = getchar();		//获取一个字符
		stack<char> s;			//符号栈
		while(ch!='\n')
		{
			if(ch=='(' || ch=='[')
			{
				s.push(ch);
			}
			else if(ch==')')
			{
				if(!s.empty() && s.top()=='(')
				{
					s.pop();
				}
				else
				{
					result.push(false);
					break;
				}
			}
			else if(ch == ']')
			{
				if(!s.empty() && s.top() == '[')
				{
					s.pop();
				}
				else
				{
					result.push(false);
					break;
				}
			}
			else
			{
				//不是()[]字符
				assert(false);
			}
			ch = getchar();
		}
		if(s.empty())
		{
			result.push(true);
		}
		--num;
		fflush(stdin);		//清空缓冲区
	}
	//输出最终结果
	while(!result.empty())
	{
		if(result.front())
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		result.pop();
	}
}
int main()
{
	Test002();
	system("pause");
	return 0;
}
