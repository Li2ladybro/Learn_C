#define _CRT_SECURE_NO_DEPRECATE
#define MAX_PEOPLE 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 15
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//菜单
enum menu
{
	Exit = 0,
	add = 1,
	del=2,
	search=3,
	modify=4,
	show=5
};
//个人信息
typedef struct People
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}People;
//通讯录信息
typedef struct Contact
{
	People info[MAX_PEOPLE];
	int size;
}Contact;
//扩大容量
void Check_Capicity(Contact* ps);
//打印菜单
void menu();
//初始化通讯录
void Init_Contact(Contact* ps);
//加好友
void Add_Contact(Contact* ps);
//展示当前信息
void Show_Contact(const Contact* ps);
//删除好友
void Del_Contact(Contact* ps);
//搜索好友
void Search_Contact(const Contact* ps);
//修改联系人
void Modify(Contact* ps);