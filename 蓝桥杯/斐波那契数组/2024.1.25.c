#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include<malloc.h>
//int main()
//{
//    int num = 0;
//    int arr[5] = { 0 };
//    int i = 0;
//    int a = 3;
//    scanf("%d", &num);
//    if (i < 5)
//    {
//        scanf("%d", &arr[i]);
//        i++;
//    }
//    printf("%d",a);
//}
long long FibArary(int N)
{
	long long* arr = (long long*)malloc((N + 1) * sizeof(long long));
	if (arr == NULL)
	{
		printf("error\n");
		exit(1);
	}
	arr[0] = 1;
	if (N == 0)
	{
		return arr[0];
		free(arr);
	}
	arr[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	free(arr);
	return arr[N];
}
int main()
{
	int N = 0;
	scanf("%d", &N);
	long long num = FibArary(N);
	printf("%lld\n",num);
	return 0;
}
