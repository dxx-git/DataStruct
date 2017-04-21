#pragma once
#include <queue>
#include <iostream>
using namespace std;


template <class T>
class Stack
{
public:
	//�㷨һ������q1ר�����������push���ݣ�q2ֻ��pop����ʱ������תվ
	void Push1(const T& data)
	{
		q1.push(data);
	}
	void Pop1()
	{
		if (q1.empty())//q1Ϊ��
		{
			cout<<"Stack empty!"<<endl;
			return;
		}
		//��q1�е�����ǰ(size-1)��Ԫ��ת�Ƶ�q2
		size_t size = q1.size();//����ʱ����size����q1ûpop֮ǰ�����ݸ���,���Ч��
		for (size_t i = 0; i < size-1; ++i)
		{
			q2.push(q1.front());
			q1.pop();
		}

		//��q1�е����һ��Ԫ��pop��
		q1.pop();

		//��q2�е�Ԫ��(size-1)ת�ƻ�q1
		for (size_t i = 0; i < size-1; ++i)
		{
			q1.push(q2.front());
			q2.pop();
		}
	}

	//�㷨�������涨q1push����q2push,������ָ��ά����ջ(tmp)����ջ(pushtmp)

	void Push2(const T& data)
	{
		queue<T>* pushtmp;//��ջָ��

		if(!q1.empty())//q1��Ϊ��,����q1�����,q2ֻ����Ϊ��תվ
		{
			pushtmp = &q1;
		}
		else          //q1Ϊ��,����q2�����,q1������תվ
		{
			pushtmp = &q2;
		}
		pushtmp->push(data);//�п�����q1����ӣ�Ҳ�п�����q2�����
	}
	void Pop2()
	{
		queue<T>* pushtmp, *tmp;//������ջָ��ͳ�ջָ��

		if (q1.empty() && q2.empty())//�������ж�Ϊ��ֱ�ӷ���
		{
			cout<<"Stack empty!"<<endl;
			return;
		}
		if(!q1.empty())//q1��Ϊ�գ�˵��q1����Ӷ��У�q2����תվ
		{
			pushtmp = &q1;
			tmp = &q2;
		}
		else      //q1Ϊ�գ�˵��q2����Ӷ��У�q1����תվ
		{
			pushtmp = &q2;
			tmp = &q1;
		}

		if(pushtmp->empty())  //��Ӷ���Ϊ�գ�˵��ջΪ��
		{
			cout<<"Stack Empty!"<<endl;
		}
		else
		{
			//��pushtmp�ĳ����һ��Ԫ����ȫ��ת�Ƶ�����tmp��
			size_t size = pushtmp->size();//����ʱ����size����q1ûpop֮ǰ�����ݸ���,���Ч��
			for (size_t i = 0; i < size-1; ++i)
			{
				tmp->push(pushtmp->front());
				pushtmp->pop();
			}

			//��pushtmp�е����ڵ㣨��ͬ������Ľڵ㣩������
			pushtmp->pop();

			//������ջ�ͳ�ջָ�룬�����˽ڵ��ƶ�����
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


