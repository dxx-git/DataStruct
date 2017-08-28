#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//#include "3_15.h"
//void Prime()
//{
//	int i = 0;
//	int j = 0;
//	for(i = 101; i < 200; i+=2)
//	{
//		int s = sqrt(i);
//		for (j = 2; j < s; ++j)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//			if (j >= s-1)
//			{
//				printf("%d  ",i);
//			}
//		}
//	}
//}

//void Multable(int num)
//{
//	int i,j = 0;
//	for (i = 1; i <= num; ++i)
//	{
//		for (j = 1; j <= i;++j)
//		{
//			printf("%d*%d=%d ",j,i,i*j);
//			if (i == j)
//			{
//				printf("\n");
//			}
//		}
//	}
//	printf("\n");
//}

//void FindLeapYear()
//{
//	int i = 1000;
//	for (; i <= 2000; ++i)
//	{
//		if (i%400==0 || ((i%4==0) && (i%100!=0)))
//		{
//			printf("%d ",i);
//		}
//	}
//}
//int main()
//{
//	//int i=43;
//	////输出被写字符的个数----4321
//	//printf("%d\n",printf("%d",printf("%d",i)));
//
//	//Prime();
//	//Multable(9);
//	FindLeapYear();
//	system("pause");
//	return 0;
//}

//void fun(void )
//{
//	int j = 10;
//	printf( "%d ", j);
//}
//int main()
//{
//	void fun(void);//函数声明
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		fun();
//	}
//	printf( "\n");
//	system("pause");
//	return 0;
//}

//void Swap1(int* x,int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void Swap2(int* x,int* y)
//{
//	*x = *y + *x;
//	*y = *x - *y;
//	*x = *x - *y;
//}
//void Swap3(int* x,int* y)
//{
//	*x = *y * *x;
//	*y = *x / *y;
//	*x = *x / *y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//Swap1(&a,&b);
//	//Swap2(&a,&b);
//	Swap3(&a,&b);
//	printf("a=%d b=%d\n",a,b);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
////统计二进制中1的个数
//	int count_one_bits1(unsigned int value)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; ++i)
//	{
//		if (((value>>i) & 1) == 1)
//		{
//			++count;
//		}
//	}
//	return count;
//}
//int count_one_bits2(unsigned int value)
//{
//	int count = 0;
//	while(value)
//	{
//		if (value%2 == 1)
//		{
//			++count;
//		}
//		value >>= 1;
//	}
//	return count;
//}
//int count_one_bits3(unsigned int value)
//{
//	int count = 0;
//	while(value)
//	{
//		count++;
//		value = value&(value-1);
//	}
//	return count;
//}
//int main()
//{
//	printf("%d ",count_one_bits1(-1));
//	printf("%d ",count_one_bits1(0));
//	printf("%d\n",count_one_bits1(15));
//
//	printf("%d ",count_one_bits2(0));
//	printf("%d ",count_one_bits2(15));
//	printf("%d\n",count_one_bits2(20));
//
//	printf("%d ",count_one_bits3(-1));
//	printf("%d ",count_one_bits3(0));
//	printf("%d\n",count_one_bits3(15));
//	system("pause");
//	return 0;
//}

/*
#include "3_22.h"
#include "3_24.h"
int main()
{
	//Val(645);
	//printf("\n");
	//ValR(645);
	//calculate();
	//printf("%d\n",Count_9());
	//f();

	//move("We love China!");
	//move("!");
	//move("Welcome to HanCheng");
	//move1();

	//Loading();
	//Loading1();
	//Loading2();

	//cal();
	//TestBinarySearch();
	//Guess();
	//TestSubstr();
	//Sum();
	//Heigh();
	Peach();

	system("pause");
	return 0;
}*/

#include "5_2.h"
int main()
{
	//TestCountBits();
	ProgressBar();
	system("pause");
	return 0;
} 




