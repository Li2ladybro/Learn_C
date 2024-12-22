#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void* malloc_p(int num)
{
	void* p = NULL;
	p=malloc(sizeof(long long) * num);
	if (p == NULL)
	{
		printf("开辟失败\n");
		return p;
	}
	else
	{
		printf("开辟成功\n");
		return p;
	}
}
int main()
{
	//long long i = 0;
	int num = 0;
	printf("请输入需要开辟long long 元素类型个数\n");
	scanf("%d", &num);
	long long * arr = malloc_p(num);
	printf("%d\n",(int) & arr[1] - (int ) & arr[0]);
	return 0;
}
//#include <stdio.h>
//
//int main() {
//    int arr[5] = { 1, 2, 3, 4, 5 };
//
//    for (int i = 0; i < 4; i++) {
//        printf("元素%d 和元素 %d address difference: %ld\n" ,i, i + 1,(long) ( & arr[i + 1] )- (long)(& arr[i]));
//    }
//
//    return 0;
//}