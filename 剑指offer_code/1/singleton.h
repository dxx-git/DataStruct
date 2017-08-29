/*设计一个类，我们只能生成该类的一个实例*/
#pragma once
#include <iostream>
#include <cassert>
using namespace std;

//我自己的想法，用引用计数以及防拷贝机制加进去来控制类只能生成一个实例，>1则断言
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
	SingleTon(const SingleTon& st);//拷贝构造函数的声明
	SingleTon& operator=(const SingleTon& st);//赋值运算符的声明

private:
	static int count;//静态成员变量的声明
	int _data;
};

int SingleTon::count = 0;//静态成员变量的定义

void TestSingleTon()
{
	SingleTon s1(10);
	SingleTon s2;
}


//解法1：将类的构造函数设为私有的来进制其他人创建实例，\
        \同时定义一个静态的实例，在需要的时候创建该实例
//缺点：只适用于单线程环境
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

//解法2;为解法1加一个同步锁
//解法3：加同步锁前后两次判断实例是否已经存在
//解法4：利用静态的构造函数（C#）
//解法5：按需创建实例