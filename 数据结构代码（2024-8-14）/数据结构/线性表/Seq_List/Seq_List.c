#include"Seq_List.h"
//��ʼ��˳���
void Inint_Seq_list(Seq_list* ps)
{
	ps->capicity = 4;
	ps->elem = (elemtype*)malloc(sizeof(elemtype) * ps->capicity);
	if (ps->elem == NULL)
	{
		printf("����ռ�ʧ�ܣ��˳�����\n");
	}
	else
	{
		memset(ps->elem,0, sizeof(ps->elem));
		ps->size = 0;
	}
}
//�ݻ�˳���
void Destory_Seq_List(Seq_list* ps)
{
	free(ps->elem);
	ps ->elem= NULL;
	ps->capicity = ps->size = 0;
}
//����
void Check_Capicity(Seq_list* ps)
{
	if (ps->size == ps->capicity)
	{
		ps->capicity *= 2;
		elemtype* ps1= (elemtype*)realloc(ps->elem, sizeof(elemtype) * ps->capicity);
		if (ps1 == NULL)
		{
			printf("����ʧ��\n");
		}
		else
			ps->elem = ps1;
	}
}
//��ӡ˳���
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
//β��Ԫ��
void Push_Back_SeqList(Seq_list* ps,elemtype x)
{
	Check_Capicity(ps);
	ps->elem[ps->size]=x;
	ps->size++;
}
//βɾԪ��
void Pop_Back_SeqList(Seq_list* ps)
{
	assert(ps->size);
	ps->size--;
}
//ͷ��Ԫ��
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
//ͷɾԪ��
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
		printf("˳����ѿ�\n");
	}
}
//����Ԫ��
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
//ɾ��Ԫ��
void Delete_SeqList(Seq_list* ps,int pos)
{
	assert(pos > 0 && ps->size&&pos<=ps->size);
	for (int start = pos - 1; start < ps->size - 1; start++)
	{
		ps->elem[start] = ps->elem[start + 1];
	}
	ps->size--;
}
//����
void Find_elem(Seq_list* ps, elemtype x)
{
	for (int start = 0; start < ps->size; start++)
	{
		if (ps->elem[start] == x)
		{
			printf("��%d��λ��\n", start+1);
			return;
		}
	}
	printf("��ӦԪ��δ�ڱ���\n");
	return;
}