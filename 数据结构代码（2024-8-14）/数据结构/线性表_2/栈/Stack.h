#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//存储结构
typedef int ElemType;

typedef struct SeqStack
{
	ElemType* _arr;
	int _top;
	int _capacity;
}SeqStack;

//初始化，构建一个空的顺序栈
void StackInint(SeqStack* stack);

//清空 -> 如果栈存在则清空
void StackClear(SeqStack* stack);

//销毁 -> 如果栈存在则销毁
void StackDestroy(SeqStack* stack);

//返回1则栈空，返回0则栈非空
int StackEmpty(SeqStack* stack);

//获取栈长度
int StackLength(SeqStack* stack);

//获取栈顶元素
ElemType StackGetTop(SeqStack* stack);

//入栈
void StackPush(SeqStack* stack, ElemType data);

//出栈
void StackPop(SeqStack* stack);




