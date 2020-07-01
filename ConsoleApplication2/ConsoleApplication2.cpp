#pragma warning(disable:4996)
#include"类.h"
#include<iostream>
#include<list>
#include<string.h>
#include<fstream>
void library::input()
{
	cout << "|    编号    |" << "     名称     |" << "    作者    |" << endl;
	cin >> id >> name >> writer;
}
void library::show()
{
	cout << "|    编号    |" << "     名称     |" << "    作者    |" << endl;
	cout << id << name << writer;
}
void book::input()
{
	library::input();
	cin>>book_chuban>>book_ISBN>>book_page;
}
void book::show()
{
	library::show();
	cout <<book_chuban << book_ISBN << book_page<<endl;
}
void vcd::input()
{
	library::input();
	cin >> vcd_chuping >> vcd_year >> vcd_hour;
}
void vcd::show()
{
	library::show();
	cout<< vcd_chuping << vcd_year << vcd_hour<<endl;
}
void gongneng::read_bookf()
{
	ifstream infile("D:\\book.txt", ios::in);
	book b;
	if (!infile)
	{
		cout << "read fail" << endl;
		return;
	}
	char temp[20];
	while (!infile.eof())
	{
		infile.getline(temp, '\n');
		b.id = atoi(temp);
		memset(temp, 0, 20);
		infile.getline(b.name, '\n');
		infile.getline(temp, '\n');
		b.book_page = atoi(temp);
		memset(temp, 0, 20);
		infile.getline(b.writer, '\n');
		infile.getline(b.book_chuban, '\n');
		infile.getline(b.book_ISBN, '\n');
		if (infile.eof())
		{
			break;
		}
		b.n_b++;
		bk.push_back(b);
	}
	infile.close();
}
void gongneng::read_vcdf()
{
	ifstream infile("D:\\vcd.txt", ios::in);
	vcd v;
	if (!infile)
	{
		cout << "read fail" << endl;
		return;
	}
	char temp[20];
	while (!infile.eof())
	{
		infile.getline(temp, '\n');
		v.id = atoi(temp);
		memset(temp, 0, 20);
		infile.getline(v.name, '\n');
		infile.getline(v.writer, '\n');
		infile.getline(v.vcd_chuping, '\n');
		infile.getline(v.vcd_hour, '\n');
		infile.getline(v.vcd_year, '\n');
		if (infile.eof())
		{
			break;
		}
		v.n_v++;
		vc.push_back(v);
	}
	infile.close();
}
void gongneng::recv_bookf()
{
	ofstream outfile("D:\\book.txt", ios::out);
	if (!outfile)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	list<book>::iterator p = bk.begin();
	while (p != bk.end())
	{
		outfile << p->id << endl;
		outfile << p->name << endl;
		outfile << p->book_page<< endl;
		outfile << p->writer << endl;
		outfile << p->book_chuban << endl;
		outfile << p->book_ISBN<< endl;
		p++;
	}
	cout << "保存完成！" << endl;
	outfile.close();
}
void gongneng::recv_vcdf()
{
	ofstream outfile("D:\\vcd.txt", ios::out);
	if (!outfile)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	list<vcd>::iterator p = vc.begin();
	while (p != vc.end())
	{
		outfile << p->id << endl;
		outfile << p->name << endl;
		outfile << p->writer << endl;
		outfile << p->vcd_chuping << endl;
		outfile << p->vcd_hour << endl;
		outfile << p->vcd_year << endl;
		p++;
	}
	cout << "保存完成！" << endl;
	outfile.close();
}
int gongneng::menu()   //主菜单函数
{
	int choice;
	while (1)
	{
		cout << "============================================" << endl;
		cout << "*              物品信息管理                *" << endl;
		cout << "*------------------------------------------*" << endl;
		cout << "*  1、添加物品信息       2、显示物品信息   *" << endl;
		cout << "*------------------------------------------*" << endl;
		cout << "*  3、查询物品信息       4、修改物品信息   *" << endl;
		cout << "*------------------------------------------*" << endl;
		cout << "*  5、删除图书信息       0、退出           *" << endl;
		cout << "*------------------------------------------*" << endl;
		cout << "请输入选择:";
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				tadd();
				break;
			}
			case 2:
			{
				show();
				break;
			}
			case 3:
			{
				tfind();
				break;
			}
			case 4:
			{
				change();
				break;
			}
			case 5:
			{
				delet();
				break;
			}

			case 0:
			{
				recv_bookf();
				recv_vcdf();
				exit(0);
			}
		}
	}
		return 0;
}
void gongneng::tadd()//添加信息（小菜单）
	{
		int choice;
		cout << "请选择需要添加的物品信息种类" << endl << "1.图书" << endl << "2.光盘" << endl << "0.返回上一级" << endl << "请输入选择：";
		cin >> choice;
		while (choice != 0 && choice != 1 && choice != 2)
		{
			cout << "输入有误，请重新输入:";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			add_book();
			break;
		}
		case 2:
		{
			add_vcd();
			break;
		}
		case 0:
		{
			menu();
			break;
		}
		}
	}
void gongneng::add_book()//添加图书信息
{
	book b;
	list<book>::iterator p1;  //图书链表迭代器						   
	list<vcd>::iterator p2;   //光盘链表迭代器
		b.input();
		int j = b.id;        //定义一个j来保存输入的编号方便后面进行重复对比
		/*进行编号是否重复查询*/
		for(p1 = bk.begin();p1 != bk.end();p1++)
		{
			if (p1->id == b.id)
			{
				cout << "输入编号重复！" << endl << "请重新输入书本信息：" << endl;
				b.input();
				while (b.id == j)
				{
					cout << "输入编号重复！" << endl << "请重新输入书本信息：" << endl;
					b.input();
				}
				break;

			}
				
		}
		for (p2 = vc.begin(); p2 != vc.end(); p2++)
		{
			if (p2->id == b.id)
			{
				cout << "输入编号重复！" << endl << "请重新输入书本信息：" << endl;
				b.input();
				while (b.id == j)
				{
					cout << "输入编号重复！" << endl << "请重新输入书本信息：" << endl;
					b.input();
				}
				break;
			}
		}
		/*查询结束*/
		bk.push_back(b);  //尾插
	cout << "添加成功！";
	b.n_b++;   //书本个数加1
	cout << "是否继续添加书本信息(Y/N):";
	char x;
	cin >> x;
	while (x != 'Y' && x != 'N')
	{
		cout << "输入有误，请重新输入:";
		cin >> x;
	}
	if (x == 'Y')
	{
		add_book();
	}
	if (x == 'N')
	{
		int c;
		cout << "1.返回上一级" << endl << "2.返回主菜单" << endl;
		cout << "请输入选择：";
		cin >> c;
		switch (c)
		{
			case 1:
			{
				tadd();
				break;
			}
			case 2:
			{
				menu();
				break;
			}
		}
	}
}
void gongneng::add_vcd()//添加光盘信息
{
	vcd v;
	list<book>::iterator p1;
	list<vcd>::iterator p2 ;
	v.input();
	int j = v.id;
	for (p1 = bk.begin(); p1 != bk.end();p1++)
	{
		if (p1->id == v.id)
		{
			cout << "输入编号重复！" << endl << "请重新输入光盘信息：" << endl;
			v.input();
			while(v.id == j)
			{
				cout << "输入编号重复！" << endl << "请重新输入光盘信息：" << endl;
				v.input();
			}
			break;
		}
	}
	for (p2 = vc.begin();p2 != vc.end();p2++)
	{
		if (p2->id == v.id)
		{
			cout << "输入编号重复！" << endl << "请重新输入光盘信息：" << endl;
			v.input();
			while (v.id == j)
			{
				cout << "输入编号重复！" << endl << "请重新输入光盘信息：" << endl;
				v.input();
			}
			break;
		}
	}
	vc.push_back(v);
	cout << "添加成功！";
	v.n_v++;   //光盘个数加1
	cout << "是否继续添加光盘信息(Y/N):";
	char x;
	cin >> x;
	while (x != 'Y' && x != 'N')
	{
		cout << "输入有误，请重新输入:";
		cin >> x;
	}
	if (x == 'Y')
	{
		add_vcd();
	}
	if (x == 'N')
	{
		int c;
		cout << "1.返回上一级" << endl << "2.返回主菜单" << endl;
		cout << "请输入选择：";
		cin >> c;
		switch (c)
		{
		case 1:
		{
			tadd();
			break;
		}
		case 2:
		{
			menu();
			break;
		}
		}
	}
}
void gongneng::tfind() //查询函数（小菜单）
{
	int choice;
	book b;
	vcd v;
	if (b.n_b == 0 && v.n_v == 0)
	{
		int c;
		cout << "物品库无信息！" << endl;
		cout << "1.添加信息" << endl << "2.返回主菜单" << endl << "请输入选择：";
		cin >> c;
		switch (c)
		{
			case 1:
			{
				tadd();
				break;
			}
			case 2:
			{
				menu();
				break;
			}
		}
	}
	else
	{
		cout << "请选择查询方式：" << endl << "1.按名字查询" << endl << "2.按编号查询" << endl << "3.按类别查询" << endl << "0.返回上一级" << endl << "请输入选择：";
		cin >> choice;
		while (choice != 0 && choice != 1 && choice != 2 && choice != 3)
		{
			cout << "输入有误，请重新输入:";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			find_name();
			break;
		}
		case 2:
		{
			find_id();
			break;
		}
		case 3:
		{
			find_lei();
			break;
		}
		case 0:
		{
			menu();
			break;
		}
		}
	}
}
void gongneng::find_name()//按名称查找
{
	char pname[20];
	int flag = 0;
	list<book>::iterator p1;
	list<vcd>::iterator p2;
	cout << "请输入名字：";
	cin >> pname;
	for (p1 = bk.begin(); p1 != bk.end(); p1++)
	{
		if (strcmp(p1->name, pname) == 0)
		{
			p1->show();
			flag = 1;
			break;
		}
	}
	for (p2 = vc.begin(); p2 != vc.end(); p2++)
	{
		if (flag == 1)
			break;
		if (strcmp(p2->name, pname) == 0)
		{
			p2->show();
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "未查找到该名字的物品！"<<endl;
	}
	int choice;
	cout << "1.继续查找" << endl << "2.返回上一级" << endl << "0.返回主菜单" << endl << "请输入选择：";
	cin >> choice;
	while (1)
	{
		if (choice == 1 || choice == 2 || choice == 0)
			break;
		else
		{
			cout << "输入错误，请重新输入：";
			cin >> choice;
		}
	}
	switch (choice)
	{
		case 1:
		{
			find_name();
			break;
		}
		case 2:
		{
			tfind();
			break;
		}
		case 0:
		{
			menu();
			break;
		}
	}
}
void gongneng::find_id()//按编号查找
{
	int pid;
	int flag = 0;
	list<book>::iterator p1;
	list<vcd>::iterator p2;
	cout << "请输入编号：";
	cin >> pid;
	for (p1 = bk.begin(); p1 != bk.end(); p1++)
	{
		if (p1->id==pid)
		{
			p1->show();
			flag = 1;
			break;
		}
	}
	for (p2 = vc.begin(); p2 != vc.end(); p2++)
	{
		if (flag == 1)
			break;
		if (p2->id==pid)
		{
			p2->show();
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "未查找到该编号的物品！" << endl;
	}
	int choice;
	cout << "1.继续查找" << endl << "2.返回上一级" << endl << "0.返回主菜单" << endl << "请输入选择：";
	cin >> choice;
	while (1)
	{
		if (choice == 1 || choice == 2 || choice == 0)
			break;
		else
		{
			cout << "输入错误，请重新输入：";
			cin >> choice;
		}
	}
	switch (choice)
	{
		case 1:
		{
			find_id();
			break;
		}
		case 2:
		{
			tfind();
			break;
		}
		case 0:
		{
			menu();
			break;
		}
	}
}
void gongneng::find_lei()//按类别查找
{
	int plei;
	list<book>::iterator p1;
	list<vcd>::iterator p2;
	cout << "1.图书类" << endl << "2.光盘类" << endl<< "请输入选择：";
	cin >> plei;
	if (plei == 1)
	{
		for (p1 = bk.begin(); p1 != bk.end(); p1++)
		{
			p1->show();
		}
	}
	if (plei == 2)
	{
		for (p2 = vc.begin(); p2 != vc.end(); p2++)
		{
			p2->show();
		}
	}
}
void gongneng::show()//显示信息函数
{
	list<book>::iterator p1;
	list<vcd>::iterator p2;
	cout << "图书:" << endl;
	for (p1 = bk.begin(); p1 != bk.end(); p1++)
	{
		p1->show();
	}
	cout << "光盘:" << endl;
	for (p2 = vc.begin(); p2 != vc.end(); p2++)
	{
		p2->show();
	}
	cout << "0.返回上一级" << endl;
	int choice;
	cin >> choice;
	if (choice == 0)
		menu();
}
void gongneng::change()
{
	int pid;
	int flag = 0;
	int bid, vid;
	list<book>::iterator p1,p3;
	list<vcd>::iterator p2,p4;
	cout << "请输入编号：";
	cin >> pid;
	for (p1 = bk.begin(); p1 != bk.end(); p1++)
	{
		if (p1->id == pid)
		{
			/*验证编号重复性*/
			cout << "请确认修改后的物品编号：";
			cin >> bid;
			for (p3 = bk.begin(); p3 != bk.end(); p3++)
			{
				if (p3->id == bid)
				{
					cout << "输入编号重复！" << endl << "请重新确认物品编号：" << endl;
					cin >> bid;
					int j = bid;
					while (bid == j)
					{
						cout << "输入编号重复！" << endl << "请重新确认物品编号：" << endl;
						cin >> bid;
					}
					break;
				}
			}
			for (p4 = vc.begin(); p4 != vc.end(); p4++)
			{
				if (p4->id == bid)
				{
					cout << "输入编号重复！" << endl << "请重新确认物品编号：" << endl;
					cin >> bid;
					int k = bid;
					while (bid == k)
					{
						cout << "输入编号重复！" << endl << "请重新确认物品编号：" << endl;
						cin >> bid;
					}
					break;
				}
			}
			/*验证完成*/
			cout << "请输入修改后的物品信息：" << endl;
			p1->input();
			while (p1->id != bid)
			{
				cout << "请保证编号与确定的一致！" << endl << "请输入修改后的物品信息：" << endl;
				p1->input();
			}
			cout << "修改成功！"<<endl;
			flag = 1;
			break;
		}
	}
	for (p2 = vc.begin(); p2 != vc.end(); p2++)
	{
		if (flag == 1)
			break;
		if (p2->id == pid)
		{
			cout << "请确认物品编号：";
			cin >> vid;
			for (p3 = bk.begin(); p3 != bk.end(); p3++)
			{
				if (p3->id == vid)
				{
					cout << "输入编号重复！" << endl << "请重新确认物品编号：" << endl;
					cin >> vid;
					int x = vid;
					while (vid == x)
					{
						cout << "输入编号重复！" << endl << "请重新确认物品编号：" << endl;
						cin >> vid;
					}
					break;
				}
			}
			for (p4 = vc.begin(); p4 != vc.end(); p4++)
			{
				if (p4->id == vid)
				{
					cout << "输入编号重复！" << endl << "请重新确认物品编号：" << endl;
					cin >> vid;
					int y = vid;
					while (vid == y)
					{
						cout << "输入编号重复！" << endl << "请重新确认物品编号：" << endl;
						cin >> vid;
					}
					break;
				}
			}
			cout << "请输入修改后的物品信息：" << endl;
			p2->input();
			while (p2->id != vid)
			{
				cout << "请保证编号与确定的一致！"<<endl<<"请输入修改后的物品信息："<<endl;
				p2->input();
			}
			cout << "修改成功！"<<endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "未查找到该编号的物品！" << endl;
	}
}
void gongneng::delet()
{
	int pid;
	int flag = 0;
	list<book>::iterator p1;
	list<vcd>::iterator p2;
	cout << "请输入编号：";
	cin >> pid;
	for (p1 = bk.begin(); p1 != bk.end(); p1++)
	{
		if (p1->id == pid)
		{
			bk.erase(p1);
			cout << "删除成功！";
			flag = 1;
			break;
		}
	}
	for (p2 = vc.begin(); p2 != vc.end(); p2++)
	{
		if (flag == 1)
			break;
		if (p2->id == pid)
		{
			vc.erase(p2);
			cout << "删除成功！";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "未查找到该编号的物品！" << endl;
	}
}
int main()
{
	gongneng g;
	g.read_bookf();
	g.read_vcdf();
	g.menu();
	return 0;
}