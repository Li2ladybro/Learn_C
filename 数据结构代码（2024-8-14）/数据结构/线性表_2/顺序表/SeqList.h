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

//初始化
void SeqListInit(SeqList* ps);

//销毁
void SeqListDestory(SeqList* ps);

//扩容
void SeqListCheckCapacity(SeqList* ps);

//打印顺序表
void SeqListPrint(SeqList* ps);

//尾插尾删
void SeqListPushBack(SeqList* ps, SLDateType date);
void SeqListPopBack(SeqList* ps);

//头插头删
void SeqListPushFront(SeqList* ps, SLDateType date);
void SeqListPopFront(SeqList* ps);

// 任意位置插入
void SeqListInsert(SeqList* ps,SLDateType date, int pos);
// 任意位置删除
void SeqListErase(SeqList* ps, int pos);
//查找
int SeqListFind(SeqList* ps, SLDateType date);




