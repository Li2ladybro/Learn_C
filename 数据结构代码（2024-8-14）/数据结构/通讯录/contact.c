#include"contact.h"
//打印菜单
void menu()
{
	printf("***************************************\n");
	printf("*********1. add********2. del**********\n");
	printf("*********3. search*****4. modify*******\n");
	printf("*********5. show*******0. Exit*********\n");
	printf("***************************************\n");
}
//扩大容量
void Check_Capicity(Contact* ps)
{
	if (ps->size >= MAX_PEOPLE)
	{
		ps->size *= 2;
		realloc(ps, sizeof(People) * ps->size);
	}
	if (ps == NULL)
	{
		printf("扩容失败\n");
	}

}
//初始化通讯录
void Init_Contact(Contact* ps)
{
	memset(ps->info, 0, sizeof(ps->info));
	ps->size = 0;
}
//添加好友
void Add_Contact(Contact* ps)
{
	    Check_Capicity(ps);
     	printf("请输入名字:>\n");
		scanf("%s", ps->info[ps->size].name);
		printf("请输入年龄:>\n");
		scanf("%d",&(ps->info[ps->size].age));
		printf("请输入性别:>\n");
		scanf("%s", ps->info[ps->size].sex); 
		printf("请输入电话:>\n");
		scanf("%s", ps->info[ps->size].tel); 
		printf("请输入地址:>\n");
		scanf("%s", ps->info[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	
}
//展示当前信息
void Show_Contact(const Contact* ps)
{
	int  a = 0;
	if (ps->size == 0)
		printf("当前通讯录为空\n");
	else
	{
		printf("%-5s\t%-4s\t%-4s\t%-10s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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
//通过名字查找信息，查找成功返回位置信息，查找失败返回-1
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
//删除好友
void Del_Contact(Contact* ps)
{
	int a = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入删除的指定联系人的姓名\n");
	scanf("%s", name);
	a=Find_by_name(ps, name);
	if (-1 == a)
	{
		printf("要删除的联系人不存在\n");
	}
    else if (0 == a)
	{
		ps->info[a] = ps->info[a + 1];
		ps->size--;
		printf("删除成功\n");

	}
	else
	{
		//删除数据
		int j = 0;
		for (j = a; j < ps->size - 1; j++)
		{
			ps->info[j] = ps->info[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
//搜索好友
void Search_Contact(const Contact* ps)
{
	int a = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入的指定联系人的姓名\n");
	scanf("%s", name);
	a = Find_by_name(ps, name);
	if (a == -1)
		printf("要查找的联系人不存在\n");
	else
	{
		printf("搜索成功\n");
		//展示数据
		printf("%-5s\t%-4s\t%-4s\t%-10s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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
		printf("当前通讯录为空");
	printf("请输入要修改联系人的名字\n");
	scanf("%s", name);
	a = Find_by_name(ps,name);
	if (-1 == a)
	{
		printf("要修改的联系人不存在\n");
	}
	else
	{	
	printf("请输入名字:>\n");
	scanf("%s", ps->info[a].name);
	printf("请输入年龄:>\n");
	scanf("%d", &(ps->info[a].age));
	printf("请输入性别:>\n");
	scanf("%s", ps->info[a].sex);
	printf("请输入电话:>\n");
	scanf("%s", ps->info[a].tel);
	printf("请输入地址:>\n");
	scanf("%s", ps->info[a].addr);
	printf("修改成功\n");
	}
}
