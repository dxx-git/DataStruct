#pragma once
//#include <stdio.h>
//
////联系if();else;
//void Show(int x,int y)
//{
//	if (x < 0)
//	{
//		y = -1;
//	}
//	else if(x == 0)
//	{
//		y = 0;
//	}
//	else
//	{
//		y = 1;
//	}
//}
//
////输出1-100之间的奇数
//void odd_number()
//{
//	int i = 1;
//	for (; i <= 100; i+=2)
//	{
//		printf("%d ",i);
//	}
//};
//
////判断两个数组是否有相同元素
//bool Judge(int* a,size_t n1,int* b,size_t n2)
//{
//	int i = 0;
//	int j = 0;
//	if (n1 >= n2)
//	{
//		for (; i<n1; ++i)
//		{
//			for (j=0; j<n2; ++j)
//			{
//				if (a[i] == b[j])
//				{
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//	else
//	{
//		for (; i<n2; ++i)
//		{
//			for (j=0; j<n1; ++j)
//			{
//				if (b[i] == a[j])
//				{
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//}
//
//#define PRECISION = 0.00000000
////求ax^2 + bx + c = 0方程的解。
//void Solve(double a,double b,double c)
//{
//	if (-PRECISION <=a && a<=PRECISION)
//	{
//		printf("方程不是二次方程，方程的解为%d!",(-1)*c/b);
//	}
//	else
//	{
//		double d = sqrt(b*b - 4*a*c);
//		if (d>0)
//		{
//			printf("方程有俩个不相等的实根，分别为：x1=%d x2=%d!",((-1)*b+d)/(2*a),((-1)*b-d)/(2*a));
//		}
//		else if (-PRECISION <=d && d<=PRECISION)
//		{
//			printf("方程有俩个相等的实根，为：x1=x2=%d!",(-1)*b/(2*a));
//		}
//		else
//		{
//			printf("方程有俩个共轭复根");
//		}
//	}
//}

//输出一个整数的每一位
void Val(int num)//反向输出
{
	while(num)
	{
		int val = num % 10;
		printf("%d ",val);

		num /= 10;
	}
}

void ValR(int num)//正向输出(递归)
{
	int val = 0;
	if (num == 0)
	{
		return;
	}

	val = num % 10;
	num /= 10;
	ValR(num);

	printf("%d ",val);
}


//输出1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
void calculate()
{
	int sign = -1;
	double deno = 1;
	double sum = 0;

	for (deno = 1.0; deno <= 100.0; ++deno)
	{
		sign = sign * (-1);
		sum += (sign*1)/deno;
	}
	printf("%f\n",sum);
}

//数一下1到100的所有整数中出现多少次数字9 
int Count_9()
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 100; ++i)
	{
        if (i % 10 == 9)
		{
			count++;
		}
		if (i / 10 == 9)//十位
		{
			count++;
		}
	}
	return count;
}