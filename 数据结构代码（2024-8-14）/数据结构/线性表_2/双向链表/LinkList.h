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

//��ʼ��
LinkListNode* ListInit();

//�����½ڵ�
LinkListNode* CreatNewNode(ElemType data);

//��ӡ���
void ListPrint(LinkListNode* phead);

//β��
void ListPushBack(LinkListNode* phead, ElemType data);

//βɾ
void ListPopBack(LinkListNode* phead);

//ͷ��
void ListPushFront(LinkListNode* phead, ElemType data);

//ͷɾ
void ListPopFront(LinkListNode* phead);

//���� -> ���ؽ���ַ
LinkListNode* ListFind(LinkListNode* phead, ElemType data);

//����λ�ò��루��ǰλ��ǰ����룩
void ListInsert(LinkListNode* pos, ElemType data);

//ɾ������λ�ý��
void ListErase(LinkListNode* pos);

//�������
void ListClear(LinkListNode* phead);

//��������
void ListDestroy(LinkListNode** pphead);

