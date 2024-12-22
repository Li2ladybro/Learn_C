#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* arr;
	int size;
	int capacity;
}SeqList;

//��ʼ��
void SeqListInit(SeqList* ps);

//����
void SeqListDestory(SeqList* ps);

//����
void SeqListCheckCapacity(SeqList* ps);

//��ӡ˳���
void SeqListPrint(SeqList* ps);

//β��βɾ
void SeqListPushBack(SeqList* ps, SLDateType date);
void SeqListPopBack(SeqList* ps);

//ͷ��ͷɾ
void SeqListPushFront(SeqList* ps, SLDateType date);
void SeqListPopFront(SeqList* ps);

// ����λ�ò���
void SeqListInsert(SeqList* ps,SLDateType date, int pos);
// ����λ��ɾ��
void SeqListErase(SeqList* ps, int pos);
//����
int SeqListFind(SeqList* ps, SLDateType date);




