#pragma once
/*实现一个栈，要求实现Push（出栈）、Pop（入栈）、\
\Min（返回最小值的操作）的时间复杂度为O(1)*/
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class  StackMin
{
public:
	void Push(T data)//入栈
	{
		s.push(data);//在栈s中入栈
		
		//如果min为空或者min中的最小值>=data，就将data同时入栈到min
		if (min.empty() || data <= min.top())
		{
			min.push(data);
		}
	}
	void Pop()//出栈
	{
		if (s.empty())//如果保存数据的栈s为空，说明栈中没数据,直接返回
		    return;

		//如果要删除的数据为最小数据，必须将min中的最小数据也删除，否则只需删除s栈的数据
		if (s.top() == min.top())
			min.pop();
		s.pop();//s.top()>min.top
	}
	T Min()//获取栈中的最小值（时间复杂度：O(1)）
	{
		return min.top();//min的栈顶元素即为最小值
	}
protected:
	stack<T> s;  //用来正常的出栈入栈
	stack<T> min;//用来保存最小的数据
};

void TestStackMin()
{
	StackMin<int> sm;
	sm.Push(4);
	sm.Push(3);
	sm.Push(5);
	sm.Push(1);
	sm.Push(1);
	sm.Push(2);

	sm.Pop();
	sm.Pop();
}