/*������ջʵ��һ������*/
#pragma once
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Queue
{
public:
	void Push(T data)//���
	{
		stack<T>* input = NULL;//���ָ��
		if (!s1.empty())//���s1��Ϊ�գ����ָ���ָ��s1
			input = &s1;
		else           //���s1Ϊ�գ����ָ���ָ��s2
			input = &s2;
		input->push(data);//�����ָ����ָ��ջ��push����
	}
	void Pop()//����
	{
		if (s1.empty() && s2.empty())//�������ջ��Ϊ�գ�˵�������ǿյģ�ֱ�ӷ���
		{
			cout<<"queue empty!"<<endl;
			return;
		}
		stack<T>* input,*output;//�������ָ��ͳ���ָ��
		if (s1.empty())//���s1Ϊ�գ��ͽ����ָ��ָ��s2,����ָ��ָ��s1
		{
			input = &s2;
			output = &s1;
		} 
		else          //���s1��Ϊ�գ��ͽ����ָ��ָ��s1,����ָ��ָ��s2
		{
			input = &s1;
			output = &s2;
		}
		size_t size = input->size();//����ʱ����size��������е�Ԫ�ظ���
		for (size_t i = 0; i < size - 1; ++i)//�����ָ����ָջ��ǰ(size-1)��Ԫ��ת�����ջ
		{
			output->push(input->top());
			input->pop();//ͬʱ��ת�ƹ�������ɾ��
		}
		input->pop();//�����Ƚ�����е����ݳ���
		swap(input,output);//������Ӻͳ���ָ��
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


