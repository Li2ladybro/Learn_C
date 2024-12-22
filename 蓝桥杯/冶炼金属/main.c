//#define _CRT_SECURE_NO_DEPRECATE
//#include<stdio.h>
//int A[10000] = { 0 }, B[10000] = { 0 };
//int check_min(int mid,int N)
//{
//	int i = 1;
//	for (i = 1; i < N; i++)
//	{
//		if (A[i] / B[i] > mid)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//int N = 0,i=0;
//scanf("%d", &N);
//for (i = 0; i < N; i++)
//	scanf("%d %d", &A[i], &B[i]);
//	int lmax = 1, rmax = 100;
//	while (lmax <rmax)
//	{
//		int mid = (lmax + rmax)/2;
//		if (check_min(mid, N))
//		{
//			lmax = mid + 1;
//		}
//		else
//			rmax = mid;
//	}
//	printf("%d ", lmax);
//	/*lmax = 1, rmax = 1e9;
//	while (lmax <= rmax)
//	{
//		int mid = (lmax + rmax) / 2;
//		if (check_max(mid, N))
//		{
//			rmax = mid - 1;
//		}
//		else
//			lmax = mid + 1;
//			
//	}
//	printf("%d", rmax);*/
//	return 0;
//}