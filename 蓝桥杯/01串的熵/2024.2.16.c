#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
int main()
{
	getchar();
	int x = 1;// 1վλ
	double sum = 11625907.5798;
	for (x = 1; x < 23333333; x++)
	{
		double p = (double)x / 23333333;// 1�ĸ���
		double result= -p * (log10(p) / log10(2)) * x - (1 - p) * (log10(1 - p) / log10(2)) * (23333333 - p);
		printf("��%d��%lf\n",x, result);
		if (fabs(result- sum) < 1)
		//if(result==sum)
		{
			if (x > 23333333.0 / 2)
			{
				printf("%d", (int)(23333333 - x));
			}
			else printf('%d', (int)x);
		}
	}
	printf("%d", (int)x);
	getchar();
	printf("����������˳�");
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include<math.h>
//
////int main()
////{
//    double n = 23333333;// 01 ���ĳ���
//    double hs = 11625907.5798;// 01 ������Ϣ��
//    double x0, x1, s;// 01 ���� 0 �� 1 �ĸ����Լ� 01 ������Ϣ��
//    for (x0 = 0; x0 < n / 2; x0++)
//    {
//        x1 = n - x0;// 01 ���� 1 �ĸ���
//        // 01 ������Ϣ��
//        s = -(x1 * (x1 * 1.0 / n) * log2(x1 * 1.0 / n) + x0 * (x0 * 1.0 / n) * log2(x0 * 1.0 / n));
//        // �������õ�s=hs����x0<x1�����˳�ѭ��
//        if (fabs(s - hs) < 0.0001)
//        {
//            printf("%d\n", (int)(x0));// ��� 01 ���� 0 �ĸ���
//            break;
//        }
//    }
//    printf("%d",(int)(log10(8) / log10(2)));
//    return 0;
//}