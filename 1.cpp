#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct teacher
{
	long id;     //��ʦ��
	char name[20];  //����
	char sex[5];   //�Ա�
	char title[20];   //ְ��
	char curricula[20];   //�ν̿γ�
	int  cl;			//�༶
    int  classnumber;    //�༶��Ŀ
	double theory;   //���ۿ�ʱ
	double experiment;  //ʵ���ʱ
	double Hours;  //�ܿ�ʱ
	struct teacher *next;
}*head=NULL;
int n=0;   //¼��Ľ�ʦ����
void Teacher_Insert()  //��ӽ�ʦ�ڿ���Ϣ
{
	struct teacher *p1,*p2,*p3;
	p1=p2=(struct teacher*)malloc(sizeof(struct teacher));  //����һ���ṹ���ֽ����Ŀռ�
	printf("������һλ��ʦ�Ľ�ʦ�ţ�����¼��������0����");
	scanf("%ld",&p1->id);
	if(p1->id!=0)     //�ж��û���Ҫ����¼�뻹��Ҫ�洢��Ϣ
		if(head==NULL)
			head=p1;  //�ж������Ƿ�Ϊ�գ���������ͷָ��p1
		else        //��Ϊ��������βָ��p1
		{
			p3=head;   //������¼�����β��
			while(p3->next!=NULL)
				p3=p3->next;  //��p3��������β��p3ָ����һ�����
			p3->next=p1;   //�����һ�����ָ��p1
		}
		while(p1->id!=0)
		{
			printf("������");
			scanf("%s",p1->name);
			printf("�Ա�");
			scanf("%s",p1->sex);
			printf("ְ�ƣ�");
			scanf("%s",p1->title);
			printf("�ν̿γ̣�");
			scanf("%s",p1->curricula);
			printf("�༶��");
			scanf("%d",&p1->cl);
			printf("�༶��Ŀ��");
			scanf("%d",&p1->classnumber);
			printf("���ۿ�ʱ��");
			scanf("%Lf",&p1->theory);
			printf("ʵ���ʱ��");
			scanf("%Lf",&p1->experiment);
			n++;
			/*�ж��Ƿ�Ϊ��һ��¼�����Ϣ����������ͷָ��p1������p2ָ��p1*/
			if(n==1) 
				head=p1;
			else
				p2->next=p1;


			p2=p1;   //p2������¼��������һ�����
			p1=(struct teacher*)malloc(sizeof(struct teacher));
			printf("������һλ��ʦ�Ľ�ʦ�ţ�����¼��������0����");
			scanf("%ld",&p1->id);
		}
		p2->next=NULL;   //�����һ�����ָ���
		printf("�������\n");
}
void Teacher_Change()    //�޸Ľ�ʦ�ڿ���Ϣ
{
	struct teacher *p;
	long i;         //����ʱ������Ľ�ʦ��
	int x;                 
	long a;
	char b[20];
	char c[5];
	char d[20];
	char e[20];
	int f;
	int g;
	double h;
	double j;
	if(head==NULL)
		printf("��δ��ӽ�ʦ�ڿ���Ϣ\n");
	printf("��������Ҫ�޸Ľ�ʦ��Ϣ�Ľ�ʦ�ţ�");
	scanf("%ld",&i);
	for(p=head;p!=NULL;p=p->next)
		if(i==p->id)          //�ж��Ƿ���Ҫ�޸ĵĽ�ʦ�Ľ�ʦ��
		{
			printf("1. �޸Ľ�ʦ��\n2. �޸�����\n3. �޸��Ա�\n4. �޸�ְ��\n5. �޸��ν̿γ�\n6. �޸İ༶\n7. �޸İ༶��Ŀ\n8. �޸����ۿ�ʱ\n9. �޸�ʵ���ʱ\n10 .�޸�ȫ����Ϣ\n0. �˳�\n");
			scanf("%d",&x);
			while(x!=0)                 //ǰ��
			{
				if(x==1)
				{
					printf("�������޸ĺ�Ľ�ʦ�ţ�");
					scanf("%ld",&a);
					p->id=a;
				}
				if(x==2)
				{
					printf("�������޸ĺ��������");
					scanf("%s",b);
					strcpy(p->name,b);
				}
				if(x==3)
				{
					printf("�������޸ĺ���Ա�");
					scanf("%s",c);
					strcpy(p->sex,c);
				}
				if(x==4)
				{
					printf("�������޸ĺ��ְ�ƣ�");
					scanf("%s",d);
					strcpy(p->title,d);
				}
				if(x==5)
				{
				printf("�������޸ĺ���ν̿γ̣�");
				scanf("%s",e);
				strcpy(p->curricula,e);
				}
				if(x==6)
				{
					printf("�������޸ĺ�İ༶��");
					scanf("%d",&f);
					p->cl=f;
				}
				if(x==7)
				{
					printf("�������޸ĺ�İ༶��Ŀ��");
					scanf("%d",&g);
					p->classnumber=g;
				}
				if(x==8)
				{
					printf("�������޸ĺ�����ۿ�ʱ��");
					scanf("%Lf",&h);
					p->theory=h;
				}
				if(x==9)
				{
					printf("�������޸ĺ��ʵ���ʱ��");
					scanf("%Lf",&j);
					p->experiment=j;
				}
				if(x==10)
				{
					printf("�������޸ĺ�Ľ�ʦ�ţ�");
					scanf("%ld",&a);
					p->id=a;
					printf("�������޸ĺ��������");
					scanf("%s",b);
					strcpy(p->name,b);
					printf("�������޸ĺ���Ա�");
					scanf("%s",c);
					strcpy(p->sex,c);
					printf("�������޸ĺ��ְ�ƣ�");
					scanf("%s",d);
					strcpy(p->title,d);
					printf("�������޸ĺ���ν̿γ̣�");
					scanf("%s",d);
					strcpy(p->title,e);
					printf("�������޸ĺ�İ༶��");
					scanf("%d",&f);
					p->cl=f;
					printf("�������޸ĺ�İ༶��Ŀ��");
					scanf("%d",&g);
					p->classnumber=g;
					printf("�������޸ĺ�����ۿ�ʱ��");
					scanf("%Lf",&h);
					p->theory=h;
					printf("�������޸ĺ��ʵ���ʱ��");
					scanf("%Lf",&j);
					p->experiment=j;
				}
				printf("1. �޸Ľ�ʦ��\n2. �޸�����\n3. �޸�ְ��\n4. �޸��ν̿γ�\n5. �޸İ༶\n6. �޸İ༶��Ŀ\n7. �޸����ۿ�ʱ\n8. �޸�ʵ���ʱ\n9 .�޸�ȫ����Ϣ\n0. �˳�\n");
				scanf("%d",&x);
		}
		printf("δ���ҵ��ý�ʦ��Ϣ\n");
	}
}
void Teacher_Print()   //�����ʦ�ڿ���Ϣ
{
	struct teacher *p;
	int i;
	p=head;
	if(head!=NULL)
	{
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("|��ʦ��\t\t|����\t|�Ա�\t|ְ��    |�ν̿γ�\t\t|�༶��Ŀ|�༶|���ۿ�ʱ\t|ʵ���ʱ|\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		do
		{
		printf("|%-15ld|%-7s|%-7s|%-8s|%-22s|%-8d|%-4d|%-9Lf|%-12Lf\n",p->id,p->name,p->sex,p->title,p->curricula,p->classnumber,p->cl,p->theory,p->experiment);
		p=p->next;	
		}while(p!=NULL);
	}
	else
	{
		printf("��δ��ӽ�ʦ�ڿ���Ϣ!\n");
		printf("1. ��ӽ�ʦ�ڿ���Ϣ\n2. �˳�ϵͳ\n");
		scanf("%d",&i);
		while(i<1&&i>3)
		{
			printf("������Ч����������ȷ��:");
			scanf("%d",&i);
		}
		switch(i)
		{
		case 1:
			Teacher_Insert();
			break;
		case 2:
			exit(0);
			break;
		}
	}
}
void Teacher_Delete()    //ɾ����ʦ�ڿν�ѧ��Ϣ
{
	struct teacher *p1,*p2;
	long i;
	if(head==NULL)
		printf("��δ¼���ʦ�ڿν�ѧ��Ϣ\n");
	printf("������Ҫɾ����ʦ��Ϣ�Ľ�ʦ�ţ�\n");
	scanf("%ld",&i);
	p1=head;
	while(i!=p1->id)
	{
		if(p1->next==NULL)
			break;
		p2=p1;
		p1=p1->next;
	}
	if(i==p1->id)
	{
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;				//p1����ͷ��㣬��p1����Ľ�����ӵ�p1ǰһ�����ĺ���
		printf("�ɹ�ɾ��!\n");
		n--;
	}
	else printf("δ��Ѱ����ʦ��Ϊ%ld����Ϣ",i);
}
/*void Teacher_Sum()                    //���ܵĽ�ѧ������(������û�ĺ� ��������ɾ������)
{
	struct teacher *p;
	if(head==NULL)
		return;
	p=head;
	do
	{
	if(p->classnumber==2)
		p->Hours=(p->experiment+p->theory)*1.5;
	if(p->classnumber==3)
		p->Hours=(p->experiment+p->theory)*2;
	if(p->classnumber>=4)
		p->Hours=(p->experiment+p->theory)*2.5*p->classnumber;
	p=p->next;
	}while(p!=NULL);
	
}*/
void Teacher_search1()            //�����ֲ�ѯ��ʦ��Ϣ
{
	struct teacher *p;
	char s[20];
	if(head==NULL)
		printf("��δ��ӽ�ʦ�ڿν�ѧ��Ϣ\n");
	printf("����Ҫ���ҵĽ�ʦ������");
	scanf("%s",s);
	for(p=head;p!=NULL;p=p->next)
		if(strcmp(p->name,s)==0)
		{
			if(p->classnumber==2)
				p->Hours=(p->experiment+p->theory)*1.5;
			if(p->classnumber==3)
				p->Hours=(p->experiment+p->theory)*2;
			if(p->classnumber>=4)
				p->Hours=(p->experiment+p->theory)*2.5;
			printf("----------------------------------------------------------------------------------------------------------\n");
			printf("|��ʦ��\t\t|����\t|�Ա�\t|ְ��    |�ν̿γ�\t\t|�༶��Ŀ|�༶|���ۿ�ʱ\t|ʵ���ʱ|�ܹ�����\n");
			printf("|%-15ld|%-7s|%-7s|%-8s|%-22s|%-8d|%-4d|%-9Lf|%-8Lf|%-8Lf\n",p->id,p->name,p->sex,p->title,p->curricula,p->classnumber,p->cl,p->theory,p->experiment,p->Hours);
			printf("----------------------------------------------------------------------------------------------------------\n");
			return;
		}
	printf("δ���ҵ��ý�ʦ��Ϣ\n");
}
void Teacher_search2()     //����ʦ�Ų�ѯ��ʦ��Ϣ
{
	struct teacher *p;
	long i;
	if(head==NULL)
		printf("��δ��ӽ�ʦ�ڿν�ѧ��Ϣ\n");
	printf("����Ҫ���ҵĽ�ʦ��ʦ�ţ�");
	scanf("%ld",&i);
	for(p=head;p!=NULL;p=p->next)
		if(i==p->id)
		{
			if(p->classnumber==2)
				p->Hours=(p->experiment+p->theory)*1.5;
			if(p->classnumber==3)
				p->Hours=(p->experiment+p->theory)*2;
			if(p->classnumber>=4)
				p->Hours=(p->experiment+p->theory)*2.5;
			printf("----------------------------------------------------------------------------------------------------------\n");
			printf("|��ʦ��\t\t|����\t|�Ա�\t|ְ��    |�ν̿γ�\t\t|�༶��Ŀ|�༶|���ۿ�ʱ\t|ʵ���ʱ|�ܹ�����\n");
			printf("|%-15ld|%-7s|%-7s|%-8s|%-22s|%-8d|%-4d|%-9Lf|%-8Lf|%-8Lf\n",p->id,p->name,p->sex,p->title,p->curricula,p->classnumber,p->cl,p->theory,p->experiment,p->Hours);
			printf("----------------------------------------------------------------------------------------------------------\n");
			return;
		}
		printf("δ���ҵ��ý�ʦ��Ϣ\n");
}
void Teacher_Output()
{
	struct teacher *p1,*p2,*p3,*p4;
	int i,j;
	if(head==NULL)
	{
		printf("��δ¼���ʦ�ڿ���Ϣ\n");
		return;
	}
	if(head->next!=NULL)    //�ж��Ƿ�ֻ��һ����ʦ
	{
		p1=head;  //p1��¼�����Ƚϵ���������ǰһ��
		p2=head->next;  //p2��¼��һ��
		for(i=1;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			{
				/*�����ܹ�����*/
				if(p1->classnumber==2)
					p1->Hours=(p1->experiment+p1->theory)*1.5;
				if(p1->classnumber==3)
					p1->Hours=(p1->experiment+p1->theory)*2;
				if(p1->classnumber>=4)
					p1->Hours=(p1->experiment+p1->theory)*2.5;
				if(p2->classnumber==2)
					p2->Hours=(p2->experiment+p2->theory)*1.5;
				if(p2->classnumber==3)
					p2->Hours=(p2->experiment+p2->theory)*2;
				if(p2->classnumber>=4)
					p2->Hours=(p2->experiment+p2->theory)*2.5;



				if(p1->Hours<p2->Hours)   //�Ƚ��ܹ���������P1�ܹ������ϴ�ʱ�Ե���������λ��
				{
					if(p1==head)
						head=p2;  //p1Ϊͷʱ��ͷָ��ָ��p2
					else
						p3->next=p2;  //����p2���ӵ�������¼p1ǰһ������p3����
					p4=p2->next;   //p4������¼p2����Ľ��
					p2->next=p1;   //p1�Ľ�㻻��ԭ��p2��λ��
					p1->next=p4;   //ԭ��p2����Ľ�����ӵ�p1
					p3=p2;		  //p3��¼��p2��λ��
					p2=p4;        //p2ָ��ԭ��λ�õ���һ�����
				}
				else    //p1���ܹ�������С����p1��p2��ָ�����Ǹ���λ�õ���һ�����
				{
					p3=p1;  //��¼p1����һλ����ǰ������λ��
					p1=p2;
					p2=p2->next;
				}
			}
			p1=head;   //ָ������ͷ����ʼ��һ����ѭ��
			p2=p1->next;  //ָ������ڶ������
		}
	}
	struct teacher *p;
	p=head;
	if(head!=NULL)
	{
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("|��ʦ��\t\t|����\t|�Ա�\t|ְ��    |�ν̿γ�\t\t|�༶��Ŀ|�༶|���ۿ�ʱ\t|ʵ���ʱ|�ܹ�����\n");
		printf("----------------------------------------------------------------------------------------------------------\n");
		do
		{
			
		if(p->classnumber==2)
			p->Hours=(p->experiment+p->theory)*1.5;
		if(p->classnumber==3)
			p->Hours=(p->experiment+p->theory)*2;
		if(p->classnumber>=4)
			p->Hours=(p->experiment+p->theory)*2.5;
		printf("|%-15ld|%-7s|%-7s|%-8s|%-22s|%-8d|%-4d|%-9Lf|%-8Lf|%-8Lf\n",p->id,p->name,p->sex,p->title,p->curricula,p->classnumber,p->cl,p->theory,p->experiment,p->Hours);
		p=p->next;	
		}while(p!=NULL);
	}
}
void main()
{
    int choice;
    while(1)  
    {  
        /*���˵�*/  
        printf("************************************************\n"); 
		printf("*             ��ʦ����������ϵͳ               *\n");
		printf("************************************************\n");
        printf("*  1. ��ӽ�ʦ�ڿν�ѧ��Ϣ                     *\n");  
        printf("*  2. �޸Ľ�ʦ�ڿν�ѧ��Ϣ                     *\n");
		printf("*  3. �����ʦ�ڿν�ѧ��Ϣ                     *\n");
        printf("*  4. ɾ����ʦ�ڿν�ѧ��Ϣ                     *\n");  
        printf("*  5. ��������ѯ��ʦ��Ϣ                       *\n");  
        printf("*  6. ����ʦ�Ų�ѯ��ʦ��Ϣ                     *\n");
		printf("*  7. �����ʦ��Ϣ�����ܹ�����������           *\n");
        printf("*  0. �˳�                                     *\n");
		printf("************************************************\n");
        printf("��ѡ��(0-7):");  

        scanf("%d",&choice);  
        getchar();  
        switch(choice)  
        { 
        case 1:  
            Teacher_Insert();  
            break;
		case 2:
			Teacher_Change();
		case 3:
			Teacher_Print();
			break;
		case 4:
			Teacher_Delete();
			break;
		case 5:
			Teacher_search1();
			break;
		case 6:
			Teacher_search2();
			break;
		case 7:
			Teacher_Output();
			break;
        case 0: 
            exit(0);  
            break;  
        } 
	}
}