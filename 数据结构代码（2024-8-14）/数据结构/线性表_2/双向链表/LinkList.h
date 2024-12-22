#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef unsigned long long ElemType;

typedef struct LinkListNode
{
	ElemType data;
	struct LinkListNode* prev;
	struct LinkListNode* next;
}LinkListNode;

//初始化
LinkListNode* ListInit();

//创建新节点
LinkListNode* CreatNewNode(ElemType data);

//打印结点
void ListPrint(LinkListNode* phead);

//尾插
void ListPushBack(LinkListNode* phead, ElemType data);

//尾删
void ListPopBack(LinkListNode* phead);

//头插
void ListPushFront(LinkListNode* phead, ElemType data);

//头删
void ListPopFront(LinkListNode* phead);

//查找 -> 返回结点地址
LinkListNode* ListFind(LinkListNode* phead, ElemType data);

//任意位置插入（当前位置前面插入）
void ListInsert(LinkListNode* pos, ElemType data);

//删除任意位置结点
void ListErase(LinkListNode* pos);

//清空链表
void ListClear(LinkListNode* phead);

//销毁链表
void ListDestroy(LinkListNode** pphead);

