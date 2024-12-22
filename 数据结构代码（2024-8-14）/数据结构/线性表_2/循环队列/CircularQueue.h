#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

typedef int ElemType;

//ѭ�����д洢�ṹ
typedef struct 
{
	ElemType* _arr;    //˳��洢
	int _front;        //��ͷ�±�
	int _rear;         //��β
	int _maxSize;      //���ռ���Ч����λΪ_maxSize-1
} MyCircularQueue;

//�����������ö��г���Ϊ k
MyCircularQueue* myCircularQueueCreate(int k);

//��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻���
int myCircularQueueEnQueue(MyCircularQueue* obj, ElemType value);

//��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
int myCircularQueueDeQueue(MyCircularQueue* obj);

//Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
int myCircularQueueFront(MyCircularQueue* obj);

//Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
int myCircularQueueRear(MyCircularQueue* obj);

//isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
int myCircularQueueIsEmpty(MyCircularQueue* obj);

//isFull() : ���ѭ�������Ƿ�������
int myCircularQueueIsFull(MyCircularQueue* obj);

//����
void myCircularQueueFree(MyCircularQueue* obj);

