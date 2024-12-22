#pragma once

#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

// ��������
// ������swap1,swap2,ΪҪ����������
void swap(int* swap1,int* swap2);

// ��ӡ����
// ������printArr,����ӡ������
// ������size������Ĵ�С
void DataPrint(int printArr[], int size);

// ��������:ֱ�Ӳ����ϣ������
// 
// ֱ�Ӳ�������
// ������arr:����������飬size��Ԫ�ظ���
void StraightInsertionSort(int* arr,int size);

// ϣ������
// ������arr:����������飬size��Ԫ�ظ���
void ShellSort(int* arr, int size);

//ѡ�����򣺼�ѡ������Ͷ�����
// 
// ��ѡ������
// ������arr:����������飬size��Ԫ�ظ���
void SimpleSelectionSort(int* arr, int size);

// ������ ���µ����㷨->����->����
// ��һ������ѡ������
// ʱ�临�Ӷȣ�O(n)=nLogN
// 
// ���µ����㷨
// ������arr:�洢������ݵ����飬size��Ԫ�ظ��� ��root����root��ʼ���µ���
void AdjustDown(int* arr, int size, int root);

// ����
void CreatHeap(int* arr, int size);

// ����
void HeapSort(int* arr, int size);

// ��������ð������+��������
// 
// ð������
// ������arr:����������飬size��Ԫ�ظ���
void BubbleSort(int* arr, int size);

// ��������
int SelectMidPivotKeyIndex(int* arr, int left, int right);  // ѡ������ʵĹؼ���
int PartQuickSort1(int* arr, int begin, int end);           // ����ָ�루Hoare��д����
int PartQuickSort2(int* arr, int begin, int end);           // �ڿӴ󷨣���ε�����ݽṹ�� 
int PartQuickSort3(int* arr, int begin,int end);            // ǰ��ָ�뷨

// ������arr:����������飬
// ������left��begin��Ϊ��������������±�
// ������right��endΪ�������ұ������±�
void QuickSort(int* arr, int left,int right); 

// ��ջģ��ʵ�ֿ�������ʵ�ַǵݹ��㷨
void QuickSortNonR(int* arr, int left, int right);

// �鲢����
// ������arr:����������飬size��Ԫ�ظ���

// ������������鲢��һ������
void MergeArr(int* arr, int* temp, int begin1, int end1, int begin2, int  end2);
// �鲢�����Ӻ���
void _MergeSort(int* arr, int* temp, int left, int right);
void MergeSort(int* arr, int size);

// �ݹ��ѭ��
void MergeSortNonR(int* arr, int size);