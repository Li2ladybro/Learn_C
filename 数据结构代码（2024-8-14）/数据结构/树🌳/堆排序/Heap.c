#include "Heap.h"

//����
void swap(ElemType* a, ElemType* b)
{
	ElemType temp = *b;
	*b = *a;
	*a = temp;
}

//���µ����㷨�����ڵ��¸���
//ǰ�᣺������������С��
//���Ӷȣ�LogN
//����a:���飬n:���ݸ�����root:�Ѷ�
void AdjustDown(ElemType* a, int n, int root)
{
	int parent = root;
	//Ĭ��������С��
	int child = parent * 2 + 1;
	while (child < n)
	{
		//��ú����е���Сֵ
		if (child + 1 < n && a[child + 1] < a[child] )
		{
			//����Һ���С�򽻻�
			child++;
		}
		//���ӽ���
		if (a[parent] > a[child])//���״��ں������¸�
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//����������ֱ�ӽ���
			break;
		}
	}
}

//���ϵ����㷨С���ϸ�
void AdjustUp(ElemType* a, int n, ElemType data)
{
	int child = n-1 ;
	int parent = (child - 1) / 2;
	while(child>0)
	{
		if (a[child] < a[parent])
		{
			//����
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//���������������ֱ���˳�
			break;
		}
	}
}

//�����ѣ��������Ϲ��������ﹹ������С��
//��Ҷ������һ�㿪ʼ����
//���Ӷȣ�n
void HeapCreat(ElemType* a, int n)
{
	//�����ѣ��������Ϲ��������ﹹ������С��
	//��Ҷ������һ�㿪ʼ����
	//���Ӷȣ�n
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
}
//������
//�ݼ���С���ѣ������ô����
//���Ӷȣ�nLogN
void HeapSort(ElemType* a, int n)
{
	HeapCreat( a, n);
	int end = n - 1;
	//��end=0ʱû��Ҫ����
	while (end > 0)
	{
		swap(&a[0], &a[end]);//ʹ�����һ��Ϊ��Сֵ
		//�����Ѿ��Ѷѹ������ˣ����������µ����㷨���������ٴι�����ֻ��������µ����㷨
		AdjustDown(a, end, 0);
		end--;
	}
}

//��ӡ��
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

//��ʼ��
void HeapInit(Heap* php, ElemType* a, int n)
{
	assert(php);
	php->_arr = (ElemType*)malloc(sizeof(ElemType) * n);
	if (php->_arr == NULL)
	{
		printf("��ʼ��ʧ��\n");
		exit(-1);
	}
	php->_size = n;
	php->_capacity = n;
	//��ֲ
	memcpy(php->_arr, a, sizeof(ElemType) * n);
	//������
	HeapCreat(php->_arr, n);
}

//���
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

//����
void HeapDestroy(Heap* php)
{
	HeapClear(php);
	php->_capacity = 0;
}

//����Ԫ�أ�����β�����µ�Ԫ�أ���Ȼ���ֶѵ�����
void HeapPush(Heap* php, ElemType data)
{
	//�������ϵ���
	assert(php);
	if (php->_size == php->_capacity)
	{
		//����
		php->_capacity *= 2;
	}
	php->_arr = (ElemType*)realloc(php->_arr, sizeof(ElemType) * php->_capacity);
	if (php->_arr == NULL)
	{
		printf("�ڴ治�㣬����ʧ��\n");
		exit(-1);
	}
	php->_arr[php->_size++]=data;
	AdjustUp(php->_arr, php->_size, data);
}

//�����Ѷ�Ԫ�أ����ҵ�������Ȼ���ֶѵ�����
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size);
	//a �ѶѶ����������һ�����ݽ��������ֶѵĽṹ����
	swap(&php->_arr[0], &php->_arr[php->_size - 1]);
	php->_size--;
	//b �������µ���
	AdjustDown(php->_arr, php->_size, 0);
}

//ȡ�Ѷ�
ElemType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size);
	return php->_arr[0];
}
