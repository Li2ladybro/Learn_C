#include"Sort.h"
#include"Stack.h"

// 打印数据
// 参数：printArr,待打印的数组
// 参数：size，数组的大小
void DataPrint(int printArr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		printf("%d ", printArr[i]);
	}

	printf("\n");

}

// 交换数据
// 参数：swap1,swap2,为要交换的数据
void swap(int* swap1, int* swap2)
{
	int temp = *swap1;
	*swap1 = *swap2;
	*swap2 = temp;
	return;
}

// 直接插入排序
// 时间复杂度：（最坏情况->逆序）
// 第一趟：end=0;比较一次
// 第二趟：end=1;比较二次
// 第三趟：end=2;比较三次
// .....
// 第size-1趟：end=size-2;比较size-1次
// O(n)=1+2+3+4+....+size-1=n^2;
// 
//时间复杂度：（最好的情况->顺序）
// 第一趟：end=0;比较一次
// 第二趟：end=1;比较一次
// 第三趟：end=2;比较一次
// .....
// 第size-1趟：end=size-2;比较一次
// O(n)=1+1+2+3+....+1=n;
// n<=O(n)<=n^2

// 稳定性：可以做到稳定，相等时就不移动
// 参数：arr:待排序的数组，size：元素个数
void StraightInsertionSort(int* arr, int size)
{
	assert(arr);

	for (int i = 0; i < size-1; i++)
	{
		int end = i;
		int temp = arr[end + 1];
		while (end>=0)
		{
			if (temp < arr[end])    // 稳定性：可以做到稳定，相等时就不移动
			{
				//arr[end]后移
				arr[end+1] = arr[end];
				end--;
			}
			else
			{
				// temp >= arr[end],则不动
				break;
			}
		}

		arr[end + 1] = temp;
	}

}

// 希尔排序（缩小增量排序）-> 在直接插入排序的基础上进行优化
// 第一步.预排序，让数组接近有序
// 第二步.直接插入排序，保证有序
// gap越大数据跳动的越快，越小跳的慢；
// gap越大越不有序，越小越接近有序
// gap ==1 -> 完成最后一趟排序 -> 相当于直接插入排序，保证有序
// 时间复杂度：O(n)= n^1.3—n^2

// 稳定性：不稳定
// 参数：arr:待排序的数组，size：元素个数
void ShellSort(int* arr, int size)
{
	int gap = size;

	while (gap > 1)
	{
		// gap !=1 -> 主要完成预排序，让数组接近有序
		gap = gap / 3 + 1;  // +1保证了最后一趟是直接插入排序
		// gap ==1 -> 完成最后一趟排序 -> 直接插入排序，保证有序

		printf("\n");

		for (int i = 0; i < size - gap; i++)
		{
			// size - gap-1趟并发排序
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0)
			{
				if (temp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = temp;
		}

		DataPrint(arr, size);

	}

}

// 简单选择排序
// 第一趟：比较 n-1 次
// 第二趟：end=1;比较n-3次
// 第三趟：end=2;比较n-5次
// .....
// O(n)=n-1+n-3+n-5+n-7+n-9+....+1=n^2

// 稳定性：会发生交换，所以也是不稳定的
// 参数：arr:待排序的数组，size：元素个数
void SimpleSelectionSort(int* arr, int size)
{

	int begin = 0, end = size - 1;
		
	while (begin<end)
	{
		// 初始化
		int mini = begin;
		int maxi = begin;

		for (int i = begin+1; i <= end; i++)
		{
			if (arr[i] < arr[mini])
			{
				// 下标交换
				mini = i;
			}

			if (arr[i] > arr[maxi])
			{
				// 下标交换
				maxi = i;
			}
		}

		// 走到这里 maxi和 mini已经拿到手了
		// 数值交换
		swap(&arr[mini], &arr[begin]); // 将对应下标位置的数据换位

		if (begin == maxi)
		{
			// 如果 maxi 在 begin 位置，但是经过上一层的交换 maxi 的数据已经被拿走，
			// 拿到了以下标为mini的位置上，故此时应该重定向 maxi	
			maxi = mini;

		}
		
		swap(&arr[maxi], &arr[end]);       // 稳定性：会发生交换，所以也是不稳定的

		// 到此第一趟排序完毕，一趟排两个数据

		// 迭代
		begin += 1;
		end -= 1;
	}
}

//堆排序
// 稳定性：不稳定
// 参数：arr:存储结点数据的数组，size：元素个数 ，root：从root开始向下调整
void AdjustDown(int* arr, int size, int root)
{
	int parent = root;
	int child = 2 * parent + 1;

	while (child<size)
	{

		if (child + 1 < size && arr[child] < arr[child + 1])
		{
			// 获取结点数据大的孩子
			child += 1;
		}

		if (arr[child] > arr[parent])
		{
			// 交换数据 + 迭代
			swap(&arr[parent], &arr[child]);
			parent = child;
			child= 2 * parent + 1;
		}

		else
		{
			break;
		}
	}
	
}

// 建堆
void CreatHeap(int* arr, int size)
{
	for (int i = (size - 1 - 1) / 2; i >=0; i--)
	{
		AdjustDown(arr, size, i);
	}
}

// 排序
void HeapSort(int* arr, int size)
{
	CreatHeap(arr, size);

	//printf("\n");

	//DataPrint(arr, size);

	int end = size-1;
	while (end > 0)
	{
		//printf("Before swap\n");
		//DataPrint(arr, size);
		//printf("\n");

		swap(&arr[0], &arr[end]);	
		//printf("After swap\n");

		//DataPrint(arr, size);
		//printf("\n");

		AdjustDown(arr, end-1, 0);
		//printf("After AdjustDown\n");


		//DataPrint(arr, size);
		//printf("\n");

		end--;
	}
}

// 冒泡排序
// 每一趟都将最大数据冒到最后，
// 结束条件：直到只剩一个数据没有排序，或者是某一趟中没有数据交换
// 时间复杂度：（最坏情况->逆序）
// 第一趟：end=size-1;比较n-1次
// 第二趟：end=size-1-1;比较n-2次
// 第三趟：end=size-1-1-1;比较n-3次
// .....
// 第size-1趟：end=1;比较一次
// O(n)=n-1+n-2+n-3+....+1=n^2;
// n<=O(1)<=n^2
// 
//时间复杂度：（最好的情况->顺序）
// 第一趟：比较n-1次,并且没有数据交换
// 直接结束排序
// O(n)=n-1=n;

// n<=O(n)<=n^2
// 稳定性：相等时候不交换数据->稳定的
// 参数：arr:待排序的数组，size：元素个数
void BubbleSort(int* arr, int size)
{
	assert(arr);
	int exchange = 0;
	for(int end=size-1;end>0;end--)
	{ 
		int cur = 0;
		while (cur<end)
		{
			
			if (arr[cur] > arr[cur + 1])       // 稳定性：相等时候不交换数据->稳定的
			{
				// 交换
				exchange = 1;
				swap(&arr[cur], &arr[cur + 1]);
			}
		
			cur++;
		}
		// 跑到此最大数据已经到末尾

		if (exchange == 0)
		{
			// 某一趟中没有数据交换，结束排序
			break;
		}
	}

}

// 快速排序

//选择出合适的关键字
int SelectMidPivotKeyIndex(int* arr, int left , int right) 
{
	int midIndex= (left+right) >>1u;   // ➗2

	if (arr[right] > arr[midIndex])
	{
		if (arr[midIndex] > arr[left])
		{
			// arr[right] > arr[midIndex] > arr[left]

			swap(&arr[midIndex], &arr[right]);    //中间值跑后面

			return right;
		}
		else 
		{
			// 走到这里有 arr[left] > arr[midIndex]
			if (arr[right] > arr[left])
			{
				// arr[right] > arr[left] >arr[midIndex]

				swap(&arr[right],&arr[left]);    //中间值跑后面
				return right;
			}
			else  // arr[left] > arr[right] 
			{
				// arr[left] > arr[right]  >arr[pivotKeyIndex]

				// 中间值本来就在末尾，不用交换
				
				return right;

			}
		}
	}

	else   // arr[midIndex] > arr[right]
	{
		if (arr[left] > arr[midIndex])
		{
			// arr[left] > arr[midIndex] >arr[right]

			swap(&arr[midIndex], &arr[right]);    //中间值跑后面

			return right;
		}

		else  // arr[midIndex]> arr[left] 
		{
			if (arr[left] > arr[right])
			{
				// arr[midIndex]> arr[left] > arr[right]

				swap(&arr[right], &arr[left]);    //中间值跑后面

				return right;
			}
			else  // arr[right]>arr[left] 
			{
				// arr[midIndex]> arr[right] > arr[left]
				
				// 中间值本来就在末尾，不用交换

				return right;
			}

		}
	}
}

// 左右指针（Hoare的写法）
int PartQuickSort1(int* arr, int begin, int end)
{
	int left = begin;
	int right = end;	
	int pivotKeyIndex = SelectMidPivotKeyIndex(arr, begin, end); // 关键字下标索引
	while (left < right)
	{
		// 如果设置的关键字在右边需要让左边的先跑
		// 因为左边的指针cur找的是大于关键字的数据
		// 最后一步交换时将大于关键字的数据刚好排到后面
		
		// left找大
		while (left < right && arr[left] <= arr[pivotKeyIndex])
		{
			left++;
		}

		// right找小
		while (left < right && arr[right] >= arr[pivotKeyIndex])
		{
			right--;
		}
		// 交换左右指针数组的值
		swap(&arr[right], &arr[left]);

	}

	swap(&arr[left], &arr[pivotKeyIndex]);

	// 到此一趟排序完毕
	// 完成了两件事：
	// a.大数放到了右边，小数放到了左边。b.关键字放到了正确位置
	return left;   //返回div

}

// 挖坑大法（严蔚敏数据结构） 
int PartQuickSort2(int* arr, int begin, int end) 
{
	int left = begin;
	int right = end;
	int pivotKeyIndex = SelectMidPivotKeyIndex(arr, begin, end); // 关键字下标索引
	int key = arr[pivotKeyIndex];   //标记关键字后面会被覆盖
	while (left<right)
	{
		// 关键字设置在右边相当于在右边关键字处挖个坑
		// 这时候就只能左边先走了
		// 碰到比关键字大的数据就与在此处挖坑，
		// 将数据填到右边的坑中，left位置形成新的坑

		// left找大
		while (left < right&&arr[left] <= arr[pivotKeyIndex])
		{
			// 这里加left < right 条件判断是为了防止在走的过程中left = right
			left++;
		}
		arr[right] = arr[left];  // 覆盖

		// right找小
		while (left < right && arr[right] >= arr[pivotKeyIndex])
		{
			// 碰到比关键字小的数据就与在此处挖坑，将数据填到左边的坑中
			// 将数据填到左边的坑中，right 位置形成新的坑
			right--;
		}
		arr[left] = arr[right];  // 覆盖
		
	}

	arr[left] = key;  // left与right相遇处改为key

	// 到此一趟排序完毕
	return left;  //返回div
	
}

// 前后指针法
int PartQuickSort3(int* arr, int begin, int end) 
{
	
	int cur = begin;            // 前指针
	int prev = cur - 1;         // 后指针
	//int pivotKeyIndex = end;
	int pivotKeyIndex = SelectMidPivotKeyIndex(arr, begin, end);    // 关键字下标索引

	while (cur <= end)
	{
		// cur找到比关键字小的就++prev，再和cur交换
		// cur找小
		if (arr[cur] < arr[pivotKeyIndex])
		{
			if (++prev != cur ) 
			{				
				//如果++prev==cur,则值相等就没必要交换（技巧）
				swap(&arr[prev], &arr[cur]);
			}
			
		}

		cur++;		
	}

	swap(&arr[++prev], &arr[pivotKeyIndex]);      
	// 稳定性：最后需要交换数据，可能回把key位置的数据，
	// 改变其与其相等数据的相对顺序

	// 到此一趟快排结束

	return prev;
}

// 排序
// 无论是那种PartQuickSort其时间复杂度都是O(n)=n;
// QuickSort主函数中实现的是先序遍历
// 如果恰巧每次选的关键字都是最小的或者是最大的（有序或接近有序）
// 这样递归会使二叉树呈现一边倒状态，可能会Stack overflow（栈溢出）
// 那么其时间复杂度最差，O(n)=n*n=n^2;
// 
// 实际中我们无法保证key是中位数，
// 那么是否考虑选出不是最大也不是最小的做key;
// 因此这里使用了SelectMidPivotKeyIndex（左右中三数取中）算法
// 这样就完美避开了最坏的情况即：每次选的关键字都是最小的或者是最大的
// 平均下来其时间复杂度为：O(n)=n*Logn;
// 
// 如果每次选出的关键字恰巧是中位数
// 那么该先序遍历是一个完全二叉树
// 时间复杂度为：O(n)=n*Logn;

// 稳定性：最后需要交换数据，可能回把key位置的数据，
// 改变其与其相等数据的相对顺序

// 参数：arr:待排序的数组，
// 参数：left，begin，为数组最左边数据下标
// 参数：right，end为数组最右边数据下标

//void QuickSort(int* arr, int left, int right)
//{
//
//	if (left >= right)
//	{
//		return;
//	}
//	// 前序遍历
//	// 
//	//int mid = PartQuickSort3(arr, left, right);
//	//int mid = PartQuickSort2(arr, left, right);
//	int mid = PartQuickSort1(arr, left, right);
//
//	QuickSort(arr, left, mid-1);
//
//	QuickSort(arr, mid+1, right);
//
//	return;
//}

// QuickSort再度优化
void QuickSort(int* arr, int left, int right)
{

	if (left >= right)
	{
		return;
	}

	if (right - left + 1 >10)
	{
		// 大区间用递归
		// 前序遍历
	    // 
	    int mid = PartQuickSort3(arr, left, right);
	    //int mid = PartQuickSort2(arr, left, right);
		//int mid = PartQuickSort1(arr, left, right);

		QuickSort(arr, left, mid - 1);

		QuickSort(arr, mid + 1, right);

		return;
		
	}
	else
	{
		// 区间中只剩10个数据不再递归，
		// 占用之前大于10个数据的区间基本有序
		// 后面直接用插入排序
		// 减少递归次数 ，如果有10层数据
		// 那么最后一层可以减少2^9个递归
		// 倒数第二层可以减少2^8个递归
		StraightInsertionSort(arr + left, right - left + 1);
		return;
	}

}

// 用栈模拟实现快速排序，实现非递归算法
void QuickSortNonR(int* arr, int left, int right)
{
	assert(arr);

	SeqStack stack;

	StackInint(&stack);

	// 先把第一个区间入栈
	StackPush(&stack, right);
	StackPush(&stack, left);

	while (StackLength(&stack)!=0)
	{		
		int begin = StackGetTop(&stack);
		StackPop(&stack);
		int end = StackGetTop(&stack);
		StackPop(&stack);

		int div = PartQuickSort3(arr, begin, end);
		// [begin,div-1] div [div+1,end]

		if (div + 1 < end)
		{
			// 先入右边的
			StackPush(&stack, end);
			StackPush(&stack, div + 1);
		}
		if (begin<div -1)
		{
			// 再入左边的
			StackPush(&stack, div - 1);
			StackPush(&stack, begin);
		}
	}
	
	return;
}

// 归并排序
// 稳定性：稳定
// 两个有序数组归并成一个数组
void MergeArr(int* arr,int* temp,int begin1, int end1 ,int begin2 ,int  end2)
{
	// 归并数组
	
	int copyIndex = begin1;
	int index = begin1;

	while (begin1 <= end1 && begin2 <= end2)
	{
		// 任意一个数组走完，就退出
		if (arr[begin1] < arr[begin2])
		{
			// 相等就不动，可以保证有序稳定性
			temp[index++] = arr[begin1];
			begin1++;
		}
		else
		{
			temp[index++] = arr[begin2];
			begin2++;
		}
	}
	while (begin1 <= end1)
	{
		// begin1数组没走完
		temp[index++] = arr[begin1];
		begin1++;
	}

	while (begin2 <= end2)
	{
		// begin2数组没走完
		temp[index++] = arr[begin2];
		begin2++;
	}

	// 拷贝数据到原数组
	while (copyIndex <= end2)
	{
		arr[copyIndex] = temp[copyIndex];
		copyIndex++;
	}
	return;
}

// 归并排序子函数
void _MergeSort(int* arr,int* temp,int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	// [left ,mid] [mid+1,right]
	// 后序遍历
	_MergeSort(arr, temp,left, mid);
	_MergeSort(arr, temp,mid +1, right);

	int begin1 = left;
	int end1 =  mid;
	int begin2 = mid + 1;
	int end2 = right;

	MergeArr(arr,temp, begin1, end1, begin2, end2);

}

// 时间复杂度：递归的情况：O(n)=nlogn;
// 空间复杂度为：O(n)=n
// 参数：arr:待排序的数组，size：元素个数
void MergeSort(int* arr, int size)
{
	int left = 0, right = size - 1;
	// 传入临时辅助空间，用于归并数组
	int* temp = (int*)malloc(sizeof(int) * size);
	_MergeSort(arr,temp, left, right);
	free(temp);
	return;
}

// 递归改循环
void MergeSortNonR(int* arr, int size)
{
	// 传入临时辅助空间，用于归并数组
	int* temp = (int*)malloc(sizeof(int) * size);

	int gap =1;

	// 凑数据
	while (gap <size)
	{
		for (int i = 0; i < size - 1; i+=2*gap)
		{			
			// [begin1,begin1+gap-1],[end1 + 1,end2]
			int begin1 = i;
			int end1 = begin1 + gap  - 1;

			int begin2 = end1 + 1;
			if (begin2 > size - 1)
			{
				// 如果第二组数组没有数据就不合并
				break;
			}
			int end2 = begin1+2*gap -1;

			if (end2 > size - 1)
			{
				// 第二组数据右边界越界则修正
				end2 = size - 1;
			}

			MergeArr(arr, temp, begin1, end1, begin2, end2);
			DataPrint(arr, size);
		}
		gap*=2;
	}
	free(temp);
	return;
}


