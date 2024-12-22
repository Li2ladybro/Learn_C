#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int turnedOn = 0;
	int H[4] = { 8,4,2,1 }, M[] = { 32,16,8,4,2,1 };
	int H_size=sizeof(H)/sizeof(H[0]);
	int M_size=sizeof(M)/sizeof(M[0]);
	scanf("%d",&turnedOn);
	if (turnedOn > 6)
	{
		printf("[]");
	}
	else
	{
		int i = 0;
		if (turnedOn == 1)
		{
			printf("[");
			for (i = M_size-1; i >=0; i--)
			{
				printf("\"0:%d%d\",",M[i]/10,M[i]%10);
			}
			for (i = H_size - 1; i >= 0; i--)
			{
				printf("\"%d:00\",", H[i]);
			}
			printf("]\n");
			printf("[\"0:01\",\"0 : 02\", \"0 : 04\", \"0 : 08\",\"0:16\",\"0 : 32\", \"1 : 00\", \"2 : 00\",\"4 : 00\", \"8 : 00\"]");
		}
	}
	return 0;
}