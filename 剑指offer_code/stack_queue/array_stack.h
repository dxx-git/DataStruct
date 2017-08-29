/*��һ������ʵ������ջ*/
#pragma once
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;


enum Choose
{
	First,//�Ե�һ��ջ���в���
	SECOND,//�Եڶ���ջ���в���
};

//�㷨һ��
/*���������ͷ�ֱ���Ϊ����ջ��ջ��ָ�룬��������ʱ���м俿£��\
\ ָ������˵���ռ�����������������������*/
template <class T>
class ArrayStack
{
public:
	ArrayStack()
		:_n(5)//Ϊ�˷�����ԣ�Ĭ������ֻ��5���ռ�
		,_a(new T[_n])
		,_sTop1(0)
		,_sTop2(_n-1)
	{}
	~ArrayStack()
	{
		if (_a)
		{
			delete []_a;
			_a = NULL;
		}
	}

	void Push1(Choose choose,T data)//��ջ(����choose:ѡ������һ��ջ�н�����ջ)
	{
		assert(_a); //Ԥ������Ϊ��
		
		if(_sTop1 > _sTop2)//�������±��Ѿ�����,˵������ռ���������Ҫ����
			_Dilatation();//���ݺ���

		if (choose == First)//�ڵ�һ��ջ��push����
			_a[_sTop1++] = data;
		else               //�ڵڶ���ջ��push����
		    _a[_sTop2--] = data;
	}
	void Pop1(Choose choose)
	{
		if (choose == First)//pop��һ��ջ�е�Ԫ��
		{
			if (_sTop1 == 0)//ջΪ��
			{
				cout<<"stack1 empty!"<<endl;
				return;
			}
			--_sTop1;//��ջ���±���ǰ��
		}
		else             //pop�ڶ���ջ�е�Ԫ��
		{
			//size_t size2 = _a+n - _a +_sTop2;//����ջ2 ��Ԫ�ظ���
			if (_sTop2 == _n)//ջΪ��
			{
				cout<<"stack2 empty!"<<endl;
				return;
			}
			++_sTop2;//��ջ���±������
		}
	}
protected:
	void _Dilatation()//���ݺ���
	{
		size_t n = _n;//����ɿռ��Ԫ�ظ���
		_n *= 2;          //ÿ���Զ������ٶ�����
		T* tmp = new T[_n];//�����¿ռ�

		//��ջ1�оɿռ�����ݿ������¿ռ���
		for (size_t i = 0; i < _sTop1; ++i)
		{
			tmp[i] = _a[i];
		}

		size_t size2 = n - _sTop2;//����ջ2��Ԫ�ظ���
		_sTop2 += n+1;//��ջ2��ջ��ָ����Ӧ������ƶ����ӵ��ֽ���

		//��ջ2�оɿռ�����ݿ������¿ռ���
		for (size_t i = _n-1; --size2; --i)
		{
			tmp[i] = _a[--n];//ע��ѭ�������͸�ֵ��ʽ
		}
		delete []_a;//�ͷžɿռ�
		swap(_a,tmp);//ָ���¿ռ�
	}
private:
	size_t _n;
	T* _a;
	size_t _sTop1;//ջ1��ջ���±�
	size_t _sTop2;//ջ2��ջ���±�
};


//�㷨����
/*��������м���������λ�÷ֱ���Ϊ����ջ��ջ��ָ�룬��������ʱ�������ߣ�\
\ ������һ��ָ���ߵ��߽�˵���ռ�����������������������\
\���м��������һ��ջ���ˣ���һ��ջ�ܿյ��������ݣ��ռ������ʵͣ�*/


//�㷨����
/*���������żλ�÷ֱ���Ϊ����ջ��ջ��ָ�룬��������ʱ������ǰ�ߣ�\
\ ������һ��ָ���ߵ��ұ߽�˵���ռ�����������������������\
\���м��������һ��ջ���ˣ���һ��ջ�ܿյ��������ݣ��ռ������ʵͣ�*/

void TestArrayStack()
{
	ArrayStack<int> as;
	as.Push1(First,1);
	as.Push1(SECOND,5);
	as.Push1(First,2);
	as.Push1(SECOND,6);
	as.Push1(First,3);
	as.Push1(First,4);

	as.Pop1(First);
	as.Pop1(First);
	as.Pop1(First);
	as.Pop1(First);
	as.Pop1(First);
	as.Pop1(SECOND);
	as.Pop1(SECOND);
	as.Pop1(SECOND);
}