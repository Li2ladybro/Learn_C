#include "LinkList.h"

//�����½ڵ�
LinkListNode* CreatNewNode(ElemType data)
{
	LinkListNode* newnode = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next= NULL;
	return newnode;
}

//��ӡ���
void ListPrint(LinkListNode* phead)
{
	assert(phead->next != phead);
	LinkListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%lld ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//��ʼ��
LinkListNode* ListInit()
{
	//�յ�ѭ������
	LinkListNode* newnode = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->prev = newnode->next = newnode;
	return newnode;
}

//β��
void ListPushBack(LinkListNode* phead, ElemType data)
{
	/*
	assert(phead);

	LinkListNode* tail = phead->prev;
	
	LinkListNode* newnode=CreatNewNode(data);

	tail->next = newnode;

	newnode->prev = tail;
	newnode->next = phead;

	phead->prev = newnode;
	*/
	ListInsert(phead, data);

}

//βɾ
void ListPopBack(LinkListNode* phead)
{
	/*
	assert(phead);
	assert(phead != phead->next);

	LinkListNode* tail = phead->prev;

	LinkListNode* tailPrev = tail->prev;

	free(tail);

	tailPrev->next = phead;

	phead->prev = tailPrev;*/
	ListErase(phead->prev);

}

//ͷ��
void ListPushFront(LinkListNode* phead, ElemType data)
{
	/*
	assert(phead);

	LinkListNode* first = phead->next;

	LinkListNode* newnode = CreatNewNode(data);

	phead->next = newnode;

	newnode->prev = phead;
	newnode->next= first;

	first->prev = newnode;*/

	ListInsert(phead->next, data);
}

//ͷɾ
void ListPopFront(LinkListNode* phead)
{
	/*
	assert(phead);
	assert(phead != phead->next);

	LinkListNode* first = phead->next;
	LinkListNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;*/
	ListErase(phead->next);

}

//���� -> ���ؽ���ַ
LinkListNode* ListFind(LinkListNode* phead, ElemType data)
{
	assert(phead);
	assert(phead != phead->next);

	LinkListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == data)
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

//����λ�ò��루��ǰλ��ǰ����룩
void ListInsert(LinkListNode* pos, ElemType data)
{
	assert(pos);

	LinkListNode* posPrev = pos->prev;
	LinkListNode* newnode = CreatNewNode(data);

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next= pos;
	pos->prev = newnode;

}

//ɾ������λ�ý��
void ListErase(LinkListNode* pos)
{
	assert(pos);
	LinkListNode* posPrev = pos->prev;
	LinkListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
	
}

//�������
void ListClear(LinkListNode* phead)
{
	assert(phead);
	LinkListNode* cur = phead->next;
	while (cur != phead)
	{
		LinkListNode* del = cur;
		cur = cur->next;
		free(del);
	}
	cur->next = cur->prev = phead;
}

//��������
void ListDestroy(LinkListNode** pphead)
{
	assert(*pphead);
	ListClear(*pphead);
	*pphead = NULL;
}
