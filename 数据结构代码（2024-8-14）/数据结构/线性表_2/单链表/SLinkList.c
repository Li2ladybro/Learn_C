#include "SLinkList.h"

//��ʼ��
void SLinkListInit(SLinkListNode** pphead)
{
	SLinkListNode* newnode=(SLinkListNode*)malloc(sizeof(SLinkListNode));
	if(newnode==NULL)
	{
		printf("��ʼ��ʧ���˳�����\n");
		exit(1);
	}
	//ͷ���
	newnode->date = 0;
	newnode->next = NULL;
	//ͷָ��
	*pphead = newnode;
}

//�����½��
SLinkListNode* SLinkListCreatNewNode(SLinkListDateType date)
{
	SLinkListNode* newnode = (SLinkListNode * )malloc(sizeof(SLinkListNode));
	if (newnode == NULL)
	{
		printf("���ٿռ�ʧ��\n");
	}
	else
	{
		newnode->date = date;
		newnode->next = NULL;
		return newnode;
	}
}

//��ӡ���
void SLinkListPrint(SLinkListNode* phead)
{
	if (phead->next == NULL)
	{
		printf("����Ϊ��\n");
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

//β��
void SLinkListPushBack(SLinkListNode** pphead, SLinkListDateType date)
{
	(*pphead)->date++;
	SLinkListNode * newnode= SLinkListCreatNewNode(date);
	SLinkListNode* tail = *pphead;
	//��β
	while (tail->next!=NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;
}

//βɾ
void SLinkListPopBack(SLinkListNode** pphead)
{
	
	//ֻ��һ��ͷ���->�ձ�
	if ((*pphead)->next == NULL)
	{
		printf("������Ϊ��\n");
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

//ͷ��
void SLinkListPushFront(SLinkListNode** pphead, SLinkListDateType date)
{
	(*pphead)->date++;
	SLinkListNode* newnode = SLinkListCreatNewNode(date);
	newnode->next = (*pphead)->next;
	(*pphead)->next = newnode;
}

//ͷɾ
void SLinkListPopFront(SLinkListNode** pphead)
{
	if ((*pphead)->next == NULL)
	{
		printf("����Ϊ��,ͷɾʧ��\n");
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

//����
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

//���
void SLinkListInsertAfter(SLinkListNode** pphead, SLinkListNode* pos, SLinkListDateType date)
{
	assert(pos);
	SLinkListNode* newnode=(SLinkListNode*)SLinkListCreatNewNode(date);
	newnode->next = pos->next;
	pos->next = newnode;
	(*pphead)->date++;
}

//��ɾ
void SLinkListEraseAfter(SLinkListNode** pphead, SLinkListNode* pos )
{
	assert(pos);
	SLinkListNode* next = pos->next;
	SLinkListNode* nextnext = next->next;
	pos->next = nextnext;
	free(next);
	(*pphead)->date--;
}
