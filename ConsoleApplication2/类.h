#ifndef ��_h_
#define ��_h_
#pragma warning(disable:4996)
#include<iostream>
#include<fstream>
#include<string.h>
#include<list>
using namespace std;
class library
{
public:
	int id;//���
	char name[20];//��Ʒ����
	char writer[20];//����
	void input();//���������Ϣ
	void show();//���������Ϣ
	library()
	{
		id = 0;
		strcpy(name, "0");
		strcpy(writer, "0");
	}
};
class book :public library
{
private:
	char book_chuban[20];//������
	char book_ISBN[20];//ISBN��
	int book_page;//ҳ��
public:
	int n_b = 0;  //�鱾��Ϣ����
	void input();//������Ʒ��Ϣ(ͬ������)
	void show();//�����Ʒ����Ϣ��ͬ�����ǣ�
	book()
	{
		strcpy(book_chuban, "0");
		strcpy(book_ISBN, "0");
		book_page = 0;
	}
	friend class gongneng;
};
class vcd :public library
{
private:
	char vcd_chuping[20];//��Ʒ��
	char vcd_year[10];//��Ʒ���
	char vcd_hour[10];//��Ƶʱ��
public:
	int n_v = 0;  //������Ϣ����
	void input();//���������Ϣ��ͬ�����ǣ�
	void show();//���������Ϣ��ͬ�����ǣ�
	vcd()
	{
		strcpy(vcd_chuping, "0");
		strcpy(vcd_year, "0");
		strcpy(vcd_hour, "0");
	}
	friend class gongneng;
};
class gongneng
{
private:
	list<book> bk;
	list<vcd> vc;
public:
	int menu();//�˵�
	void tadd();//�����Ϣ
	void add_book();//����鱾��Ϣ
	void add_vcd();//��ӹ�����Ϣ
	void tfind();//��ѯ��Ʒ��Ϣ
	void find_name();//�����ֲ�ѯ
	void find_id();//����Ų�ѯ
	void find_lei();//������ѯ
	void show();//��ʾ��Ʒ��
	void change();//�޸���Ʒ��Ϣ
	void delet();//ɾ����Ʒ��Ϣ
	void read_bookf();//��book�ļ�
	void read_vcdf();//��vcd�ļ�
	void recv_bookf();//����book�ļ�
	void recv_vcdf();//����vcd�ļ�
};
#endif