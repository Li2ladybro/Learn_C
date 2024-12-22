#include"Seq_List.h"
//初始化顺序表
void Inint_Seq_list(Seq_list* ps)
{
	ps->capicity = 4;
	ps->elem = (elemtype*)malloc(sizeof(elemtype) * ps->capicity);
	if (ps->elem == NULL)
	{
		printf("申请空间失败，退出程序\n");
	}
	else
	{
		memset(ps->elem,0, sizeof(ps->elem));
		ps->size = 0;
	}
}
//摧毁顺序表
void Destory_Seq_List(Seq_list* ps)
{
	free(ps->elem);
	ps ->elem= NULL;
	ps->capicity = ps->size = 0;
}
//扩容
void Check_Capicity(Seq_list* ps)
{
	if (ps->size == ps->capicity)
	{
		ps->capicity *= 2;
		elemtype* ps1= (elemtype*)realloc(ps->elem, sizeof(elemtype) * ps->capicity);
		if (ps1 == NULL)
		{
			printf("扩容失败\n");
		}
		else
			ps->elem = ps1;
	}
}
//打印顺序表
void Print_Seq_List(Seq_list* ps)
{
	assert(ps->size);
	int start =0;
	for (start=0; start<ps->size;start++)
	{
		printf("%d ", ps->elem[start]);
	}
	printf("\n");
}
//尾插元素
void Push_Back_SeqList(Seq_list* ps,elemtype x)
{
	Check_Capicity(ps);
	ps->elem[ps->size]=x;
	ps->size++;
}
//尾删元素
void Pop_Back_SeqList(Seq_list* ps)
{
	assert(ps->size);
	ps->size--;
}
//头插元素
void Push_front_SeqList(Seq_list* ps,elemtype x)
{
	Check_Capicity(ps);
	int start = 0;
	for(start= ps->size;start>0;start--)
	{
		ps->elem[start] = ps->elem[start - 1];
	}
	ps->elem[start] = x;
	ps->size++;
}
//头删元素
void Pop_front_SeqList(Seq_list* ps)
{
	assert(ps->size);
	for (int start = 0; start < ps->size - 1; start++)
	{
		ps->elem[start] = ps->elem[start + 1];
	}
	ps->size--;
	if (ps->size==0)
	{
		printf("顺序表已空\n");
	}
}
//插入元素
void Insert_SeqList(Seq_list* ps, int pos, elemtype x)
{
	Check_Capicity(ps);
	for (int end = ps->size; end >= pos; end--)
	{
		ps->elem[end] = ps->elem[end - 1];
	}
	ps->elem[pos - 1] = x;
	ps->size++;
}
//删除元素
void Delete_SeqList(Seq_list* ps,int pos)
{
	assert(pos > 0 && ps->size&&pos<=ps->size);
	for (int start = pos - 1; start < ps->size - 1; start++)
	{
		ps->elem[start] = ps->elem[start + 1];
	}
	ps->size--;
}
//查找
void Find_elem(Seq_list* ps, elemtype x)
{
	for (int start = 0; start < ps->size; start++)
	{
		if (ps->elem[start] == x)
		{
			printf("在%d号位置\n", start+1);
			return;
		}
	}
	printf("对应元素未在表中\n");
	return;
}