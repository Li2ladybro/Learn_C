#include "SeqList.h"

//初始化
void SeqListInit(SeqList* ps)
{
	ps->capacity = 3;
	ps->size = 0;
	ps->arr = (SLDateType*)malloc(sizeof(SLDateType) * ps->capacity);
	if (ps->arr == NULL)
	{
		printf("初始化失败，退出程序\n");
		exit(1);
	}
	printf("顺序表初始化成功\n");
}

//销毁
void SeqListDestory(SeqList* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
	printf("顺序表已销毁\n");

}

//扩容
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
		printf("扩容失败，退出程序\n");
		exit(1);
	}
}

//打印顺序表
void SeqListPrint(SeqList* ps) 
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("顺序表为空\n");
	}
	for (int start = 0; start < ps->size; start++)
	{
		printf("%d ", ps->arr[start]);	
	}
	printf("\n");
}

//尾插
void SeqListPushBack(SeqList* ps, SLDateType date)
{
	SeqListCheckCapacity(ps);
	ps->arr[ps->size] = date;
	ps->size++;
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}

//头插
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

//头删
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

// 任意位置插入
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

// 任意位置删除
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

//查找
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