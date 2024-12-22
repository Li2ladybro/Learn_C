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

//�����½��
SLinkListNode* SLinkListCreatNewNode(SLinkListDateType date);

//��ӡ���
void SLinkListPrint(SLinkListNode* phead);

//��ʼ��
void SLinkListInit(SLinkListNode** pphead);

//β��
void SLinkListPushBack(SLinkListNode** pphead, SLinkListDateType date);

//βɾ
void SLinkListPopBack(SLinkListNode** pphead);

//ͷ��
void SLinkListPushFront(SLinkListNode** pphead, SLinkListDateType date);

//ͷɾ
void SLinkListPopFront(SLinkListNode** pphead);

//����
SLinkListNode* SLinkListFind(SLinkListNode* phead, SLinkListDateType date);

//���
void SLinkListInsertAfter(SLinkListNode** pphead,SLinkListNode* pos, SLinkListDateType date);

//��ɾ
void SLinkListEraseAfter(SLinkListNode** pphead,SLinkListNode* pos);