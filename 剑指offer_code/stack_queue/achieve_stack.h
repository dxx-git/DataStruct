#pragma once
#include <queue>
#include <iostream>
using namespace std;


template <class T>
class Stack
{
public:
	//算法一：队列q1专门用来保存和push数据，q2只是pop数据时做个中转站
	void Push1(const T& data)
	{
		q1.push(data);
	}
	void Pop1()
	{
		if (q1.empty())//q1为空
		{
			cout<<"Stack empty!"<<endl;
			return;
		}
		//将q1中的数据前(size-1)个元素转移到q2
		size_t size = q1.size();//用临时变量size保存q1没pop之前的数据个数,提高效率
		for (size_t i = 0; i < size-1; ++i)
		{
			q2.push(q1.front());
			q1.pop();
		}

		//将q1中的最后一个元素pop掉
		q1.pop();

		//将q2中的元素(size-1)转移回q1
		for (size_t i = 0; i < size-1; ++i)
		{
			q1.push(q2.front());
			q2.pop();
		}
	}

	//算法二：不规定q1push还是q2push,用两个指针维护出栈(tmp)和入栈(pushtmp)

	void Push2(const T& data)
	{
		queue<T>* pushtmp;//入栈指针

		if(!q1.empty())//q1不为空,就在q1中入队,q2只是作为中转站
		{
			pushtmp = &q1;
		}
		else          //q1为空,就在q2中入队,q1用作中转站
		{
			pushtmp = &q2;
		}
		pushtmp->push(data);//有可能在q1中入队，也有可能在q2中入队
	}
	void Pop2()
	{
		queue<T>* pushtmp, *tmp;//定义入栈指针和出栈指针

		if (q1.empty() && q2.empty())//两个队列都为空直接返回
		{
			cout<<"Stack empty!"<<endl;
			return;
		}
		if(!q1.empty())//q1不为空，说明q1是入队队列，q2是中转站
		{
			pushtmp = &q1;
			tmp = &q2;
		}
		else      //q1为空，说明q2是入队队列，q1是中转站
		{
			pushtmp = &q2;
			tmp = &q1;
		}

		if(pushtmp->empty())  //入队队列为空，说明栈为空
		{
			cout<<"Stack Empty!"<<endl;
		}
		else
		{
			//将pushtmp的除最后一个元素外全部转移到队列tmp中
			size_t size = pushtmp->size();//用临时变量size保存q1没pop之前的数据个数,提高效率
			for (size_t i = 0; i < size-1; ++i)
			{
				tmp->push(pushtmp->front());
				pushtmp->pop();
			}

			//让pushtmp中的最后节点（连同最后进入的节点）出队列
			pushtmp->pop();

			//交换入栈和出栈指针，减少了节点移动次数
			swap(pushtmp,tmp);
		}
	}

protected:
	queue<T> q1;
	queue<T> q2;
};


void TestStack()
{
	Stack<int> s;

	s.Push1(1);
	s.Push1(2);
	s.Push1(3);
	s.Push1(4);

	s.Pop1();

	s.Push2(5);
	s.Push2(6);
	s.Push2(7);
	s.Push2(8);

	s.Pop2();
	s.Pop2();
	s.Pop2();
	s.Pop2();
	s.Pop2();
	s.Pop2();
	s.Pop2();
	s.Pop2();
}


