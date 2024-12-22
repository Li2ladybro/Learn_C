#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

typedef int SLinkListDateType;

typedef struct SLinkListNode
{
	SLinkListDateType date;
	struct SLinkListNode* next;
}SLinkListNode;

//开辟新结点
SLinkListNode* SLinkListCreatNewNode(SLinkListDateType date);

//打印结点
void SLinkListPrint(SLinkListNode* phead);

//初始化
void SLinkListInit(SLinkListNode** pphead);

//尾插
void SLinkListPushBack(SLinkListNode** pphead, SLinkListDateType date);

//尾删
void SLinkListPopBack(SLinkListNode** pphead);

//头插
void SLinkListPushFront(SLinkListNode** pphead, SLinkListDateType date);

//头删
void SLinkListPopFront(SLinkListNode** pphead);

//查找
SLinkListNode* SLinkListFind(SLinkListNode* phead, SLinkListDateType date);

//后插
void SLinkListInsertAfter(SLinkListNode** pphead,SLinkListNode* pos, SLinkListDateType date);

//后删
void SLinkListEraseAfter(SLinkListNode** pphead,SLinkListNode* pos);