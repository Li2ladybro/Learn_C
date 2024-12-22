//#define _CRT_SECURE_NO_DEPRECATE
//#include<stdio.h>
//int main()
//{
//	int A[10000] = { 0 }, B[10000] = { 0 };
//	int N = 0;
//	scanf("%d", &N);
//	int i = 0, j = 0;
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d%d", &A[i], &B[i]);
//	}
//	for (i = 1; i < 1e6; i++)
//	{
//		int flig = 1;
//		for (j = 0; j < N; j++)
//		{
//			if (B[j] != (A[j] / i))
//			{
//				flig = 0;
//				break;
//			}
//		}
//		if (flig)
//		{
//			printf("%d ", i);
//			break;
//		}
//	}
//	for (i = 1e6; i > 0; i--)
//	{
//		int flig = 1;
//		for (j = 0; j < N; j++)
//		{
//			if (B[j] != (A[j] / i))
//			{
//				flig = 0;
//				break;
//			}
//		}
//		if (flig)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}