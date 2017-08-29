//#include <iostream>
//using namespace std;
//
//void fun(int *a[2],int n)
//{
//	int ou = 0;
//	int ji = 0;
//	for (int i = 0; i < n; ++i)//n表示有多少组数据
//	{
//		for (int j = a[i][0]; j <a[i][1]; ++j)
//		{
//			if (j%2 == 0)
//				ou += j*j;
//			else
//				ji += j*j*j;
//		}
//	}
//	cout<<ou<<" "<<ji<<endl;
//}
//int main()
//{
//	int n = 2;//两组
//	int *a[2];
//	for (int i = 0; i < n; ++i)
//	{
//		cin>>a[i][0]>>a[i][1];
//		fun(a,n);
//	}
//	system("pause");
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int n = 0;
//	int x=0,y=0,temp=0,sum1,sum2;
//	scanf("%d",&n);
//
//	while(n--)
//	{
//		sum1 = 0;
//		sum2 = 0;
//		scanf("%d %d",&x,&y);
//		if (x > y)
//		{
//			temp = x;
//			x = y;
//			y = temp;
//		}
//		for (;x <= y; x++)
//		{
//			if(x%2 == 0)
//				sum1 += x*x;
//			else
//				sum2 += x*x*x;
//
//		}
//		printf("%d %d\n",sum1,sum2);
//	}
//
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int JudgeString(char* s)
//{
//	int len = strlen(s);
//	char* start = s;
//	char* end = s+len-1;
//	while(start != end)
//	{
//		if (*start == *end)
//		{
//			start++;
//			end--;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	char* str = "abcba";
//	if (1 == JudgeString(str))
//		printf("Y\n");
//	else
//		printf("N\n");
//
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int n = 0,m = 0,i,j,k;
//	int *a = NULL;
//	int *a1 = NULL;
//	scanf("%d",&n);
//	a = malloc(sizeof(int)*n);
//	for (i = 0; i < n; ++i)
//	{
//		scanf("%d",&a[i]);
//	}
//	scanf("%d",&m);
//	a1 = malloc(sizeof(int)*n);
//	for (j = 0; j < m; ++j)
//	{
//		a1[j] = a[n-m+j];
//	}
//	for (; j < n; ++j)
//	{
//		a1[j] = a[j-m];
//	}
//	for (k = 0; k < n; ++k)
//	{
//		printf("%d ",a1[k]);
//	}
//	printf("\n");
//	free(a);
//	free(a1);
//	system("pause");
//	return 0;
//}



