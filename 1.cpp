#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct teacher
{
	long id;     //教师号
	char name[20];  //名字
	char sex[5];   //性别
	char title[20];   //职称
	char curricula[20];   //任教课程
	int  cl;			//班级
    int  classnumber;    //班级数目
	double theory;   //理论课时
	double experiment;  //实验课时
	double Hours;  //总课时
	struct teacher *next;
}*head=NULL;
int n=0;   //录入的教师人数
void Teacher_Insert()  //添加教师授课信息
{
	struct teacher *p1,*p2,*p3;
	p1=p2=(struct teacher*)malloc(sizeof(struct teacher));  //申请一个结构体字节数的空间
	printf("请输入一位教师的教师号（结束录入请输入0）：");
	scanf("%ld",&p1->id);
	if(p1->id!=0)     //判断用户是要结束录入还是要存储信息
		if(head==NULL)
			head=p1;  //判断链表是否为空，是则将链表头指向p1
		else        //不为空则将链表尾指向p1
		{
			p3=head;   //用来记录链表的尾部
			while(p3->next!=NULL)
				p3=p3->next;  //若p3不是链表尾则将p3指向下一个结点
			p3->next=p1;   //将最后一个结点指向p1
		}
		while(p1->id!=0)
		{
			printf("姓名：");
			scanf("%s",p1->name);
			printf("性别：");
			scanf("%s",p1->sex);
			printf("职称：");
			scanf("%s",p1->title);
			printf("任教课程：");
			scanf("%s",p1->curricula);
			printf("班级：");
			scanf("%d",&p1->cl);
			printf("班级数目：");
			scanf("%d",&p1->classnumber);
			printf("理论课时：");
			scanf("%Lf",&p1->theory);
			printf("实验课时：");
			scanf("%Lf",&p1->experiment);
			n++;
			/*判断是否为第一个录入的信息，是则将链表头指向p1，否则将p2指向p1*/
			if(n==1) 
				head=p1;
			else
				p2->next=p1;


			p2=p1;   //p2用来记录链表的最后一个结点
			p1=(struct teacher*)malloc(sizeof(struct teacher));
			printf("请输入一位教师的教师号（结束录入请输入0）：");
			scanf("%ld",&p1->id);
		}
		p2->next=NULL;   //将最后一个结点指向空
		printf("输入完成\n");
}
void Teacher_Change()    //修改教师授课信息
{
	struct teacher *p;
	long i;         //查找时候输入的教师号
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
		printf("尚未添加教师授课信息\n");
	printf("请输入需要修改教师信息的教师号：");
	scanf("%ld",&i);
	for(p=head;p!=NULL;p=p->next)
		if(i==p->id)          //判断是否是要修改的教师的教师号
		{
			printf("1. 修改教师号\n2. 修改姓名\n3. 修改性别\n4. 修改职称\n5. 修改任教课程\n6. 修改班级\n7. 修改班级数目\n8. 修改理论课时\n9. 修改实验课时\n10 .修改全部信息\n0. 退出\n");
			scanf("%d",&x);
			while(x!=0)                 //前哨
			{
				if(x==1)
				{
					printf("请输入修改后的教师号：");
					scanf("%ld",&a);
					p->id=a;
				}
				if(x==2)
				{
					printf("请输入修改后的姓名：");
					scanf("%s",b);
					strcpy(p->name,b);
				}
				if(x==3)
				{
					printf("请输入修改后的性别：");
					scanf("%s",c);
					strcpy(p->sex,c);
				}
				if(x==4)
				{
					printf("请输入修改后的职称：");
					scanf("%s",d);
					strcpy(p->title,d);
				}
				if(x==5)
				{
				printf("请输入修改后的任教课程：");
				scanf("%s",e);
				strcpy(p->curricula,e);
				}
				if(x==6)
				{
					printf("请输入修改后的班级：");
					scanf("%d",&f);
					p->cl=f;
				}
				if(x==7)
				{
					printf("请输入修改后的班级数目：");
					scanf("%d",&g);
					p->classnumber=g;
				}
				if(x==8)
				{
					printf("请输入修改后的理论课时：");
					scanf("%Lf",&h);
					p->theory=h;
				}
				if(x==9)
				{
					printf("请输入修改后的实验课时：");
					scanf("%Lf",&j);
					p->experiment=j;
				}
				if(x==10)
				{
					printf("请输入修改后的教师号：");
					scanf("%ld",&a);
					p->id=a;
					printf("请输入修改后的姓名：");
					scanf("%s",b);
					strcpy(p->name,b);
					printf("请输入修改后的性别：");
					scanf("%s",c);
					strcpy(p->sex,c);
					printf("请输入修改后的职称：");
					scanf("%s",d);
					strcpy(p->title,d);
					printf("请输入修改后的任教课程：");
					scanf("%s",d);
					strcpy(p->title,e);
					printf("请输入修改后的班级：");
					scanf("%d",&f);
					p->cl=f;
					printf("请输入修改后的班级数目：");
					scanf("%d",&g);
					p->classnumber=g;
					printf("请输入修改后的理论课时：");
					scanf("%Lf",&h);
					p->theory=h;
					printf("请输入修改后的实验课时：");
					scanf("%Lf",&j);
					p->experiment=j;
				}
				printf("1. 修改教师号\n2. 修改姓名\n3. 修改职称\n4. 修改任教课程\n5. 修改班级\n6. 修改班级数目\n7. 修改理论课时\n8. 修改实验课时\n9 .修改全部信息\n0. 退出\n");
				scanf("%d",&x);
		}
		printf("未查找到该教师信息\n");
	}
}
void Teacher_Print()   //浏览教师授课信息
{
	struct teacher *p;
	int i;
	p=head;
	if(head!=NULL)
	{
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("|教师号\t\t|姓名\t|性别\t|职称    |任教课程\t\t|班级数目|班级|理论课时\t|实验课时|\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		do
		{
		printf("|%-15ld|%-7s|%-7s|%-8s|%-22s|%-8d|%-4d|%-9Lf|%-12Lf\n",p->id,p->name,p->sex,p->title,p->curricula,p->classnumber,p->cl,p->theory,p->experiment);
		p=p->next;	
		}while(p!=NULL);
	}
	else
	{
		printf("尚未添加教师授课信息!\n");
		printf("1. 添加教师授课信息\n2. 退出系统\n");
		scanf("%d",&i);
		while(i<1&&i>3)
		{
			printf("输入无效，请输入正确项:");
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
void Teacher_Delete()    //删除教师授课教学信息
{
	struct teacher *p1,*p2;
	long i;
	if(head==NULL)
		printf("尚未录入教师授课教学信息\n");
	printf("请输入要删除教师信息的教师号：\n");
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
			p2->next=p1->next;				//p1不是头结点，将p1后面的结点连接到p1前一个结点的后面
		printf("成功删除!\n");
		n--;
	}
	else printf("未搜寻到教师号为%ld的信息",i);
}
/*void Teacher_Sum()                    //算总的教学工作量(有问题没改好 垃圾函数删掉算了)
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
void Teacher_search1()            //按名字查询教师信息
{
	struct teacher *p;
	char s[20];
	if(head==NULL)
		printf("尚未添加教师授课教学信息\n");
	printf("输入要查找的教师姓名：");
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
			printf("|教师号\t\t|姓名\t|性别\t|职称    |任教课程\t\t|班级数目|班级|理论课时\t|实验课时|总工作量\n");
			printf("|%-15ld|%-7s|%-7s|%-8s|%-22s|%-8d|%-4d|%-9Lf|%-8Lf|%-8Lf\n",p->id,p->name,p->sex,p->title,p->curricula,p->classnumber,p->cl,p->theory,p->experiment,p->Hours);
			printf("----------------------------------------------------------------------------------------------------------\n");
			return;
		}
	printf("未查找到该教师信息\n");
}
void Teacher_search2()     //按教师号查询教师信息
{
	struct teacher *p;
	long i;
	if(head==NULL)
		printf("尚未添加教师授课教学信息\n");
	printf("输入要查找的教师教师号：");
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
			printf("|教师号\t\t|姓名\t|性别\t|职称    |任教课程\t\t|班级数目|班级|理论课时\t|实验课时|总工作量\n");
			printf("|%-15ld|%-7s|%-7s|%-8s|%-22s|%-8d|%-4d|%-9Lf|%-8Lf|%-8Lf\n",p->id,p->name,p->sex,p->title,p->curricula,p->classnumber,p->cl,p->theory,p->experiment,p->Hours);
			printf("----------------------------------------------------------------------------------------------------------\n");
			return;
		}
		printf("未查找到该教师信息\n");
}
void Teacher_Output()
{
	struct teacher *p1,*p2,*p3,*p4;
	int i,j;
	if(head==NULL)
	{
		printf("尚未录入教师授课信息\n");
		return;
	}
	if(head->next!=NULL)    //判断是否只有一个老师
	{
		p1=head;  //p1记录用来比较的两个结点的前一个
		p2=head->next;  //p2记录后一个
		for(i=1;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			{
				/*计算总工作量*/
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



				if(p1->Hours<p2->Hours)   //比较总工作量，当P1总工作量较大时对调两个结点的位置
				{
					if(p1==head)
						head=p2;  //p1为头时将头指针指向p2
					else
						p3->next=p2;  //否则将p2链接到用来记录p1前一个结点的p3后面
					p4=p2->next;   //p4用来记录p2后面的结点
					p2->next=p1;   //p1的结点换到原来p2的位置
					p1->next=p4;   //原来p2后面的结点链接到p1
					p3=p2;		  //p3记录下p2的位置
					p2=p4;        //p2指向原来位置的下一个结点
				}
				else    //p1的总工作量较小，则将p1，p2都指向他们各自位置的下一个结点
				{
					p3=p1;  //记录p1后移一位后他前个结点的位置
					p1=p2;
					p2=p2->next;
				}
			}
			p1=head;   //指向链表头，开始下一趟外循环
			p2=p1->next;  //指向链表第二个结点
		}
	}
	struct teacher *p;
	p=head;
	if(head!=NULL)
	{
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("|教师号\t\t|姓名\t|性别\t|职称    |任教课程\t\t|班级数目|班级|理论课时\t|实验课时|总工作量\n");
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
        /*主菜单*/  
        printf("************************************************\n"); 
		printf("*             教师工作量管理系统               *\n");
		printf("************************************************\n");
        printf("*  1. 添加教师授课教学信息                     *\n");  
        printf("*  2. 修改教师授课教学信息                     *\n");
		printf("*  3. 浏览教师授课教学信息                     *\n");
        printf("*  4. 删除教师授课教学信息                     *\n");  
        printf("*  5. 按姓名查询教师信息                       *\n");  
        printf("*  6. 按教师号查询教师信息                     *\n");
		printf("*  7. 输出教师信息（按总工作量排名）           *\n");
        printf("*  0. 退出                                     *\n");
		printf("************************************************\n");
        printf("请选择(0-7):");  

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