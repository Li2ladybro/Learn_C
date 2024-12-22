//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	int K = 0;
//	char c1 = 0, c2 = 0;
//	scanf("%d", &K);
//	char* S = (char*)malloc((int)5e5);
//	//char S[(int)5e5] = { 0 };
//	if (S == NULL)
//	{
//		printf("\n¿ª±Ù¿Õ¼äÊ§°Ü\n");
//	}
//	else
//	{
//		scanf("%s %c %c", S, &c1,&c2);
//		//printf("%s", strerror(errno));
//		//scanf("\n%c%c");
//	}
//	int len = strlen(S);
//	int i = 0, j = 0,ans=0;
//	for (i = 0; i < len; i++)
//	{
//		
//		if(S[i]==c1)
//			for (j = i + 1; j < len; j++)
//			{
//				if (S[j] == c2&&j-i+1>=K)
//				{
//					ans++;
//			    }
//			}
//	}
//	printf("%d", ans);
//	return 0;
//}
