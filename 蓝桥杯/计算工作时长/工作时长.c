#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int main()
{
	FILE* pe;
	pe = fopen("D:\\c语言code\\计算工作时长\\数据.txt", "r");
	if (pe == NULL)
	{
		printf("文件打开失败！\n");
		exit(1);
	}

	int date[520][12] = { 0 };
	int i = 0, j = 0;//i行，j列
	//读入数据集
	while (!feof(pe))
	{
		for (i = 0; i < 520; i++)
		{
			for (j = 0; j < 12; j++)
			{
				if (j % 2)
				{
					fscanf(pe, "%c", &date[i][j]);
				}
				else
					fscanf(pe, "%d", &date[i][j]);
			}
		}
	}
	fclose(pe);
	int month = 1, day = 1;
	//int h1 = 0, h2 = 0, m1 = 0, m2 = 0, s1 = 0, s2 = 0;//小时，分钟，秒
	int all_s = 0;//总的工作时长
	for (month = 1; month <= 12; month++)
	{
		for (day = 1; day <= 31; day++)
		{
			int  flag = 1;
			int temp1[3] = { 0 };//临时变量给时间，赋值
			int temp2[3] = { 0 };//临时变量给时间，赋值
			//printf("开始111111111111");
			for (i = 0; i < 520; i++)
			{
				if (date[i][2] == month && date[i][4] == day)
				{
					printf("%2d月 %2d日 %2d时 %2d分 %2d秒\n", month, day, date[i][6], date[i][8], date[i][10]);
					if (flag == 1)//一天中第一次记录打卡时间
			     	{
							temp1[0] = date[i][6];
							temp1[1] = date[i][8];
							temp1[2] = date[i][10];
							flag = 2;
					}
					else          //一天中第二次记录打卡时间
					{
							temp2[0] = date[i][6];
							temp2[1] = date[i][8];
							temp2[2] = date[i][10];
							flag = 1;
					}
				}
				else
					continue;
			}
			if (temp1[0] > temp2[0])//默认第一次记录的值为下班时间
			{
				all_s += (int)(temp1[0] * 36e2 + temp1[1] * 60 + temp1[2] - temp2[2] - temp2[0] * 36e2 - temp2[1] * 60);
				printf("%2d月 %2d日工作时长为：%d秒\n", month, day, (int)(temp1[0] * 36e2 + temp1[1] * 60 + temp1[2] - temp2[2] - temp2[0] * 36e2 - temp2[1] * 60));
				printf("*************************************\n");
			}
			else
			{
				all_s += (int)(temp2[0] * 36e2 + temp2[1] * 60 + temp2[2] - temp1[2] - temp1[0] * 36e2 - temp1[1] * 60);
				printf("%2d月 %2d日工作时长为：%d秒\n", month, day, (int)(temp2[0] * 36e2 + temp2[1] * 60 + temp2[2] - temp1[2] - temp1[0] * 36e2 - temp1[1] * 60));
				printf("******/********************************\n");
			}
			//printf("%d月%d日工作时长为：%d秒\n", month, day, );
		}
	}
	printf("总的工作时长为：%d秒\n", all_s);
	printf("%d", all_s);
	return 0;
}
