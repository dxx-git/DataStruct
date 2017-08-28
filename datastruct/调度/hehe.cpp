//
////先来先服务
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h> 
//#include<stdlib.h> 
//
//typedef struct process_FCFS
//{
//    float arrivetime;//到达时间 
//    float servetime;//服务时间 
//    float finishtime;//完成时间 
//	float starttime;//开始运行时间
//    float roundtime;//周转时间 
//    float daiquantime;//带权周转时间 
//}FCFS; 
//
//struct process_FCFS a[100]; //静态开辟100个进程的空间
//
////按到达时间进行冒泡排序
//struct process_FCFS *sortarrivetime(struct process_FCFS a[],int n) 
//{ 
//   int i = 0,j = 0; 
//   struct process_FCFS t; 
//   int flag = 0; //设置标志位以优化冒泡排序
//   for(i=1;i<n;i++) 
//  { 
//     flag=0; 
//     for(j=0;j<n-i;j++) 
//    { 
//        if(a[j].arrivetime>a[j+1].arrivetime) //比较进程到达时间，按到达时间从小到大排序
//       { 
//           t=a[j]; 
//           a[j]=a[j+1]; 
//           a[j+1]=t; 
//           flag=1;//交换 
//       }
//    } 
//    if(flag==0)//如果一趟排序中没发生任何交换，则排序结束
//       break; 
//   } 
//   return a; 
//} 
//
////先来先服务算法
//void print(struct process_FCFS a[],int n) 
//{ 
//    int i = 0; 
//    for(i=0;i<n;i++)
//   { 
//       printf("到达时间：%f\n",a[i].arrivetime); 
//       printf("服务时间：%f\n",a[i].servetime); 
//	   printf("开始运行时间：%f\n",a[i].starttime);
//
//       printf("完成时间：%f\n",a[i].finishtime); 
//       printf("周转时间：%f\n",a[i].roundtime); 
//       printf("带权周转时间：%f",a[i].daiquantime); 
//       printf("\n\n");
//   } 
//} 
//
//void Fcfs(struct process_FCFS a[],int n) 
//{ 
//    int i = 0; 
//	a[0].starttime=a[0].arrivetime; 
//    a[0].finishtime=a[0].arrivetime+a[0].servetime; 
//    a[0].roundtime=a[0].finishtime-a[0].arrivetime; 
//    a[0].daiquantime=a[0].roundtime/a[0].servetime; 
//	printf("\n");
//    for(i=0;i<n;i++) 
//   { 
//       if(a[i].arrivetime<a[i-1].finishtime) 
//      { 
//		  a[i].starttime=a[i-1].finishtime; 
//          a[i].finishtime=a[i].starttime+a[i].servetime; 
//          a[i].roundtime=a[i].finishtime-a[i].arrivetime; 
//          a[i].daiquantime=a[i].roundtime/a[i].servetime; 
//      }
//      else 
//     {    a[i].starttime=a[i].arrivetime;
//          a[i].finishtime=a[i].starttime+a[i].servetime; 
//          a[i].roundtime=a[i].finishtime-a[i].arrivetime; 
//          a[i].daiquantime=a[i].roundtime/a[i].servetime; 
//     } 
//   } 
//
//    printf("先来先服务\n"); 
//    print(a,n); 
//} 
////主函数
//int main() 
//{ 
//    int n = 0,i = 0; 
//    printf("请输入有几个进程:"); 
//    scanf("%d",&n); 
//    for(i=0;i<n;i++) 
//   { 
//	   printf("请输入第%d个进程进程控制块的相关信息:\n",i+1);
//       printf("arrivetime:"); 
//       scanf("%f",&a[i].arrivetime); 
//       printf("servetime:"); 
//       scanf("%f",&a[i].servetime);
//   } 
//   sortarrivetime(a,n);//先将进程按进入时间从小到大排序
//   Fcfs(a,n); //调用先来先服务算法
//   system("pause");
//   return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <queue>
#include<windows.h>
using namespace std;
#pragma once
struct PCBNode
{
	string _name;      
	double _arrivetime; 
	double _needtime;    //估计运行时间
	double _runtime;     //实际运行时间
	double _endtime;     //结束时间
	PCBNode *_next;
	PCBNode(const string& name="",const double arrive=0.0,const double run=0.0)
		:_name(name)
		,_arrivetime(arrive)
		,_needtime(run)
		,_runtime(0.0)
		,_endtime(0.0)
		,_next(NULL)
	{}
};
class PCB
{
	typedef PCBNode Node;
public:
	PCB()
		:_head(NULL)
		,_tail(NULL)
	{}
	~PCB()
	{
		Node *cur=_head;
		while (cur)
		{
			Node *del=cur;
			cur=cur->_next;
			delete del;
			del=NULL;
		}
		_head=NULL;
		_tail=NULL;
	}
public:
	bool IsEmpty()
	{
		return _head == _tail == NULL;
	}
	void Input()
	{
		string name;
		double arrive=0.0;
		double need=0.0;
		int num=0;
		cout<<"请输入您要执行的进程总数>";
		cin>>num;
		for (int i=0;i<num;++i)
		{
			cout<<"请输入进程名?>";
			cin>>name;
			cout<<"请输入进程的到达时间>";
			cin>>arrive;
			cout<<"请输入进程的估计运行时间>";
			cin>>need;
			Node *NewNode=new Node(name,arrive,need);
			if(_head == NULL)     //空链表
			{
				_head=NewNode;
				_tail=NewNode;
			}
			else                 //非空链表
			{
				_tail->_next=NewNode;
				_tail=NewNode;
			}
		}
	}
	void Display()
	{
		Node *cur=_head;
		while (cur)
		{
			cout<<"进程名>"<<cur->_name<<" ";
			cout<<"到达时间>"<<cur->_arrivetime<<" ";
			cout<<"运行时间>"<<cur->_needtime<<endl;
			cur=cur->_next;
		}
	}

	void FCFS()
	{
		int count=0;
		Node *cur=_head;
		double finish=0.0;          //完成时间
		double time=0.0;            //周转时间=完成时间-到达时间
		double weighttime=0.0;      //带权周转时间=周转时间/运行时间
		double avertime=0.0;
		double averweighttime=0.0;  
		while(cur)
		{   
			if(finish <= cur->_arrivetime)
			{
				//当完成时间小于达到时间时
				finish=cur->_arrivetime+cur->_needtime;
				time=finish-cur->_arrivetime;
				avertime += time;
				weighttime=time/cur->_needtime;
				averweighttime += weighttime;
			}
			else
			{
				finish += cur->_needtime;
				time=finish-cur->_arrivetime;
				avertime += time;
				weighttime=time/cur->_needtime;
				averweighttime += weighttime;
			}
			cout<<"进程名>"<<cur->_name<<" ";
			cout<<"完成时间>"<<finish<<" ";
			cout<<"周转时间>"<<time<<" ";
			cout<<"带权周转时间>"<<weighttime<<endl;
			count++;
			cur=cur->_next;
		}
		cout<<"平均周转时间>"<<avertime/count<<endl;
		cout<<"平均带权周转时间>"<<averweighttime/count<<endl;
	}
	void SortByRunTime(Node *node)
	{
		Node *cur=node;
		int flag=1;
		Node *tail=NULL;
		while (cur != tail)
		{
			while(cur->_next != tail)
			{
				if (cur->_needtime > cur->_next->_needtime)
				{
					Node *tmp=new Node(cur->_name,cur->_arrivetime,cur->_needtime);
					cur->_name=cur->_next->_name;
					cur->_arrivetime=cur->_next->_arrivetime;
					cur->_needtime=cur->_next->_needtime;

					cur->_next->_name=tmp->_name;
					cur->_next->_arrivetime=tmp->_arrivetime;
					cur->_next->_needtime=tmp->_needtime;
					flag=0;
				}
				cur=cur->_next;
			}
			if(flag == 1)
				break;
			tail=cur;
			cur=node;
		}
	}
	void SJF()
	{
		int count=0;
		Node *cur=_head;
		double finish=0.0;
		double time=0.0;
		double weighttime=0.0;
		double avertime=0.0;
		double averweighttime=0.0;  
		SortByRunTime(_head->_next);
		while(cur)
		{   
			if(finish <= cur->_arrivetime)
			{
				finish=cur->_arrivetime+cur->_needtime;
				time=finish-cur->_arrivetime;
				avertime += time;
				weighttime=time/cur->_needtime;
				averweighttime += weighttime;
			}
			else
			{
				finish += cur->_needtime;
				time=finish-cur->_arrivetime;
				avertime += time;
				weighttime=time/cur->_needtime;
				averweighttime += weighttime;
			}
			cout<<"进程名>"<<cur->_name<<" ";
			cout<<"完成时间>"<<finish<<" ";
			cout<<"周转时间>"<<time<<" ";
			cout<<"带权周转时间>"<<weighttime<<endl;
			count++;
			cur=cur->_next;
		}
		cout<<"平均周转时间>"<<avertime/count<<endl;
		cout<<"平均带权周转时间>"<<averweighttime/count<<endl;

	}
	void RR(const double& q)
	{
		double time=0.0;
		double weighttime=0.0;
		double avertime=0.0;
		double averweighttime=0.0;  

		double sys=0.0;      //系统时间
		queue<Node *> q1;    //辅助队列
		int count=0;
		Node *cur=_head;
		while (cur)
		{
			count++;
			q1.push(cur);
			cur=cur->_next;
		}
		cur=_head;
		while (!q1.empty())
		{
			Node *tmp=q1.front();
			if(tmp->_arrivetime <= sys)   //是否有进程到达
			{
				if (tmp->_needtime > q)   //一个时间片里不能执行完成				{
					Sleep(q);
				tmp->_needtime -= q;
				tmp->_runtime += q;
				sys += q;
				q1.push(tmp);
				q1.pop();
			}
			else
			{
				Sleep(tmp->_needtime);
				sys += tmp->_needtime;
				tmp->_endtime=sys;
				tmp->_runtime += tmp->_needtime;
				tmp->_needtime=0.0;
				q1.pop();
			}
		}
			else
				sys++;
	}
	cur=_head;
	while (cur)
	{
		time=cur->_endtime-cur->_arrivetime;
		avertime += time;
		weighttime=time/cur->_runtime;
		averweighttime += weighttime;
		cout<<"进程名>"<<cur->_name<<" ";
		cout<<"完成时间>"<<cur->_endtime<<" ";
		cout<<"周转时间>"<<time<<" ";
		cout<<"带权周转时间>"<<weighttime<<endl;
		cur=cur->_next;
	}
	cout<<"平均周转时间>"<<avertime/count<<endl;
	cout<<"平均带权周转时间>"<<averweighttime/count<<endl;

}
protected:
	Node *_head;
	Node *_tail;
};


void menu()
{
	cout<<"*********单批道进程调度算法******"<<endl;
	cout<<"************* 1.FCFS**************"<<endl;
	cout<<"************* 2.SJF***************"<<endl;
	cout<<"************* 3.RR***************"<<endl;
	cout<<"************* 4.Input*************"<<endl;
	cout<<"************* 0.Exit**************"<<endl;
}

void testPCB()
{
	PCB pcb;
	int choice=0;
	int index=1;
	while (index)
	{
		menu();
		cout<<"请输入您的选择>";
		";
			cin>>choice;
		switch(choice)
		{
		case 1:
			if(!pcb.IsEmpty())
			{
				cout<<"此时没有进程在等待"<<endl;
				break;
			}
			else
			{
				cout<<"先来先服务的进程调度算法>"<<endl;
				pcb.FCFS();
			}
			break;
		case 2:
			if(!pcb.IsEmpty())
			{
				cout<<"此时没有进程在等待"<<endl;
				break;
			}
			else
			{
				cout<<"短作业优先的进程调度算法>"<<endl;
				pcb.SJF();
			}
			break;
		case 3:
			if(!pcb.IsEmpty())
			{
				cout<<"此时没有进程在等待"<<endl;
				break;
			}
			else
			{
				double q=0.0;
				cout<<"时间片轮转的进程调度算法>"<<endl;
				cout<<"请输入时间片的大小>";
				cin>>q;
				pcb.RR(q);
			}
			break;
		case 4:
			pcb.Input();
			break;
		case 0:
			index=0;
			break;
		default:
			cout<<"error"<<endl;
			break;
		}
	}
}

int main()
{
	testPCB();
	system("pause");
	return 0;
}