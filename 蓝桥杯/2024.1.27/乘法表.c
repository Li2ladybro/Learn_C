#include<stdio.h>
// r 行，c列，conut 计数
int main()
{
int r = 1;
int c = 1;
//# 接收乘积
int count = 1;
while (r <= 9)
{
    c = 1;
    while (c <= r)

    {//  # 从1开始乘
        printf("%d*%d=%d\t", c, r, c * r);
        c += 1;
    }
    printf("\n");
        r += 1;
 }
}
