#pragma once

#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

// 交换数据
// 参数：swap1,swap2,为要交换的数据
void swap(int* swap1,int* swap2);

// 打印数据
// 参数：printArr,待打印的数组
// 参数：size，数组的大小
void DataPrint(int printArr[], int size);

// 插入排序:直接插入和希尔排序
// 
// 直接插入排序
// 参数：arr:待排序的数组，size：元素个数
void StraightInsertionSort(int* arr,int size);

// 希尔排序
// 参数：arr:待排序的数组，size：元素个数
void ShellSort(int* arr, int size);

//选择排序：简单选择排序和堆排序
// 
// 简单选择排序
// 参数：arr:待排序的数组，size：元素个数
void SimpleSelectionSort(int* arr, int size);

// 堆排序 向下调整算法->建堆->排序
// 是一种树形选择排序
// 时间复杂度：O(n)=nLogN
// 
// 向下调整算法
// 参数：arr:存储结点数据的数组，size：元素个数 ，root：从root开始向下调整
void AdjustDown(int* arr, int size, int root);

// 建堆
void CreatHeap(int* arr, int size);

// 排序
void HeapSort(int* arr, int size);

// 交换排序：冒泡排序+快速排序
// 
// 冒泡排序
// 参数：arr:待排序的数组，size：元素个数
void BubbleSort(int* arr, int size);

// 快速排序
int SelectMidPivotKeyIndex(int* arr, int left, int right);  // 选择出合适的关键字
int PartQuickSort1(int* arr, int begin, int end);           // 左右指针（Hoare的写法）
int PartQuickSort2(int* arr, int begin, int end);           // 挖坑大法（严蔚敏数据结构） 
int PartQuickSort3(int* arr, int begin,int end);            // 前后指针法

// 参数：arr:待排序的数组，
// 参数：left，begin，为数组最左边数据下标
// 参数：right，end为数组最右边数据下标
void QuickSort(int* arr, int left,int right); 

// 用栈模拟实现快速排序，实现非递归算法
void QuickSortNonR(int* arr, int left, int right);

// 归并排序
// 参数：arr:待排序的数组，size：元素个数

// 两个有序数组归并成一个数组
void MergeArr(int* arr, int* temp, int begin1, int end1, int begin2, int  end2);
// 归并排序子函数
void _MergeSort(int* arr, int* temp, int left, int right);
void MergeSort(int* arr, int size);

// 递归改循环
void MergeSortNonR(int* arr, int size);