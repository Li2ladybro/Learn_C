#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
//������
int calute_result(int num, int arr[101])
{
    int flag = 1;
    int count=1;//��������
    int isg = 1;//����1,2,3,4,5........
    int sum = 0;
    for (count = 1; count <= num;count++)
    {
        isg = 1;
        for (; count <= num; count++)
        {
           
            if (arr[count] == 0)
            {
                isg = 1;
            }
            else if (isg == arr[count])
            {
                sum += 1;
                arr[count] = 0;

            }
           isg+= 1;
        }
    }
    return sum;
}

int main()
{
    int num = 0;//��Ƭ��Ŀ
    int arr[101] = { 0 };//��Ƭ����
    int count = 0;
    int result = 0;
    //printf("�����뿨Ƭ��Ŀ����N <=100��");
    scanf("%d", &num);
    //printf("�����뿨Ƭ���У�");
    for (count = 0; count < num; count++)
    {
        scanf("%d", &arr[count]);
    }
    result = calute_result(num, arr);
    printf("%d", result);
    return 0;
}