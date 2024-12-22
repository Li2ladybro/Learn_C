#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* arr = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	printf("before:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int lift=0,right = 10 - 1;
	while (lift < right)
	{
		int temp = arr[lift];
		arr[lift] = arr[right];
		arr[right] = temp;
		lift++;
		right--;
	}
	printf("afterswp:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}