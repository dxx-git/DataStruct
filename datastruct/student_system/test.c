#define _CRT_SECURE_NO_WARNINGS
//���ͷ�ļ�
#include<stdio.h>
#include<string.h>

#define STUDENT_COUNT 1//�궨��
//����������
int main(void)
{
	int i,j;
	//����ѧ������

	char names[STUDENT_COUNT][50];
	char xingbie[STUDENT_COUNT];
	int number[STUDENT_COUNT];
	int phonenumber[STUDENT_COUNT];
	char danwei[STUDENT_COUNT];
	int mail[STUDENT_COUNT]; 
	int n;//��ǰѧ������
	int temp;//����һ����������
	char name[STUDENT_COUNT][50];//����һ���������
	int k;//����һ���������ڴ���names[i]���±�
	int choice = 1;//�����û�����
	printf("ϵͳ�˵�\n");
	printf("*************************************\n");
	printf("��ӭʹ��ѧ��ͨ����Ϣ����ϵͳ\n");
	printf("[1] ��������ѧ����Ϣ\n");
	printf("[2] �������ѧ����Ϣ\n");
	printf("[3] ���绰�������ĳ��ѧ����Ϣ\n");
	printf("[4] ����������ĳ��ѧ����Ϣ\n");
	printf("[5] �������޸�ĳ��ѧ����Ϣ\n");
	printf("[6] ���绰�����޸�ĳ��ѧ����Ϣ\n");
	printf("[7] ������ɾ��ĳ��ѧ����Ϣ\n");
	printf("[8] ���绰����ɾ��ĳ��ѧ����Ϣ\n");
	printf("[0] �˳�����\n");
	printf("**************************************\n");
	while(choice)
	{
		printf("����������ѡ��0-8��:");

		scanf("%d",&choice);

		if(choice==0)//�ж�
		{
			break;//���������ѭ��
		}
		//��ʾ�˵�
		switch(choice)
		{
		case 1://��������ѧ������Ϣ
			for(n=0;n<STUDENT_COUNT;n++)
			{
				printf("�������%dѧ����Ϣ(�������Ա�ѧ�ţ��绰���룬��λ����ַ)\n",n+1);
				scanf("%s%s%d%d%s%d",&names[n],&xingbie[n],&number[n],&phonenumber[n],&danwei[n],&mail[n]);
			}
			break;
		case 2://�������ѧ����Ϣ
			//��ӡ��ͷ
			printf("������%dѧ����Ϣ(�������Ա�ѧ�ţ��绰���룬��λ����ַ)\n",n+1);
			printf("------------------------------------------------------\n");
			for(i=0;i<n;i++)
			{
				//��ӡ��Ϣ\n
				printf("%s%s%d%d%s%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("------------------------------------------------------\n");
			}
			break;
		case 3://���绰�������ĳ��ѧ����Ϣ
			printf("���������ѧ���绰��\n");
			scanf("%d",&j);
			k=-1;
			//ѧ�Ų���
			for(i=0;i<n;i++)
			{
				if(j==phonenumber[i])
				{
					k=i;
					break;
				}
			}
			if(k==-1)
			{
				printf("�Բ���û�и�ѧ����Ϣ");
			}
			else
			{
				//�ȴ�ӡ��ͷ
				printf("�������%dѧ����Ϣ(�������Ա�ѧ�ţ��绰���룬��λ����ַ)\n",n+1);
				printf("-----------------------------------------------------------\n");
				//���ӡѧ����Ϣ
				printf("\n15%s\t15%s\t15%d\t15%d\t15%s\t15%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("----------------------------------------------------------\n");
			}
			break;
		case 4://����������ĳ��ѧ����Ϣ
			printf("���������ѧ������\n");
			scanf("%s",&name);
			k=-1;//���ñ���K�����ڶ�β���
			for(i=0;i<n;++i)
			{
				if(strcmp(name[i],names[i])==0)//�����ıȽ�
				{
					k=i;
					break;
				}
			}
			if(k==-1)
			{
				printf("�Բ���û�и�ѧ������Ϣ��\n");
			}
			else
			{
				//�ȴ�ӡ��ͷ
				printf("�������%dѧ����Ϣ(������ѧ�ţ��Ա𣬵绰���룬��λ����ַ)\n",n+1);
				printf("-----------------------------------------------------------\n");
				//���ӡѧ����Ϣ
				printf("\n15%s\t15%s\t15%d\t15%d\t15%s\t15%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("----------------------------------------------------------\n");
			}
			break;
		case 5://�������޸�ĳ��ѧ����Ϣ
			printf("������Ҫ�޸�ѧ����������");
			scanf("%s",&name);
			k=-1;
			for(i=0;i<n;++i)
			{
				if(strcmp(name[i],names[i])==0)
				{
					k=i;
					printf("������Ҫ�޸ĵ���Ϣ��\n");
					printf("����\n");
					scanf("%15s",names[i]);
					printf("ѧ��\n");
					scanf("%d",&number[i]);
					printf("�Ա�\n");
					scanf("%s",&xingbie[i]);
					printf("�绰����\n");
					scanf("%d",&phonenumber[i]);
					printf("��λ\n");
					scanf("%s",&danwei[i]);
					printf("��ַ\n");
					scanf("%d",&mail[i]);

					break;
				}
			}
			if(k==-1)
			{
				printf("�Բ���û�и�ѧ��");
			}


			break;
		case 6:// ��ѧ���޸�ĳ��ѧ����Ϣ
			printf("������Ҫ�޸�ѧ���ĵ绰���룺");
			scanf("%d",&temp);
			k=-2;
			for(i=0;i<n;++i)
			{
				if(temp==phonenumber[i])
				{
					k=i;
					printf("������Ҫ�޸ĵ���Ϣ��\n");
					printf("����\n");
					scanf("%15s",names[i]);
					printf("ѧ��\n");
					scanf("%d",&number[i]);
					printf("�Ա�\n");
					scanf("%s",&xingbie[i]);
					printf("�绰����\n");
					scanf("%d",&phonenumber[i]);
					printf("��λ\n");
					scanf("%s",&danwei[i]);
					printf("��ַ\n");
					scanf("%d",&mail[i]);
					break;		
				}
			}
			if(k==-2)
			{
				printf("�Բ���û�и�ѧ��");
			}
			break;
		case 7://������ɾ��ĳ��ѧ����Ϣ
			k=-3;
			printf("������Ҫɾ��ѧ����������");
			scanf("%s",&name);
			for(i=0;i<n;++i)
			{
				if(strcmp(name[i],names[i])==0)
				{
					k=i;
					for(j=i;j<=n-i-1;++j,++i)
					{
						strcpy(names[i],names[i+1]);//����
						number[i]=number[i+1];//ѧ��
						xingbie[i]=xingbie[i+1];//�Ա�
						phonenumber[i]=phonenumber[i+1];//�绰����
						danwei[i]=danwei[i+1];//��λ
						mail[i]=mail[i+1];//��ַ
						printf("ɾ���ɹ�");		
					}	
				}
			}
			n=n-1;
			printf("�������%dѧ����Ϣ(���֣��Ա�ѧ�ţ��绰���룬��λ����ַ)\n",n+1);
			printf("-------------------------------------\n");
			for(i=0;i<n;++i)
			{
				printf("\n15%s\t15%s\t15%d\t15%d\t15%s\t15%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("-------------------------------------\n");		
			}
			if
				(k==-3)
			{
				printf("ɾ��ʧ��");
			}



			break;
		case 8://���绰����ɾ��ĳ��ѧ����Ϣ
			k=-4;

			printf("������Ҫɾ��ѧ���ĵ绰����");
			scanf("%d",&temp);


			for(i=0;i<n;++i)
			{
				if(temp==phonenumber[i])
				{
					k=i;
					for(j=i;j<=n-i-1;++j,++i)
					{

						strcpy(names[i],names[i+1]);//����
						number[i]=number[i+1];//ѧ��
						xingbie[i]=xingbie[i+1];//�Ա�
						phonenumber[i]=phonenumber[i+1];//�绰����
						danwei[i]=danwei[i+1];//��λ
						mail[i]=mail[i+1];//��ַ
						printf("ɾ���ɹ�");
					}							
				}
			}
			n=n-1;
			printf("�������%dѧ����Ϣ(���֣��Ա�ѧ�ţ��绰���룬��λ����ַ)\n",n+1);
			printf("-------------------------------------\n");
			for(i=0;i<n;++i)
			{
				printf("\n15%s\t15%s\t15%d\t15%d\t15%s\t15%d\n",names[i],xingbie[i],number[i],phonenumber[i],danwei[i],mail[i]);
				printf("-------------------------------------\n");
			}
			printf("\n");

			if
				(k==-4)
			{
				printf("�Բ���û�и�ѧ��\n");
			}

			break;
		default:;
		}
	}
	printf("���������ллʹ�ã�");
	return 0;			

}

