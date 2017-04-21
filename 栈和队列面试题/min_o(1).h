#pragma once
/*ʵ��һ��ջ��Ҫ��ʵ��Push����ջ����Pop����ջ����\
\Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO(1)*/
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class  StackMin
{
public:
	void Push(T data)//��ջ
	{
		s.push(data);//��ջs����ջ
		
		//���minΪ�ջ���min�е���Сֵ>=data���ͽ�dataͬʱ��ջ��min
		if (min.empty() || data <= min.top())
		{
			min.push(data);
		}
	}
	void Pop()//��ջ
	{
		if (s.empty())//����������ݵ�ջsΪ�գ�˵��ջ��û����,ֱ�ӷ���
		    return;

		//���Ҫɾ��������Ϊ��С���ݣ����뽫min�е���С����Ҳɾ��������ֻ��ɾ��sջ������
		if (s.top() == min.top())
			min.pop();
		s.pop();//s.top()>min.top
	}
	T Min()//��ȡջ�е���Сֵ��ʱ�临�Ӷȣ�O(1)��
	{
		return min.top();//min��ջ��Ԫ�ؼ�Ϊ��Сֵ
	}
protected:
	stack<T> s;  //���������ĳ�ջ��ջ
	stack<T> min;//����������С������
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