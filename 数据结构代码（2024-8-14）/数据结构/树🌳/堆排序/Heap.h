#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//堆的存储结构
typedef int ElemType;

//小堆
typedef struct Heap
{
	ElemType* _arr;     //数组
	int _size;
	int _capacity;
}Heap;

//交换
void swap(ElemType* a, ElemType* b);

//向下调整算法（根节点下浮）大数下浮
//前提：左右子树都是小堆
//复杂度：LogN
//参数a:数组，n:数据个数，root:堆顶
void AdjustDown(ElemType* a,int n,int root);

//向上调整算法（操作数在数组最后一个数据）小数上浮
void AdjustUp(ElemType* a, int n, ElemType data);

//构建堆（自下向上构建）这里构建的是小堆
//从叶结点的上一层开始构建
//复杂度：n
void HeapCreat(ElemType* a, int n);

//堆排序
//递减用小根堆，递增用大根堆
//复杂度：nLogN
void HeapSort(ElemType* a, int n);

//打印堆
void HeapPrint(Heap* php);

//初始化
void HeapInit(Heap* php, ElemType* a,int n);

//清空
void HeapClear(Heap* php);

//销毁
void HeapDestroy(Heap* php);

//插入元素，数组尾插入新的元素，依然保持堆的特性
void HeapPush(Heap* php, ElemType data);

//弹出堆顶元素，并且弹出后，依然保持堆的性质
void HeapPop(Heap* php);

//取堆顶
ElemType HeapTop(Heap* php);