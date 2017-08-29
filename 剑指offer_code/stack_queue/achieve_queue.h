/*用两个栈实现一个队列*/
#pragma once
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Queue
{
public:
	void Push(T data)//入队
	{
		stack<T>* input = NULL;//入队指针
		if (!s1.empty())//如果s1不为空，入队指针就指向s1
			input = &s1;
		else           //如果s1为空，入队指针就指向s2
			input = &s2;
		input->push(data);//在入队指针所指的栈中push数据
	}
	void Pop()//出队
	{
		if (s1.empty() && s2.empty())//如果两个栈都为空，说明队列是空的，直接返回
		{
			cout<<"queue empty!"<<endl;
			return;
		}
		stack<T>* input,*output;//定义入队指针和出队指针
		if (s1.empty())//如果s1为空，就将入队指针指向s2,出队指针指向s1
		{
			input = &s2;
			output = &s1;
		} 
		else          //如果s1不为空，就将入队指针指向s1,出队指针指向s2
		{
			input = &s1;
			output = &s2;
		}
		size_t size = input->size();//用临时变量size保存队列中的元素个数
		for (size_t i = 0; i < size - 1; ++i)//将入队指针所指栈的前(size-1)个元素转入出队栈
		{
			output->push(input->top());
			input->pop();//同时将转移过的数据删除
		}
		input->pop();//将最先进入队列的数据出队
		swap(input,output);//交换入队和出队指针
	}
protected:
	stack<T> s1;
	stack<T> s2;
};


void TestQueue()
{
	Queue<int> q;
	q.Push(1);
	q.Push(4);
	q.Push(3);
	q.Push(5);

	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
}


