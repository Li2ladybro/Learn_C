#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
static int DFS(int* box, int dex, int* used, int n)
{
	int i = 0;
	if (dex == n + 1)
	{
		printf("\n");
		for (i = 1; i <dex; i++)
		{
			printf("%d ", box[i]);
		}
		return 0;
	}
	for (i = 1; i <= n; i++)
	{
		if (used[i] == 0)
		{
			box[dex] = i;
			used[i] = 1;
			DFS(box, dex + 1, used, n);
			used[i] = 0;
		}
	}
}
int main()
{
	int box[4] = { 0 },dex=1;
	int used[4] = { 0 }, n = 3;
	//scanf("%d", &n);
	DFS(box, dex, used, n);
	return 0;
}