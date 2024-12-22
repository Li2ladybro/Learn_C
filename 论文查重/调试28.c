#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<windows.h>
//#include "调试20.h"
#define Old_File_Address "./旧题目.txt"
#define New_File_Address "./新题目.txt"
#define M  5000
#define N  100
//函数名：bk_caluate
//参数：地址，整型
//返回值：整型
//Function：统计空白行
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
//函数名：judge_reasonably
//参数：地址，整型
//返回值：整型
//Function：判定数据是否输入合理
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
case 1:printf("\n***************请输入1....100的整数***************\n");
scanf("%d", &max_repetition);
judge_reasonably(max_repetition);
}*/
}
//函数名：Write_File_To_Array
//参数：地址
//返回类型：int
//Function：将题目写入数组并返回文件行数
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
	printf("文件一共%d行\n", line_count);
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
//函数名：dt_file_caluatesimilarity
//参数：地址
//返回类型：int
//Function：计算不同文件重复率
int dt_file_caluatesimilarity(char oldfile[], char newfile[])
{
	int old_count, new_count, len1, len2;
	int similar_count = 0;
	len1 = strlen(oldfile) - 1;
	len2 = strlen(newfile) - 1;
	for (new_count = 0; new_count < len2; )
	{
		if (newfile[new_count] & 0x80)//汉字一次比两个字符
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
		else //非汉字一次比一个字符
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
//计算同一文件下的重复率
// 函数名： se_file_caluatesimilarity
//参数：地址
//返回类型：int
//Function：计算同一文件重复度
int se_file_caluatesimilarity(char title[M][N], int bk_count, int line_count)
{
	int count1 = 0;
	int count2 = 0;
	int similarity = 0;
	int sm_count = 0;
	char reset_arry[2] = "\n";//文档空行
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
	int bk_count = 0;//统计空白行数目
	char  max_repetition_flag[100] = { 0 };//标记最大重复率，检测是否合法
	char oldTile[M][N] = { 0 };
	char newTiles[M][N] = { 0 };
	char print_new_tile_flag = 0;//用于标记新题目是否被打印过。
	char reset_arry[2] = "\n";//文档空行
	//将旧题目文件读到二维数组oldTile中
	FILE* pi = fopen(Old_File_Address, "r");
	if (pi == NULL)
	{
		printf("未找到旧题目,请将旧题目文件放到放到当前文件夹下，并重命名为旧题目.txt后重新运行程序\n");
		printf("******************press any key exit********************\n");
		getchar();
		return 1;
	}
	else
	{
		printf("旧题目文件打开成功，开始读取中......\n");
	}
	old_line_count = Write_File_To_Array(pi, oldTile);
	puts("旧题目读取成功");
	bk_count = bk_caluate(oldTile, old_line_count);
	similarity = se_file_caluatesimilarity(oldTile, bk_count, old_line_count);
	printf("文件题目重复比为:%d%%，空白行有%d行", similarity, bk_count);
	printf("\n************************\n");
	//将新题目文件读到二维数组newTiles中	
	FILE* new_pi = fopen(New_File_Address, "r");
	if (new_pi == NULL)
	{
		printf("未找到新题目,请将新题目文件放到放到当前文件夹下，并重命名为新题目.txt后重新运行程序\n");
		printf("******************press any key exit********************\n");
		getchar();
		return 1;
	}
	else
	{
		printf("新题目文件打开成功,开始读取中......\n");
	}
	new_line_count = Write_File_To_Array(new_pi, newTiles);
	if (fclose(new_pi) == 0);
	puts("新题目文件读取成功");
	bk_count = bk_caluate(newTiles, new_line_count);
	similarity = se_file_caluatesimilarity(newTiles, bk_count, new_line_count);
	printf("文件题目重复比为:%d%%，空白行有%d行", similarity, bk_count);
	printf("\n************************\n");
	printf("请输入最大重复率（1....100的整数）:\n");
	scanf("%d", &max_repetition);//测试数据123,q12,q,12q,80,包含所有数据可能的输入
	fgets(max_repetition_flag, 100, stdin);
	//printf("t=%d,max_repetition=%d", t, max_repetition);
	while (!judge_reasonably(max_repetition, max_repetition_flag))
	{
		printf("************输入异常!************\n请输入最大重复率（1....100的整数）:\n");
		//max_repetition_flag= scanf("%d", &max_repetition);
		scanf("%d", &max_repetition);
		fgets(max_repetition_flag, 100, stdin);
	}
	//max_repetition = agn_reasonably(max_repetition,max_repetition_flag);
	puts("\n查重成功！！！");
	FILE* pe = fopen("Output_file.txt", "w");//将结果输出到Output_file中 
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
				//与旧题目重复的新题目只打印一次
				if (1 == print_new_tile_flag)
				{

					printf("\n%d号新题目:%s", new_Tile + 1, newTiles[new_Tile]);
					fprintf(pe, "\n%d号新题目:%s", new_Tile + 1, newTiles[new_Tile]);
					print_new_tile_flag = 0;
				}
				fprintf(pe, "%d号旧题目:", old_Tile + 1);
				printf("%d号旧题目:", old_Tile + 1);
				for (count = 0; count < old_Tile_len2; count++)
				{
					fputc(oldTile[old_Tile][count], pe);
				}
				/*fputs(oldTile[i], pe);*/
				fprintf(pe, "------重复率：%d%%\n", similarity);
				for (count = 0; count < old_Tile_len2; count++)
				{
					printf("%c", oldTile[old_Tile][count]);
				}
				printf("------%d%%重复率\n", similarity);
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
			printf("....\n....\n....\n查重结果导出成功");
		}*/
	return 0;
}
