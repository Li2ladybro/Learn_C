#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int elemtype;
typedef struct Seq_list
{
	elemtype* elem;
	int size;//记录当前顺序表有效元素
	int capicity;//总的容量大小
}Seq_list;
//初始化顺序表
void Inint_Seq_list(Seq_list* ps);
//摧毁顺序表
void Destory_Seq_List(Seq_list* ps);
//扩容
void Check_Capicity(Seq_list* ps);
//打印顺序表
void Print_Seq_List(Seq_list* ps);
//尾插元素
void Push_Back_SeqList(Seq_list* ps,elemtype x);
//尾删元素
void Pop_Back_SeqList(Seq_list* ps);
//头插元素
void Push_front_SeqList(Seq_list* ps, elemtype x);
//头删元素
void Pop_front_SeqList(Seq_list* ps);
//插入元素
void Insert_SeqList(Seq_list* ps, int pos, elemtype x);
//删除元素
void Delete_SeqList(Seq_list* ps, elemtype x);
//查找
void Find_elem(Seq_list* ps, elemtype x);
