/*Ԫ�س�ջ����ջ˳��ĺϷ��ԡ���*/
#pragma once
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

template <class T>
class Stack_Legal
{
public:
	bool IsLegal(T* in,T* out,size_t insz,size_t outsz)
	{
		assert(insz == outsz);//��ֹ��������ջ���кͳ�ջ���еĳ��Ȳ�һ��
		
		size_t inIndex = 0;//��ջ���е��±�
		size_t outIndex = 0;//��ջ���е��±�

		while(outIndex != outsz)//��ջ���е��±�û�ߵ�β����˵������Ԫ��û��ƥ���ջ
		{
			//��ջΪ�ջ�ջ��Ԫ�����ջ���еĵ�ǰԪ�ز�ƥ��
			if (s.empty() || s.top() != out[outIndex])
			{
				//�������Ԫ�ض�����ջ����ջ���л�û���ߵ�β��˵�����в�ƥ��
				if(inIndex == insz)
					return false;
				//�����ջ���л�û���ߵ�β���ͽ���ǰԪ����ջ
				s.push(in[inIndex++]);
			}
			//���ջ��Ԫ�غͳ�ջ���еĵ�ǰԪ����ͬ���ͽ���ջ���е��±�����ߣ���popջ��Ԫ��
			else
			{
				++outIndex;
				s.pop();
			}
		}

	    return true;
	}

protected:
	stack<T> s;
};


void TestStackLegal()
{
	Stack_Legal<int> s;
	int in1[] = {1,2,3,4,5};
	int out1[] = {5,4,3,2,1};
	size_t insz1 = sizeof(in1)/sizeof(in1[0]);
	size_t outsz1 = sizeof(out1)/sizeof(out1[0]);
	cout<<s.IsLegal(in1,out1,insz1,outsz1)<<endl;

    int in2[] = {1,2,3,4,5};
	int out2[] = {1,2,3,4,5};
	size_t insz2 = sizeof(in2)/sizeof(in2[0]);
	size_t outsz2 = sizeof(out2)/sizeof(out2[0]);
	cout<<s.IsLegal(in2,out2,insz2,outsz2)<<endl;

	int in3[] = {1,2,3,4,5};
	int out3[] = {3,4,2,5,1};
	size_t insz3 = sizeof(in3)/sizeof(in3[0]);
	size_t outsz3 = sizeof(out3)/sizeof(out3[0]);
	cout<<s.IsLegal(in3,out3,insz3,outsz3)<<endl;

	int in4[] = {1,2,3,4,5};
	int out4[] = {5,2,4,3,1};
	size_t insz4 = sizeof(in4)/sizeof(in4[0]);
	size_t outsz4  = sizeof(out4)/sizeof(out4[0]);
	cout<<s.IsLegal(in4,out4,insz4,outsz4)<<endl;
}