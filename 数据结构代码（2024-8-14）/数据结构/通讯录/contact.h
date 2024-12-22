#define _CRT_SECURE_NO_DEPRECATE
#define MAX_PEOPLE 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 15
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//�˵�
enum menu
{
	Exit = 0,
	add = 1,
	del=2,
	search=3,
	modify=4,
	show=5
};
//������Ϣ
typedef struct People
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}People;
//ͨѶ¼��Ϣ
typedef struct Contact
{
	People info[MAX_PEOPLE];
	int size;
}Contact;
//��������
void Check_Capicity(Contact* ps);
//��ӡ�˵�
void menu();
//��ʼ��ͨѶ¼
void Init_Contact(Contact* ps);
//�Ӻ���
void Add_Contact(Contact* ps);
//չʾ��ǰ��Ϣ
void Show_Contact(const Contact* ps);
//ɾ������
void Del_Contact(Contact* ps);
//��������
void Search_Contact(const Contact* ps);
//�޸���ϵ��
void Modify(Contact* ps);