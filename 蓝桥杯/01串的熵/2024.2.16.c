#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
int main()
{
	getchar();
	int x = 1;// 1站位
	double sum = 11625907.5798;
	for (x = 1; x < 23333333; x++)
	{
		double p = (double)x / 23333333;// 1的概率
		double result= -p * (log10(p) / log10(2)) * x - (1 - p) * (log10(1 - p) / log10(2)) * (23333333 - p);
		printf("第%d次%lf\n",x, result);
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
	printf("输入任意键退出");
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include<math.h>
//
////int main()
////{
//    double n = 23333333;// 01 串的长度
//    double hs = 11625907.5798;// 01 串的信息熵
//    double x0, x1, s;// 01 串中 0 和 1 的个数以及 01 串的信息熵
//    for (x0 = 0; x0 < n / 2; x0++)
//    {
//        x1 = n - x0;// 01 串中 1 的个数
//        // 01 串的信息熵
//        s = -(x1 * (x1 * 1.0 / n) * log2(x1 * 1.0 / n) + x0 * (x0 * 1.0 / n) * log2(x0 * 1.0 / n));
//        // 如果计算得到s=hs，且x0<x1，则退出循环
//        if (fabs(s - hs) < 0.0001)
//        {
//            printf("%d\n", (int)(x0));// 输出 01 串中 0 的个数
//            break;
//        }
//    }
//    printf("%d",(int)(log10(8) / log10(2)));
//    return 0;
//}