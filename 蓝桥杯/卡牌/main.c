#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct data
{
	int a;
	long long b;
}data;
 int main()
 {
	int  n = 0;
	long long m = 0;
	scanf("%d %lld", &n, &m);
	data *arr=malloc(sizeof(data)*(int)1e6);
	if (arr == NULL)
	{
		printf("¿ª±Ù¿Õ¼äÊ§°Ü\n");
	}
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i].a);
	}
	for (i= 1; i<= n; i++)
	{
		scanf("%lld", &arr[i].b);
	}
	int max = 0,index=1;
	for (i = 1; i <= n; i++)
	{
		if (arr[i].a >= max)
		{
			max = arr[i].a;
			index = i;
		}
	}
	long long sum = 0;
	for (i = index-1; i >=1; i--)
	{
        sum += (max- arr[i].a);
		if (max - arr[i].a > arr[i].b || sum > m)
		{
			sum = 0;
			int fiag = 1;
			while (fiag)
			{
				max -= 1;
				for (i = 1; i <= n; i++)
				{
					if (arr[i].a == max)
					{
						fiag = 0;
						max = arr[i].a;
						index = i;
						break;
					}
				}
			}
		}
	}
	printf("%d", arr[index].a);
	free(arr);
	arr = NULL;
	return 0;
 }