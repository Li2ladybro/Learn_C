#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int N;
int st[10] = { 0 };
typedef struct data
{
	int t;
	int d;
	int L;
}data;
data arr[30] = { 0 };
static int DFS(int u, int time)
{
	if (u == N)
		return 1;
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (!st[i])
		{
			st[i] = 1;
			if (arr[i].t + arr[i].d < time)
			{
				st[i] = 0;
				return 0;
			}
			int t = (time > arr[i].t ? time : arr[i].t) + arr[i].L;
			u += 1;
			if (DFS(u, t))
				return 1;
			st[i] = 0;
		}
	}
	return 0;
}
int main()
{
	int result = 0;
	int T = 0;
	scanf("%d", &T);
		int j = 0;
	for (j = 0; j < T; j++)
	{
		scanf("%d", &N);
		int i = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%d%d%d", &arr[i].t, &arr[i].d, &arr[i].L);
		}
		if (DFS(0, 0))
			printf("yes");
		else
			printf("no");
	}
	
	return 0;
}