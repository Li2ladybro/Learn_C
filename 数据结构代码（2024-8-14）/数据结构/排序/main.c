#include"Sort.h"

void StraightInsertionSortTest();

void ShellSortTest();

void SimpleSelectionSortTest();

void HeapSortTest();

void BubbleSortTest();

void QuickSortTest();

void MergeSortTest();
int main()
{
	//StraightInsertionSortTest();
	//ShellSortTest();
	//SimpleSelectionSortTest();
	//HeapSortTest();
	//BubbleSortTest();
	//QuickSortTest();
	MergeSortTest();

	//int N =10;

	//int* arr = (int*)malloc(sizeof(int) * N);

	//if (arr == NULL)
	//{
	//	exit(-1);
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	arr[i] = rand();
	//	//printf("%d ", arr[i]);
	//}
	//printf("\n");
	//printf("MergeSort之前的数据\n");
	//DataPrint(arr, N);
	//long beginTime = clock();

	//MergeSortNonR(arr,N);

	//long endTime = clock();
	//printf("After Sort Spend %ld ms\n", endTime - beginTime);
	//printf("MergeSort之后的数据\n");
	//DataPrint(arr, N);

	//printf("\n");
	//

	//free(arr);
	return 0;
}

void StraightInsertionSortTest()
{
	int arr[] = { 2,3,4,5,2,3,8,6,7 };
	int size = sizeof(arr) / sizeof(int);
	printf("直接插入排序之前的数据\n");
	DataPrint(arr, size);

	StraightInsertionSort(arr, size);
	printf("直接插入排序之后的数据\n");
	DataPrint(arr, size);

}

void ShellSortTest()
{
	int arr[] = {12,3,1,2,7,12,14,16,18,10,56,34,65, 2,3,4,5,2,3,8,6,7 };
	int size = sizeof(arr) / sizeof(int);
	printf("希尔排序之前的数据\n");
	DataPrint(arr, size);

	ShellSort(arr, size);
	printf("希尔排序之后的数据\n");
	DataPrint(arr, size);
}

void SimpleSelectionSortTest()
{

	int arr[] = { 12,3,1,2,7,12,56,14,16,18,10,56,34,65, 2,3,4,5,2,3,8,6,7 };
	int size = sizeof(arr) / sizeof(int);
	printf("SimpleSelectionSort之前的数据\n");
	DataPrint(arr, size);
	printf("\n");
	SimpleSelectionSort(arr, size);
	printf("SimpleSelectionSort之后的数据\n");
	DataPrint(arr, size);
}

void HeapSortTest()
{
	
	int arr[] = { 12,3,1,2,7,12,56,14,16,18,10,56,34,65, 2,3,4,5,2,3,8,6,7 };
	int size = sizeof(arr) / sizeof(int);
	printf("HeapSort之前的数据\n");
	DataPrint(arr, size);
	printf("\n");
	HeapSort(arr, size);
	printf("HeapSort之后的数据\n");
	DataPrint(arr, size);
}

void BubbleSortTest()
{
	//int arr[] = { 10000,57282,8638,6776,777,8812,3,457,999,1,2,7,12,56,14,16,18,10,56,34,65, 2,3,4,5,2,3,8,6,7 };
	int arr[] = { 1,2,3,4,5 };
	int size = sizeof(arr) / sizeof(int);
	printf("BubbleSort之前的数据\n");
	DataPrint(arr, size);
	printf("\n");
	BubbleSort(arr, size);
	printf("BubbleSort之后的数据\n");
	DataPrint(arr, size);
}

void QuickSortTest()
{
	//int arr[] = { 49,38,65,97,76,13,27,49,38,65,97,76,13};
	int arr[] = { 1,2,3,4,5 };
	//int arr[] = { 49,38,65,97,76,13,27 };
	int size = sizeof(arr) / sizeof(int);
	printf("QuickSort之前的数据\n");
	DataPrint(arr, size);
	printf("\n");
	QuickSort(arr, 0,size-1);
	printf("QuickSort之后的数据\n");
	DataPrint(arr, size);

}

void MergeSortTest()
{
	//int arr[] = { 10000,57282,8638,6776,777,8812,3,457,999,1,2,7,12,56,14,16,18,10,56,34,65, 2,3,4,5,2,3,8,6,7 };
	//int arr[] = { 1,2,3,4,5 };
	int arr[] = { 3,813};
	
	int size = sizeof(arr) / sizeof(int);
	printf("MergeSort之前的数据\n");
	DataPrint(arr, size);
	printf("\n");
	MergeSort(arr, size);
	printf("MergeSort之后的数据\n");
	DataPrint(arr, size);
}
