#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int K = 0;
	char c1 = 0, c2 = 0;
	int lift[(int)1e6] = { 0 }, num1 = 0;
	int right[(int)1e6] = { 0 }, num2 = 0;
	scanf("%d", &K);
	//char* S = (char*)malloc((int)5e5);
	char S[(int)5e6] = { 0 };
	if (S == NULL)
	{
		printf("\n¿ª±Ù¿Õ¼äÊ§°Ü\n");
	}
	else
	{
		scanf("%s %c %c", S, &c1, &c2);
	}
	int len = strlen(S);
	int i = 0, j = len;
	for (i = 0; i < j; i++)
	{
		if (S[i] == c1)
		{
			lift[num1] = i;
			num1++;
		}
		else if (S[i] == c2)
		{
			right[num2] = i;
			num2++;
		}
	}
	int  sum = 0;
	for (i = 0; i < num1; i++)
	{
		int l = 0, r = num2 - 1,mid = 0;
		int title = lift[i] + K - 1;
		while (l < r)
		{
			mid = (l + r) / 2;
			if (right[mid] >= title)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		if(right[l] >= title)
		sum += num2- l;
	}
	printf("%d", sum);
	return 0;
}