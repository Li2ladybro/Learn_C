#include "Heap.h"

void HeapTest()
{
	ElemType arr[10] = { 0,34,456,283,7938,7983,3,4,5,7 };	
	//HeapSort(arr, sizeof(arr) / sizeof(ElemType));
	Heap hp;
	HeapInit(&hp, arr, sizeof(arr) / sizeof(ElemType));
	HeapPush(&hp, -1);
	HeapPrint(&hp);
	printf("堆顶元素为：%d\n", HeapTop(&hp));
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("堆顶元素为：%d\n", HeapTop(&hp));
	HeapClear(&hp);
	HeapDestroy(&hp);

}


int main()
{
	HeapTest();
	return 0;
}