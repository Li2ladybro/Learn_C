#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//�ѵĴ洢�ṹ
typedef int ElemType;

//С��
typedef struct Heap
{
	ElemType* _arr;     //����
	int _size;
	int _capacity;
}Heap;

//����
void swap(ElemType* a, ElemType* b);

//���µ����㷨�����ڵ��¸��������¸�
//ǰ�᣺������������С��
//���Ӷȣ�LogN
//����a:���飬n:���ݸ�����root:�Ѷ�
void AdjustDown(ElemType* a,int n,int root);

//���ϵ����㷨�����������������һ�����ݣ�С���ϸ�
void AdjustUp(ElemType* a, int n, ElemType data);

//�����ѣ��������Ϲ��������ﹹ������С��
//��Ҷ������һ�㿪ʼ����
//���Ӷȣ�n
void HeapCreat(ElemType* a, int n);

//������
//�ݼ���С���ѣ������ô����
//���Ӷȣ�nLogN
void HeapSort(ElemType* a, int n);

//��ӡ��
void HeapPrint(Heap* php);

//��ʼ��
void HeapInit(Heap* php, ElemType* a,int n);

//���
void HeapClear(Heap* php);

//����
void HeapDestroy(Heap* php);

//����Ԫ�أ�����β�����µ�Ԫ�أ���Ȼ���ֶѵ�����
void HeapPush(Heap* php, ElemType data);

//�����Ѷ�Ԫ�أ����ҵ�������Ȼ���ֶѵ�����
void HeapPop(Heap* php);

//ȡ�Ѷ�
ElemType HeapTop(Heap* php);