//
////�����ȷ���
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h> 
//#include<stdlib.h> 
//
//typedef struct process_FCFS
//{
//    float arrivetime;//����ʱ�� 
//    float servetime;//����ʱ�� 
//    float finishtime;//���ʱ�� 
//	float starttime;//��ʼ����ʱ��
//    float roundtime;//��תʱ�� 
//    float daiquantime;//��Ȩ��תʱ�� 
//}FCFS; 
//
//struct process_FCFS a[100]; //��̬����100�����̵Ŀռ�
//
////������ʱ�����ð������
//struct process_FCFS *sortarrivetime(struct process_FCFS a[],int n) 
//{ 
//   int i = 0,j = 0; 
//   struct process_FCFS t; 
//   int flag = 0; //���ñ�־λ���Ż�ð������
//   for(i=1;i<n;i++) 
//  { 
//     flag=0; 
//     for(j=0;j<n-i;j++) 
//    { 
//        if(a[j].arrivetime>a[j+1].arrivetime) //�ȽϽ��̵���ʱ�䣬������ʱ���С��������
//       { 
//           t=a[j]; 
//           a[j]=a[j+1]; 
//           a[j+1]=t; 
//           flag=1;//���� 
//       }
//    } 
//    if(flag==0)//���һ��������û�����κν��������������
//       break; 
//   } 
//   return a; 
//} 
//
////�����ȷ����㷨
//void print(struct process_FCFS a[],int n) 
//{ 
//    int i = 0; 
//    for(i=0;i<n;i++)
//   { 
//       printf("����ʱ�䣺%f\n",a[i].arrivetime); 
//       printf("����ʱ�䣺%f\n",a[i].servetime); 
//	   printf("��ʼ����ʱ�䣺%f\n",a[i].starttime);
//
//       printf("���ʱ�䣺%f\n",a[i].finishtime); 
//       printf("��תʱ�䣺%f\n",a[i].roundtime); 
//       printf("��Ȩ��תʱ�䣺%f",a[i].daiquantime); 
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
//    printf("�����ȷ���\n"); 
//    print(a,n); 
//} 
////������
//int main() 
//{ 
//    int n = 0,i = 0; 
//    printf("�������м�������:"); 
//    scanf("%d",&n); 
//    for(i=0;i<n;i++) 
//   { 
//	   printf("�������%d�����̽��̿��ƿ�������Ϣ:\n",i+1);
//       printf("arrivetime:"); 
//       scanf("%f",&a[i].arrivetime); 
//       printf("servetime:"); 
//       scanf("%f",&a[i].servetime);
//   } 
//   sortarrivetime(a,n);//�Ƚ����̰�����ʱ���С��������
//   Fcfs(a,n); //���������ȷ����㷨
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
	double _needtime;    //��������ʱ��
	double _runtime;     //ʵ������ʱ��
	double _endtime;     //����ʱ��
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
		cout<<"��������Ҫִ�еĽ�������>";
		cin>>num;
		for (int i=0;i<num;++i)
		{
			cout<<"�����������?>";
			cin>>name;
			cout<<"��������̵ĵ���ʱ��>";
			cin>>arrive;
			cout<<"��������̵Ĺ�������ʱ��>";
			cin>>need;
			Node *NewNode=new Node(name,arrive,need);
			if(_head == NULL)     //������
			{
				_head=NewNode;
				_tail=NewNode;
			}
			else                 //�ǿ�����
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
			cout<<"������>"<<cur->_name<<" ";
			cout<<"����ʱ��>"<<cur->_arrivetime<<" ";
			cout<<"����ʱ��>"<<cur->_needtime<<endl;
			cur=cur->_next;
		}
	}

	void FCFS()
	{
		int count=0;
		Node *cur=_head;
		double finish=0.0;          //���ʱ��
		double time=0.0;            //��תʱ��=���ʱ��-����ʱ��
		double weighttime=0.0;      //��Ȩ��תʱ��=��תʱ��/����ʱ��
		double avertime=0.0;
		double averweighttime=0.0;  
		while(cur)
		{   
			if(finish <= cur->_arrivetime)
			{
				//�����ʱ��С�ڴﵽʱ��ʱ
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
			cout<<"������>"<<cur->_name<<" ";
			cout<<"���ʱ��>"<<finish<<" ";
			cout<<"��תʱ��>"<<time<<" ";
			cout<<"��Ȩ��תʱ��>"<<weighttime<<endl;
			count++;
			cur=cur->_next;
		}
		cout<<"ƽ����תʱ��>"<<avertime/count<<endl;
		cout<<"ƽ����Ȩ��תʱ��>"<<averweighttime/count<<endl;
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
			cout<<"������>"<<cur->_name<<" ";
			cout<<"���ʱ��>"<<finish<<" ";
			cout<<"��תʱ��>"<<time<<" ";
			cout<<"��Ȩ��תʱ��>"<<weighttime<<endl;
			count++;
			cur=cur->_next;
		}
		cout<<"ƽ����תʱ��>"<<avertime/count<<endl;
		cout<<"ƽ����Ȩ��תʱ��>"<<averweighttime/count<<endl;

	}
	void RR(const double& q)
	{
		double time=0.0;
		double weighttime=0.0;
		double avertime=0.0;
		double averweighttime=0.0;  

		double sys=0.0;      //ϵͳʱ��
		queue<Node *> q1;    //�������ТD
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
			if(tmp->_arrivetime <= sys)   //�Ƿ��н��̵���
			{
				if (tmp->_needtime > q)   //һ��ʱ��Ƭ�ﲻ��ִ�����				{
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
		cout<<"������>"<<cur->_name<<" ";
		cout<<"���ʱ��>"<<cur->_endtime<<" ";
		cout<<"��תʱ��>"<<time<<" ";
		cout<<"��Ȩ��תʱ��>"<<weighttime<<endl;
		cur=cur->_next;
	}
	cout<<"ƽ����תʱ��>"<<avertime/count<<endl;
	cout<<"ƽ����Ȩ��תʱ��>"<<averweighttime/count<<endl;

}
protected:
	Node *_head;
	Node *_tail;
};


void menu()
{
	cout<<"*********���������̵����㷨******"<<endl;
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
		cout<<"����������ѡ��>";
		";
			cin>>choice;
		switch(choice)
		{
		case 1:
			if(!pcb.IsEmpty())
			{
				cout<<"��ʱû�н����ڵȴ�"<<endl;
				break;
			}
			else
			{
				cout<<"�����ȷ���Ľ��̵����㷨>"<<endl;
				pcb.FCFS();
			}
			break;
		case 2:
			if(!pcb.IsEmpty())
			{
				cout<<"��ʱû�н����ڵȴ�"<<endl;
				break;
			}
			else
			{
				cout<<"����ҵ���ȵĽ��̵����㷨>"<<endl;
				pcb.SJF();
			}
			break;
		case 3:
			if(!pcb.IsEmpty())
			{
				cout<<"��ʱû�н����ڵȴ�"<<endl;
				break;
			}
			else
			{
				double q=0.0;
				cout<<"ʱ��Ƭ��ת�Ľ��̵����㷨>"<<endl;
				cout<<"������ʱ��Ƭ�Ĵ�С>";
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