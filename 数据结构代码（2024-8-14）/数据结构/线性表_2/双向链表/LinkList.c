#include "LinkList.h"

//创建新节点
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

//打印结点
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

//初始化
LinkListNode* ListInit()
{
	//空的循环链表
	LinkListNode* newnode = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->prev = newnode->next = newnode;
	return newnode;
}

//尾插
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

//尾删
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

//头插
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

//头删
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

//查找 -> 返回结点地址
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

//任意位置插入（当前位置前面插入）
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

//删除任意位置结点
void ListErase(LinkListNode* pos)
{
	assert(pos);
	LinkListNode* posPrev = pos->prev;
	LinkListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
	
}

//清空链表
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

//销毁链表
void ListDestroy(LinkListNode** pphead)
{
	assert(*pphead);
	ListClear(*pphead);
	*pphead = NULL;
}
