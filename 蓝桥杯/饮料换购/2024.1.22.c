#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
static int calute_drink_num(int num)
{
	int drink_num=num;
	while (num / 3)
	{
		drink_num += num / 3;
		num =num/3+ num % 3;
	}
	return drink_num;
}
int main()
{
	int num = 0;//购买饮料数目
	int drink_num = 0;
	printf("请输入小明购买饮料数目：");
	scanf("%d", &num);
	drink_num = calute_drink_num(num);
	printf("小明喝到的饮料数目：%d", drink_num);
	return 0;
}