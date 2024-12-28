#include"title_check_file.h"
#include "2024_9_15Dlg.h"
//函数名：inint_file_data
//参数：File_data*
//返回类型：void 
//Function：初始化文件数据
void inint_file_data(File_data* ps)
{
	ps->_breadth = 100;               // 一行100字节
	ps->_capacity = 500;              // 初始文件行数默认设置为500行
	ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);    //向堆区申请内存
	if (ps->_titles == NULL)
	{
		printf("申请空间失败，退出程序\n");
		exit(1);
	}
	else
	{
		memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
		ps->_current_line_count = 0;
	}
}

//函数名：write_file_to_array
//参数：地址：文件；地址：存放地址
//返回类型：int
//Function：将题目写入数组并返回文件行数
void write_file_to_array(FILE* f, File_data* ps)
{
	int rank = 0;
	int forcecasting = 0;
	while ((forcecasting = fgetc(f)) != EOF)
	{
		if (forcecasting == '\n')
		{
			ps->_current_line_count++;
		}

	}
	rewind(f);
	if (ps->_capacity <=ps->_current_line_count++)
	{
		ps->_capacity = 1.5* ps->_current_line_count;
		free(ps->_titles);    // 释放旧空间
		ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);    //向堆区申请内存
		memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
		//malloc(ps->_titles, sizeof(char) * ps->_capacity * ps->_breadth);    //向堆区申请内存
		//printf("新内存开辟成功\n");
	}
	for (rank = 0; rank < ps->_current_line_count; rank++)
	{
		fgets(ps->_titles[rank],100, f);
	}
	//return ps->_Current_line_count;
}

//函数名：bk_caluate
//参数：地址，整型
//返回值：整型
//Function：统计空白行
int bk_caluate(File_data* ps)
{
	char reset_arry[2] = "\n";
	int count = 0;
	int bk_count = 0;
	for (count = 0; count < ps->_current_line_count; count++)
	{
		if (strcmp((ps->_titles)[count], reset_arry) == 0)
			bk_count++;
	}
	return bk_count;
}

//计算同一文件下的重复率
// 函数名： se_file_caluatesimilarity
//参数：File_data* ：题目地址; int：空白行数目
//返回类型：int
//Function：计算同一文件重复度
int se_file_caluatesimilarity(File_data* ps, int bk_count)
{
	int count1 = 0;      //从左边一列题目与
	int count2 = 0;      //右边一列题目一一比较
	int similarity = 0;
	int sm_count = 0;
	char reset_arry[2] = "\n";//文档空行
	for (count1 = 0; count1 < ps->_current_line_count; count1++)
	{
		if (strcmp((ps->_titles)[count1], reset_arry) == 0)
			continue;          //如果此行为空白行则跳过访问下一个题目
		for (count2 = 0; count2 < ps->_current_line_count; count2++)
		{
			//如果对面的题目也为空白行则跳过继续访问下一个题目||与此题目同行的不做比较->没意义
			if ((strcmp((ps->_titles)[count1], reset_arry) == 0) || (count1 == count2))
				continue;
			//只要找到一个与之相同的题目直接退出循环，进行下一个题目遍历
			if (strcmp((ps->_titles)[count1], (ps->_titles)[count2]) == 0)   // 基于整个题目进行比较，并非一个个字符
			{
				sm_count++;
				break;
			}
		}
	}
	return  sm_count * 100 / (ps->_current_line_count - bk_count);   //一样的题目/总的题目数目（不包含空白行）
}

//函数名：dt_file_caluatesimilarity
//参数：地址
//返回类型：int
//Function：计算不同文件重复率
int dt_file_caluatesimilarity(char oldtitle[], char newtitle[])
{
	int old_title_current, new_title_current, old_title_length, new_title_length;
	int similar_count = 0;
	old_title_length = strlen(oldtitle) - 1;
	new_title_length= strlen(newtitle)- 1;
	for (new_title_current = 0; new_title_current < new_title_length; )
	{
		if (newtitle[new_title_current] & 0x80)//汉字一次比两个字符
		{
			for (old_title_current = 0; old_title_current < old_title_length; )
			{
				if ((newtitle[new_title_current] == oldtitle[old_title_current]) && (newtitle[new_title_current + 1] == oldtitle[old_title_current + 1]))
				{
					similar_count += 2;
					break;
				}
				old_title_current += 2;
			}
			new_title_current += 2;
		}
		else //非汉字一次比一个字符
		{
			for (old_title_current = 0; old_title_current < old_title_length; old_title_current++)
			{
				if (newtitle[new_title_current] == oldtitle[old_title_current])
				{
					similar_count++;
					break;
				}
			}
			new_title_current++;
		}
	}
	return similar_count * 100 / new_title_length;
}

//函数名：obtaine_check_result_and_write_to_file
//参数：File_data* ：旧题目地址;File_data* ：新题目地址;FILE* ：要写入文件的地址；int：最大重复率
//返回类型：void
//Function：得出查重结果并把结果写入Output_file.txt文件
void obtaine_check_result_and_write_to_file
(
	File_data* oldtitle,
	File_data* newtitle,
	FILE* pi, 
	int max_repetition,
	int old_bk_count,
	int old_se_file_similarity,
	int new_bk_count,
	int new_se_file_similarity
)
{
	int new_title_count = 0;
	int old_title_count = 0;
	char reset_arry[2] = "\n";                   //文档空行
	char fprint_new_tile_flag = 0;               //用于标记新题目是否被写入过。
	int similarity = 0;                          //标记重复度
	int count = 0;                               //标记字符位
	int old_title_length = 0;                    //标记字符长度

	//先写入基本信息
	fprintf(pi, "旧文件题目一共有%d行，空白行有%d行,重复比率:%d%%，\n",oldtitle->_current_line_count,old_bk_count,old_se_file_similarity);
	fprintf(pi, "新文件题目一共有%d行，空白行有%d行,重复比率:%d%%，\n",newtitle->_current_line_count,new_bk_count,new_se_file_similarity);
	fprintf(pi, "****************************************************\n");

	for (new_title_count = 0; new_title_count < newtitle->_current_line_count; new_title_count++)
	{

		if (strcmp((newtitle->_titles)[new_title_count], reset_arry) == 0)
			continue;        //跳过空白行
		fprint_new_tile_flag = 1;
		for (old_title_count = 0; old_title_count < oldtitle->_current_line_count; old_title_count++)
		{
			if (strcmp((oldtitle->_titles)[new_title_count], reset_arry) == 0)
				continue;    //跳过空白行
			similarity = dt_file_caluatesimilarity((oldtitle->_titles)[old_title_count], (newtitle->_titles)[new_title_count]);//得到重复度
			old_title_length = strlen((oldtitle->_titles)[old_title_count]) - 1;
			if (similarity > max_repetition)
			{
				//与旧题目重复的新题目只打印一次
				if (1 == fprint_new_tile_flag)
				{
					fprintf(pi, "\n%d号新题目:%s", new_title_count + 1, (newtitle->_titles)[new_title_count]);
					fprint_new_tile_flag = 0;
				}
				fprintf(pi, "%d号旧题目:", old_title_count + 1);
				for (count = 0; count < old_title_length; count++)
				{
					fputc((oldtitle->_titles)[old_title_count][count], pi);
				}
				fprintf(pi, "------重复率：%d%%\n", similarity);
			}
		}
	}
}