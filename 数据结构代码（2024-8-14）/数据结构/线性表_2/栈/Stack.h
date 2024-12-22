#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//�洢�ṹ
typedef int ElemType;

typedef struct SeqStack
{
	ElemType* _arr;
	int _top;
	int _capacity;
}SeqStack;

//��ʼ��������һ���յ�˳��ջ
void StackInint(SeqStack* stack);

//��� -> ���ջ���������
void StackClear(SeqStack* stack);

//���� -> ���ջ����������
void StackDestroy(SeqStack* stack);

//����1��ջ�գ�����0��ջ�ǿ�
int StackEmpty(SeqStack* stack);

//��ȡջ����
int StackLength(SeqStack* stack);

//��ȡջ��Ԫ��
ElemType StackGetTop(SeqStack* stack);

//��ջ
void StackPush(SeqStack* stack, ElemType data);

//��ջ
void StackPop(SeqStack* stack);




