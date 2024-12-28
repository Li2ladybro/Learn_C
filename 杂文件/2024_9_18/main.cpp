//函数名：dt_file_caluatesimilarity
//参数：地址
//返回类型：int
//Function：计算不同文件重复率
//int dt_file_caluatesimilarity(char oldtitle[], char newtitle[])
//{
//	int old_title_current, new_title_current, old_title_length, new_title_length;
//	int similar_count = 0;
//	old_title_length = strlen(oldtitle) - 1;
//	new_title_length = strlen(newtitle) - 1;
//	for (new_title_current = 0; new_title_current < new_title_length; )
//	{
//		if (newtitle[new_title_current] & 0x80)//汉字一次比两个字符
//		{
//			for (old_title_current = 0; old_title_current < old_title_length; )
//			{
//				if ((newtitle[new_title_current] == oldtitle[old_title_current]) && (newtitle[new_title_current + 1] == oldtitle[old_title_current + 1]))
//				{
//					similar_count += 2;
//					break;
//				}
//				old_title_current += 2;
//			}
//			new_title_current += 2;
//		}
//		else //非汉字一次比一个字符
//		{
//			for (old_title_current = 0; old_title_current < old_title_length; old_title_current++)
//			{
//				if (newtitle[new_title_current] == oldtitle[old_title_current])
//				{
//					similar_count++;
//					break;
//				}
//			}
//			new_title_current++;
//		}
//	}
//	return similar_count * 100 / new_title_length;
//}

#include<stdio.h>
#include"string.h"

int main()
{
	

	char arr[200] = " 旧文件题目一共有11行，空白行有3行新文件题目一共有11行，空白行有3行*********************************";
}