/*元素出栈、入栈顺序的合法性。）*/
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
		assert(insz == outsz);//制止所给的入栈序列和出栈序列的长度不一样
		
		size_t inIndex = 0;//入栈序列的下标
		size_t outIndex = 0;//出栈序列的下标

		while(outIndex != outsz)//出栈序列的下标没走到尾，就说明还有元素没有匹配出栈
		{
			//当栈为空或栈顶元素与出栈序列的当前元素不匹配
			if (s.empty() || s.top() != out[outIndex])
			{
				//如果所有元素都已入栈而出栈序列还没有走到尾，说明序列不匹配
				if(inIndex == insz)
					return false;
				//如果入栈序列还没有走到尾，就将当前元素入栈
				s.push(in[inIndex++]);
			}
			//如果栈顶元素和出栈序列的当前元素相同，就将出栈序列的下标向后走，并pop栈顶元素
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