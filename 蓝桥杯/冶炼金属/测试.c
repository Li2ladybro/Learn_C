#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
int A[10000] = { 0 }, B[10000] = { 0 };
static int compere(int x,int y)
{
	return x - y;
}
int main()
{
	int N = 0, i = 0, j = 0, result[2] = { 0 };
	scanf("%d", &N);
	int c[10000] = { 0 };
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &A[i], &B[i]);
		c[i]= A[i] / B[i];
	}
	qsort(c, 10000, 4, compere);
	result[1] = c[0];
	//printf("\n%d", c[0]);
	int d[10000] = { 0 },d1=0;
	for (i = c[0]-1; i > 0; i--)
	{
		for (j = 0; j < N; j++)
		{
			/*if (A[j] / i > B[j])
			{
				result[0] = i+1;
				printf("%d %d", result[0],result[1]);
				return 0;
			}*/
			if (A[j] / i != B[j])
			{
				result[0] = i+1;
				printf("%d %d", result[0], result[1]);
				return 0;
			}
		}
		
	}
}