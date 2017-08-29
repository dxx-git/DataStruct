/*���һ���࣬����ֻ�����ɸ����һ��ʵ��*/
#pragma once
#include <iostream>
#include <cassert>
using namespace std;

//���Լ����뷨�������ü����Լ����������Ƽӽ�ȥ��������ֻ������һ��ʵ����>1�����
class SingleTon
{
public:
	SingleTon(const int data = int())
		:_data(data)
	{
		count += 1;

		if (count > 1)
		{
			cout<<"error:this class is a singleton class.\n"<<endl;
			assert(false);
		}
	}

private:
	SingleTon(const SingleTon& st);//�������캯��������
	SingleTon& operator=(const SingleTon& st);//��ֵ�����������

private:
	static int count;//��̬��Ա����������
	int _data;
};

int SingleTon::count = 0;//��̬��Ա�����Ķ���

void TestSingleTon()
{
	SingleTon s1(10);
	SingleTon s2;
}


//�ⷨ1������Ĺ��캯����Ϊ˽�е������������˴���ʵ����\
        \ͬʱ����һ����̬��ʵ��������Ҫ��ʱ�򴴽���ʵ��
//ȱ�㣺ֻ�����ڵ��̻߳���
class SingleTon1
{
private:
SingleTon1()
{}
static SingleTon1* instance = NULL;
public:
	SingleTon1* Get()
	{
		if (NULL == instance)
		{
			instance = new SingleTon1();
		}
		return instance;
	}
};

//�ⷨ2;Ϊ�ⷨ1��һ��ͬ����
//�ⷨ3����ͬ����ǰ�������ж�ʵ���Ƿ��Ѿ�����
//�ⷨ4�����þ�̬�Ĺ��캯����C#��
//�ⷨ5�����贴��ʵ��