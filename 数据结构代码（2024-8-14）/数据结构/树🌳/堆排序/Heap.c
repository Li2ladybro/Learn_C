#include "Heap.h"

//交换
void swap(ElemType* a, ElemType* b)
{
	ElemType temp = *b;
	*b = *a;
	*a = temp;
}

//向下调整算法（根节点下浮）
//前提：左右子树都是小堆
//复杂度：LogN
//参数a:数组，n:数据个数，root:堆顶
void AdjustDown(ElemType* a, int n, int root)
{
	int parent = root;
	//默认左孩子是小的
	int child = parent * 2 + 1;
	while (child < n)
	{
		//获得孩子中的最小值
		if (child + 1 < n && a[child + 1] < a[child] )
		{
			//如果右孩子小则交换
			child++;
		}
		//父子交换
		if (a[parent] > a[child])//父亲大于孩子则下浮
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//不发生交换直接结束
			break;
		}
	}
}

//向上调整算法小数上浮
void AdjustUp(ElemType* a, int n, ElemType data)
{
	int child = n-1 ;
	int parent = (child - 1) / 2;
	while(child>0)
	{
		if (a[child] < a[parent])
		{
			//交换
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//如果不发生交换，直接退出
			break;
		}
	}
}

//构建堆（自下向上构建）这里构建的是小堆
//从叶结点的上一层开始构建
//复杂度：n
void HeapCreat(ElemType* a, int n)
{
	//构建堆（自下向上构建）这里构建的是小堆
	//从叶结点的上一层开始构建
	//复杂度：n
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
}
//堆排序
//递减用小根堆，递增用大根堆
//复杂度：nLogN
void HeapSort(ElemType* a, int n)
{
	HeapCreat( a, n);
	int end = n - 1;
	//当end=0时没必要交换
	while (end > 0)
	{
		swap(&a[0], &a[end]);//使得最后一个为最小值
		//上面已经把堆构建过了，满足了向下调整算法的条件，再次构建就只需调用向下调整算法
		AdjustDown(a, end, 0);
		end--;
	}
}

//打印堆
void HeapPrint(Heap* php)
{
	assert(php);
	assert(php->_size);
	int start = 0;
	while (start < php->_size)
	{
		printf("%d ", php->_arr[start]);
		start++;
	}
	printf("\n");
}

//初始化
void HeapInit(Heap* php, ElemType* a, int n)
{
	assert(php);
	php->_arr = (ElemType*)malloc(sizeof(ElemType) * n);
	if (php->_arr == NULL)
	{
		printf("初始化失败\n");
		exit(-1);
	}
	php->_size = n;
	php->_capacity = n;
	//移植
	memcpy(php->_arr, a, sizeof(ElemType) * n);
	//构建堆
	HeapCreat(php->_arr, n);
}

//清空
void HeapClear(Heap* php)
{
	assert(php);
	if (php->_size == 0)
	{
		return;
	}
	free(php->_arr);
	php->_size = 0;
}

//销毁
void HeapDestroy(Heap* php)
{
	HeapClear(php);
	php->_capacity = 0;
}

//插入元素，数组尾插入新的元素，依然保持堆的特性
void HeapPush(Heap* php, ElemType data)
{
	//进行向上调整
	assert(php);
	if (php->_size == php->_capacity)
	{
		//扩容
		php->_capacity *= 2;
	}
	php->_arr = (ElemType*)realloc(php->_arr, sizeof(ElemType) * php->_capacity);
	if (php->_arr == NULL)
	{
		printf("内存不足，扩容失败\n");
		exit(-1);
	}
	php->_arr[php->_size++]=data;
	AdjustUp(php->_arr, php->_size, data);
}

//弹出堆顶元素，并且弹出后，依然保持堆的性质
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size);
	//a 把堆顶与数组最后一个数据交换，保持堆的结构不变
	swap(&php->_arr[0], &php->_arr[php->_size - 1]);
	php->_size--;
	//b 进行向下调整
	AdjustDown(php->_arr, php->_size, 0);
}

//取堆顶
ElemType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size);
	return php->_arr[0];
}
