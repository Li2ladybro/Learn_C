#include"contact.h"
//��ӡ�˵�
void menu()
{
	printf("***************************************\n");
	printf("*********1. add********2. del**********\n");
	printf("*********3. search*****4. modify*******\n");
	printf("*********5. show*******0. Exit*********\n");
	printf("***************************************\n");
}
//��������
void Check_Capicity(Contact* ps)
{
	if (ps->size >= MAX_PEOPLE)
	{
		ps->size *= 2;
		realloc(ps, sizeof(People) * ps->size);
	}
	if (ps == NULL)
	{
		printf("����ʧ��\n");
	}

}
//��ʼ��ͨѶ¼
void Init_Contact(Contact* ps)
{
	memset(ps->info, 0, sizeof(ps->info));
	ps->size = 0;
}
//��Ӻ���
void Add_Contact(Contact* ps)
{
	    Check_Capicity(ps);
     	printf("����������:>\n");
		scanf("%s", ps->info[ps->size].name);
		printf("����������:>\n");
		scanf("%d",&(ps->info[ps->size].age));
		printf("�������Ա�:>\n");
		scanf("%s", ps->info[ps->size].sex); 
		printf("������绰:>\n");
		scanf("%s", ps->info[ps->size].tel); 
		printf("�������ַ:>\n");
		scanf("%s", ps->info[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	
}
//չʾ��ǰ��Ϣ
void Show_Contact(const Contact* ps)
{
	int  a = 0;
	if (ps->size == 0)
		printf("��ǰͨѶ¼Ϊ��\n");
	else
	{
		printf("%-5s\t%-4s\t%-4s\t%-10s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (a = 0; a < ps->size; a++)
		{
			printf ("%-5s\t%-4d\t%-4s\t%-10s\t%-30s\n"
				, ps->info[a].name
				, ps->info[a].age
				, ps->info[a].sex
				, ps->info[a].tel
				, ps->info[a].addr
			);
		}
	}
}
//ͨ�����ֲ�����Ϣ�����ҳɹ�����λ����Ϣ������ʧ�ܷ���-1
 static int Find_by_name(const Contact* ps,char name[MAX_NAME])
{
	int a = 0;
	for (a = 0; a < ps->size; a++)
	{
		if (0 == strcmp(name, ps->info[a].name))
		{
			return a;
		}
	}
	return -1;
}
//ɾ������
void Del_Contact(Contact* ps)
{
	int a = 0;
	char name[MAX_NAME] = { 0 };
	printf("������ɾ����ָ����ϵ�˵�����\n");
	scanf("%s", name);
	a=Find_by_name(ps, name);
	if (-1 == a)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
	}
    else if (0 == a)
	{
		ps->info[a] = ps->info[a + 1];
		ps->size--;
		printf("ɾ���ɹ�\n");

	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = a; j < ps->size - 1; j++)
		{
			ps->info[j] = ps->info[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
//��������
void Search_Contact(const Contact* ps)
{
	int a = 0;
	char name[MAX_NAME] = { 0 };
	printf("�������ָ����ϵ�˵�����\n");
	scanf("%s", name);
	a = Find_by_name(ps, name);
	if (a == -1)
		printf("Ҫ���ҵ���ϵ�˲�����\n");
	else
	{
		printf("�����ɹ�\n");
		//չʾ����
		printf("%-5s\t%-4s\t%-4s\t%-10s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-5s\t%-4d\t%-4s\t%-10s\t%-30s\n"
			, ps->info[a].name
			, ps->info[a].age
			, ps->info[a].sex
			, ps->info[a].tel
			, ps->info[a].addr);
	}
}
void Modify(Contact* ps)
{
	int a = 0;
	char name[MAX_ADDR] = { 0 };
	if (!ps->size)
		printf("��ǰͨѶ¼Ϊ��");
	printf("������Ҫ�޸���ϵ�˵�����\n");
	scanf("%s", name);
	a = Find_by_name(ps,name);
	if (-1 == a)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
	}
	else
	{	
	printf("����������:>\n");
	scanf("%s", ps->info[a].name);
	printf("����������:>\n");
	scanf("%d", &(ps->info[a].age));
	printf("�������Ա�:>\n");
	scanf("%s", ps->info[a].sex);
	printf("������绰:>\n");
	scanf("%s", ps->info[a].tel);
	printf("�������ַ:>\n");
	scanf("%s", ps->info[a].addr);
	printf("�޸ĳɹ�\n");
	}
}
