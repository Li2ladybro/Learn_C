#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int main()
{
	FILE* pe;
	pe = fopen("D:\\c����code\\���㹤��ʱ��\\����.txt", "r");
	if (pe == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(1);
	}

	int date[520][12] = { 0 };
	int i = 0, j = 0;//i�У�j��
	//�������ݼ�
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
	//int h1 = 0, h2 = 0, m1 = 0, m2 = 0, s1 = 0, s2 = 0;//Сʱ�����ӣ���
	int all_s = 0;//�ܵĹ���ʱ��
	for (month = 1; month <= 12; month++)
	{
		for (day = 1; day <= 31; day++)
		{
			int  flag = 1;
			int temp1[3] = { 0 };//��ʱ������ʱ�䣬��ֵ
			int temp2[3] = { 0 };//��ʱ������ʱ�䣬��ֵ
			//printf("��ʼ111111111111");
			for (i = 0; i < 520; i++)
			{
				if (date[i][2] == month && date[i][4] == day)
				{
					printf("%2d�� %2d�� %2dʱ %2d�� %2d��\n", month, day, date[i][6], date[i][8], date[i][10]);
					if (flag == 1)//һ���е�һ�μ�¼��ʱ��
			     	{
							temp1[0] = date[i][6];
							temp1[1] = date[i][8];
							temp1[2] = date[i][10];
							flag = 2;
					}
					else          //һ���еڶ��μ�¼��ʱ��
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
			if (temp1[0] > temp2[0])//Ĭ�ϵ�һ�μ�¼��ֵΪ�°�ʱ��
			{
				all_s += (int)(temp1[0] * 36e2 + temp1[1] * 60 + temp1[2] - temp2[2] - temp2[0] * 36e2 - temp2[1] * 60);
				printf("%2d�� %2d�չ���ʱ��Ϊ��%d��\n", month, day, (int)(temp1[0] * 36e2 + temp1[1] * 60 + temp1[2] - temp2[2] - temp2[0] * 36e2 - temp2[1] * 60));
				printf("*************************************\n");
			}
			else
			{
				all_s += (int)(temp2[0] * 36e2 + temp2[1] * 60 + temp2[2] - temp1[2] - temp1[0] * 36e2 - temp1[1] * 60);
				printf("%2d�� %2d�չ���ʱ��Ϊ��%d��\n", month, day, (int)(temp2[0] * 36e2 + temp2[1] * 60 + temp2[2] - temp1[2] - temp1[0] * 36e2 - temp1[1] * 60));
				printf("******/********************************\n");
			}
			//printf("%d��%d�չ���ʱ��Ϊ��%d��\n", month, day, );
		}
	}
	printf("�ܵĹ���ʱ��Ϊ��%d��\n", all_s);
	printf("%d", all_s);
	return 0;
}
