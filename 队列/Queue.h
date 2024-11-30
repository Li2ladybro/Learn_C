#pragma once
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

extern struct BinaryNode;

//�洢�ṹ
typedef struct BinaryNode* QueueDataElemType;  // �����ָ�룬�ṹ��̫����

typedef struct QueueNode
{
	QueueDataElemType data;
	struct QueueNode* next;
}QueueNode;

//�����ȳ���FIFO��

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//��ʼ��������һ���յĶ���
void QueueInint(Queue* queue);

//��� -> ������д��������
void QueueClear(Queue* queue);

//���� -> ������д���������
void QueueDestroy(Queue* queue);

//����1����пգ�����0����зǿ�
int QueueEmpty(Queue* queue);

//��ȡ���г���
int QueueLength(Queue* queue);

//��ȡ����ͷԪ��
QueueDataElemType QueueFront(Queue* queue);

//��ȡ����βԪ��
QueueDataElemType QueueBack(Queue* queue);

//�����
void QueuePush(Queue* queue, QueueDataElemType data);

//������
void QueuePop(Queue* queue);
