#include<stdio.h>
// r �У�c�У�conut ����
int main()
{
int r = 1;
int c = 1;
//# ���ճ˻�
int count = 1;
while (r <= 9)
{
    c = 1;
    while (c <= r)

    {//  # ��1��ʼ��
        printf("%d*%d=%d\t", c, r, c * r);
        c += 1;
    }
    printf("\n");
        r += 1;
 }
}
