#include "SLinkList.h"

//初始化
void SLinkListInit(SLinkListNode** pphead)
{
	SLinkListNode* newnode=(SLinkListNode*)malloc(sizeof(SLinkListNode));
	if(newnode==NULL)
	{
		printf("初始化失败退出程序\n");
		exit(1);
	}
	//头结点
	newnode->date = 0;
	newnode->next = NULL;
	//头指针
	*pphead = newnode;
}

//开辟新结点
SLinkListNode* SLinkListCreatNewNode(SLinkListDateType date)
{
	SLinkListNode* newnode = (SLinkListNode * )malloc(sizeof(SLinkListNode));
	if (newnode == NULL)
	{
		printf("开辟空间失败\n");
	}
	else
	{
		newnode->date = date;
		newnode->next = NULL;
		return newnode;
	}
}

//打印结点
void SLinkListPrint(SLinkListNode* phead)
{
	if (phead->next == NULL)
	{
		printf("链表为空\n");
	}
	else
	{
		printf("%d:",phead->date);
		phead = phead->next;
		while (phead)
		{
			printf("%d->", phead->date);
			phead = phead->next;
		}
		printf("NULL\n");
	}
}

//尾插
void SLinkListPushBack(SLinkListNode** pphead, SLinkListDateType date)
{
	(*pphead)->date++;
	SLinkListNode * newnode= SLinkListCreatNewNode(date);
	SLinkListNode* tail = *pphead;
	//找尾
	while (tail->next!=NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;
}

//尾删
void SLinkListPopBack(SLinkListNode** pphead)
{
	
	//只有一个头结点->空表
	if ((*pphead)->next == NULL)
	{
		printf("单链表为空\n");
	}
	else
	{
		SLinkListNode* prev = *pphead;
		SLinkListNode* tail = *pphead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev ->next= NULL;
		(*pphead)->date--;
	}
}

//头插
void SLinkListPushFront(SLinkListNode** pphead, SLinkListDateType date)
{
	(*pphead)->date++;
	SLinkListNode* newnode = SLinkListCreatNewNode(date);
	newnode->next = (*pphead)->next;
	(*pphead)->next = newnode;
}

//头删
void SLinkListPopFront(SLinkListNode** pphead)
{
	if ((*pphead)->next == NULL)
	{
		printf("链表为空,头删失败\n");
	}
	else
	{
		SLinkListNode* next = (*pphead)->next;
		SLinkListNode* nextnext = next->next;
		if(nextnext==NULL)
		{			
			(*pphead)->next =NULL;
			free(next);
		}
		else
		{
			(*pphead)->next = nextnext;
			free(next);
		}
		(*pphead)->date--;
	}
}

//查找
SLinkListNode* SLinkListFind(SLinkListNode* phead, SLinkListDateType date)
{
	SLinkListNode* cur = phead->next;
	while (cur)
	{
		if (cur->date == date)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

//后插
void SLinkListInsertAfter(SLinkListNode** pphead, SLinkListNode* pos, SLinkListDateType date)
{
	assert(pos);
	SLinkListNode* newnode=(SLinkListNode*)SLinkListCreatNewNode(date);
	newnode->next = pos->next;
	pos->next = newnode;
	(*pphead)->date++;
}

//后删
void SLinkListEraseAfter(SLinkListNode** pphead, SLinkListNode* pos )
{
	assert(pos);
	SLinkListNode* next = pos->next;
	SLinkListNode* nextnext = next->next;
	pos->next = nextnext;
	free(next);
	(*pphead)->date--;
}
