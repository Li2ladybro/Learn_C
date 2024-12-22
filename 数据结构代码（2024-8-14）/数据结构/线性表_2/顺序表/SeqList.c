#include "SeqList.h"

//��ʼ��
void SeqListInit(SeqList* ps)
{
	ps->capacity = 3;
	ps->size = 0;
	ps->arr = (SLDateType*)malloc(sizeof(SLDateType) * ps->capacity);
	if (ps->arr == NULL)
	{
		printf("��ʼ��ʧ�ܣ��˳�����\n");
		exit(1);
	}
	printf("˳����ʼ���ɹ�\n");
}

//����
void SeqListDestory(SeqList* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
	printf("˳���������\n");

}

//����
void SeqListCheckCapacity(SeqList* ps) 
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity = ps->capacity * 2;
		ps->arr = realloc(ps->arr, sizeof(SLDateType) * ps->capacity );
	}
	if (ps->arr == NULL)
	{
		printf("����ʧ�ܣ��˳�����\n");
		exit(1);
	}
}

//��ӡ˳���
void SeqListPrint(SeqList* ps) 
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("˳���Ϊ��\n");
	}
	for (int start = 0; start < ps->size; start++)
	{
		printf("%d ", ps->arr[start]);	
	}
	printf("\n");
}

//β��
void SeqListPushBack(SeqList* ps, SLDateType date)
{
	SeqListCheckCapacity(ps);
	ps->arr[ps->size] = date;
	ps->size++;
}

//βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}

//ͷ��
void SeqListPushFront(SeqList* ps, SLDateType date)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int end = ps->size;
	while (end >= 1)
	{
		ps->arr[end] = ps->arr[end - 1];
		end--;
	}
	ps->arr[end] = date;
	ps->size++;
}

//ͷɾ
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int start = 0;
	while (start<ps->size-1)
	{
		ps->arr[start] = ps->arr[start + 1];
		start++;
	}
	ps->size--;
}

// ����λ�ò���
void SeqListInsert(SeqList* ps, SLDateType date, int pos)
{
	assert(ps);
	assert(pos >= 0&&pos<ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size;
	while (end>pos)
	{
		ps->arr[end] = ps->arr[end - 1];
		end--;
	}
	ps->arr[pos] = date;
	ps->size++;
}

// ����λ��ɾ��
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	int start = pos;
	while ( start< ps->size-1)
	{
		ps->arr[start] = ps->arr[start + 1];
		start++;
	}
	ps->size--;
}

//����
int SeqListFind(SeqList* ps, SLDateType date)
{
	assert(ps);
	for (int start = 0; start < ps->size; start++)
	{
		if (ps->arr[start] == date)
		{
			return start;
		}
	}
	return -1;
}