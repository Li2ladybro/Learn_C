#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<windows.h>
//#include "����20.h"
#define Old_File_Address "./����Ŀ.txt"
#define New_File_Address "./����Ŀ.txt"
#define M  5000
#define N  100
//��������bk_caluate
//��������ַ������
//����ֵ������
//Function��ͳ�ƿհ���
int bk_caluate(char Tiles[M][N], int line_count)
{
	char reset_arry[2] = "\n";
	int count = 0;
	int bk_count = 0;
	for (count = 0; count < line_count; count++)
	{
		if (strcmp(Tiles[count], reset_arry) == 0)
			bk_count++;
	}
	return bk_count;
}
//��������judge_reasonably
//��������ַ������
//����ֵ������
//Function���ж������Ƿ��������
int judge_reasonably(int max_repetition, char max_repetition_flag[100])
{
	char reset_arry[2] = "\n";
	if ((0 < max_repetition) && (100 >= max_repetition) && (0 == strcmp(max_repetition_flag, reset_arry)))
		return max_repetition;
	else
		return 0;
	/*max_repetition = 1;
switch (max_repetition)
{
case 0:return max_repetition; break;
case 1:printf("\n***************������1....100������***************\n");
scanf("%d", &max_repetition);
judge_reasonably(max_repetition);
}*/
}
//��������Write_File_To_Array
//��������ַ
//�������ͣ�int
//Function������Ŀд�����鲢�����ļ�����
int Write_File_To_Array(FILE* f, char Tiles[M][N])
{
	//int reset = 0;
	//char reset_arry[2] = "\n";
	int rank = 0;
	int line_count = 0;
	int forcecasting = 0;
	while ((forcecasting = fgetc(f)) != EOF)
	{
		if (forcecasting == '\n')
		{
			line_count++;
		}
	}
	printf("�ļ�һ��%d��\n", line_count);
	rewind(f);
	for (rank = 0; rank < line_count; rank++)
	{
		fgets(Tiles[rank], 100, f);
		/*if (strcmp(Tiles[rank], reset_arry) == 0)
		{
			for (reset = 0; 5 > reset; reset++)
			{
				Tiles[rank][reset] = 5;
			}
		}
		printf("%s", Tiles[rank])*/;
	}
	return line_count;
}
//��������dt_file_caluatesimilarity
//��������ַ
//�������ͣ�int
//Function�����㲻ͬ�ļ��ظ���
int dt_file_caluatesimilarity(char oldfile[], char newfile[])
{
	int old_count, new_count, len1, len2;
	int similar_count = 0;
	len1 = strlen(oldfile) - 1;
	len2 = strlen(newfile) - 1;
	for (new_count = 0; new_count < len2; )
	{
		if (newfile[new_count] & 0x80)//����һ�α������ַ�
		{
			for (old_count = 0; old_count < len1; )
			{
				if ((newfile[new_count] == oldfile[old_count]) && (newfile[new_count + 1] == oldfile[old_count + 1]))
				{
					similar_count += 2;
					break;
				}
				old_count += 2;
			}
			new_count += 2;
		}
		else //�Ǻ���һ�α�һ���ַ�
		{
			for (old_count = 0; old_count < len1; old_count++)
			{
				if (newfile[new_count] == oldfile[old_count])
				{
					similar_count++;
					break;
				}
			}
			new_count++;
		}
	}
	return similar_count * 100 / len2;
}
//����ͬһ�ļ��µ��ظ���
// �������� se_file_caluatesimilarity
//��������ַ
//�������ͣ�int
//Function������ͬһ�ļ��ظ���
int se_file_caluatesimilarity(char title[M][N], int bk_count, int line_count)
{
	int count1 = 0;
	int count2 = 0;
	int similarity = 0;
	int sm_count = 0;
	char reset_arry[2] = "\n";//�ĵ�����
	for (count1 = 0; count1 < line_count; count1++)
	{
		if (strcmp(title[count1], reset_arry) == 0)
			continue;
		for (count2 = 0; count2 < line_count; count2++)
		{
			if ((strcmp(title[count2], reset_arry) == 0) || (count1 == count2))
				continue;
			if (strcmp(title[count1], title[count2]) == 0)
				sm_count++;
			break;
		}
		return  sm_count / (line_count - bk_count);
	}
}
int main()
{
	/*int max_Tiles_count = 0;
	int max_Tiles_len = 0;*/
	int old_Tile = 0;
	int new_Tile = 0;
	int max_repetition = 0;
	int count = 0;
	int old_Tile_len2 = 0;
	int old_line_count = 0;
	int new_line_count = 0;
	int similarity = 0;
	int bk_count = 0;//ͳ�ƿհ�����Ŀ
	char  max_repetition_flag[100] = { 0 };//�������ظ��ʣ�����Ƿ�Ϸ�
	char oldTile[M][N] = { 0 };
	char newTiles[M][N] = { 0 };
	char print_new_tile_flag = 0;//���ڱ������Ŀ�Ƿ񱻴�ӡ����
	char reset_arry[2] = "\n";//�ĵ�����
	//������Ŀ�ļ�������ά����oldTile��
	FILE* pi = fopen(Old_File_Address, "r");
	if (pi == NULL)
	{
		printf("δ�ҵ�����Ŀ,�뽫����Ŀ�ļ��ŵ��ŵ���ǰ�ļ����£���������Ϊ����Ŀ.txt���������г���\n");
		printf("******************press any key exit********************\n");
		getchar();
		return 1;
	}
	else
	{
		printf("����Ŀ�ļ��򿪳ɹ�����ʼ��ȡ��......\n");
	}
	old_line_count = Write_File_To_Array(pi, oldTile);
	puts("����Ŀ��ȡ�ɹ�");
	bk_count = bk_caluate(oldTile, old_line_count);
	similarity = se_file_caluatesimilarity(oldTile, bk_count, old_line_count);
	printf("�ļ���Ŀ�ظ���Ϊ:%d%%���հ�����%d��", similarity, bk_count);
	printf("\n************************\n");
	//������Ŀ�ļ�������ά����newTiles��	
	FILE* new_pi = fopen(New_File_Address, "r");
	if (new_pi == NULL)
	{
		printf("δ�ҵ�����Ŀ,�뽫����Ŀ�ļ��ŵ��ŵ���ǰ�ļ����£���������Ϊ����Ŀ.txt���������г���\n");
		printf("******************press any key exit********************\n");
		getchar();
		return 1;
	}
	else
	{
		printf("����Ŀ�ļ��򿪳ɹ�,��ʼ��ȡ��......\n");
	}
	new_line_count = Write_File_To_Array(new_pi, newTiles);
	if (fclose(new_pi) == 0);
	puts("����Ŀ�ļ���ȡ�ɹ�");
	bk_count = bk_caluate(newTiles, new_line_count);
	similarity = se_file_caluatesimilarity(newTiles, bk_count, new_line_count);
	printf("�ļ���Ŀ�ظ���Ϊ:%d%%���հ�����%d��", similarity, bk_count);
	printf("\n************************\n");
	printf("����������ظ��ʣ�1....100��������:\n");
	scanf("%d", &max_repetition);//��������123,q12,q,12q,80,�����������ݿ��ܵ�����
	fgets(max_repetition_flag, 100, stdin);
	//printf("t=%d,max_repetition=%d", t, max_repetition);
	while (!judge_reasonably(max_repetition, max_repetition_flag))
	{
		printf("************�����쳣!************\n����������ظ��ʣ�1....100��������:\n");
		//max_repetition_flag= scanf("%d", &max_repetition);
		scanf("%d", &max_repetition);
		fgets(max_repetition_flag, 100, stdin);
	}
	//max_repetition = agn_reasonably(max_repetition,max_repetition_flag);
	puts("\n���سɹ�������");
	FILE* pe = fopen("Output_file.txt", "w");//����������Output_file�� 
	for (new_Tile = 0; new_Tile < new_line_count; new_Tile++)
	{

		if (strcmp(newTiles[new_Tile], reset_arry) == 0)
			continue;
		print_new_tile_flag = 1;
		for (old_Tile = 0; old_Tile < old_line_count; old_Tile++)
		{
			if (strcmp(oldTile[old_Tile], reset_arry) == 0)
				continue;
			similarity = dt_file_caluatesimilarity(oldTile[old_Tile], newTiles[new_Tile]);
			old_Tile_len2 = strlen(oldTile[old_Tile]) - 1;
			if (similarity > max_repetition)
			{
				//�����Ŀ�ظ�������Ŀֻ��ӡһ��
				if (1 == print_new_tile_flag)
				{

					printf("\n%d������Ŀ:%s", new_Tile + 1, newTiles[new_Tile]);
					fprintf(pe, "\n%d������Ŀ:%s", new_Tile + 1, newTiles[new_Tile]);
					print_new_tile_flag = 0;
				}
				fprintf(pe, "%d�ž���Ŀ:", old_Tile + 1);
				printf("%d�ž���Ŀ:", old_Tile + 1);
				for (count = 0; count < old_Tile_len2; count++)
				{
					fputc(oldTile[old_Tile][count], pe);
				}
				/*fputs(oldTile[i], pe);*/
				fprintf(pe, "------�ظ��ʣ�%d%%\n", similarity);
				for (count = 0; count < old_Tile_len2; count++)
				{
					printf("%c", oldTile[old_Tile][count]);
				}
				printf("------%d%%�ظ���\n", similarity);
			}
		}
	}
	/*	if (fclose(pe) == 0);
		{
			printf("...>>>\n");
			Sleep(3000);
			printf("...>>>\n");
			Sleep(3000);
			printf("...>>>\n");
			Sleep(3000);
			printf("....\n....\n....\n���ؽ�������ɹ�");
		}*/
	return 0;
}
